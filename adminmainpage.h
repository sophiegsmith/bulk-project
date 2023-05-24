#ifndef ADMINMAINPAGE_H
#define ADMINMAINPAGE_H

#include <QDialog>
#include "memberinfo.h"
#include "sales.h"
namespace Ui {
class adminMainPage;
}

class adminMainPage : public QDialog
{
    Q_OBJECT

public:
    explicit adminMainPage(QWidget *parent = nullptr);
    ~adminMainPage();

private slots:
    void on_pushButton_2_members_clicked();

    void on_pushButton_sales_clicked();

    void on_github_push_button_clicked();

private:
    Ui::adminMainPage *ui;
    memberinfo *info;
    sales *report;
};

#endif // ADMINMAINPAGE_H
