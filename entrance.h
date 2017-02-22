#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <QDialog>

namespace Ui {
class Entrance;
}

class Entrance : public QDialog
{
    Q_OBJECT

public:
    explicit Entrance(QWidget *parent = 0);
    ~Entrance();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Entrance *ui;
};

#endif // ENTRANCE_H
