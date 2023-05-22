#ifndef ITEMREVENUE_H
#define ITEMREVENUE_H


#include <QDialog>

namespace Ui {
class itemRevenue;
}

class itemRevenue : public QDialog
{
    Q_OBJECT

public:
    explicit itemRevenue(QWidget *parent = nullptr);
    ~itemRevenue();

private:
    Ui::itemRevenue *ui;
};

#endif // ITEMREVENUE_H
