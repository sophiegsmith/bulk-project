//<<<<<<< HEAD

//=======
//>>>>>>> bd2b559065e0a26f730cf772bce1ca4e2d64b587
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
<<<<<<< HEAD
//<<<<<<< HEAD
//=======

//>>>>>>> bd2b559065e0a26f730cf772bce1ca4e2d64b587
=======
>>>>>>> c97b26aa3f0764c3f64feee9a9403079be73f751
