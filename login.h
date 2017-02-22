#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "students.h"
#include "teachers.h"
#include "management.h"
#include <QApplication>


namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

public slots:
    /*
     * @brief 注销，删除人员登录信息等数据
     * @param 无
     * @return 无
     */
    void relogin();

private slots:
    /*
     * @brief 登陆管理系统
     * @param 无
     * @return 无
     * @exception 若输入有误或用户名密码错误弹出警告窗口
     */
    void on_TLoginButton_clicked();

    /*
     * @brief 退出程序
     * @param 无
     * @return 无
     */
    void on_TBackButton_clicked();



private:

    Ui::login *ui;
    management*mng;
    students*std;
    teachers* tch;

};

#endif // LOGIN_H
