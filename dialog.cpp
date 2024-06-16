#include "dialog.h"
#include "ui_dialog.h"
#include <QtCharts/QChartView>
#include <QVBoxLayout>
#include <QDebug>

/**
 * @brief Konstruktor klasy Dialog.
 * Tworzy nowe okno dialogowe z wykresem liniowym.
 * @param parent Wskaźnik do rodzica tego okna dialogowego.
 */
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    chart(new QChart),
    progressBar1Series(new QLineSeries),
    progressBar2Series(new QLineSeries),
    progressBar3Series(new QLineSeries)
{
    ui->setupUi(this);

    progressBar1Series->setName("ProgressBar 1");
    progressBar2Series->setName("ProgressBar 2");
    progressBar3Series->setName("ProgressBar 3");

    chart->legend()->show();
    chart->addSeries(progressBar1Series);
    chart->addSeries(progressBar2Series);
    chart->addSeries(progressBar3Series);
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 10);
    chart->axisY()->setRange(0, 100); // assuming values are between 0 and 100

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(chartView);
    setLayout(layout);
}

/**
 * @brief Destruktor klasy Dialog.
 *
 * Usuwa obiekt interfejsu użytkownika.
 */
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::updateChart(int progressBarIndex, int value)
{
    static int count = 0;
    qDebug() << "Adding point to progressBar" << progressBarIndex << ":" << count << value;

    switch (progressBarIndex) {
    case 1:
        progressBar1Series->append(count, value);
        break;
    case 2:
        progressBar2Series->append(count, value);
        break;
    case 3:
        progressBar3Series->append(count, value);
        break;
    default:
        return; // In case of an invalid index
    }
    count++;

    // Update axes ranges
    chart->axisX()->setRange(0, count);
    chart->axisY()->setRange(0, 100); // assuming values are between 0 and 100
}


