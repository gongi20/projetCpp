#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include<QBarSet>
#include<QBarSeries>
namespace Ui {
class graph;
}

class graph : public QDialog
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);
    ~graph();

private:
    Ui::graph *ui;
};

#endif // GRAPH_H
