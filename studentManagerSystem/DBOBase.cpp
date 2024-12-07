/*******************************************************************
** Database.cpp **
** Function: 数据库基类 **
** Author: zhengpeichen ** 
** Date: 2018/07/07 **
*******************************************************************/
#include "DBOBase.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>
#include <QFile>
#include <QDate>

#define MIN(a,b)  ((a) > (b) ? (b) : (a))

//////////////////////////////////////////////////////////////////////////
DBOBase::DBOBase(const QString &txDriverType)
	: c_txDBDriver_type(txDriverType)
{
	DB_driver_type_ = DBT_NONE;
	port_ = 3306;
	ptrDB_ = nullptr;
	QStringList drivse = QSqlDatabase::drivers();
}

DBOBase::~DBOBase()
{
	if (ptrDB_) {
		QString oldConnectName = ptrDB_->connectionName();
		delete ptrDB_;
		ptrDB_ = nullptr;
		QSqlDatabase::removeDatabase(oldConnectName);
	}
}

bool DBOBase::isDBValid()
{// 数据库是否有效;
	if (nullptr == ptrDB_) {
		txError_ = QString("null DB driver");
		return false;
	}

	bool bR = ptrDB_->isValid();
	if (!bR) {
		QString tx = ptrDB_->lastError().text();
		txError_ = tx.isEmpty() ? QString("invalid DB driver") : tx;
	}
	return bR;
}

bool DBOBase::isDBOpen()
{
	if (!isDBValid())  return false;
	if (!ptrDB_->isOpen() || txConnection_ != ptrDB_->connectionName()) {
		QString tx = ptrDB_->lastError().text();
		txError_ = tx.isEmpty() ? QString("disconnected DB driver") : tx;
		return false;
	}

	return true;
}

void DBOBase::Disconnect()
{
	// 关闭数据库，释放驱动;
	if (isDBOpen()) {
		ptrDB_->close();
	}

	if (ptrDB_) {
		QString oldConnectName = ptrDB_->connectionName();
		delete ptrDB_;
		ptrDB_ = nullptr;
		QSqlDatabase::removeDatabase(oldConnectName);
	}
}

bool DBOBase::DeleteTable(const QString &tabName)
{// 删除数据表;
	if (!isDBOpen())  return false;
	QString strSql;
	strSql = QString("DROP TABLE %1").arg(tabName);
	QSqlQuery sqlQuery(*ptrDB_);
	bool bR = sqlQuery.exec(strSql);
	if (!bR) txError_ = ptrDB_->lastError().text();
	return bR;
}

int DBOBase::GetTablesCount()
{// 获得数据库中数据表的数量;
	if (!isDBOpen()) return -1;

	return GetTablesName().size();
}

QStringList DBOBase::GetTablesName()
{// 获得数据库中数据表的名称列表;
	if (!isDBOpen()) return QStringList();

	QStringList strList = ptrDB_->tables(QSql::Tables);
	QStringList tmpList;
	for (int i = 0; i < strList.size(); i++)
	{
		if (!strList.at(i).contains(QString("~TMPCLP"))) {
			tmpList << strList.at(i);
		}
	}
	return tmpList;
}

bool DBOBase::TableExist(const QString &tabName)
{// 查询指定数据表是否已存在（重名检查）;
	if (!isDBOpen()) return false;

	return ptrDB_->tables(QSql::Tables).contains(tabName);
}

bool DBOBase::TableFieldExist(const QString &tabName, const QStringList& fields_ls)
{// 查询指定数据表是否已存在（重名及字段匹配检查）;
	if (false == isDBOpen())  	return false;

	bool bExist = false;
	if (ptrDB_->tables(QSql::Tables).contains(tabName)) {
		if (fields_ls != GetFieldNames(tabName)) {
			bExist = false;
			DeleteTable(tabName);
		}
		else {
			bExist = true;
		}
	}

	return bExist;
}

int DBOBase::GetTableSize(const QString &tabName, const QString &options/* =QString() */)
{// 查询数据表中的记录条数;
	if (!isDBOpen())  return -1;

	QString strSql = QString("SELECT COUNT(*) FROM %1 %2").arg(tabName).arg(options);
	QSqlQuery sqlQuery(*ptrDB_);
	if (!sqlQuery.exec(strSql)) {
		txError_ = ptrDB_->lastError().text();
		return -1;// 查询失败;
	}

	int nCnt = 0;
	if (sqlQuery.next()) {
		nCnt = sqlQuery.value(0).toInt();
	}
	return nCnt;
}

bool DBOBase::BackupDB(const QString & sPath)
{// 备份数据库到指定文件;
	QFile srcFile(txDatabase_);
	bool bR = srcFile.copy(sPath);
	if (!bR) {
		txError_ = srcFile.errorString();
	}
	return bR;
}

bool DBOBase::CreateIndex(const QString & table, const QString & indexName, const QStringList & fieldList)
{// 向指定数据表上添加索引;
	if (!isDBOpen() || fieldList.isEmpty())  return false;

	QString strColumns;
	for (int i = 0; i < fieldList.size(); i++) {
		strColumns += QString("%1%2").arg(0 == i ? QString() : QString(",")).arg(fieldList.at(i));
	}
	QString strSQL = QString("CREATE INDEX %1 ON %2(%3)").arg(indexName).arg(table).arg(strColumns);
	QSqlQuery query(*ptrDB_);
	bool bR = query.exec(strSQL);
	if (!bR) txError_ = ptrDB_->lastError().text();
	return bR;
}

bool DBOBase::DeleteIndex(const QString & indexName)
{// 删除数据库指定索引;
	if (!isDBOpen()) return false;

	QString strSQL = QString("DROP INDEX %1").arg(indexName);
	QSqlQuery query(*ptrDB_);
	bool bR = query.exec(strSQL);
	if (!bR)  txError_ = ptrDB_->lastError().text();
	return bR;
}

bool DBOBase::AppendData(const QString &tabName, const QVariantList &varList)
{// 插入新纪录到数据库;
	if (!isDBOpen()) return false;

	QStringList nameList = GetFieldNames(tabName);
	if (nameList.isEmpty()) {
		txError_ = QString("table_info is null");
		return false;
	}

	QString strFields;// 字段字串;
	QString strValues;// 字段值字串;
	int nFieldSize = MIN(nameList.size(), varList.size());
	for (int i = 0; i < nFieldSize; i++)
	{
		QVariant tmpVar = varList.value(i);
		if (tmpVar.isNull()) {// 空白对象;
			continue;
		}
		if (!strFields.isEmpty() && i < nFieldSize) {// 除最后一个字段外，其余中间需要添加分隔符‘ , ’;
			strValues += QString(",");
			strFields += QString(",");
		}

		strFields += nameList.at(i);
		if (QVariant::String == tmpVar.type()) {
			strValues += QString("'%1'").arg(varList.value(i).toString());
		}
		else if (QVariant::Date == tmpVar.type()) {
			strValues += QString("'%1'").arg(varList.value(i).toDate().toString(QString("yyyy-MM-dd")));
		}
		else if (QVariant::DateTime == tmpVar.type()) {
			strValues += QString("'%1'").arg(varList.value(i).toDateTime().toString(QString("yyyy-MM-dd hh:mm:ss")));
		}
		else {
			strValues += tmpVar.toString();
		}
	}

	QString strSql;
	strSql = QString(QString("INSERT INTO %1(%2) VALUES(%3)")).arg(tabName).arg(strFields).arg(strValues);
	QSqlQuery sqlQuery(*ptrDB_);
	if (!sqlQuery.exec(strSql)) {
		txError_ = sqlQuery.lastError().text();
		return false;
	}
	return true;
}

bool DBOBase::AppendDataCustom(const QString &tabName, const QStringList &fieldList, const QVariantList &varList)
{// 插入新纪录到数据库;
	if (!isDBOpen())  return false;
	if (fieldList.isEmpty() || varList.isEmpty()) {
		txError_ = QString("table_info is null");
		return false;
	}

	QString strFields;// 字段字串;
	QString strValues;// 字段值字串;
	int nFieldSize = MIN(fieldList.size(), varList.size());
	for (int i = 0; i < nFieldSize; i++)
	{
		QVariant tmpVar = varList.value(i);
		if (tmpVar.isNull()) {// 空白对象;
			continue;
		}
		if (!strFields.isEmpty() && i < nFieldSize) {// 除最后一个字段外，其余中间需要添加分隔符‘ , ’;
			strValues += QString(",");
			strFields += QString(",");
		}

		strFields += fieldList.at(i);
		if (QVariant::String == tmpVar.type()) {
			strValues += QString("'%1'").arg(varList.value(i).toString());
		}
		else if (QVariant::Date == tmpVar.type()) {
			strValues += QString("'%1'").arg(varList.value(i).toDate().toString(QString("yyyy-MM-dd")));
		}
		else if (QVariant::DateTime == tmpVar.type()) {
			strValues += QString("'%1'").arg(varList.value(i).toDate().toString(QString("yyyy-MM-dd hh:mm:ss")));
		}
		else {
			strValues += tmpVar.toString();
		}
	}

	QString strSql;
	strSql = QString(QString("INSERT INTO %1(%2) VALUES(%3)")).arg(tabName).arg(strFields).arg(strValues);
	QSqlQuery sqlQuery(*ptrDB_);
	if (!sqlQuery.exec(strSql)) 
	{
		txError_ = sqlQuery.lastError().text();
		return false;
	}
	return true;
}

bool DBOBase::SetDatasInTrans(const QString &tabName, const QList<QVariantList> &lsVarList)
{// 插入多条新纪录到数据库(事务处理版本);
	if (!isDBOpen()) return false;
	QStringList nameList = GetFieldNames(tabName);
	if (nameList.isEmpty() || lsVarList.isEmpty()) {
		txError_ = QString("table_info is null");
		return false;
	}

	ptrDB_->transaction();
	QList<int> emptyValueIndList;// 空值跳过的序号列表
	QSqlQuery sqlQuery(*ptrDB_);
	QString sFields = QString(QString("INSERT INTO %1 (")).arg(tabName);
	QString sDataBind(QString(" VALUES("));
	int nFieldSize = MIN(lsVarList.at(0).size(), nameList.size());
	for (int i = 0; i < nFieldSize; i++) {
		if (lsVarList.at(0).at(i).isNull()) {
			emptyValueIndList << i;
			if (i == nFieldSize - 1) {
				int n = sFields.lastIndexOf(QString(",")) - 1;
				sFields.replace(n, 1, QString(")"));
				n = sDataBind.lastIndexOf(QString(",")) - 1;
				sDataBind.replace(n, 1, QString(")"));
			}
			continue;// 空值跳过;
		}

		if (i < nameList.size() - 1) {
			sFields += nameList.at(i) + QString(",");
			sDataBind += QString("?,");
		}
		else {
			sFields += nameList.at(i) + QString(")");
			sDataBind += QString("?)");
		}
	}

	QString sPrepared = sFields + sDataBind;
	for (int indVarList = 0; indVarList < lsVarList.size(); indVarList++)
	{
		QList<QVariant> lsData = lsVarList.at(indVarList);
		sqlQuery.prepare(sPrepared);
		for (int iData = 0; iData < lsData.size(); iData++) {
			if (false==emptyValueIndList.contains(iData)) {
				sqlQuery.addBindValue(lsData.at(iData));
			}
		}

		if (!sqlQuery.exec()) {
			ptrDB_->rollback();
			txError_ = sqlQuery.lastError().text();
			return false;
		}
	}

	ptrDB_->commit();
	return true;
}

bool DBOBase::SetDatas(const QString &tabName, const QList<QVariantList> &lsVarList)
{// 插入多条新纪录到数据库;
	if (!isDBOpen()) return false;
	if (tabName.isEmpty() || lsVarList.isEmpty() || lsVarList.at(0).isEmpty()) return false;

	QStringList nameList = GetFieldNames(tabName);
	if (nameList.isEmpty()) {
		txError_ = QString("table_info is null");
		return false;
	}

	QList<int> emptyValueIndList;// 空值跳过的序号列表;
	QSqlQuery sqlQuery(*ptrDB_);
	QString sFields = QString(QString("INSERT INTO %1 (")).arg(tabName);
	QString sDataBind = QString(" VALUES(");
	int nFieldSize = MIN(nameList.size(), lsVarList.at(0).size());
	for (int i = 0; i < nFieldSize; i++)
	{
		if (lsVarList.at(0).at(i).isNull()) {
			emptyValueIndList << i;
			if (i == nFieldSize - 1) {
				int n = sFields.lastIndexOf(QString(","));
				sFields.replace(n,1,QString(")"));
				n = sDataBind.lastIndexOf(QString(","));
				sDataBind.replace(n, 1, QString(")"));
			}
			continue;// 空值跳过;
		}
		if (i < nameList.size() - 1) {
			sFields += QString(QString("%1, ")).arg(nameList.at(i));
			sDataBind += QString("?, ");
		}
		else {
			sFields += QString(QString("%1)")).arg(nameList.at(i));
			sDataBind += QString("?)");
		}
	}
	QString sPrepared = sFields + sDataBind;
	for (int indVarList = 0; indVarList < lsVarList.size(); indVarList++)
	{
		QList<QVariant> lsData = lsVarList.at(indVarList);
		sqlQuery.prepare(sPrepared);
		for (int iData = 0; iData < lsData.size(); iData++)	{
			if (false == emptyValueIndList.contains(iData)) {
				sqlQuery.addBindValue(lsData.at(iData));
			}
		}
		if (!sqlQuery.exec()) {
			txError_ = sqlQuery.lastError().text();
			return false;
		}
	}

	return true;
}

QList<QVariantList> DBOBase::GetDatas(const QString &tabName, const QString &strOptions, const QString &strWhere/* =QString() */)
{// 从数据表中查询获得多条新纪录;
	if (!isDBOpen()) return QList<QVariantList>();

	QString tmpOption(strOptions);
	// 执行SQL查询;
	QString strSql = QString("SELECT %1 FROM %2 %3").arg(tmpOption).arg(tabName).arg(strWhere);
	QSqlQuery sqlQuery(strSql, *ptrDB_);
	QSqlRecord rec;
	QList<QVariant> lsVar;
	QList<QList<QVariant>> lslsVar;
	while (sqlQuery.next())
	{
		rec = sqlQuery.record();
		lsVar.clear();
		for (int i = 0; i < rec.count(); i++)
		{
			lsVar << rec.field(i).value();
		}
		lslsVar << lsVar;
	}

	if (lslsVar.isEmpty()) txError_ = sqlQuery.lastError().text();
	return lslsVar;
}

bool DBOBase::DeleteData(const QString &tabName, const QString &strWhere)
{// 删除数据;
	if (!isDBOpen())  return false;

	QString strSql;
	strSql = QString(QString("DELETE FROM %1 %2")).arg(tabName).arg(strWhere);
	QSqlQuery sqlQuery(*ptrDB_);
	bool bR = sqlQuery.exec(strSql);
	if (bR) txError_ = sqlQuery.lastError().text();
	return bR;
}

bool DBOBase::UpdateData(const QString &tabName, const QStringList &fieldList, const QVariantList &newDataList, const QString &strWhere)
{// 更新数据;
	if (!isDBOpen())  return false;
	if (tabName.isEmpty() || fieldList.size() != newDataList.size()) {
		txError_ = QString("field and data miss match");
		return false;
	}

	QString strSql;
	strSql = QString(QString("UPDATE %1 SET ")).arg(tabName);
	QString strVal;
	for (int i = 0; i < fieldList.size(); i++) {
		QVariant tmpVar = newDataList.at(i);
		if (tmpVar.isNull() || tmpVar.toString().isEmpty()) {
			strVal = QString("null");
		}
		else {
			if (QVariant::String == tmpVar.type()) {
				strVal = QString(QString("'%1'")).arg(tmpVar.toString());
			}
			else if (QVariant::DateTime == tmpVar.type()) {
				strVal = QString(QString("#%1#")).arg(tmpVar.toDateTime().toString(QString("yyyy-MM-dd hh:mm:ss")));
			}
			else if (QVariant::Date == tmpVar) {
				strVal = QString("#%1#").arg(tmpVar.toDate().toString(QString("yyyy-MM-dd")));
			}
			else {
				strVal = tmpVar.toString();
			}
		}

		strSql += QString(" %1=%2%3").arg(fieldList.at(i)).arg(strVal).arg(i < fieldList.size() - 1 ? QString(",") : QString());
	}

	if (!strWhere.isEmpty()) {
		strSql = QString(QString("%1 %2")).arg(strSql).arg(strWhere);
	}
	QSqlQuery sqlQuery(strSql, *ptrDB_);
	if (sqlQuery.lastError().isValid()) {
		txError_ = sqlQuery.lastError().text();
		return false;
	}
	return true;
}

int DBOBase::FindCount(const QString &tabName, const QString &strOptions)
{// 查询符合条件的记录个数;
	if (!isDBOpen())  return false;

	QString strSql;
	strSql = QString(QString("SELECT count(*) FROM %1 %2")).arg(tabName).arg(strOptions);
	QSqlQuery sqlQuery(*ptrDB_);
	if (!sqlQuery.exec(strSql) || !sqlQuery.next()) {
		txError_ = ptrDB_->lastError().text();
		return -1;
	}

	return sqlQuery.value(0).toInt();
}

bool DBOBase::CreateDB(const QString& dbPath)
{
	return true;
}

QString DBOBase::FormatDatetime(const QString &sDatetimeStr)
{// 转换特定数据库日期查询字段格式
	QString sFmtDateTime;
	switch(DB_driver_type_)
	{
	case DBT_ACCESS:
		sFmtDateTime = QString("#%1#").arg(sDatetimeStr);
		break;
	default:
		sFmtDateTime = QString("'%1'").arg(sDatetimeStr);
		break;
	}

	return sFmtDateTime;
}

