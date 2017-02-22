#include "students.h"
#include "studentslogin.h"
#include "entrance.h"
#include <login.h>
#include <QString>
#include "studentdata.h"
#include <QApplication>
#include "adddata.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login haha;
    haha.exec();

    return a.exec();
}
