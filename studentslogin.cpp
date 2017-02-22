#include "studentslogin.h"
#include "entrance.h"
#include "students.h"
#include "management.h"
#include "ui_studentslogin.h"
#include <QDebug>

StudentsLogin::StudentsLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentsLogin)
{
    ui->setupUi(this);


}

StudentsLogin::~StudentsLogin()
{
    delete ui;
}



void StudentsLogin::on_SBackButton_clicked()
{
      this->close();
      Entrance *Entran= new Entrance();
      Entran->show();
}

void StudentsLogin::on_SLoginButton_clicked()
{  
    qDebug() << "a"+ui->SLineEdit->text()+ui->SPLineEdit->text();
    account = ui->SLineEdit->text();
    code = ui->SPLineEdit->text();
    emit loginclick(true);
}

QStringList StudentsLogin::accountInfo()
{
    QStringList q;
    q<<account<<code;
    return q;
}

