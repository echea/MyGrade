#include "login.h"
#include "ui_login.h"
#include <QDebug>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("成绩管理系统");
    std = NULL;
    tch = NULL;
    mng = NULL;
}

login::~login()
{
    delete ui;
    if(std != NULL)
    {
        delete std;
        delete (studentManagement*)mng;
    }
    if(tch != NULL)
    {
        delete tch;
        delete (teacherManagement*)mng;
    }
}

void login::on_TLoginButton_clicked()
{
    QString account = ui->TLineEdit->text();
    QString code = ui->TPLineEdit->text();
    qDebug() << account;
    qDebug() << code;
    if(account.size() == 10)
    {
        if(mng != NULL)
        {
            delete mng;
        }
        mng = new studentManagement(account, code);
    }
    else
    {
        mng = new teacherManagement(account, code);
    }

    if(mng->login() == 1 && account.size() == 10)
    {
        std = new students(mng);
        std->show();
        connect(std, SIGNAL(logout()), this, SLOT(relogin()));
        this->close();
    }
    else if(mng->login() == 1 && account.size() == 5)
    {
        tch = new teachers(mng);
        tch->show();
        connect(tch, SIGNAL(logout()), this, SLOT(relogin()));
        this->close();
    }
    else{
        ui->TLineEdit->clear();
        ui->TPLineEdit->clear();
        QMessageBox::warning(this,tr("warning"),tr("用户名或密码错误"),QMessageBox::Yes);
    }
}


void login::on_TBackButton_clicked()
{
    close();

}

void login::relogin()
{
    if(std != NULL)
    {
        delete std;
        std = NULL;
    }
    if(tch != NULL)
    {
        delete tch;
        tch = NULL;
    }
    ui->TLineEdit->clear();
    ui->TPLineEdit->clear();
    this->show();
}
