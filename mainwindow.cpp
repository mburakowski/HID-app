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
 * @brief Konstruktor klasy MainWindow
 * @param controller Wskaźnik do obiektu klasy Controller
 * @param parent Wskaźnik do obiektu nadrzędnego
 * @details Konstruktor inicjuje interfejs użytkownika, wczytuje obrazy i ustawia połączenia sygnałów i slotów dla pokręteł.
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

    setWindowTitle(tr("Hello, World!"));
    qDebug() << tr("Hello, World!");

    previousDialValue = ui->dial_4->value();

    QPixmap pix("C:/Users/MaciejBurakowski(258/Documents/WDS_BASIC/imgs/hand.png");
    QPixmap pix2("C:/Users/MaciejBurakowski(258/Documents/WDS_BASIC/imgs/machanie.png");



    // // Check if the pixmaps are successfully loaded
    // if (pix.isNull()) {
    //     qDebug() << "Failed to load image: C:/Users/MaciejBurakowski/Documents/WDS_BASIC/imgs/hand.png";
    // } else {
    //     QPixmap pixRotated = pix.transformed(QTransform().rotate(-120));
    //     ui->label_pic->setPixmap(pixRotated.scaled(200, 200, Qt::KeepAspectRatio));
    //     ui->label_pic->move(ui->label_pic->x(), ui->label_pic->y() - 100); // ręka góra dół
    // }

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
    serial->setPortName("COM28"); // Ustaw odpowiedni port szeregowy
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


    // Connect ComboBox signals to slots
    connect(ui->pok1, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_dialComboBox_1_changed);
    connect(ui->pok2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_dialComboBox_2_changed);
    connect(ui->pok3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_dialComboBox_3_changed);
    connect(ui->pok4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_dialComboBox_4_changed);
    connect(ui->przycisk_pok1, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_buttonComboBox_1_changed);
    connect(ui->przycisk_pok2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_buttonComboBox_2_changed);
    connect(ui->przycisk_pok3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_buttonComboBox_3_changed);
    connect(ui->przycisk_pok4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_buttonComboBox_4_changed);

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

void MainWindow::loadSettings()
{
    QSettings settings("MACIEKCORP", "WDS_BASIC");
    totalTurns = settings.value("totalTurns", 0).toInt();
}

void MainWindow::saveSettings()
{
    QSettings settings("MACIEKCORP", "WDS_BASIC");
    settings.setValue("totalTurns", totalTurns);
}

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
 * @brief Slot obsługujący zmianę wartości dial_4 (pokrętło głośności)
 * @param value Nowa wartość pokrętła
 * @details Slot odpowiada za zmianę głośności systemu na podstawie wartości pokrętła.
 */
void MainWindow::on_dial_4_valueChanged(int value) {
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
    }
}


/**
 * @brief Slot obsługujący zmianę wartości dial_2 (pokrętło przewijania)
 * @param value Nowa wartość pokrętła
 * @details Slot odpowiada za symulację przewijania strony w zależności od wartości pokrętła.
 */
void MainWindow::on_dial_2_valueChanged(int value){
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
}
}


/**
 * @brief Slot obsługujący zmianę wartości dial_3 (pokrętło wirtualnych pulpitów)
 * @param value Nowa wartość pokrętła
 * @details Slot odpowiada za zmianę wirtualnego pulpitu w systemie Windows na podstawie wartości pokrętła.
 */
void MainWindow::on_dial_3_valueChanged(int value)
{
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
    }
}

/**
 * @brief Slot obsługujący zmianę wartości dial (pokrętło Alt+Tab)
 * @param value Nowa wartość pokrętła
 * @details Slot odpowiada za wywołanie kombinacji klawiszy Alt+Tab w zależności od zmiany wartości pokrętła.
 */
void MainWindow::on_dial_valueChanged(int value)
    {
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
    }

void MainWindow::on_encoderValueChanged(int encoderValue)
{
    // Zakładamy, że wartość enkodera jest w zakresie 0-100
    // W przeciwnym razie należy dostosować przeskalowanie wartości
    int value = encoderValue % 101;

    qDebug() << "Encoder value changed to:" << value;

    // Obliczamy różnicę między obecną wartością enkodera a poprzednią wartością
    int delta = value - previousDialValue;

    // Ustawiamy poprzednią wartość enkodera na obecną wartość
    previousDialValue = value;

    // Aktualizujemy głośność systemu w zależności od ruchu enkodera
    int newVolume = controllerInstance->getSystemVolume() + delta;

    // Upewniamy się, że głośność nie wyjdzie poza zakres 0-100
    newVolume = qBound(0, newVolume, 100);

    // Ustawiamy nową głośność systemu
    controllerInstance->setSystemVolume(newVolume);

    // Aktualizujemy wartość paska postępu
    ui->progressBar_3->setValue(newVolume);
    emit dial4ValueChanged(value);
}

void MainWindow::readSerialData()
{
    QByteArray data = serial->readAll();

    // Przetwarzanie poprawnie sformatowanych danych
    for (int i = 0; i <= data.size() - 8; i += 8) {
        QByteArray segment = data.mid(i, 8);

        // Sprawdzenie, czy segment jest poprawnie sformatowany
        if (segment.size() == 8) {
            processSensorData(segment);
        } else {
            qDebug() << "Nieznane dane: " << data.mid(i, 8).toHex();
        }
    }
}

void MainWindow::processSensorData(const QByteArray &data)
{
    // Wydzielamy pierwsze cztery bajty (dane z enkodera)
    QByteArray encoderData = data.mid(0, 4);

    // Konwersja z little-endian hex na dec (dla enkodera)
    quint32 encoderValue = qFromLittleEndian<quint32>(reinterpret_cast<const uchar*>(encoderData.constData()));
    qDebug() << "Encoder value:" << encoderValue;

    // Emitujemy sygnał zmiany wartości enkodera
    emit encoderValueChanged(encoderValue);

    // Wydzielamy kolejne cztery bajty (dane z TOFa)
    QByteArray tofData = data.mid(4, 4);

    // Konwersja z little-endian hex na dec (dla TOFa)
    quint32 tofValue = qFromLittleEndian<quint32>(reinterpret_cast<const uchar*>(tofData.constData()));
    qDebug() << "TOF value:" << tofValue;

    // Przekształcamy wartość TOF na poziom ruchu obrazka
    int level = mapTOFValueToLevel(tofValue);

    // Aktualizujemy pozycję obrazka na podstawie poziomu
    updateImagePosition(level);
}




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
void MainWindow::processTOFData(const QByteArray &data)
//void MainWindow::processTOFData()
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
 * @brief Slot obsługujący kliknięcie przycisku wyciszenia dźwięku
 */
void MainWindow::on_pushButton_3_clicked()
{
    int index = ui->przycisk_pok1->currentIndex();
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
}
/**
 * @brief Slot obsługujący kliknięcie przycisku wyciszenia mikrofonu
 */
void MainWindow::on_pushButton_2_clicked()
{
    int index = ui->przycisk_pok2->currentIndex();
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
}

/**
 * @brief Slot obsługujący kliknięcie przycisku zmiany pulpitu (skrót Win+D)
 */
void MainWindow::on_pushButton_4_clicked()
{
    int index = ui->przycisk_pok3->currentIndex();
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
}

/**
 * @brief Slot obsługujący kliknięcie przycisku Enter
 */
void MainWindow::on_pushButton_clicked()
{
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


void MainWindow::on_someProgressBarValueChanged(int progressBarIndex, int value)
{
    // Obsługa zmiany wartości paska postępu, jeżeli potrzebne
    qDebug() << "Progress bar" << progressBarIndex << "value changed to" << value;
}

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

void MainWindow::updateTotalKnobCountLabel(int totalTurns)
{
    ui->total_knob_count->setText(QString::number(totalTurns));
}

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
    // Tutaj dodaj logikę zmiany funkcji dla pierwszego pokrętła
}

void MainWindow::on_dialComboBox_2_changed(int index) {
    // Tutaj dodaj logikę zmiany funkcji dla drugiego pokrętła
}

void MainWindow::on_dialComboBox_3_changed(int index) {
    // Tutaj dodaj logikę zmiany funkcji dla trzeciego pokrętła
}

void MainWindow::on_dialComboBox_4_changed(int index) {
    // Tutaj dodaj logikę zmiany funkcji dla czwartego pokrętła
}

void MainWindow::on_buttonComboBox_1_changed(int index) {
    // Tutaj dodaj logikę zmiany funkcji dla pierwszego przycisku
}

void MainWindow::on_buttonComboBox_2_changed(int index) {
    // Tutaj dodaj logikę zmiany funkcji dla drugiego przycisku
}

void MainWindow::on_buttonComboBox_3_changed(int index) {
    // Tutaj dodaj logikę zmiany funkcji dla trzeciego przycisku
}

void MainWindow::on_buttonComboBox_4_changed(int index) {
    // Tutaj dodaj logikę zmiany funkcji dla czwartego przycisku
}

void MainWindow::setVolume(int value) {
    // Obliczamy różnicę między obecną wartością pokrętła a poprzednią wartością
    int delta = value - previousDialValue;

    // Ustawiamy poprzednią wartość pokrętła na obecną wartość
    previousDialValue = value;

    // Aktualizujemy głośność systemu w zależności od ruchu enkodera
    int newVolume = controllerInstance->getSystemVolume() + delta;

    // Upewniamy się, że głośność nie wyjdzie poza zakres 0-100
    newVolume = qBound(0, newVolume, 100);

    // Ustawiamy nową głośność systemu
    controllerInstance->setSystemVolume(newVolume);

    // Aktualizujemy wartość paska postępu
    //ui->progressBar_3->setValue(newVolume);

    // Emitujemy sygnał informujący o zmianie wartości pokrętła
    emit dial4ValueChanged(value);

    // Emitujemy sygnał informujący o zmianie wartości paska postępu (progressBar_3)
    emit progressBarValueChanged(3, newVolume);

    // Inkrementujemy licznik całkowitych przekręceń
    totalTurns++;
    if (totalTurns > 1000) {
        totalTurns = 0;  // Resetujemy licznik po osiągnięciu 1000 przekręceń
    }

    // Emitujemy sygnał informujący o zmianie całkowitej liczby przekręceń
    emit totalTurnsChanged(totalTurns);

    // Aktualizujemy etykietę z całkowitą liczbą przekręceń
    updateTotalKnobCountLabel(totalTurns);
}


void MainWindow::changeWebWindow(int value) {
    // Określamy kody klawiszy PageUp i PageDown
    BYTE vkPageUp = VK_PRIOR;
    BYTE vkPageDown = VK_NEXT;

    // Sprawdź, czy wartość dial_2 wskazuje na lewą stronę (mniej niż 50)
    if (value < 50) {
        // Wysyłamy Ctrl+PageDown do aktywnego okna
        keybd_event(VK_CONTROL, 0, 0, 0);
        keybd_event(vkPageDown, 0, 0, 0);
        keybd_event(vkPageDown, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
        qDebug() << "Przesunięto w lewo!";
    } else {
        // Wysyłamy Ctrl+PageUp do aktywnego okna
        keybd_event(VK_CONTROL, 0, 0, 0);
        keybd_event(vkPageUp, 0, 0, 0);
        keybd_event(vkPageUp, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
        qDebug() << "Przesunięto w prawo!";
    }

    // Poczekaj 500 ms (0.5 sekundy) po wysłaniu zdarzenia klawisza
    Sleep(500);

    // Ustawiamy fokus na okno przeglądarki
    HWND foregroundWindow = GetForegroundWindow();
    SetForegroundWindow(foregroundWindow);

    // Emitujemy sygnał informujący o zmianie wartości pokrętła
    emit dial2ValueChanged(value);

    // Inkrementujemy licznik całkowitych przekręceń
    totalTurns++;
    if (totalTurns > 1000) {
        totalTurns = 0;  // Resetujemy licznik po osiągnięciu 1000 przekręceń
    }

    // Emitujemy sygnał informujący o zmianie całkowitej liczby przekręceń
    emit totalTurnsChanged(totalTurns);

    // Aktualizujemy etykietę z całkowitą liczbą przekręceń
    updateTotalKnobCountLabel(totalTurns);
}


void MainWindow::changeDesktop(int value) {
    //ui->progressBar_2->setValue(value);

    static int previousValue = 0;
    int delta = value - previousValue;

    // Sprawdzenie, czy istnieje więcej niż jeden pulpit
    bool multipleDesktops = IsProcessDPIAware() && (GetDesktopWindow() != GetShellWindow());

    if (delta < 0) {
        // Ruch pokrętłem w lewo
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_CONTROL;  // Wciśnięcie klawisza Ctrl
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LWIN;  // Wciśnięcie klawisza Windows
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LEFT;  // Wciśnięcie strzałki w lewo
        SendInput(1, &input, sizeof(INPUT));

        // Zwalnianie klawiszy
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LWIN;  // Zwolnienie klawisza Windows
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_CONTROL;  // Zwolnienie klawisza Ctrl
        SendInput(1, &input, sizeof(INPUT));

    } else if (delta > 0) {
        // Ruch pokrętłem w prawo
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_CONTROL;  // Wciśnięcie klawisza Ctrl
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LWIN;  // Wciśnięcie klawisza Windows
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_RIGHT;  // Wciśnięcie strzałki w prawo
        SendInput(1, &input, sizeof(INPUT));

        // Zwalnianie klawiszy
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_LWIN;  // Zwolnienie klawisza Windows
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_CONTROL;  // Zwolnienie klawisza Ctrl
        SendInput(1, &input, sizeof(INPUT));

    } else if (!multipleDesktops) {
        // Nie ma więcej niż jednego pulpitu, więc tworzymy nowy za pomocą skrótu Win+Ctrl+D
        INPUT input[4] = {};

        // Wciśnięcie klawisza Ctrl
        input[0].type = INPUT_KEYBOARD;
        input[0].ki.wVk = VK_CONTROL;

        // Wciśnięcie klawisza Windows
        input[1].type = INPUT_KEYBOARD;
        input[1].ki.wVk = VK_LWIN;

        // Wciśnięcie klawisza D
        input[2].type = INPUT_KEYBOARD;
        input[2].ki.wVk = 'D';

        // Zwalnianie wszystkich klawiszy
        input[3].type = INPUT_KEYBOARD;
        input[3].ki.wVk = VK_CONTROL;
        input[3].ki.dwFlags = KEYEVENTF_KEYUP;

        SendInput(4, input, sizeof(INPUT));
    }

    previousValue = value;
    emit dial3ValueChanged(value);
    totalTurns++;
    if (totalTurns > 1000) {
        totalTurns = 0;  // Resetuj licznik po osiągnięciu 1000 przekręceń
    }
    emit totalTurnsChanged(totalTurns);
    updateTotalKnobCountLabel(totalTurns);
}


void MainWindow::changeAppFocus(int value)
{
    static int previousValue = value;
    int delta = value - previousValue;

    // Jeśli delta jest dodatnie (przekręcenie w prawo), wykonujemy skrót Alt + Tab
    if (delta > 0) {
        // Wykonujemy skrót Alt + Tab
        INPUT inputs[4] = {};

        // Wciśnięcie klawisza Alt
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = VK_MENU;

        // Wciśnięcie klawisza Tab
        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = VK_TAB;

        // Zwolnienie klawisza Tab
        inputs[2].type = INPUT_KEYBOARD;
        inputs[2].ki.wVk = VK_TAB;
        inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

        // Zwolnienie klawisza Alt
        inputs[3].type = INPUT_KEYBOARD;
        inputs[3].ki.wVk = VK_MENU;
        inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

        SendInput(4, inputs, sizeof(INPUT));
    }

    // Aktualizujemy poprzednią wartość
    previousValue = value;

    totalTurns++;
    if (totalTurns > 1000) {
        totalTurns = 0;  // Resetuj licznik po osiągnięciu 1000 przekręceń
    }
    emit totalTurnsChanged(totalTurns);
    updateTotalKnobCountLabel(totalTurns);
}

