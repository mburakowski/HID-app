#include "mainwindow.h"
#include "controller.h"
#include <QWidget>
#include <QSlider>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QVBoxLayout>
#include <QGuiApplication>

/**
 * @brief Funkcja główna programu.
 *
 * Tworzy instancję kontrolera i głównego okna aplikacji, ładuje tłumaczenia interfejsu użytkownika
 * i uruchamia główną pętlę zdarzeń aplikacji.
 *
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica argumentów wiersza poleceń.
 * @return Kod wyjścia programu.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLocale::setDefault(QLocale(QLocale::Polish, QLocale::Poland));

    // Tworzenie obiektu klasy Controller
    Controller controllerInstance;

    // Tworzenie głównego okna aplikacji i przypisanie do niego kontrolera
    MainWindow mainWindow(&controllerInstance);

    QSerialPort serialPort;
    QTranslator translator;

    if (translator.load("WDS_BASIC_pl_PL.qm")) {
        a.installTranslator(&translator);
        qDebug() << "Loaded translation file: WDS_BASIC_pl_PL.qm";
    } else {
        qDebug() << "Failed to load translation file.";
    }


    // Wyświetlanie głównego okna aplikacji i uruchamianie pętli zdarzeń
    mainWindow.show();
    //mainWindow.setFixedSize(mainWindow.size()); //to blokuje możliwość skalowania okna głównego ;))
    return a.exec();
}


