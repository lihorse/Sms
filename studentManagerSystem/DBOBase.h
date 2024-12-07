/************************************************************************
*[Function]数据库操作接口基类;
*[Description]基于QSqlDatabase特例化的派生类，提供用户管理数据访问接口;
*[Author]LiuPan-2021/10/20;
*[Notes]
************************************************************************/
#include <QString>
#include <QVariantList>
#include <QDebug>
class QSqlDatabase;

//////////////////////////////////////////////////////////////////////////
class DBOBase
{
public:
	enum DBType_em{// 数据库类型;
		DBT_NONE,
		DBT_ACCESS,
		DBT_MYSQL,
		DBT_SQLITE,
		DBT_SQLSERVER,
		DBT_SIZE
	};

public:
	DBOBase(const QString &txDriverType);
	virtual ~DBOBase();

	//获得连接数据库的连接名;
	QString GetConnectName() { return txConnection_; }
	// 获得最近错误信息;
	QString  LastError() { return txError_; }
	// 获取数据库操作对象;
	QSqlDatabase *GetDBO() { return ptrDB_; }
	// 获取数据库类型;
	int GetDBType() { return DB_driver_type_; }

	/*! 转换特定数据库日期查询字段格式
	*/
	QString FormatDatetime(const QString &sDatetimeStr);

	///* access to private members */
	void setPort(int nPort) { port_ = nPort; };
	int getPort() { return port_; };
	void setDatabaseName(QString str) { txDatabase_ = str; };
	QString getDatabaseName() { return txDatabase_; };
	void setHostName(QString str) { txHost_ = str; };
	QString getHostName() { return txHost_; };
	void setUserName(QString str) { txUser_ = str; };
	QString getUserName() { return txUser_; };
	void setPassword(QString str) { txPassword_ = str; };
	QString getPassword() { return txPassword_; };

	// 数据库是否有效;
	virtual bool isDBValid();
	// 数据库是否连接;
	virtual bool isDBOpen();
	// 断开数据库连接;
	virtual void Disconnect();

	/************************************************************************
	*[Function]创建新的数据库连接并打开数据库;
	*[Parameter]
	-[I]dbPath: QString.数据库文件路径名称;
	-[I]user: QString.登入用户;
	-[I]password: QString.登入密码;
	-[I]connection: QString.打开的数据库连接命名（可选）;
	-[I]host: QString.主机名（可选）;
	-[I]port: int.端口号（可选）;
	*[Return]成功-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual bool Reconnect(const QString &dbPath, const QString &connection, const QString &user, const QString &password, const QString &host=QString(),int port=3306)=0;

	/************************************************************************
	*[Function]使用默认用户登入并重新打开数据库连接;
	*[Parameter]
	-[I]dbPath: QString.数据库文件路径名称;
	-[I]connection: QString.打开的数据库连接命名（可选）;
	*[Return]成功-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual bool Reconnect(const QString &dbPath, const QString &connection) = 0;

	/************************************************************************
	*[Function]创建数据库连接并打开数据库;
	*[Parameter]
	-[I]user: QString.登入用户;
	-[I]password: QString.登入密码;
	-[I]connection: QString.打开的数据库连接命名（可选）;
	-[I]host: QString.主机名（可选）;
	-[I]port: int.端口号（可选）;
	*[Return]成功-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual bool Connect(const QString &user, const QString &password, const QString &host = QString(), int port = 3306)=0;

	/************************************************************************
	*[Function]使用默认用户登入并打开数据库连接;
	*[Parameter]
	*[Return]成功-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual bool Connect() = 0;

	/************************************************************************
	*[Function]创建数据表;
	*[Parameter]
	-[I]tabName: QString.数据表名;
	-[I]fieldType_ls: QStringList.数据表字段和类型定义;
	*[Return]成功-true, 失败-false,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual bool CreateTable(const QString &tabName, const QStringList &fieldType_ls)=0;

	/************************************************************************
	*[Function]获得数据表中所有字段名;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]返回字段名列表.失败返回空列表,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual QStringList GetFieldNames(const QString &tabName) = 0;

	/************************************************************************
	*[Function]获得数据表的所有字段变量类型对应的QVariant类型枚举值;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]QVariant::type.失败返回空列表,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual QVector<int> GetFieldTypeList(const QString &tabName) = 0;

	/************************************************************************
	*[Function]获得数据表中所有字段变量类型(字符表示);
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]返回字段名列表.返回空列表表示查询失败,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual QStringList GetFieldTypeText(const QString &tabName) = 0;

	/************************************************************************
	*[Function]获得数据表字段数量;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]>=0：成功返回数据表数量。-1：查询失败,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual int GetFieldSize(const QString &tabName)=0;

	/************************************************************************
	*[Function]插入新纪录到数据库;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]varList: QVariantList.待插入的记录数据内容列表;
	*[Return]返回字段名列表.返回空列表表示查询失败,错误信息通过LastError()获取;
	*[Note]
	-1.记录值列必须按照数据表字段顺序排列，空值以QVarian()替代;
	-2.一次插入一条记录.按字段列顺序构造SQL语句，varList值列表中的空值将跳过此字段;
	************************************************************************/
	virtual bool AppendData(const QString &tabName, const QVariantList &varList);

	/************************************************************************
	*[Function]插入新纪录(指定字段)到数据库;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]fieldList: QStringList.插入记录的字段名列表.未出现的数据表字段默认为空值;
	-[I]varList: QVariantList.待插入的记录数据内容列表;
	*[Return]返回字段名列表.返回空列表表示查询失败,错误信息通过LastError()获取;
	*[Note]
	-1.字段列fieldList必须和待插入的记录值列varList一一匹配对应;
	-2.一次插入一条记录.按字段列顺序构造SQL语句，varList值列表中的空值将跳过此字段;
	************************************************************************/
	virtual bool AppendDataCustom(const QString &tabName, const QStringList &fieldList, const QVariantList &varList);

	/************************************************************************
	*[Function]插入多条新纪录到数据库(事务处理版本);
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]lsVarList: QList<QVariantList>.待插入的记录多条数据列表;
	*[Return]返回字段名列表.返回空列表表示查询失败,错误信息通过LastError()获取;
	*[Note]一次插入多条记录.按字段列前后顺序构造SQL语句，varList值列表中的空值将跳过此字段;
	************************************************************************/
	virtual bool SetDatasInTrans(const QString &tabName, const QList<QVariantList> &lsVarList);

	/************************************************************************
	*[Function]插入多条新纪录到数据库;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]lsVarList: QList<QVariantList>.待插入的记录多条数据列表;
	*[Return]返回字段名列表.返回空列表表示查询失败,错误信息通过LastError()获取;
	*[Note]一次插入多条记录.按字段列顺序构造SQL语句，varList值列表中的空值将跳过此字段;
	************************************************************************/
	virtual bool SetDatas(const QString &tabName, const QList<QVariantList> &lsVarList);

	/************************************************************************
	*[Function]从数据表中查询获得多条新纪录;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]strField: QString.查询目标要求(字段或*);
	-[I]strWhere: 额外的查询条件;
	*[Return]QList<QVariantList>.返回查询到的记录列表;
	*[Note]查询失败也会返回空列表;
	************************************************************************/
	virtual QList<QVariantList> GetDatas(const QString &tabName, const QString &strOptions, const QString &strWhere = QString());

	/************************************************************************
	*[Function]删除数据;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]成功-true, 失败-false,错误信息通过LastError()获取;
	*[Note]
	************************************************************************/
	virtual bool DeleteData(const QString &tabName, const QString &strWhere);

	/************************************************************************
	*[Function]更新数据;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]fieldList: QStringList.更新字段名列表;
	-[I]newDataList: QVariantList.更新数据值列表;
	-[I]strWhere: QString.更新的查询条件;
	*[Return]成功-true, 失败-false,错误信息通过LastError()获取;
	*[Note]
	************************************************************************/
	virtual bool UpdateData(const QString &tabName, const QStringList &fieldList, const QVariantList &newDataList, const QString &strWhere);

	//获得字段中符合条件的行的个数;
	/************************************************************************
	*[Function]查询符合条件的记录个数;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]strWhere
	*[Return]存在重名数据表-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual int FindCount(const QString &tabName, const QString &strOptions);

	/************************************************************************
	*[Function]查询指定数据表是否已存在（重名检查）;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]存在重名数据表-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual bool TableExist(const QString &tabName);

	/************************************************************************
	*[Function]查询指定数据表是否已存在（重名及字段匹配检查）;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]fields_ls: 数据表字段名称列表;
	*[Return]存在相同数据表-true, 不存在数据表或数据表字段名(顺序)不匹配-false;
	*[Note]1.错误信息通过LastError()获取; 2.数据表不匹配时，则自动删除已存在数据表;
	************************************************************************/
	virtual bool TableFieldExist(const QString &tabName, const QStringList& fields_ls);

	/************************************************************************
	*[Function]向指定数据表上添加索引;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]indexName: QString.索引名称;
	-[I]fieldList: QStringList.将要索引的字段列(一列或多列);
	*[Return]成功-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual bool  CreateIndex(const QString &table, const QString &indexName, const QStringList &fieldList);

	/************************************************************************
	*[Function] 删除数据库指定索引;
	*[Parameter]
	-[I]indexName: QString.索引名称;
	*[Return]成功-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual bool  DeleteIndex(const QString &indexName);

	/************************************************************************
	*[Function]获取数据库中所有数据表的数量;
	*[Parameter]
	*[Return]int.数据库中所有数据表的数量;失败返回-1;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual int GetTablesCount();

	/************************************************************************
	*[Function]获取数据库中所有数据表名称列表;
	*[Parameter]
	*[Return]QStringList.数据库中所有数据表名称列表;失败-返回空列表;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual QStringList GetTablesName();

	/************************************************************************
	*[Function]删除数据表;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]成功-true, 失败-false,错误信息通过LastError()获取;
	*[Note]
	************************************************************************/
	virtual bool DeleteTable(const QString &tabName);

	/************************************************************************
	*[Function]查询数据表中的记录条数;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]>=0：成功返回数据表数量。-1：查询失败,错误信息通过LastError()获取;
	*[Note]
	************************************************************************/
	virtual int GetTableSize(const QString &tabName, const QString &options = QString());

	/************************************************************************
	*[Function]备份数据库到指定文件;
	*[Parameter]
	-[I]sPath: QString.备份路径（包括备份的文件名）;
	*[Return]成功-true, 失败-false,错误信息通过LastError()获取;
	*[Note]
	************************************************************************/
	virtual bool BackupDB(const QString &sPath);

/************************************************************************
*[Function]创建数据库
*[Parameter]
-[I]dbPath: QString.创建数据库路径(包含数据库名称);
*[Return]成功-true, 失败-false,错误信息通过LastError()获取;
*[Note]                                                                */
/************************************************************************/
	virtual bool CreateDB(const QString& dbPath);

	/************************************************************************
	*[Function]查询并返回符合条件的指定范围的记录（分页查询）;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	-[I]strField: QString.查询目标要求(字段或*);
	-[I]strWhere: 额外的查询条件;
	*[Return]QList<QVariantList>.返回查询到的记录列表;
	*[Note]查询失败也会返回空列表;
	************************************************************************/
	virtual QList<QVariantList> getDatasRangeCount(const QString &tabName, const QString &strOptions, int iBegin, int iEnd, const QString &strWhere = QString()){return QList<QVariantList>();};

protected:
	QSqlDatabase *ptrDB_;// 数据库连接驱动指针;
	int DB_driver_type_;// 数据库类型;
	int port_;// 端口;
	const QString c_txDBDriver_type;// qt数据库驱动类型;
	QString  txHost_;// 主机名称;
	QString  txPassword_;// 数据库连接密码;
	QString  txUser_;// 数据库连接用户名;
	QString  txDatabase_;// 数据库文件路径名;
	QString  txConnection_;// 数据库连接名称;
	QString  txError_;// 最新错误信息;
};
