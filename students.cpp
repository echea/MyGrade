#include "students.h"
#include "ui_students.h"
#include "qcustomplot.h"
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlDatabase>

students::students(management* mg, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::students)
{


    ui->setupUi(this);
    this->mg = mg;
    makeLabel();
    makeTable(ui->tableWidget);
    connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(get_row_data(int,int)));
    cdata = NULL;
    setWindowTitle("学生成绩管理系统");
}

students::~students()
{
    delete ui;
    if(cdata != NULL)
    {
        delete cdata;
        cdata = NULL;
    }
}

void students::makeLabel()
{
  qDebug() << "inside makelabel";
  ui->label_name->setText(mg->message().value(0).toString());
  ui->label_grade->setText(mg->message().value(3).toString()+mg->message().value(2).toString()+"年级");
  ui->label_prof->setText(mg->message().value(1).toString());
}

void students::setRowData(QTableWidget *tablewidget,int row, QString year,QString semester,
                QString name, QString mark){


    tablewidget->setItem(row,0,new QTableWidgetItem(year));
    tablewidget->setItem(row,1,new QTableWidgetItem(semester));
    tablewidget->setItem(row,2,new QTableWidgetItem(name));
    tablewidget->setItem(row,3,new QTableWidgetItem(mark));
    QString GPA;
    if (mark.toInt()>=95){GPA.setNum(5.0);}
    else if (mark.toInt()<60){GPA.setNum(0);}
    else {  GPA.setNum(1.5+(mark.toInt()-60)*0.1);};
    tablewidget->setItem(row,4,new QTableWidgetItem(GPA));
    tablewidget->setColumnWidth(0,51);
    tablewidget->setColumnWidth(1,45);
    tablewidget->setColumnWidth(2,155);
    tablewidget->setColumnWidth(3,51);
    tablewidget->setColumnWidth(4,51);
    for(int i=0;i<=4;i++)
    tablewidget->item(row, i)->setTextAlignment(Qt::AlignCenter);


}

void students::makeTable(QTableWidget *tablewidget){
    int i=0;
    tablewidget->setColumnCount(5); // 设置表格控件列大小
    tablewidget->setRowCount(0); // 设置表格控件行的大小
    QStringList strList;
    strList << tr("学年") << tr("学期") << tr("课程名称") << tr("成绩") << tr("绩点") ;
    tablewidget->setHorizontalHeaderLabels(strList); // 设置表格控件，列表头内容
    QSqlQuery query = mg->courses();
    tablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tablewidget->setAlternatingRowColors(1);
    while(query.next()){
      tablewidget->insertRow(i); // 设置表格控件行的数量
       setRowData(tablewidget,i, query.value(2).toString(),query.value(3).toString(), query.value(0).toString(),query.value(4).toString());
       i++;

    };
}

void students::plotCoursedata(QStringList course)
{
    QStringList numbers = mg->courseMarks(course).split(",");
    qDebug() << numbers;
    cdata = new coursedata(course[2], numbers);
    cdata->show();
}


void students::get_row_data(int row,int column){
    QStringList strList;
    strList<<ui->tableWidget->item(row,0)->text();
    strList<<ui->tableWidget->item(row,1)->text();
    strList<<ui->tableWidget->item(row,2)->text();
    qDebug()<<strList;
    plotCoursedata(strList);
}


void students::on_quit_button_clicked()
{
    this->close();
    logout();
}

