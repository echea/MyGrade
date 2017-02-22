#ifndef ADDDATA_H
#define ADDDATA_H

#include <QDialog>
#include "management.h"

namespace Ui {
class adddata;
}

class adddata : public QDialog
{
    Q_OBJECT

public:
    explicit adddata(management*mng,QString course, QWidget *parent = 0);
    ~adddata();

private slots:
    /*
     * @brief 退出添加成绩界面
     * @param 无
     * @return 无
     */
    void on_pushButton_back_clicked();
    /*
     * @brief 确认添加成绩
     * @param 无
     * @return 无
     * @exception 若输入有误或添加失败弹出警告窗口
     */

    void on_pushButton_add_clicked();

signals:
    void renew();

private:
    management *mng;
    Ui::adddata *ui;
};

#endif // ADDDATA_H
