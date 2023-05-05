#include "graph.h"
#include "ui_graph.h"
#include "client.h"
#include "client_b.h"
#include "graph.h"
#include "facture.h"
#include "histo.h"
#include "ui_client.h"
#include "vehicule.h"
#include "ui_vehicule.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QTextEdit>
#include <QPainter>
#include <QPdfWriter>
#include <QMessageBox>
#include <QPrinter>
graph::graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);
    QBarSet *set0= new QBarSet("tunis");
    QBarSet *set1= new QBarSet("Ben arous");
    QBarSet *set2= new QBarSet("Manouba");
    QBarSet *set3= new QBarSet("ariana");
    QBarSet *set4= new QBarSet("autres");
client_b s;

    *set0 <<s.calcultunis()<<s.calculben()<<s.calculmanouba()<<s.calculariana()<<s.calculaut();


    QBarSeries *series=new QBarSeries();

    series->append(set0);


        QChart *chart= new QChart();
        chart->addSeries(series);
        chart->setTitle("BARCHART Example in QT ");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "tunis"  << "Ben arous" <<  "Manouba"  << "ariana" << "autres";
       QBarCategoryAxis *axis =new QBarCategoryAxis ();
       axis->append(categories);
       chart->createDefaultAxes();
       chart->setAxisX(axis,series);



        QChartView *chartView= new QChartView(chart);
        chartView->setParent(ui->Frame);
  QString myString = QString::number(s.calcultunis());


}

graph::~graph()
{
    delete ui;
}
