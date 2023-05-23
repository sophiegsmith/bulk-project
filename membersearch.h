#ifndef MEMBERSEARCH_H
#define MEMBERSEARCH_H

#include <QDialog>

namespace Ui {
class memberSearch;
}

class memberSearch : public QDialog
{
    Q_OBJECT

public:
    explicit memberSearch(QWidget *parent = nullptr);
    ~memberSearch();

private slots:
    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::memberSearch *ui;
};

#endif // MEMBERSEARCH_H
