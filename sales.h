#ifndef SALES_H
#define SALES_H

#include <QDialog>
#include <QWidget>
#include <string>
#include "itemrevenue.h"

namespace Ui {
class sales;
}

class sales : public QDialog
{
    Q_OBJECT

public:
    explicit sales(QWidget *parent = nullptr);
    ~sales();
//<<<<<<< HEAD
    void on_pushButton_clicked();
    void on_lineEdit_3_editingFinished();
    void on_lineEdit_2_editingFinished();
    void on_lineEdit_editingFinished();
    void on_pushButton_3_clicked();
//=======

private slots:
//    void on_lineEdit_editingFinished();

//    void on_lineEdit_2_editingFinished();

//    void on_lineEdit_3_editingFinished();

//    void on_pushButton_clicked();

//    void on_pushButton_3_clicked();

//>>>>>>> c97b26aa3f0764c3f64feee9a9403079be73f751
private:
    Ui::sales *ui;
    itemRevenue *rev;
};

#endif // SALES_H
