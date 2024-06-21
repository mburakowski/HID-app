/**
 * @file mainwindow.cpp
 * @brief Zawiera główną logikę programu oraz interfejs użytkownika dla aplikacji.
 */

#include "mainwindow.h"
#include "dialog.h"
#include "achievements.h"
#include <QVBoxLayout>
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <Windows.h>
#include <psapi.h>
#include <QPushButton>
#include "ui_mainwindow.h"
#include <QProgressBar>
#include <mmdeviceapi.h>
#include "controller.h"
#include <ShellScalingApi.h>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPaintEvent>
#include <QtGui>
#include <QSettings>
#include <QTranslator>

/**
 * @class MainWindow
 * @brief Klasa MainWindow obsługuje główne okno i jego interakcje.
 *
 * Ta klasa zarządza interfejsem użytkownika i łączy interakcje użytkowników
 * z funkcjonalnymi częściami aplikacji, takimi jak zmiana głośności systemu,
 * nawigacja między kartami itp.
 */



/**
 * @brief Konstruuje obiekt MainWindow.
 * @param controller Wskaźnik do obiektu kontrolera dla logiki aplikacji.
 * @param parent Wskaźnik do widgetu nadrzędnego, który jest przekazywany do konstruktora QMainWindow.
 */
MainWindow::MainWindow(Controller *controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controllerInstance(controller),
    dialog(new Dialog(this)),
    totalTurns(0),
    isPolishSelected(false),
    totalClicks(0),
    previousEncoderValue(0) // Inicjalizacja zmiennej
{
    ui->setupUi(this);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    loadSettings();

    setWindowTitle(tr("HID-app"));

    QTimer::singleShot(1000, this, SLOT(setupConnections()));

    previousDialValue = ui->dial_4->value();

    QPixmap pix("C:/Users/MaciejBurakowski(258/Documents/WDS_BASIC/imgs/hand.png");
    QPixmap pix2("C:/Users/MaciejBurakowski(258/Documents/WDS_BASIC/imgs/machanie.png");


    // Check if the pixmaps are successfully loaded
    if (pix.isNull()) {
        qDebug() << "Failed to load image: C:/Users/MaciejBurakowski/Documents/WDS_BASIC/imgs/hand.png";
    } else {
        QPixmap pixRotated = pix.transformed(QTransform().rotate(-120));
        ui->label_pic->setPixmap(pixRotated.scaled(200, 200, Qt::KeepAspectRatio));

        // Przesunięcie rysunku bardziej w prawo i w górę
        int xOffset = 2500; // ilość pikseli do przesunięcia w prawo
        int yOffset = -2500; // ilość pikseli do przesunięcia w górę
        ui->label_pic->move(ui->label_pic->x() + xOffset, ui->label_pic->y() + yOffset); // dostosowanie pozycji
    }


    if (pix2.isNull()) {
        qDebug() << "Failed to load image: C:/Users/MaciejBurakowski/Documents/WDS_BASIC/imgs/machanie.png";
    } else {
        ui->label_pic2->setPixmap(pix2.scaled(150, 150, Qt::KeepAspectRatio)); // machanie ręką
    }
    scaleFactor = 0.01f;
    moveCounter = 0;

    // Inicjalizacja portu szeregowego
    serial = new QSerialPort(this);
    serial->setPortName("COM18"); // Ustaw odpowiedni port szeregowy
    serial->setBaudRate(QSerialPort::Baud9600); // Ustaw odpowiednią szybkość transmisji
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // Połączenie sygnałów zmiany wartości pokręteł z odpowiednimi slotami
    connect(ui->dial, &QDial::valueChanged, this, &MainWindow::on_dial_valueChanged);
    connect(ui->dial_2, &QDial::valueChanged, this, &MainWindow::on_dial_2_valueChanged);
    connect(ui->dial_3, &QDial::valueChanged, this, &MainWindow::on_dial_3_valueChanged);
    connect(ui->dial_4, &QDial::valueChanged, this, &MainWindow::on_dial_4_valueChanged);
    connect(this, &MainWindow::encoderValueChanged, this, &MainWindow::on_encoderValueChanged);
    connect(this, &MainWindow::encoderValueChanged, this, &MainWindow::handleEncoderValue);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    connect(ui->progressBar, &QProgressBar::valueChanged, this, [this](int value) { emit progressBarValueChanged(1, value); });
    connect(ui->progressBar_2, &QProgressBar::valueChanged, this, [this](int value) { emit progressBarValueChanged(2, value); });
    connect(ui->progressBar_3, &QProgressBar::valueChanged, this, [this](int value) { emit progressBarValueChanged(3, value); });

    connect(ui->languageButton, &QPushButton::clicked, this, &MainWindow::switchLanguage);

    connect(ui->pok1, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_dialComboBox_1_changed);
    connect(ui->pok2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_dialComboBox_2_changed);
    connect(ui->pok3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_dialComboBox_3_changed);
    connect(ui->pok4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_dialComboBox_4_changed);
    connect(ui->przycisk_pok1, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_buttonComboBox_1_changed);
    connect(ui->przycisk_pok2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_buttonComboBox_2_changed);
    connect(ui->przycisk_pok3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_buttonComboBox_3_changed);
    connect(ui->przycisk_pok4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_buttonComboBox_4_changed);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked, Qt::UniqueConnection);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked, Qt::UniqueConnection);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked, Qt::UniqueConnection);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked, Qt::UniqueConnection);


    // Otwieranie portu szeregowego
    if (serial->open(QIODevice::ReadOnly)) {
        qDebug() << "Serial port opened successfully";
    } else {
        qDebug() << "Failed to open serial port:" << serial->errorString();
    }
}

/**
 * @brief Destruktor klasy MainWindow
 * @details Destruktor zwalnia zasoby przydzielone dynamicznie.
 */
MainWindow::~MainWindow()
{
    delete ui;
    saveSettings();
}

/**
 * @brief Ładuje ustawienia konfiguracyjne.
 *
 * Używa QSettings do wczytania zapisanych ustawień aplikacji, takich jak liczba przekręceń pokrętła.
 */
void MainWindow::loadSettings()
{
    QSettings settings("MACIEKCORP", "WDS_BASIC");
    totalTurns = settings.value("totalTurns", 0).toInt();
}

/**
 * @brief Zapisuje bieżące ustawienia konfiguracyjne.
 *
 * Zapisuje bieżące ustawienia, takie jak liczba przekręceń pokrętła, do trwałego przechowywania.
 */
void MainWindow::saveSettings()
{
    QSettings settings("MACIEKCORP", "WDS_BASIC");
    settings.setValue("totalTurns", totalTurns);
}

/**
 * @brief Stosuje skalowanie UI zgodnie z rozdzielczością ekranu.
 *
 * Automatycznie skaluje interfejs użytkownika na podstawie rozdzielczości ekranu,
 * używając wartości DPI do dostosowania wielkości widgetów.
 */
void MainWindow::applyScaling()
{
    qreal dpi = QGuiApplication::primaryScreen()->logicalDotsPerInch();
    qreal scale = dpi / 96.0;

    // Ustaw skalowanie dla głównego okna
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    this->resize(this->size() * scale);

    // Przejdź przez wszystkie widgety i ustaw ich skalowanie
    scaleUI(ui->centralwidget, scale);
}

/**
 * @brief Stosuje skalowanie UI zgodnie z rozdzielczością ekranu.
 *
 * Automatycznie skaluje interfejs użytkownika na podstawie rozdzielczości ekranu,
 * używając wartości DPI do dostosowania wielkości widgetów.
 */
void MainWindow::scaleUI(QWidget *widget, qreal scale)
{
    widget->setGeometry(widget->x() * scale, widget->y() * scale, widget->width() * scale, widget->height() * scale);

    QFont font = widget->font();
    font.setPointSizeF(font.pointSizeF() * scale);
    widget->setFont(font);

    foreach (QObject *child, widget->children()) {
        QWidget *childWidget = qobject_cast<QWidget *>(child);
        if (childWidget) {
            scaleUI(childWidget, scale);
        }
    }
}

/**
 * @brief Obsługuje zmianę wartości pokrętła odpowiedzialnego za pokrętło 4.
 * @param value Nowa wartość pokrętła.
 *
 * Slot, który reaguje na zmianę wartości pokrętła
 */
void MainWindow::on_dial_4_valueChanged(int value) {
    static QElapsedTimer timer;
    if (!timer.isValid() || timer.elapsed() > 200) { // 200 ms threshold
        timer.start();
        qDebug() << "Processing dial change...";
    ui->progressBar_3->setValue(value); //newVolume
    int index = ui->pok1->currentIndex();
    switch (index) {
    case 0:
        setVolume(value);
        break;
    case 1:
        changeWebWindow(value);
        break;
    case 2:
        changeDesktop(value);
        break;
    case 3:
        changeAppFocus(value);
        break;
    default:
        break;
    }}
}


/**
 * @brief Obsługuje zmianę wartości pokrętła odpowiedzialnego za pokrętło 3.
 * @param value Nowa wartość pokrętła.
 *
 * Slot, który reaguje na zmianę wartości pokrętła
 */
void MainWindow::on_dial_2_valueChanged(int value){

    static QElapsedTimer timer;
    if (!timer.isValid() || timer.elapsed() > 200) { // 200 ms threshold
        timer.start();
        qDebug() << "Processing dial change...";


ui->progressBar->setValue(value);
int index = ui->pok2->currentIndex();
switch (index) {
case 0:
    changeWebWindow(value);
    break;
case 1:
    setVolume(value);
    break;
case 2:
    changeDesktop(value);
    break;
case 3:
    changeAppFocus(value);
    break;
default:
    break;
}}
}

/**
 * @brief Obsługuje zmianę wartości pokrętła odpowiedzialnego za pokrętło 2.
 * @param value Nowa wartość pokrętła.
 *
 * Slot, który reaguje na zmianę wartości pokrętła
 */
void MainWindow::on_dial_3_valueChanged(int value)
{
    static QElapsedTimer timer;
    if (!timer.isValid() || timer.elapsed() > 200) { // 200 ms threshold
        timer.start();
        qDebug() << "Processing dial change...";


    ui->progressBar_2->setValue(value);
    int index = ui->pok3->currentIndex();
    switch (index) {
    case 0:
        changeDesktop(value);
        break;
    case 1:
        setVolume(value);
        break;
    case 2:
        changeWebWindow(value);
        break;
    case 3:
        changeAppFocus(value);
        break;
    default:
        break;
    } }
}

/**
 * @brief Obsługuje zmianę wartości pokrętła odpowiedzialnego za pokrętło 1.
 * @param value Nowa wartość pokrętła.
 *
 * Slot, który reaguje na zmianę wartości pokrętła
 */
void MainWindow::on_dial_valueChanged(int value)
{
    //int scaledValue = value / 5;
    static QElapsedTimer timer;
    if (!timer.isValid() || timer.elapsed() > 200) { // 200 ms threshold
        timer.start();
        qDebug() << "Processing dial change...";

        ui->progressBar_4->setValue(value);
        int index = ui->pok4->currentIndex();
        switch (index) {
        case 0:
            changeAppFocus(value);
            break;
        case 1:
            setVolume(value);
            break;
        case 2:
            changeWebWindow(value);
            break;
        case 3:
            changeDesktop(value);
            break;
        default:
            break;
        }
    } else {
        qDebug() << "Dial change ignored due to rapid re-spin.";
    }
}


/**
 * @brief Slot obsługujący zmianę wartości enkodera.
 * @param encoderValue Nowa wartość enkodera.
 *
 * Metoda obsługuje zmiany wartości enkodera, eliminując drgania dzięki mechanizmowi debouncing.
 * Ustawia głośność systemu zgodnie z odczytaną wartością enkodera.
 */
    void MainWindow::on_encoderValueChanged(int encoderValue) {
        static int lastReportedValue = -1;
        static QElapsedTimer debounceTimer;
        int debounceInterval = 50; // 50 ms dla debouncing

        if (lastReportedValue != encoderValue && (!debounceTimer.isValid() || debounceTimer.elapsed() > debounceInterval)) {
            debounceTimer.start();
            lastReportedValue = encoderValue;

            // Tutaj wykonujesz akcje, które mają być wykonane po zmianie wartości enkodera
            qDebug() << "Encoder value changed to:" << encoderValue;
            controllerInstance->setSystemVolume(encoderValue); // Zakładamy, że istnieje taka funkcja
        }
    }

/**
 * @brief Odczytuje dane z portu szeregowego.
 *
 * Metoda sprawdza, czy otrzymano właściwą ilość danych. W przypadku niekompletnych danych czyści bufor wejściowy.
 */
void MainWindow::readSerialData()
{
    QByteArray buffer = serial->read(expectedDataSize);

    // Check if we have received the correct amount of data
    if (buffer.size() == expectedDataSize) {
        processSerialFrame(buffer);
    } else {
        serial->clear(QSerialPort::Input); // Clear the input buffer if data is incomplete
        qDebug() << "Incomplete or excess data received";
    }
}


/**
 * @brief Przetwarza ramkę danych otrzymaną przez port szeregowy.
 * @param data Dane do przetworzenia.
 *
 * Metoda interpretuje dane z portu szeregowego, aktualizując wartości pokręteł i przycisków na interfejsie użytkownika.
 */
void MainWindow::processSerialFrame(const QByteArray &data)
{
    QDataStream stream(data);
    stream.setByteOrder(QDataStream::LittleEndian);

    int encValues[4];
    int buttonValues[4];
    int rangeMillimeter;
    int mode;

    stream >> encValues[0] >> buttonValues[0];
    stream >> encValues[1] >> buttonValues[1];
    stream >> encValues[2] >> buttonValues[2];
    stream >> buttonValues[3];
    stream >> rangeMillimeter >> mode;

    // Update dials based on encoder values
    ui->dial->setValue(encValues[0]);
    ui->dial_3->setValue(encValues[1]);
    ui->dial_2->setValue(encValues[2]);

    // Trigger buttons based on button values
    handleButtonPress(buttonValues[0], ui->pushButton, 0);
    handleButtonPress(buttonValues[1], ui->pushButton_4, 1);
    handleButtonPress(buttonValues[2], ui->pushButton_2, 2);
    handleButtonPress(buttonValues[3], ui->pushButton_3, 3);

    // Optionally handle TOF range
    int level = mapTOFValueToLevel(rangeMillimeter);
    updateImagePosition(level);
}

/**
 * @brief Slot obsługujący zdarzenia naciśnięcia przycisków.
 * @param buttonValue Wartość stanu przycisku (naciśnięty lub nie).
 * @param button Wskaźnik do przycisku, którego to dotyczy.
 * @param buttonIndex Indeks przycisku.
 *
 * Metoda debouncuje stany przycisków, aby zapobiegać błędnym odczytom spowodowanym drganiami.
 */
void MainWindow::handleButtonPress(int buttonValue, QPushButton* button, int buttonIndex) {
    static QVector<int> lastButtonState(4, 1); // Initial state is '1' (released)
    static QVector<QElapsedTimer> timers(4); // Timers for debouncing
    int debounceThreshold = 50; // milliseconds

    if (!timers[buttonIndex].isValid() || timers[buttonIndex].elapsed() > debounceThreshold) {
        if (buttonValue == 0 && lastButtonState[buttonIndex] == 1) {
            button->click();
            lastButtonState[buttonIndex] = 0;
            timers[buttonIndex].start();
        } else if (buttonValue == 1 && lastButtonState[buttonIndex] == 0) {
            lastButtonState[buttonIndex] = 1;
            timers[buttonIndex].start();
        }
    }
}

/**
 * @brief Przetwarza naciśnięcia przycisków.
 * @param buttonValues Tablica wartości przycisków.
 *
 * Metoda obsługuje przetwarzanie stanów przycisków, realizując mechanizm anty-drganiowy i detekcję wielokrotnego naciśnięcia.
 */
void MainWindow::processButtonPresses(int buttonValues[4])
{
    static QVector<int> pressCount(4, 1); // Counters for each button
    static const int threshold = 3; // Threshold for button press detection

    for (int i = 0; i < 4; ++i) {
        if (buttonValues[i] == 0) {
            pressCount[i]++;
        } else {
            if (pressCount[i] >= threshold) {
                //simulateButtonClick(i); // Simulate the button click
            }
            pressCount[i] = 0; // Reset the counter when button is released or after a click is simulated
        }
    }
}

/**
 * @brief Przetwarza dane z enkodera.
 * @param data Dane z enkodera.
 *
 * Metoda przetwarza dane z enkodera, konwertując je z formatu hex na decimal i skalując odpowiednio wartość.
 */
void MainWindow::processEncoderData(const QByteArray &data)
{
    // Wyodrębnij pierwsze dwa bajty
    QByteArray significantBytes = data.mid(0, 2);

    // Konwersja na hex string
    QString hexString = significantBytes.toHex();

    // Konwersja z hex na dec
    bool ok;
    int number = hexString.toInt(&ok, 16);

    if (ok) {
        // Skalowanie wartości
        int scaledValue = scaleValue(number, 65280, 500);
        qDebug() << "Dane z enkodera po skalowaniu:" << scaledValue;

        // Tutaj wykonaj dalsze operacje na danych z enkodera, jeśli potrzebne
    } else {
        qDebug() << "Nie udało się przekonwertować danych z enkodera na system dziesiętny.";
    }
}

/**
 * @brief Przetwarza dane z czujnika TOF.
 * @param data Dane z czujnika TOF.
 *
 * Metoda przetwarza dane z czujnika TOF, konwertując wartości z hex na decimal i realizując dalszą logikę bazującą na odczytanej odległości.
 */
void MainWindow::processTOFData(const QByteArray &data)
{
    // Wyodrębnij pierwsze dwa bajty
    QByteArray significantBytes = data.mid(0, 2);

    // Konwersja na hex string
    QString hexString = significantBytes.toHex();

    // Konwersja z hex na dec
    bool ok;
    int distance = hexString.toInt(&ok, 16);

    if (ok) {
        qDebug() << "Odczytana odległość z czujnika TOF: " << distance;
        // Tutaj wykonaj dalsze operacje na odczytanej odległości, jeśli potrzebne
    } else {
        qDebug() << "Nie udało się przekonwertować danych z czujnika TOF na system dziesiętny.";
    }
}

/**
 * @brief Obsługuje wartość z enkodera i aktualizuje głośność systemu.
 * @param value Nowa wartość z enkodera.
 *
 * Metoda aktualizuje głośność systemu na podstawie odczytanej wartości z enkodera, uwzględniając kierunek i wielkość zmiany.
 */
void MainWindow::handleEncoderValue(int value)
{
    // Pobierz aktualną głośność systemu
    int currentVolume = controllerInstance->getSystemVolume();

    // Oblicz różnicę między nową wartością enkodera a poprzednią
    int delta = value - previousEncoderValue;

    // Określ kierunek ruchu enkodera
    int direction = delta > 0 ? 1 : (delta < 0 ? -1 : 0);

    // Aktualizuj głośność systemu w zależności od kierunku ruchu enkodera
    int newVolume = currentVolume + direction * qAbs(delta);

    // Upewnij się, że głośność jest w granicach 0-100
    newVolume = qBound(0, newVolume, 100);

    // Ustaw nową głośność systemu
    controllerInstance->setSystemVolume(newVolume);

    // Aktualizuj wartość paska postępu
    ui->progressBar_3->setValue(newVolume);

    // Zapisz nową wartość enkodera jako poprzednią
    previousEncoderValue = value;
}


/**
 * @brief Slot obsługujący kliknięcie przycisku 4
 */
void MainWindow::on_pushButton_3_clicked()
{
    static QElapsedTimer timer;
    if (!timer.isValid() || timer.elapsed() > 200) { // 200 ms threshold
        timer.start();
        qDebug() << "Processing click...";

        int index = ui->przycisk_pok4->currentIndex();
        switch (index) {
        case 0:
            controllerInstance->toggleMute();
            break;
        case 1:
            controllerInstance->toggleMicrophoneMute();
            break;
        case 2:
            controllerInstance->createNewDesktop();
            break;
        case 3:
            controllerInstance->accChanges();
            break;
        default:
            break;
        }
        totalClicks++;
        ui->total_click_count->setText(QString::number(totalClicks));
    } else {
        qDebug() << "Click ignored due to rapid re-click.";
    }
}

/**
 * @brief Slot obsługujący kliknięcie przycisku 3
 */
void MainWindow::on_pushButton_2_clicked()
{
    static QElapsedTimer timer;
    if (!timer.isValid() || timer.elapsed() > 200) { // 200 ms threshold
        timer.start();
        qDebug() << "Processing click...";

        int index = ui->przycisk_pok4->currentIndex();
        switch (index) {
        case 0:
            controllerInstance->toggleMicrophoneMute();
            break;
        case 1:
            controllerInstance->toggleMute();
            break;
        case 2:
            controllerInstance->createNewDesktop();
            break;
        case 3:
            controllerInstance->accChanges();
            break;
        default:
            break;
        }
        totalClicks++;
        ui->total_click_count->setText(QString::number(totalClicks));
    } else {
        qDebug() << "Click ignored due to rapid re-click.";
    }
}

/**
 * @brief Slot obsługujący kliknięcie przycisku 2
 */
void MainWindow::on_pushButton_4_clicked()
{
    static QElapsedTimer timer;
    if (!timer.isValid() || timer.elapsed() > 200) { // 200 ms threshold
        timer.start();
        qDebug() << "Processing click...";

        int index = ui->przycisk_pok4->currentIndex();
        switch (index) {
        case 0:
            controllerInstance->createNewDesktop();
            break;
        case 1:
            controllerInstance->toggleMute();
            break;
        case 2:
            controllerInstance->toggleMicrophoneMute();
            break;
        case 3:
            controllerInstance->accChanges();
            break;
        default:
            break;
        }
        totalClicks++;
        ui->total_click_count->setText(QString::number(totalClicks));
    } else {
        qDebug() << "Click ignored due to rapid re-click.";
    }
}


/**
 * @brief Slot obsługujący kliknięcie przycisku 1
 */
void MainWindow::on_pushButton_clicked()
{
    static QElapsedTimer timer;
    if (!timer.isValid() || timer.elapsed() > 200) { // 200 ms threshold
        timer.start();
        qDebug() << "Processing click...";

        int index = ui->przycisk_pok4->currentIndex();
        switch (index) {
        case 0:
            controllerInstance->accChanges();
            break;
        case 1:
            controllerInstance->toggleMute();
            break;
        case 2:
            controllerInstance->toggleMicrophoneMute();
            break;
        case 3:
            controllerInstance->createNewDesktop();
            break;
        default:
            break;
        }
        totalClicks++;
        ui->total_click_count->setText(QString::number(totalClicks));
    } else {
        qDebug() << "Click ignored due to rapid re-click.";
    }
}


/**
 * @brief Aktualizuje rozmiar obrazka na podstawie przekazanej wartości deltaY
 * @param deltaY Wartość przesunięcia obrazka
 */
void MainWindow::updateImageSize(int deltaY)
{
    // Sprawdź, czy przesunięcie w górę jest możliwe
    if (deltaY < 0 && moveCounter <= 0) {
        return; // Nie pozwól na ruch w górę, jeśli counter jest już na minimalnej wartości
    }

    // Sprawdź, czy przesunięcie w dół jest możliwe
    if (deltaY > 0 && moveCounter >= 10) {
        return; // Nie pozwól na ruch w dół, jeśli counter jest już na maksymalnej wartości
    }

    // Pobieramy obecne położenie obrazka
    int currentX = ui->label_pic->geometry().x();
    int currentY = ui->label_pic->geometry().y();

    // Aktualizujemy położenie obrazka
    ui->label_pic->move(currentX, currentY + deltaY);

    // Aktualizujemy licznik ruchu
    moveCounter += (deltaY > 0) ? 1 : -1;
}

/**
 * @brief Slot obsługujący kliknięcie przycisku oddalenia obrazka
 */
void MainWindow::on_oddalenie_clicked()
{
    // Wywołanie funkcji do aktualizacji położenia obrazka - przesuwa w górę o 10 pikseli
    updateImageSize(-20);
}

/**
 * @brief Slot obsługujący kliknięcie przycisku przybliżenia obrazka
 */
void MainWindow::on_przyblizenie_clicked()
{
    // Wywołanie funkcji do aktualizacji położenia obrazka - przesuwa w dół o 10 pikseli
    updateImageSize(20);
}


/**
 * @brief Obraca obrazek w etykiecie label_pic2 o 60 stopni w lewo, a następnie o 100 stopni w prawo
 * @details Wykorzystuje QTimer do uzyskania efektu animacji obracania obrazka
 */
void MainWindow::wavingImage()
{
    // Pobierz obrazek
    QPixmap originalPixmap2("C:/Users/MaciejBurakowski(258/Documents/WDS_BASIC/imgs/machanie.png");

    // Obróć obrazek o 60 stopni w lewo
    QPixmap rotateLeft = originalPixmap2.transformed(QTransform().rotate(60));

    // Ustaw skalowany obrazek w etykiecie
    ui->label_pic2->setPixmap(rotateLeft.scaled(170, 170, Qt::KeepAspectRatio));

    // Przechwyć originalPixmap2 przez wartość
    QPixmap pixmapCopy = originalPixmap2;

    // Oczekaj przez krótki czas
    QTimer::singleShot(350, [=]() {
        // Obróć obrazek o 100 stopni w prawo
        QPixmap rotateRight = pixmapCopy.transformed(QTransform().rotate(-20));

         // Ustaw skalowany obrazek w etykiecie
        ui->label_pic2->setPixmap(rotateRight.scaled(170, 170, Qt::KeepAspectRatio));

        // Oczekaj przez kolejny krótki czas
        QTimer::singleShot(350, [=]() {
            // Ustaw oryginalny obrazek
            ui->label_pic2->setPixmap(originalPixmap2.scaled(170, 170, Qt::KeepAspectRatio));
        });
    });
}


/**
 * @brief Slot obsługujący kliknięcie przycisku otwierającego dialog z wykresem
 */
void MainWindow::on_Wykres_clicked()
{
    Dialog *dialog = new Dialog(this);
    connect(this, &MainWindow::progressBarValueChanged, dialog, &Dialog::updateChart);
    dialog->show();
}

/**
 * @brief Obsługa zmiany wartości paska postępu, jeżeli potrzebne
 */
void MainWindow::on_someProgressBarValueChanged(int progressBarIndex, int value)
{   
    qDebug() << "Progress bar" << progressBarIndex << "value changed to" << value;
}

/**
 * @brief Aktualizowanie wartości na wykresie
 */
void MainWindow::updateChartValues(int progressBarIndex, int value)
{
    emit progressBarValueChanged(progressBarIndex, value);
}


/**
 * @brief Slot obsługujący kliknięcie przycisku rozpoczynającego animację machania obrazkiem
 */
void MainWindow::on_Front_Wave_clicked()
{
    wavingImage();
}

/**
 * @brief Slot obsługujący kliknięcie przycisku otwierającego dialog z osiągnięciami
 */
void MainWindow::on_osiagniecia_przycisk_clicked()
{
    Achievements *dialog = new Achievements(this);

    connect(this, &MainWindow::totalTurnsChanged, dialog, &Achievements::updateProgressBars);

    emit totalTurnsChanged(totalTurns);

    dialog->show();
}

/**
 * @brief Slot obsługujący zmianę wartości indeksu w ComboBoxie zmiany trybu
 * @param index Indeks wybranej opcji w ComboBoxie
 */
void MainWindow::on_zmiana_trybu_currentIndexChanged(int index)
{
    QString selectedText = ui->zmiana_trybu->currentText();
    if(selectedText == "Mode 2")
    {
        QMessageBox::information(this, "Info", QObject::tr("Choosen Mode 2! Make sure, that HID device is connected."));

        ui->Front_Wave->hide();
        ui->oddalenie->hide();
        ui->przyblizenie->hide();
        ui->wyswietlacz->show();
    }
    else
    {
        ui->wyswietlacz->hide();
        ui->Front_Wave->show();
        ui->oddalenie->show();
        ui->przyblizenie->show();
    }
}

/**
 * @brief Mapuje wartość z czujnika TOF na poziom, który określa pozycję ruchu obrazka.
 * @param tofValue Odczytana wartość z czujnika TOF.
 * @return Obliczony poziom ruchu obrazka.
 *
 * Funkcja mapuje wartości odczytane z czujnika Time-of-Flight na zakresy poziomów ruchu obrazka,
 * aby umożliwić ich wizualną reprezentację.
 */
int MainWindow::mapTOFValueToLevel(int tofValue)
{
    // Definiujemy zakresy wartości TOF
    const int minTOF = 60;
    const int maxTOF = 300;

    // Definiujemy zakresy poziomów ruchu obrazka
    const int minLevel = 0;
    const int maxLevel = 10;

    // Upewniamy się, że wartość TOF mieści się w granicach
    tofValue = qBound(minTOF, tofValue, maxTOF);

    // Odwrotne mapowanie wartości TOF na poziom ruchu obrazka
    int level = maxLevel - ((tofValue - minTOF) * (maxLevel - minLevel) / (maxTOF - minTOF));

    return level;
}

/**
 * @brief Aktualizuje pozycję obrazka na podstawie zmiennej poziomu.
 * @param level Obliczony poziom, który determinuje przesunięcie obrazka.
 *
 * Metoda aktualizuje pozycję obrazka w zależności od otrzymanego poziomu, przesuwając go o określoną liczbę pikseli.
 */
void MainWindow::updateImagePosition(int level)
{
    // Oblicz przesunięcie obrazka na podstawie poziomu
    int deltaY = (level - moveCounter) * 20; // Przyjmując 20 pikseli na poziom

    // Pobieramy obecne położenie obrazka
    int currentX = ui->label_pic->geometry().x();
    int currentY = ui->label_pic->geometry().y();

    // Aktualizujemy położenie obrazka
    ui->label_pic->move(currentX, currentY + deltaY);

    // Aktualizujemy licznik ruchu
    moveCounter = level;
}

/**
 * @brief Aktualizuje etykietę z całkowitą liczbą przekręceń pokrętła.
 * @param totalTurns Całkowita liczba przekręceń pokrętła.
 *
 * Wyświetla wartość całkowitej liczby przekręceń w odpowiedniej etykiecie.
 */
void MainWindow::updateTotalKnobCountLabel(int totalTurns)
{
    ui->total_knob_count->setText(QString::number(totalTurns));
    updateDistanceLabel(totalTurns);
}

void MainWindow::updateDistanceLabel(int value) {
    double convertedValue = value * (3.14 / 20);
    ui->distance->setText(QString::number(convertedValue, 'f', 2));  // 'f' for fixed-point, 2 digits after decimal point
}


/**
 * @brief Ładuje język interfejsu użytkownika.
 * @param langCode Kod języka do załadowania.
 *
 * Funkcja ładuje plik tłumaczenia na podstawie podanego kodu języka i aktualizuje interfejs użytkownika.
 */
void MainWindow::loadLanguage(const QString &langCode)
{
    qDebug() << "Loading language:" << langCode;

    if (langCode == "pl_PL") {
        // Usuwamy wcześniejsze tłumaczenie (jeśli istnieje)
        qApp->removeTranslator(&translator);

        // Ładujemy nowe tłumaczenie
        if (translator.load(":/translations/WDS_BASIC_pl_PL.qm")) {
            qApp->installTranslator(&translator);
            qDebug() << "Loaded translation file: WDS_BASIC_pl_PL.qm";
        } else {
            qDebug() << "Failed to load translation file: WDS_BASIC_pl_PL.qm";
        }
    } else {
        // Usuwamy tłumaczenie, aby powrócić do angielskiego (domyślnego)
        qApp->removeTranslator(&translator);
        qDebug() << "Reverted to default (English)";
    }

    // Aktualizujemy flagę określającą wybrany język
    isPolishSelected = (langCode == "pl_PL");

    // Ponowne tłumaczenie interfejsu użytkownika
    ui->retranslateUi(this);
    qDebug() << "UI retranslated.";
}

/**
 * @brief Przełącza język interfejsu użytkownika.
 *
 * Funkcja przełącza język interfejsu użytkownika między polskim a angielskim, w zależności od aktualnie ustawionego języka.
 */
void MainWindow::switchLanguage()
{
    qDebug() << "Switching language. Current language is Polish:" << isPolishSelected;

    // Przełączamy język na przeciwny
    if (isPolishSelected) {
        loadLanguage(""); // Przełącz na angielski (domyślny)
    } else {
        loadLanguage("pl_PL"); // Przełącz na polski
    }

    qDebug() << "Language switched. Current language is Polish:" << isPolishSelected;
}

void MainWindow::on_dialComboBox_1_changed(int index) {
}

void MainWindow::on_dialComboBox_2_changed(int index) {  
}

void MainWindow::on_dialComboBox_3_changed(int index) {
}

void MainWindow::on_dialComboBox_4_changed(int index) {
}

void MainWindow::on_buttonComboBox_1_changed(int index) {
}

void MainWindow::on_buttonComboBox_2_changed(int index) {
}

void MainWindow::on_buttonComboBox_3_changed(int index) {
}

void MainWindow::on_buttonComboBox_4_changed(int index) {
}

/**
 * @brief Ustawia głośność systemu na podstawie zmian wartości pokrętła.
 * @param value Nowa wartość pokrętła dla głośności.
 *
 * Funkcja oblicza różnicę między aktualną wartością a poprzednią wartością pokrętła, aktualizuje głośność systemową
 * i emituje sygnał o zmianie wartości. Również aktualizuje licznik całkowitych przekręceń pokrętła.
 */
void MainWindow::setVolume(int value) {
    // Obliczamy różnicę między obecną wartością pokrętła a poprzednią wartością
    int delta = value - previousDialValue;
    previousDialValue = value;
    int newVolume = controllerInstance->getSystemVolume() + delta;
    newVolume = qBound(0, newVolume, 100);
    controllerInstance->setSystemVolume(newVolume);

    // Inkrementujemy licznik całkowitych przekręceń
    totalTurns++;
    if (totalTurns > 1000) {
        totalTurns = 0;
    }

    emit totalTurnsChanged(totalTurns);
    updateTotalKnobCountLabel(totalTurns);
}

/**
 * @brief Zmienia aktywną kartę w przeglądarce.
 * @param value Nowa wartość odczytana z pokrętła.
 *
 * Funkcja zmienia aktywną kartę w przeglądarce, symulując naciśnięcia klawiszy.
 * Kierunek zmiany (lewo lub prawo) zależy od tego, czy wartość odczytana jest większa
 * czy mniejsza od ostatniej zapamiętanej wartości.
 */
void MainWindow::changeWebWindow(int value) {
    static int lastValue = 0;
    BYTE vkTab = VK_TAB;
    bool right = value > lastValue; // Czy zwiększamy wartość?

    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(vkTab, 0, right ? 0 : KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(vkTab, 0, right ? KEYEVENTF_KEYUP : KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

    //qDebug() << "Navigated " << (right ? "right" : "left") << " to the next tab.";

    lastValue = value;

    emit dial2ValueChanged(value);

    totalTurns++;
    if (totalTurns > 1000) {
        totalTurns = 0;
    }

    emit totalTurnsChanged(totalTurns);
    updateTotalKnobCountLabel(totalTurns);
}

/**
 * @brief Zmienia aktywny pulpit (desktop) systemu Windows.
 * @param value Nowa wartość odczytana z pokrętła.
 *
 * Funkcja zmienia pulpit użytkownika na następny lub poprzedni, w zależności od kierunku obrotu pokrętła.
 * Możliwość tworzenia nowego pulpitu, jeśli nie istnieje więcej niż jeden.
 */
void MainWindow::changeDesktop(int value) {

    static int previousValue = 0;
    int delta = value - previousValue;

    // Sprawdzenie, czy istnieje więcej niż jeden pulpit
    bool multipleDesktops = IsProcessDPIAware() && (GetDesktopWindow() != GetShellWindow());

    if (delta < 0) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_CONTROL;
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LWIN;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LEFT;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LWIN;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_CONTROL;
        SendInput(1, &input, sizeof(INPUT));

    } else if (delta > 0) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_CONTROL;
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LWIN;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_RIGHT;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LWIN;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_CONTROL;
        SendInput(1, &input, sizeof(INPUT));

    } else if (!multipleDesktops) {
        // Nie ma więcej niż jednego pulpitu, więc tworzymy nowy za pomocą skrótu Win+Ctrl+D
        INPUT input[4] = {};

        input[0].type = INPUT_KEYBOARD;
        input[0].ki.wVk = VK_CONTROL;

        input[1].type = INPUT_KEYBOARD;
        input[1].ki.wVk = VK_LWIN;

        input[2].type = INPUT_KEYBOARD;
        input[2].ki.wVk = 'D';

        input[3].type = INPUT_KEYBOARD;
        input[3].ki.wVk = VK_CONTROL;
        input[3].ki.dwFlags = KEYEVENTF_KEYUP;

        SendInput(4, input, sizeof(INPUT));
    }

    previousValue = value;
    emit dial3ValueChanged(value);
    totalTurns++;
    if (totalTurns > 1000) {
        totalTurns = 0;
    }
    emit totalTurnsChanged(totalTurns);
    updateTotalKnobCountLabel(totalTurns);
}

/**
 * @brief Zmienia fokus aplikacji.
 * @param direction Kierunek zmiany fokusu (1 dla 'następny', -1 dla 'poprzedni').
 *
 * Funkcja obsługuje przełączanie fokusu między aplikacjami za pomocą kombinacji Alt+Tab,
 * gdzie kierunek zależy od wartości przekazanej w parametrze.
 */
void MainWindow::changeAppFocus(int direction)
{
    static bool isAltPressed = false;

    if (!isAltPressed) {
        INPUT inputAlt;
        inputAlt.type = INPUT_KEYBOARD;
        inputAlt.ki.wVk = VK_MENU;
        inputAlt.ki.dwFlags = 0; // 0 oznacza naciśnięcie klawisza
        SendInput(1, &inputAlt, sizeof(INPUT));
        isAltPressed = true;
    }

    INPUT inputs[2] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_TAB;
    inputs[0].ki.dwFlags = 0;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = VK_TAB;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(2, inputs, sizeof(INPUT));
}

/**
 * @brief Resetuje stan klawisza Alt.
 *
 * Funkcja resetuje stan klawisza Alt do stanu nieaktywnego, czyli zwalnia klawisz Alt.
 */
void MainWindow::resetAppFocus()
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VK_MENU;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));

    // Reset flagi
    isAltPressed = false;
}

