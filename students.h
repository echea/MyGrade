#ifndef STUDENTS_H
#define STUDENTS_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableWidget>
#include "coursedata.h"
#include "management.h"

namespace Ui {
class students;
}

class students : public QMainWindow
{
    Q_OBJECT

public:
    explicit students(management* mg, QWidget *parent = 0);
    /*
     * @brief 设置学生课程信息
     * @param 行数，上课年份，学期，课程名，成绩
     * @return 无
     */
    void setRowData(QTableWidget *tablewidget,int row, QString year,QString semester,
                    QString name, QString mark);

    /*
     * @brief 作表
     * @param 无
     * @return 无
     */
    void makeTable(QTableWidget *tablewidget);

    /*
     * @brief 显示学生个人信息
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
    ~students();

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
    coursedata * cdata;
    Ui::students *ui;
    management* mg;

signals:
    void logout();

};

#endif // STUDENTS_H
