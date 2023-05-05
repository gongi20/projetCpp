#ifndef EMP_H
#define EMP_H

#include <QDialog>

namespace Ui {
class emp;
}

class emp : public QDialog
{
    Q_OBJECT

public:
    explicit emp(QWidget *parent = nullptr);
    ~emp();

private:
    Ui::emp *ui;
};

#endif // EMP_H
