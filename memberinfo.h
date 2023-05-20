#ifndef MEMBERINFO_H
#define MEMBERINFO_H

#include <QDialog>

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

private:
    Ui::memberinfo *ui;
};

#endif // MEMBERINFO_H
