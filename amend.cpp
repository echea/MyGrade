#include "amend.h"
#include "ui_amend.h"
#include <qmessagebox.h>

amend::amend(management* mng, QString str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::amend)
{
    ui->setupUi(this);
    this->mng = mng;
    this->message = str.split(",");
    setWindowTitle("修改" + message[3] + "的成绩");
}

amend::~amend()
{
    delete ui;
}


void amend::on_pushButton_cancel_clicked()
{
    QSqlQuery query;
    query.exec("SELECT studentId FROM student WHERE studentName = \""+message[3] +"\"");
    query.first();
    QString studentId = query.value(0).toString();

    query.exec("SELECT courseId FROM course WHERE courseName = \""+message[2] +"\"");
    query.first();
    QString courseId = query.value(0).toString();

    ((teacherManagement*)mng)->deleteRecord(studentId, courseId, message[0], message[1]);
    close();
    renew();
   QMessageBox::about(NULL, "Success", "删除成功");
}

void amend::on_pushButton_yes_clicked()
{
    if(ui->lineEdit->text().toInt()<=100&&ui->lineEdit->text().toInt()>=0){

        QSqlQuery query;
        query.exec("SELECT studentId FROM student WHERE studentName = \""+message[3] +"\"");
        query.first();
        QString studentId = query.value(0).toString();

        query.exec("SELECT courseId FROM course WHERE courseName = \""+message[2] +"\"");
        query.first();
        QString courseId = query.value(0).toString();
        ((teacherManagement*)mng)->update(ui->lineEdit->text(),studentId, courseId, message[0], message[1]);
        emit (renew());
        close();
    }
    else{
        QMessageBox::warning(this,tr("warning"),tr("错误的成绩输入"),QMessageBox::Yes);

    }

}

void amend::on_pushButton_back_clicked()
{
    close();

}
