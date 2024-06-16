#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCharts/QtCharts>
#include <QtCharts/QLineSeries>
//#include "mainwindow.h"
#include <QDateTime>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

/**
 * @brief Klasa Dialog reprezentująca okno dialogowe z wykresem.
 *
 * Klasa dziedziczy po QDialog i zawiera wykres wyświetlany w oknie dialogowym.
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy Dialog.
     *
     * @param parent Wskaźnik na obiekt nadrzędny (rodzica) okna dialogowego.
     */
    //explicit Dialog(MainWindow *mainWindow, QWidget *parent = nullptr);
    explicit Dialog(QWidget *parent = nullptr);
    //void updateChart(int progressBarIndex, int value);

    /**
     * @brief Destruktor klasy Dialog.
     */
    ~Dialog();


public slots:
    //void updateChart(int value);
    // void updateDial4Value(int value);
    // void updateDial2Value(int value);
    // void updateDial3Value(int value);
    // void updateDialValue(int value);
    // void updateChartFromMainWindow(int value);
    //void on_someEventTriggered();
    void updateChart(int progressBarIndex, int value);



private:
    Ui::Dialog *ui; /**< Wskaźnik na obiekt interfejsu użytkownika. */
    QChartView *chartView; /**< Wskaźnik na obiekt widoku wykresu. */
    QLineSeries *series; /**< Wskaźnik na obiekt serii danych wykresu. */
    QMainWindow *mainWindowInstance;
    QTimer *timer;
    QChart *chart;
    QDateTime lastTime;
    QLineSeries *progressBar1Series;
    QLineSeries *progressBar2Series;
    QLineSeries *progressBar3Series;
    int count; // Add this line


};

#endif // DIALOG_H
