#ifndef TEACHERS_H
#define TEACHERS_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableWidget>
#include "coursedata.h"
#include "management.h"
#include "studentdata.h"

namespace Ui {
class teachers;
}

class teachers : public QMainWindow
{
    Q_OBJECT

public:
    explicit teachers(management* mg,QWidget *parent = 0);

    /*
     * @brief 设置老师教过的课程信息
     * @param 行数，老师id，课程名，上课年份，学期，上课学生数量
     * @return 无
     */
    void setRowData(QTableWidget *tablewidget,int row, QString ID,QString coursename,QString year,QString semester,
         QString number_student);

    /*
     * @brief 作表
     * @param 无
     * @return 无
     */
    void makeTable(QTableWidget *tablewidget);

    /*
     * @brief 显示老师个人信息
     * @param 无
     * @return 无
     */
    void makeLabel();

    /*
     * @brief 作图，弹出课程成绩分布直方图窗口
     * @param 课程信息，以逗号分隔
     * @return 无
     */
    void plotCoursedata(QStringList course);
    ~teachers();

private slots:
    /*
     * @brief 表格中一行所有信息
     * @param 表格行，列数
     * @return 无
     */
    void get_row_data(int row,int column);

    /*
     * @brief 注销当前账户信息
     * @param 无
     * @return 无
     * @exception 返回登陆页面
     */
    void on_quit_button_clicked();

private:
    Ui::teachers *ui;
    coursedata * cdata;
    management* mg;
    studentdata* studata;

signals:
    void logout();
};

#endif // TEACHERS_H
