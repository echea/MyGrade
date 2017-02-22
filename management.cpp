#include "management.h"

int management::login()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/linshenbo/Documents/QT/education/qtstudent.db");
    if(!db.open()){
        qDebug() << "connect fail";
        return 0;
    }
    else{
        qDebug() << "connect success";
        QSqlQuery query;
        if(id.size() == 10)
        {
            query.exec("SELECT code FROM student WHERE studentId = \"" + id + "\"");
            query.first();
            return code == query.value(0).toString();
        }
        else if(id.size() == 5)
        {
            query.exec("SELECT code FROM teacher WHERE teacherId = \"" + id + "\"");
            query.first();
            return code == query.value(0).toString();
        }
        return 0;
    }
}

QString management::courseMarks(QStringList course)
{
    QSqlQuery query;
    QString re = "";
    QString qe = "SELECT count(studentId) FROM record NATURAL JOIN course WHERE courseName = \"" + course[2] + "\" AND year = " + course[0] + " AND semester = \"" + course[1] + "\" ";
    qDebug() << qe+"AND mark < 60";
    query.exec(qe + "AND mark < 60");
    query.first();
    re += query.value(0).toString() + ",";
    query.exec(qe + "AND mark < 69 AND mark >= 60");
    query.first();
    re += query.value(0).toString() + ",";
    query.exec(qe + "AND mark < 79 AND mark >= 70");
    query.first();
    re += query.value(0).toString() + ",";
    query.exec(qe + "AND mark < 89 AND mark >=80");
    query.first();
    re += query.value(0).toString() + ",";
    query.exec(qe + "AND mark >=90");
    query.first();
    re += query.value(0).toString() + ",";

    qe = "SELECT avg(mark) FROM record NATURAL JOIN course WHERE courseName = \"" + course[2] + "\" AND year = " + course[0] + " AND semester = \"" + course[1] + "\" ";
    query.exec(qe);
    query.first();
    re += query.value(0).toString() + ",";

    qe = "SELECT count(studentId) FROM record NATURAL JOIN course WHERE courseName = \"" + course[2] + "\" AND year = " + course[0] + " AND semester = \"" + course[1] + "\" ";
    query.exec(qe);
    query.first();
    int count = query.value(0).toInt();
    count = count/2 - 1;
    qe = "SELECT mark FROM record NATURAL JOIN course WHERE courseName = \"" + course[2] + "\" AND year = " + course[0] + " AND semester = \"" + course[1] + "\" ";
    if(count % 2 != 0)
    {
        qe += "ORDER BY mark LIMIT " + QString::number(count) + ",1";
        query.exec(qe);
        query.first();
        re += query.value(0).toString();
    }
    else
    {
        qe += "ORDER BY mark LIMIT " + QString::number(count) + ",2";
        query.exec(qe);
        int median = 0;
        while(query.next())
        {
            median += query.value(0).toInt();
        }
        median /= 2;
        re += QString::number(median);
    }


    return re;
}

studentManagement::studentManagement(QString id, QString code)
{
    this->id = id;
    this->code = code;
}

QSqlQuery studentManagement::message()
{
    QSqlQuery query;
    query.exec("SELECT studentName, majorName, grade, degreeName FROM student NATURAL JOIN major NATURAL JOIN degree WHERE studentId = \""+id+"\"");
    query.first();
    return query;
}

int studentManagement::rank()
{
    QSqlQuery query;
    query.exec("SELECT studentId, avg(mark) AS avg_m FROM student NATURAL JOIN record WHERE majorId = \(select majorId FROM student WHERE studentId = \""+id+"\"\) GROUP BY studentId ORDER BY avg_m");
    int rank = 0;
//    qDebug() << "SELECT studentId, avg(mark) AS avg_m FROM student NATURAL JOIN record WHERE majorId = \(select majorId FROM student WHERE studentId = \""+id+"\"\) GROUP BY studentId ORDER BY avg_m";
    while(query.next()){
        rank++;
        if(query.value(0).toString() == id)
        {
            return rank;
        }
    }
}

double studentManagement::GPA()
{
    QSqlQuery query;
    query.exec("SELECT avg(mark) FROM student NATURAL JOIN record WHERE studentId = \""+id+"\"");
//    qDebug() << "SELECT avg(mark) FROM student NATURAL JOIN record WHERE studentId = \""+id+"\"";
    query.first();
    return query.value(0).toDouble();
}

QSqlQuery studentManagement::courses()
{
    QSqlQuery query;
    query.exec("SELECT courseName, courseId, year, semester, mark FROM record NATURAL JOIN course WHERE studentId = \""+id+"\" ORDER BY year,semester");
    return query;
}

teacherManagement::teacherManagement(QString id, QString code)
{
    this->id = id;
    this->code = code;
}

QSqlQuery teacherManagement::courses()
{
    QSqlQuery query;
    query.exec("SELECT courseName, courseId, year, semester, count(DISTINCT studentId) FROM record NATURAL JOIN course NATURAL JOIN student WHERE teacherId = \"" + id + "\" GROUP BY courseId ORDER BY courseName, year");
    return query;
}

QSqlQuery teacherManagement::message()
{
    QSqlQuery query;
    query.exec("SELECT teacherName, departmentName FROM teacher NATURAL JOIN department WHERE teacherId = \""+id+"\"");
    query.first();
    return query;
}

int teacherManagement::update(QString mark, QString studentId, QString courseId, QString year, QString semester)
{
    QSqlQuery query;
    query.exec("UPDATE record SET mark = " + mark + " WHERE studentId = \"" + studentId +"\" AND teacherId = \"" + id +"\" AND courseId = " + courseId +" AND semester = \"" + semester +"\" AND year = "+year);
    qDebug() << "update success";
}

int teacherManagement::insert(QString studentName, QString studentId, QString mark, QString courseName, QString year, QString semester)
{
    QSqlQuery query;
    query.exec("SELECT studentName FROM student WHERE studentId = " + studentId);
    qDebug() << "SELECT studentName FROM student WHERE studentId = " + studentId;
    query.first();
    if(query.value(0).toString() != studentName)
    {
        return 0;
    }
    qDebug() << "inside insert";
    query.exec("SELECT courseId FROM course WHERE courseName = \"" + courseName + "\"");
    qDebug() << "inside insert";
    query.first();
    QString courseId = query.value(0).toString();
    qDebug() << "inside insert";
    qDebug() << "INSERT INTO RECORD VALUES(\"" + studentId + "\"," + courseId + ",\"" + getId() + "\"," + mark + ",\"" + semester + "\"," + year + ")";
    query.exec("INSERT INTO record VALUES(\"" + studentId + "\"," + courseId + ",\"" + getId() + "\"," + mark + ",\"" + semester + "\"," + year + ")");
    qDebug() << "inside insert end";
    query.exec("SELECT * FROM record WHERE studentId = 3120100009");
    query.first();
    qDebug() << query.value(0).toString();

}

int teacherManagement::deleteRecord(QString studentId, QString courseId, QString year, QString semester)
{
    QSqlQuery query;
    query.exec("DELETE FROM record WHERE studentId = \"" + studentId +"\" AND teacherId = \"" + id +"\" AND courseId = " + courseId +" AND semester = \"" + semester +"\" AND year = "+year);
    qDebug() << "update success";
}

QSqlQuery teacherManagement::students(QStringList str)
{
    QSqlQuery query;
    query.exec("SELECT studentName, mark FROM record NATURAL JOIN student NATURAL JOIN course WHERE teacherId = " + id + " AND courseName = \"" + str[2] + "\" AND semester = \"" + str[1] + "\" AND year = " + str[0]);
    return query;
}
