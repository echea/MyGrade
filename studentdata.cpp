#include "studentdata.h"
#include "ui_studentdata.h"
#include <QDebug>

studentdata::studentdata(management*mng, QStringList str,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentdata)
{
    ui->setupUi(this);
    setWindowTitle(str[0]+","+str[1]+","+str[2]);
    this->mng = mng;
    title=str;
    makeTable(str);
    connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(get_row_data(int,int)));
    this->show();
    cdata = NULL;
    add = NULL;
    amd = NULL;

}

studentdata::~studentdata()
{
    delete ui;
    if(cdata != NULL)
    {
        delete cdata;
        cdata != NULL;
    }
    if(add != NULL)
    {
        delete add;
        add != NULL;
    }
    if(amd != NULL)
    {
        delete amd;
    }
}

void studentdata::makeTable(QStringList str){
    int i=0;
    ui->tableWidget->setColumnCount(3); // 设置表格控件列大小
    ui->tableWidget->setRowCount(0); // 设置表格控件行的大小
    QStringList strList;
    strList << tr("学生姓名") << tr("成绩") << tr("绩点") ;
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setHorizontalHeaderLabels(strList); // 设置表格控件，列表头内容
    QSqlQuery query = ((teacherManagement*)mng)->students(str);
    ui->tableWidget->setAlternatingRowColors(1);
    while(query.next()){
      ui->tableWidget->insertRow(i); // 设置表格控件行的数量
       setRowData(i,query.value(0).toString(),query.value(1).toString());
       i++;

    };
    qDebug() << "inside studentdata maketable";
}

void studentdata::setRowData(int row, QString name, QString mark){

    ui->tableWidget->setItem(row,0,new QTableWidgetItem(name));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(mark));
    QString GPA;
    if (mark.toInt()>=95){GPA.setNum(5.0);}
    else if (mark.toInt()<60){GPA.setNum(0);}
    else {  GPA.setNum(1.5+(mark.toInt()-60)*0.1);};
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(GPA));
    ui->tableWidget->setColumnWidth(0,75);
    ui->tableWidget->setColumnWidth(1,74);
    ui->tableWidget->setColumnWidth(2,74);
    for(int i=0;i<=2;i++)
    ui->tableWidget->item(row, i)->setTextAlignment(Qt::AlignCenter);

}

void studentdata::get_row_data(int row,int column){
    QString str = this->windowTitle() + ",";
    str += ui->tableWidget->item(row,0)->text();
    amd=new amend(mng, str);
    connect(amd,SIGNAL(renew()),this,SLOT(renew()));
    amd->exec();
}

void studentdata::plotCoursedata(QStringList course)
{
    QStringList numbers = mng->courseMarks(course).split(",");
    qDebug() << numbers;
    cdata = new coursedata(course[2], numbers);
    cdata->show();
}


void studentdata::renew(){
    makeTable(title);
}

void studentdata::on_pushButton_detail_clicked()
{
    QStringList course = this->windowTitle().split(",");
    plotCoursedata(course);

}

void studentdata::on_pushButton_add_clicked()
{
    add=new adddata(this->mng, this->windowTitle());
    connect(add,SIGNAL(renew()),this,SLOT(renew()));
    add->show();
}
