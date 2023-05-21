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

private:
    Ui::memberSearch *ui;
};

#endif // MEMBERSEARCH_H
