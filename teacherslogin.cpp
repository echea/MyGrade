#include "teacherslogin.h"
#include "entrance.h"
#include "ui_teacherslogin.h"
#include <QDebug>

TeachersLogin::TeachersLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeachersLogin)
{
    ui->setupUi(this);


    tch = new teachers() ;


}

TeachersLogin::~TeachersLogin()
{
    delete ui;
}

void TeachersLogin::on_TLoginButton_clicked()
{

    QString account = ui->TLineEdit->text();
    QString code = ui->TPLineEdit->text();
    qDebug() << account;
    qDebug() << code;
    mng = new studentManagement(account, code);
    if(mng->login() == 1)
    {
        std = new students(mng);
        std->show();
        this->close();
        std->plotCoursedata();
    }
    else
    {
        QMessageBox::warning(this,tr("warning"),tr("用户名或密码错误"),QMessageBox::Yes);
    }
}

void TeachersLogin::on_TBackButton_clicked()
{
    this->close();
    Entrance *Entran=new Entrance;
    Entran->show();
}
