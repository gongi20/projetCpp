#ifndef STAT_H
#define STAT_H

#include <QDialog>
#include<QtCharts>
#include<QChartView>
#include<QBarSet>
#include<QBarSeries>
namespace Ui {
class stat;
}

class stat : public QDialog
{
    Q_OBJECT

public:
    explicit stat(QWidget *parent = nullptr);
    ~stat();

private:
    Ui::stat *ui;
};

#endif // STAT_H
