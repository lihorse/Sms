#include "MysqlDBO.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

MysqlDBO::MysqlDBO(QString dbName, QString connectName /* = QString() */) 
	: DBOBase(QString("QMYSQL"))
{
	DB_driver_type_ = DBT_MYSQL;
	ptrDB_ = new QSqlDatabase(QSqlDatabase::addDatabase(c_txDBDriver_type, connectName));
	txDatabase_ = dbName;
	txConnection_ = connectName;
	txHost_ = "127.0.0.1";
}

MysqlDBO::~MysqlDBO()
{
	Disconnect();
}

bool MysqlDBO::Reconnect(const QString &dbPath, const QString &connection, const QString &user, const QString &password, const QString &host, int port)
{// 创建新的数据库连接并打开数据库;
	if (isDBOpen()) {
		if (ptrDB_->connectionName() == txConnection_)
			return true;
		else
			ptrDB_->close();
	}

	if (ptrDB_) {// 释放驱动对象;
		QString oldConnectName = ptrDB_->connectionName();
		delete ptrDB_;
		ptrDB_ = nullptr;
		QSqlDatabase::removeDatabase(oldConnectName);
	}

	ptrDB_ = new QSqlDatabase(QSqlDatabase::addDatabase(c_txDBDriver_type, connection));
	ptrDB_->setDatabaseName(dbPath);
	ptrDB_->setUserName(user);
	ptrDB_->setPassword(password);
	ptrDB_->setHostName(host);
	ptrDB_->setPort(port);
	ptrDB_->setConnectOptions(QString("MYSQL_OPT_RECONNECT=1"));
	if (!ptrDB_->open()) {
		txError_ = ptrDB_->lastError().text();
		return false;
	}

	txConnection_ = ptrDB_->connectionName();
	txDatabase_ = dbPath;
	return true;
}

bool MysqlDBO::Connect(const QString &user, const QString &password, const QString &host, int port)
{// 创建数据库连接;
	if (!isDBValid()) return false;
	if (isDBOpen())  return true;

	ptrDB_->setDatabaseName(txDatabase_);
	ptrDB_->setUserName(user);
	ptrDB_->setPassword(password);
	ptrDB_->setHostName(host);
	ptrDB_->setPort(port);
	ptrDB_->setConnectOptions(QString("MYSQL_OPT_RECONNECT=1"));
	bool bR = ptrDB_->open();
	if (!bR) {
		txError_ = ptrDB_->lastError().text();
        qDebug() << txError_;
	}
	return bR;
}

bool MysqlDBO::Reconnect(const QString &dbPath, const QString &connection)
{// 使用默认用户登入并重新打开数据库连接;
	if (isDBOpen()) {
		if (ptrDB_->connectionName() == txConnection_)
			return true;
		else
			ptrDB_->close();
	}

	if (ptrDB_) {// 释放驱动对象;
		QString oldConnectName = ptrDB_->connectionName();
		delete ptrDB_;
		ptrDB_ = nullptr;
		QSqlDatabase::removeDatabase(oldConnectName);
	}

	// 重新打开数据库连接;
	ptrDB_ = new QSqlDatabase(QSqlDatabase::addDatabase(c_txDBDriver_type, connection));
	ptrDB_->setDatabaseName(dbPath);
	ptrDB_->setHostName(txHost_);
	ptrDB_->setPort(port_);
	ptrDB_->setUserName(QString("root"));
	ptrDB_->setPassword(QString("unicomp"));
	ptrDB_->setConnectOptions(QString("MYSQL_OPT_RECONNECT=1"));
	if (!ptrDB_->open()) {
		txError_ = ptrDB_->lastError().text();
		return false;
	}

	txConnection_ = ptrDB_->connectionName();
	txDatabase_ = dbPath;
	return true;
}

bool MysqlDBO::Connect()
{// 使用默认用户登入并打开数据库连接;
	if (false == isDBValid()) return false;
	if (true == isDBOpen())  return true;

	ptrDB_->setDatabaseName(txDatabase_);
	ptrDB_->setHostName(txHost_);
	ptrDB_->setPort(port_);
	ptrDB_->setUserName(QString("root"));
	ptrDB_->setPassword(QString("unicomp"));
	ptrDB_->setConnectOptions(QString("MYSQL_OPT_RECONNECT=1"));
	bool bR = ptrDB_->open();
	if (!bR)  txError_ = ptrDB_->lastError().text();
	return bR;
}

bool MysqlDBO::CreateTable(const QString &tabName, const QStringList &fieldType_ls)
{// 创建数据表;
	if (!isDBOpen())  return false;

	QSqlQuery sqlQuery(*ptrDB_);
	QString sql = "SELECT COUNT(*) FROM information_schema.TABLES WHERE TABLE_SCHEMA = :dbName AND TABLE_NAME = :tableName";
	sqlQuery.prepare(sql);
	sqlQuery.bindValue(":dbName", txDatabase_);
	sqlQuery.bindValue(":tableName", tabName);
	if (sqlQuery.exec() && sqlQuery.next()) 
	{
		int count = sqlQuery.value(0).toInt();
		if(count > 0)
		{
            //LOG_TAG("表存在");
			return true;
		}
	} else {
        //LOG_TAG("查询表存在性时出错：" +sqlQuery.lastError().text());
	}

	QString strSql;
	for (int i = 0; i < fieldType_ls.size(); i++) {
		strSql += fieldType_ls.at(i) + (i < fieldType_ls.size() - 1 ? QString(",") : QString());
	}
	strSql = QString("CREATE TABLE  %3.%1(ind int AUTO_INCREMENT not null, %2, PRIMARY KEY (`ind`))ENGINE=InnoDB DEFAULT CHARSET=utf8;").arg(tabName).arg(strSql).arg(txDatabase_);
	bool bR = sqlQuery.exec(strSql);
	if (!bR) 
	{
		txError_ = sqlQuery.lastError().text();
        //LOG_TAG(txError_);
	}

	return bR;
}

int MysqlDBO::GetFieldSize(const QString &tabName)
{// 获得数据表字段数量;
	if (!isDBOpen())  return -1;

	return GetFieldNames(tabName).size();
}

QStringList MysqlDBO::GetFieldNames(const QString &tabName)
{// 查询表格字段内容;
	if (!isDBOpen()) return QStringList();

	QString strSql;
	strSql = QString("select COLUMN_NAME from information_schema.COLUMNS where table_name='%1' and table_schema='%2'").arg(tabName).arg(txDatabase_);
	QSqlQuery sqlQuery(strSql, *ptrDB_);
	sqlQuery.next();// 跳过默认的自增主键的名称;
	QStringList nameList;// 读取所有字段名称;
	while (sqlQuery.next()) {
		nameList << sqlQuery.value(0).toString();
	}
	return nameList;
}

QVector<int> MysqlDBO::GetFieldTypeList(const QString &tabName)
{// 获得数据表的所有字段变量类型对应的QVariant类型枚举值;
	QVector<int> type_ls;
	if (!isDBOpen())	return type_ls;

	QString strSql;
	strSql = QString("select DATA_TYPE from information_schema.COLUMNS where table_name='%1' and table_schema='%2'").arg(tabName).arg(txDatabase_);
	QSqlQuery sqlQuery(*ptrDB_);
	if (!sqlQuery.exec(strSql)) {
		txError_ = ptrDB_->lastError().text();
		return type_ls;
	}

	sqlQuery.next();// 跳过默认的自增主键的名称;
	int nameCol = sqlQuery.record().indexOf(QString("type"));// 查找字段名称在查询记录中所在的列序号;
	QStringList typeName_ls;
	while (sqlQuery.next()) {// 读取所有字段;
		QString sType = sqlQuery.value(nameCol).toString();
		int varType = 0;
		if (QString("TEXT") == sType) {
			varType = QVariant::String;
		}
		else if (QString("BLOB") == sType) {
			varType = QVariant::BitArray;
		}
		else if (QString("INTEGER") == sType) {
			varType = QVariant::Int;
		}
		else if (QString("REAL") == sType) {
			varType = QVariant::Double;
		}
		else if (QString("NUMERIC") == sType) {
			varType = QVariant::String;//QVariant
		}
		else if (QString("date") == sType) {
			varType = QVariant::String;//Date
		}
		else if (QString("datetime") == sType) {
			varType = QVariant::String;//DateTime
		}
		else {
			varType = QVariant::Invalid;
		}
		type_ls.append(varType);
	}

	return type_ls;
}

QStringList MysqlDBO::GetFieldTypeText(const QString &tabName)
{// 获得数据表中所有字段变量类型(字符表示);
	QStringList type_ls;
	if (!isDBOpen())	return type_ls;

	/************************************************************************
	*查询结果数量=表中字段数量;
	*查询结果单条记录信息有：cid name type notnull dflt_value pk ;
	*cid: 序号;
	*name：字段名称;
	*type：字段类型;
	*notnull: 是否支持为空. 1-不为空，0-可以为空值;
	*dflt_value: 是否有默认值. 空-无默认值;
	*pk: 是否主键.1-主键，0-非主键;
	************************************************************************/
	QString strSql;
	strSql = QString("select DATA_TYPE from information_schema.COLUMNS where table_name='%1' and table_schema='%2'").arg(tabName).arg(txDatabase_);
	QSqlQuery sqlQuery(*ptrDB_);
	if (!sqlQuery.exec(strSql)) {
		txError_ = ptrDB_->lastError().text();
		return type_ls;
	}

	sqlQuery.next();// 跳过默认的自增主键的名称;
	int nameCol = sqlQuery.record().indexOf(QString("type"));// 查找字段名称在查询记录中所在的列序号;
	QStringList typeName_ls;
	while (sqlQuery.next()) {// 读取所有字段;
		type_ls.append(sqlQuery.value(nameCol).toString());
	}

	return type_ls;
}


bool MysqlDBO::CreateDB(const QString& dbPath)
{
//查寻是否存在数据库
	
	// 使用默认用户登入并打开数据库连接;
	if (false == isDBValid()) return false;
	if (true == isDBOpen())  return true;

	ptrDB_->setHostName(txHost_);
	//ptrDB_->setPort(port_);
	ptrDB_->setUserName(QString("root"));
	ptrDB_->setPassword(QString("unicomp"));
	QString sql = QString("CREATE  DATABASE  %1").arg(dbPath);
	if(!ptrDB_->open())
	{
		txError_ = ptrDB_->lastError().text();
        //LOG_TAG("失败：" + txError_);
		return false;
	}
	QSqlQuery sqlQuery(*ptrDB_);

	QString checkDBQuery = "SHOW DATABASES LIKE 'detectionrecord'";
	if(sqlQuery.exec(checkDBQuery)) 
	{
		while(sqlQuery.next()) 
		{
			if(sqlQuery.value(0).toString() == "detectionrecord") 
			{
                //LOG_TAG("数据库存在");
				txDatabase_ = dbPath;
				ptrDB_->close();
				return true;
			}
		}
	}
	bool success = sqlQuery.exec(sql);
	if (!success) {
		txError_ = sqlQuery.lastError().text();
        //LOG_TAG("失败：" + txError_);
		ptrDB_->close();
		return false;
	}
	txDatabase_ = dbPath;
	ptrDB_->close();
	return true;
}
