#ifndef AMEND_H
#define AMEND_H

#include <QDialog>
#include <QSqlDatabase>
#include "management.h"

namespace Ui {
class amend;
}

class amend : public QDialog
{
    Q_OBJECT

public:
    explicit amend(management* mng, QString str, QWidget *parent = 0);
    ~amend();

private slots:
    /*
     * @brief 退出修改成绩界面
     * @param 无
     * @return 无
     */
    void on_pushButton_back_clicked();

    /*
     * @brief 确认修改成绩
     * @param 无
     * @return 无
     * @exception 若输入有误或修改失败弹出警告窗口
     */
    void on_pushButton_yes_clicked();

    /*
     * @brief 删除该学生成绩
     * @param 无
     * @return 无
     * @exception 删除成功弹出窗口
     */
    void on_pushButton_cancel_clicked();

signals:
    void renew();

private:
    Ui::amend *ui;
    management* mng;
    QStringList message;
};

#endif // AMEND_H
