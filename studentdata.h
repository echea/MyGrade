#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include <QDialog>
#include "amend.h"
#include "coursedata.h"
#include "management.h"
#include "adddata.h"
namespace Ui {
class studentdata;
}

class studentdata : public QDialog
{
    Q_OBJECT

public:
    explicit studentdata(management*mg, QStringList str,QWidget *parent = 0);

    /*
     * @brief 设置学生姓名和成绩在某一行
     * @param 行数，姓名，成绩
     * @return 无
     */
    void setRowData(int row, QString name, QString mark);

    /*
     * @brief 做出某一课程成绩分布直方图
     * @param 课程信息
     * @return 无
     */
    void plotCoursedata(QStringList course);

    /*
     * @brief 作表，展示学生所有课程成绩信息
     * @param 学生信息
     * @return 无
     */
    void makeTable(QStringList str);
    ~studentdata();

private slots:
    /*
     * @brief 获取选中学生信息，调用修改成绩窗口
     * @param 选中行，列
     * @return 无
     * @exception 弹出修改成绩窗口
     */
    void get_row_data(int row,int column);

    /*
     * @brief 弹出课程成绩分布直方图信息
     * @param 无
     * @return 无
     * @exception 弹出课程成绩分布直方图信息
     */
    void on_pushButton_detail_clicked();

    /*
     * @brief 弹出添加成绩记录窗口
     * @param 无
     * @return 无
     * @exception 弹出添加成绩记录窗口
     */

    void on_pushButton_add_clicked();

    /*
     * @brief 修改、删除或添加成绩后刷新表格信息
     * @param 无
     * @return 无
     */
    void renew();




private:
    amend* amd;
    coursedata * cdata;
    management* mng;
    adddata * add;
    QStringList title;
    Ui::studentdata *ui;
};

#endif // STUDENTDATA_H
