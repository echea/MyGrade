#ifndef TEACHERSLOGIN_H
#define TEACHERSLOGIN_H

#include <QDialog>
#include "students.h"
#include "teachers.h"

#include "management.h"

namespace Ui {
class TeachersLogin;
}

class TeachersLogin : public QDialog
{
    Q_OBJECT

public:
    explicit TeachersLogin(QWidget *parent = 0);
    ~TeachersLogin();


private slots:
    void on_TLoginButton_clicked();

    void on_TBackButton_clicked();

private:
    Ui::TeachersLogin *ui;
    management*mng;
    students*std;
    teachers*tch;

};

#endif // TEACHERSLOGIN_H
