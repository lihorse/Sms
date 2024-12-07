#pragma once

#include "DBOBase.h"

class MysqlDBO : public DBOBase
{
public:
	explicit MysqlDBO(QString dbName, QString connectName = QString());
	~MysqlDBO();

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
	virtual bool Reconnect(const QString &dbPath, const QString &connection, const QString &user, const QString &password, const QString &host, int port);

	/************************************************************************
	*[Function]使用默认用户登入并重新打开数据库连接;
	*[Parameter]
	-[I]dbPath: QString.数据库文件路径名称;
	-[I]connection: QString.打开的数据库连接命名（可选）;
	*[Return]成功-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual bool Reconnect(const QString &dbPath, const QString &connection);

	/************************************************************************
	*[Function]使用默认用户登入并打开数据库连接;
	*[Parameter]
	*[Return]成功-true, 失败-false;
	*[Note]错误信息通过LastError()获取;
	************************************************************************/
	virtual bool Connect();

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
	virtual bool Connect(const QString &user, const QString &password, const QString &host, int port);

	/************************************************************************
	*[Function]创建数据表;
	*[Parameter]
	-[I]tabName: QString.数据表名;
	-[I]fieldType_ls: QStringList.数据表字段和类型定义;
	*[Return]成功-true, 失败-false,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual bool CreateTable(const QString &tabName, const QStringList &fieldType_ls);

	/************************************************************************
	*[Function]获得数据表字段数量;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]>=0：成功返回数据表数量。-1：查询失败,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual int GetFieldSize(const QString &tabName);

	/************************************************************************
	*[Function]获得数据表中所有字段名;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]返回字段名列表.失败返回空列表,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual QStringList GetFieldNames(const QString &tabName);

	/************************************************************************
	*[Function]获得数据表的所有字段变量类型对应的QVariant类型枚举值;
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]QVariant::type.失败返回空列表,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual QVector<int> GetFieldTypeList(const QString &tabName);

	/************************************************************************
	*[Function]获得数据表中所有字段变量类型(字符表示);
	*[Parameter]
	-[I]tabName: QString.数据表名称;
	*[Return]返回字段名列表.返回空列表表示查询失败,错误信息通过LastError()获取;
	*[Note]字段列表自动跳过默认添加的‘ind’主键列！！！;
	************************************************************************/
	virtual QStringList GetFieldTypeText(const QString &tabName);

	/************************************************************************
	*[Function]创建数据库
	*[Parameter]
	-[I]dbPath: QString.创建数据库路径(包含数据库名称);
	*[Return]成功-true, 失败-false,错误信息通过LastError()获取;
	*[Note]                                                                */
	/************************************************************************/
	virtual bool CreateDB(const QString& dbPath);
};
