#ifndef MEMBERINFO_H
#define MEMBERINFO_H
#include "membersearch.h"

#include <QDialog>
#include <QStandardItemModel>


namespace Ui {
class memberinfo;
}

class memberinfo : public QDialog
{
    Q_OBJECT

public:
    explicit memberinfo(QWidget *parent = nullptr);
    ~memberinfo();

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellActivated(int row, int column);

    void on_tableWidget_cellChanged(int row, int column);

    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_tableWidget_cellEntered(int row, int column);

    void on_tableWidget_cellPressed(int row, int column);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::memberinfo *ui;
    memberSearch *search;
    QStandardItemModel *m_model;

};

#endif // MEMBERINFO_H
