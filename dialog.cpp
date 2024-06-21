/**
  ******************************************************************************
  * @file           : dialog.cpp
  * @brief          : Tworzy instancje okna dialogowego służącego do generowania
  *                     wykresu
  ******************************************************************************


  ******************************************************************************
  */


#include "dialog.h"
#include "ui_dialog.h"
#include <QtCharts/QChartView>
#include <QVBoxLayout>
#include <QDebug>

/**
 * @class Dialog
 * @brief Klasa Dialog służy do tworzenia i zarządzania oknem dialogowym wyświetlającym wykresy z danych.
 *
 * Klasa Dialog pochodzi od QDialog i zarządza trzema seriami danych, które są prezentowane jako linie na wykresie.
 * Posiada metody do aktualizacji danych w czasie rzeczywistym.
 */


/**
 * @fn Dialog::Dialog(QWidget *parent)
 * @brief Konstruktor klasy Dialog.
 * @param parent Wskaźnik na widget nadrzędny.
 *
 * Inicjalizuje interfejs użytkownika i przygotowuje wykres z trzema seriami danych.
 * Konfiguruje wykres oraz osie, dodając serie i ustawiając zakresy.
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
 * @fn Dialog::~Dialog()
 * @brief Destruktor klasy Dialog.
 *
 * Sprząta po klasie, zwalniając zaalokowane zasoby.
 */

Dialog::~Dialog()
{
    delete ui;
}


/**
 * @fn Dialog::updateChart(int progressBarIndex, int value)
 * @brief Aktualizuje dane na wykresie dla określonej serii.
 * @param progressBarIndex Indeks paska postępu (1-3), który określa, którą serię danych aktualizujemy.
 * @param value Nowa wartość do dodania do serii danych.
 *
 * Dodaje punkt do odpowiedniej serii danych na wykresie. Automatycznie zarządza zakresem osi na wykresie,
 * aby wszystkie dane były widoczne.
 */
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


