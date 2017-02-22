#ifndef MANAGEMENT
#define MANAGEMENT

#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>

class management
{
public:
    /*
     * @brief 连接数据库，确认用户名密码匹配
     * @param 无
     * @return 匹配返回1，不匹配返回0
     */
    int login();

    virtual QSqlQuery courses() = 0;

    /*
     * @brief 获取某一科目各分数段人数
     * @param 该科目信息
     * @return 各分数段人数字符串，以都好分隔
     */
    QString courseMarks(QStringList course);

    virtual QSqlQuery message() = 0;

    /*
     * @brief 获取已登录人员id
     * @param 无
     * @return 返回id
     */
    QString getId()
    {
        return id;
    }

protected:
    QSqlDatabase db;
    QString id;
    QString code;
};

class studentManagement : public management
{
public:
    studentManagement(QString id, QString code);
    /*
     * @brief 获取学生上过的所有课程信息
     * @param 无
     * @return 返回数据库查询结果
     */
    virtual QSqlQuery courses();

    /*
     * @brief 获取学生个人信息
     * @param 无
     * @return 返回数据库查询结果
     */
    virtual QSqlQuery message();

    /*
     * @brief 获取学生排名
     * @param 无
     * @return 返回学生排名
     */
    int rank();

    /*
     * @brief 获取学生均绩
     * @param 无
     * @return 返回学生均绩
     */
    double GPA();

};

class teacherManagement : public management
{
public:
    teacherManagement(QString id, QString code);

    /*
     * @brief 获取该老师教授过的所有课程信息
     * @param 无
     * @return 数据库查询结果
     */
    virtual QSqlQuery courses();

    /*
     * @brief 获取老师个人信息
     * @param 无
     * @return 数据库查询结果
     */
    virtual QSqlQuery message();

    /*
     * @brief 更新某学生成绩记录
     * @param 成绩，学生id，课程id，开课年份，开课学期
     * @return 更新成狗返回1，否则返回0
     */
    int update(QString mark, QString studentId, QString courseId, QString year, QString semester);

    /*
     * @brief 新增学生成绩记录
     * @param 学生姓名，学号，成绩，课程名，开课年份，开课学期
     * @return 更新成功返回1，否则返回0
     */
    int insert(QString studentName, QString studentId, QString mark, QString courseName, QString year, QString semester);

    /*
     * @brief 删除学生成绩记录
     * @param 学生id， 课程id， 开课年份， 开课学期
     * @return 更新成功返回1，否则返回0
     */
    int deleteRecord(QString studentId, QString courseId, QString year, QString semester);

    /*
     * @brief 获取该老师教授某门课程的全部学生信息
     * @param 课程信息，老师信息，以逗号分隔组成字符串
     * @return 数据库查询结果
     */
    QSqlQuery students(QStringList str);
};

#endif // MANAGEMENT

