#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT
signals:
    void siglogincheck(const QString &username, const QString &password);
public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
