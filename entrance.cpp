#include "entrance.h"
#include "studentslogin.h"
#include "teacherslogin.h"
#include "ui_entrance.h"

Entrance::Entrance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entrance)
{
    ui->setupUi(this);
}

Entrance::~Entrance()
{
    delete ui;
}

void Entrance::on_pushButton_2_clicked()
{
    this->close();
    StudentsLogin *StuLogin = new StudentsLogin;
    StuLogin->show();
}

void Entrance::on_pushButton_3_clicked()
{
    this->close();
    TeachersLogin *TeaLogin = new TeachersLogin;
    TeaLogin->show();
}
