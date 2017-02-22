#ifndef COURSEDATA_H
#define COURSEDATA_H

#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class coursedata;
}

class coursedata : public QDialog
{
    Q_OBJECT

public:
    explicit coursedata(QString course, QStringList numbers, QWidget *parent = 0);

    /*
     * @brief 设置成绩平均数，中位数数据
     * @param 平均数，中位数字符串
     * @return 无
     */
    void setRowData(QString mean,QString middle);

    /*
     * @brief 设置各分数段人数数据
     * @param 各分数段人数整型变量
     * @return 无
     */
    void init_ui(int A,int B,int C, int D, int E);

    ~coursedata();

private:
    Ui::coursedata *ui;
    QCPBars* bars;
};

#endif // COURSEDATA_H
