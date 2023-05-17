
#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "adminmainpage.h"


QT_BEGIN_NAMESPACE
namespace Ui { class admin; }
QT_END_NAMESPACE

class admin : public QMainWindow

{
    Q_OBJECT

public:
    admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::admin *ui;
    adminMainPage *adminMP;
};

#endif // ADMIN_H
