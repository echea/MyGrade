#include "teachers.h"
#include "ui_teachers.h"


teachers::teachers(management* mg,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teachers)
{
    ui->setupUi(this);
    this->mg = mg;
    makeLabel();
    makeTable(ui->tableWidget);
    connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(get_row_data(int,int)));
    cdata = NULL;
    studata = NULL;
    setWindowTitle("学生成绩管理系统");
}


teachers::~teachers()
{
    delete ui;
    if(cdata != NULL)
    {
        delete cdata;
        cdata = NULL;
    }
    if(studata != NULL)
    {
        delete studata;
        studata = NULL;
    }
}


void teachers::makeLabel()
{
  qDebug() << "inside makelabel";
  ui->label_name->setText(mg->message().value(0).toString());
  ui->label_prof->setText(mg->message().value(1).toString());
}

void teachers::setRowData(QTableWidget *tablewidget,int row, QString name, QString id, QString year,
                QString semester, QString number){

    tablewidget->setItem(row,0,new QTableWidgetItem(name));
    tablewidget->setItem(row,1,new QTableWidgetItem(id));
    tablewidget->setItem(row,2,new QTableWidgetItem(year));
    tablewidget->setItem(row,3,new QTableWidgetItem(semester));
    tablewidget->setItem(row,4,new QTableWidgetItem(number));
    tablewidget->setColumnWidth(0,153);
    tablewidget->setColumnWidth(1,50);
    tablewidget->setColumnWidth(2,50);
    tablewidget->setColumnWidth(3,50);
    tablewidget->setColumnWidth(4,50);
    for(int i=0;i<=4;i++)
    tablewidget->item(row, i)->setTextAlignment(Qt::AlignCenter);
}


void teachers::makeTable(QTableWidget *tablewidget){
    int i=0;
    tablewidget->setColumnCount(5); // 设置表格控件列大小
    tablewidget->setRowCount(0); // 设置表格控件行的大小
    QStringList strList;
    strList << tr("课程名称") << tr("课程号") << tr("学年") << tr("学期") << tr("上课人数");
    tablewidget->setHorizontalHeaderLabels(strList); // 设置表格控件，列表头内容
    qDebug() << "inside make table";
    QSqlQuery query = mg->courses();
    qDebug() << "inside make table";
    tablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tablewidget->setAlternatingRowColors(1);
    while(query.next()){
      tablewidget->insertRow(i); // 设置表格控件行的数量
       setRowData(tablewidget,i, query.value(0).toString(),query.value(1).toString(), query.value(2).toString(), query.value(3).toString(),query.value(4).toString());
       i++;

    };
}

void teachers::plotCoursedata(QStringList course)
{
    QStringList numbers = mg->courseMarks(course).split(",");
    qDebug() << numbers;
    qDebug() << "inside get row >> plot data";
    cdata = new coursedata(course[2], numbers);
    cdata->show();
}


void teachers::get_row_data(int row,int column){
    QStringList strList;
    strList<<ui->tableWidget->item(row,2)->text();
    strList<<ui->tableWidget->item(row,3)->text();
    strList<<ui->tableWidget->item(row,0)->text();
    studata=new studentdata(mg, strList);
//    plotCoursedata(strList);
    qDebug() << "inside get row";
}

void teachers::on_quit_button_clicked()
{
    this->close();
    logout();
}
