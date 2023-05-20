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

private:
    Ui::sales *ui;
};

#endif // SALES_H
