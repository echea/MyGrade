#ifndef STUDENTSLOGIN_H
#define STUDENTSLOGIN_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class StudentsLogin;
}

class StudentsLogin : public QDialog
{
    Q_OBJECT

public:
    explicit StudentsLogin(QWidget *parent = 0);
    ~StudentsLogin();
    QStringList accountInfo();

private slots:
    void on_SBackButton_clicked();
    void on_SLoginButton_clicked();
    void hahaha(){
        qDebug() << "hahahahahaha";
    }

signals:
    void loginclick(int judge);

private:
    Ui::StudentsLogin *ui;
    QString account;
    QString code;

};

#endif // STUDENTSLOGIN_H
