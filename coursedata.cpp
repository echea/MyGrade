#include "coursedata.h"
#include "ui_coursedata.h"
#include "QTableWidget"

coursedata::coursedata(QString course, QStringList numbers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::coursedata)
{
    ui->setupUi(this);
    init_ui(numbers[0].toInt(), numbers[1].toInt(), numbers[2].toInt(), numbers[3].toInt(), numbers[4].toInt());
    setRowData(numbers[5],numbers[6]);
    bars = NULL;
    setWindowTitle("统计数据");

}

coursedata::~coursedata()
{
    delete ui;
    if(bars != NULL)
    {
        delete bars;
    }
}


void coursedata::init_ui(int A,int B,int C, int D, int E)
{
    QVector<QString> labels(5);
    QVector<double> values(5);

    labels[0] = QString("<60");
    labels[1] = QString("60~69");
    labels[2] = QString("70~79");
    labels[3] = QString("80~89");
    labels[4] = QString("90~100");
    values[0] = A;
    values[1] = B;
    values[2] = C;
    values[3] = D;
    values[4] = E;
    bars=new QCPBars(this->ui->widget->xAxis,this->ui->widget->yAxis);
    bars->setWidth(0.5);
        QVector<double> index(5);
        for(int i=0;i<5;++i)
            index[i]=i;
        bars->setData(index,values);
    qDebug() << "init ui";
    this->ui->widget->xAxis->setAutoTicks(false);
    this->ui->widget->xAxis->setAutoTickLabels(false);
    this->ui->widget->xAxis->setAutoTickStep(false);
    this->ui->widget->yAxis->setAutoTickStep(false);
    this->ui->widget->yAxis->setTickStep(1);

    this->ui->widget->addPlottable(bars);
    this->ui->widget->rescaleAxes();
    double wid=this->ui->widget->xAxis->range().upper-this->ui->widget->xAxis->range().lower;
    double cl=bars->width()+(1.0*wid-bars->width()*5)/4;
    QVector<double> coor;
    for(int i=0;i<5;++i)
        coor.append(this->ui->widget->xAxis->range().lower+i*cl+bars->width()/2);
    this->ui->widget->xAxis->setTickVector(coor);
    this->ui->widget->xAxis->setTickVectorLabels(labels);
    this->ui->widget->replot();
}

void coursedata::setRowData(QString mean,QString middle){

    ui->tableWidget->setColumnCount(2); // 设置表格控件列大小
    ui->tableWidget->setRowCount(1); // 设置表格控件行的大小
    ui->tableWidget->resizeColumnToContents(120);
    QStringList strList;
    strList << tr("平均分") << tr("中位数");
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setHorizontalHeaderLabels(strList); // 设置表格控件，列表头内容

    ui->tableWidget->setItem(0,0,new QTableWidgetItem(mean));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(middle));
    ui->tableWidget->setColumnWidth(0,75);
    ui->tableWidget->setColumnWidth(1,74);
    ui->tableWidget->item(0, 0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->item(0, 1)->setTextAlignment(Qt::AlignCenter);


}
