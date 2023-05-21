#ifndef SALES_H
#define SALES_H

#include <QDialog>

namespace Ui {
class sales;
}

class sales : public QDialog
{
    Q_OBJECT

public:
    explicit sales(QWidget *parent = nullptr);
    ~sales();
    void on_pushButton_clicked();
    void on_lineEdit_3_editingFinished();
    void on_lineEdit_2_editingFinished();
    void on_lineEdit_editingFinished();
private:
    Ui::sales *ui;
};

#endif // SALES_H
