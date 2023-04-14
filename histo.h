#ifndef HISTO_H
#define HISTO_H

#include <QDialog>

namespace Ui {
class histo;
}

class histo : public QDialog
{
    Q_OBJECT

public:
    explicit histo(QWidget *parent = nullptr);
    ~histo();

private:
    Ui::histo *ui;
};

#endif // HISTO_H
