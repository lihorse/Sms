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
    void siglogincheck(const QString &username, const QString &password,const int &level);
public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void loginInputClear();
private slots:

    void on_btn_log_clicked();

    void on_btn_clr_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
