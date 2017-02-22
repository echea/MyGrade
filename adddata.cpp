#include "adddata.h"
#include "ui_adddata.h"
#include "QMessageBox"
#include "QDebug"

adddata::adddata(management*mng, QString course, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddata)
{
    ui->setupUi(this);
    this->mng=mng;
    setWindowTitle("添加学生成绩,"+course);
}

adddata::~adddata()
{
    delete ui;
}


void adddata::on_pushButton_back_clicked()
{
        close();
}

void adddata::on_pushButton_add_clicked()
{
    QStringList newstudent;
    QStringList course = this->windowTitle().split(",");
    qDebug() << "inside add data";
    qDebug() << course;
    if(ui->lineEdit_mark->text().toInt()<=100&ui->lineEdit_mark->text().toInt()>=0){
        newstudent<<ui->lineEdit_name->text()<<ui->lineEdit_number->text()<<ui->lineEdit_mark->text();
        qDebug() << newstudent;
        ((teacherManagement*)mng)->insert(newstudent[0], newstudent[1], newstudent[2], course[3], course[1], course[2]);
        renew();
        close();
    }
    else{
        QMessageBox::warning(this,tr("warning"),tr("错误的成绩输入"),QMessageBox::Yes);

    };
}
