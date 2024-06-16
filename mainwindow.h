#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controller.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMainWindow>
#include <QSlider>
#include <QPushButton>
#include <QDial>
#include <QWheelEvent>
#include <QMainWindow>
#include <QSerialPort>
#include <QTranslator>

//Funkcja do skalowania wartości
inline int scaleValue(int value, int fromMax, int toMax) {
    return (value * toMax) / fromMax;
}


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Klasa MainWindow reprezentująca główne okno aplikacji.
 *
 * Klasa dziedziczy po QMainWindow i zawiera interfejs użytkownika oraz logikę aplikacji.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy MainWindow.
     *
     * @param controller Wskaźnik na obiekt klasy Controller, który zarządza logiką aplikacji.
     * @param parent Wskaźnik na obiekt nadrzędny (rodzica) głównego okna.
     */

    explicit MainWindow(Controller *controller, QWidget *parent = nullptr);
    /**
     * @brief Destruktor klasy MainWindow.
     */
    ~MainWindow();

protected:



public slots:

    void handleEncoderValue(int value);


private slots: // Deklaracje slotów

    void on_dial_4_valueChanged(int value);

    void on_dial_2_valueChanged(int value);

    void on_dial_3_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();
    void updateImageSize(int deltaY); //

    void on_oddalenie_clicked();

    void on_przyblizenie_clicked();

    //void on_Wykres_clicked();

    void wavingImage();

    void on_Front_Wave_clicked();

    void on_osiagniecia_przycisk_clicked();

    void on_zmiana_trybu_currentIndexChanged(int index);

    void readSerialData(); //uint8_t receivedData

    //void initializeSerialPort();

    void on_encoderValueChanged(int value);

    void processEncoderData(const QByteArray &data);

    //void processTOFData();
    void processTOFData(const QByteArray &data);

    //void processSerialData(const QByteArray &data);

    void processSensorData(const QByteArray &data);

    void updateChartValues(int progressBarIndex, int values);

    void on_Wykres_clicked();

    void on_someProgressBarValueChanged(int progressBarIndex, int value);

    void updateTotalKnobCountLabel(int totalTurns);

    void scaleUI(QWidget *widget, qreal scale);

    void applyScaling();

    void switchLanguage();

    void on_dialComboBox_1_changed(int index);
    void on_dialComboBox_2_changed(int index);
    void on_dialComboBox_3_changed(int index);
    void on_dialComboBox_4_changed(int index);
    void on_buttonComboBox_1_changed(int index);
    void on_buttonComboBox_2_changed(int index);
    void on_buttonComboBox_3_changed(int index);
    void on_buttonComboBox_4_changed(int index);

    void setVolume(int value);
    void changeWebWindow(int value);
    void changeDesktop(int value);
    void changeAppFocus(int value);


private:
    Ui::MainWindow *ui; /**< Wskaźnik na obiekt interfejsu użytkownika. */
    int previousDialValue; /**< Poprzednia wartość pokrętła. */
    int previousEncoderValue;
    Controller *controllerInstance; /**< Wskaźnik na obiekt klasy Controller. */
    float scaleFactor; /**< Współczynnik skali obrazu. */
    QSerialPort *serial;
    unsigned char receivedData;
    int moveCounter;
    int mapTOFValueToLevel(int tofValue);
    void updateImagePosition(int level);
    Dialog *dialog;
    void loadSettings();
    void saveSettings();
    int totalTurns = 0;
    QTranslator translator;
    bool isPolishSelected;
    void loadLanguage(const QString& langCode);
    int totalClicks;



signals:
    void changeFocus(); /**< Sygnał emitowany przy zmianie fokusu. */
    void encoderValueChanged(int value);
    void serialDataReceived(int value);
    void dialValueChanged(int value);
    void dial2ValueChanged(int value);
    void dial3ValueChanged(int value);
    void dial4ValueChanged(int value);
    void progressBarValueChanged(int progressBarIndex, int value);
    void totalTurnsChanged(int totalTurns);
    void totalTurnsReset();


};

#endif // MAINWINDOW_H
