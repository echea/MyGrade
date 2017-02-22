#ifndef PEOPLE_H
#define PEOPLE_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableWidget>
#include "coursedata.h"
#include "management.h"

class people: public QMainWindow
{
    Q_OBJECT

public:
    virtual void setRowData(QTableWidget *tablewidget,int row, QString year,QString semester,
                    QString name, QString mark) = 0;
    virtual void makeTable(QTableWidget *tablewidget) = 0;
    virtual void makeLabel() = 0;
    virtual void searchCourse() = 0;
    virtual void plotCoursedata() = 0;
    ~people();

protected:
    coursedata * cdata;
    management* mg;
};

#endif // PEOPLE_H

