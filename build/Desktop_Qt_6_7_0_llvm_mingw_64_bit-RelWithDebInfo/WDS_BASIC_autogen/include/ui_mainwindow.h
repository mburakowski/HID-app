/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QDial *dial_4;
    QDial *dial_2;
    QDial *dial_3;
    QDial *dial;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_4;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *przycisk_pok1;
    QComboBox *przycisk_pok2;
    QComboBox *przycisk_pok3;
    QComboBox *przycisk_pok4;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *pok1;
    QComboBox *pok2;
    QComboBox *pok3;
    QComboBox *pok4;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *total_knob_count;
    QLabel *total_click_count;
    QLabel *distance;
    QPushButton *Wykres;
    QPushButton *osiagniecia_przycisk;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QComboBox *zmiana_trybu;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QComboBox *zmiana_led;
    QGraphicsView *wyswietlacz;
    QGroupBox *groupBox_4;
    QLabel *label_pic;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *oddalenie;
    QPushButton *przyblizenie;
    QLabel *label_pic2;
    QPushButton *Front_Wave;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1120, 770);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 100, 661, 52));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dial_4 = new QDial(horizontalLayoutWidget);
        dial_4->setObjectName("dial_4");
        dial_4->setWrapping(false);

        horizontalLayout->addWidget(dial_4);

        dial_2 = new QDial(horizontalLayoutWidget);
        dial_2->setObjectName("dial_2");

        horizontalLayout->addWidget(dial_2);

        dial_3 = new QDial(horizontalLayoutWidget);
        dial_3->setObjectName("dial_3");

        horizontalLayout->addWidget(dial_3);

        dial = new QDial(horizontalLayoutWidget);
        dial->setObjectName("dial");

        horizontalLayout->addWidget(dial);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 160, 661, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        progressBar_3 = new QProgressBar(horizontalLayoutWidget_2);
        progressBar_3->setObjectName("progressBar_3");
        progressBar_3->setValue(24);

        horizontalLayout_2->addWidget(progressBar_3);

        progressBar = new QProgressBar(horizontalLayoutWidget_2);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);

        progressBar_2 = new QProgressBar(horizontalLayoutWidget_2);
        progressBar_2->setObjectName("progressBar_2");
        progressBar_2->setValue(24);

        horizontalLayout_2->addWidget(progressBar_2);

        progressBar_4 = new QProgressBar(horizontalLayoutWidget_2);
        progressBar_4->setObjectName("progressBar_4");
        progressBar_4->setValue(24);

        horizontalLayout_2->addWidget(progressBar_4);

        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 70, 661, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton = new QPushButton(horizontalLayoutWidget_3);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);

        horizontalLayoutWidget_6 = new QWidget(groupBox);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(14, 30, 661, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        przycisk_pok1 = new QComboBox(horizontalLayoutWidget_6);
        przycisk_pok1->addItem(QString());
        przycisk_pok1->addItem(QString());
        przycisk_pok1->addItem(QString());
        przycisk_pok1->addItem(QString());
        przycisk_pok1->setObjectName("przycisk_pok1");

        horizontalLayout_6->addWidget(przycisk_pok1);

        przycisk_pok2 = new QComboBox(horizontalLayoutWidget_6);
        przycisk_pok2->addItem(QString());
        przycisk_pok2->addItem(QString());
        przycisk_pok2->addItem(QString());
        przycisk_pok2->addItem(QString());
        przycisk_pok2->setObjectName("przycisk_pok2");

        horizontalLayout_6->addWidget(przycisk_pok2);

        przycisk_pok3 = new QComboBox(horizontalLayoutWidget_6);
        przycisk_pok3->addItem(QString());
        przycisk_pok3->addItem(QString());
        przycisk_pok3->addItem(QString());
        przycisk_pok3->addItem(QString());
        przycisk_pok3->setObjectName("przycisk_pok3");

        horizontalLayout_6->addWidget(przycisk_pok3);

        przycisk_pok4 = new QComboBox(horizontalLayoutWidget_6);
        przycisk_pok4->addItem(QString());
        przycisk_pok4->addItem(QString());
        przycisk_pok4->addItem(QString());
        przycisk_pok4->addItem(QString());
        przycisk_pok4->setObjectName("przycisk_pok4");

        horizontalLayout_6->addWidget(przycisk_pok4);

        horizontalLayoutWidget_5 = new QWidget(groupBox);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(10, 210, 661, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pok1 = new QComboBox(horizontalLayoutWidget_5);
        pok1->addItem(QString());
        pok1->addItem(QString());
        pok1->addItem(QString());
        pok1->addItem(QString());
        pok1->setObjectName("pok1");

        horizontalLayout_5->addWidget(pok1);

        pok2 = new QComboBox(horizontalLayoutWidget_5);
        pok2->addItem(QString());
        pok2->addItem(QString());
        pok2->addItem(QString());
        pok2->addItem(QString());
        pok2->setObjectName("pok2");

        horizontalLayout_5->addWidget(pok2);

        pok3 = new QComboBox(horizontalLayoutWidget_5);
        pok3->addItem(QString());
        pok3->addItem(QString());
        pok3->addItem(QString());
        pok3->addItem(QString());
        pok3->setObjectName("pok3");

        horizontalLayout_5->addWidget(pok3);

        pok4 = new QComboBox(horizontalLayoutWidget_5);
        pok4->addItem(QString());
        pok4->addItem(QString());
        pok4->addItem(QString());
        pok4->addItem(QString());
        pok4->setObjectName("pok4");

        horizontalLayout_5->addWidget(pok4);


        gridLayout->addWidget(groupBox, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayoutWidget = new QWidget(groupBox_3);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 20, 251, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        verticalLayoutWidget_4 = new QWidget(groupBox_3);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(280, 20, 21, 80));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        total_knob_count = new QLabel(verticalLayoutWidget_4);
        total_knob_count->setObjectName("total_knob_count");

        verticalLayout_4->addWidget(total_knob_count);

        total_click_count = new QLabel(verticalLayoutWidget_4);
        total_click_count->setObjectName("total_click_count");

        verticalLayout_4->addWidget(total_click_count);

        distance = new QLabel(verticalLayoutWidget_4);
        distance->setObjectName("distance");

        verticalLayout_4->addWidget(distance);

        Wykres = new QPushButton(groupBox_3);
        Wykres->setObjectName("Wykres");
        Wykres->setGeometry(QRect(10, 110, 93, 29));
        osiagniecia_przycisk = new QPushButton(groupBox_3);
        osiagniecia_przycisk->setObjectName("osiagniecia_przycisk");
        osiagniecia_przycisk->setGeometry(QRect(110, 110, 121, 29));
        formLayoutWidget = new QWidget(groupBox_3);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 150, 267, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        zmiana_trybu = new QComboBox(formLayoutWidget);
        zmiana_trybu->addItem(QString());
        zmiana_trybu->addItem(QString());
        zmiana_trybu->setObjectName("zmiana_trybu");

        verticalLayout_3->addWidget(zmiana_trybu);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        zmiana_led = new QComboBox(formLayoutWidget);
        zmiana_led->addItem(QString());
        zmiana_led->addItem(QString());
        zmiana_led->addItem(QString());
        zmiana_led->addItem(QString());
        zmiana_led->setObjectName("zmiana_led");

        verticalLayout_2->addWidget(zmiana_led);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);

        wyswietlacz = new QGraphicsView(groupBox_3);
        wyswietlacz->setObjectName("wyswietlacz");
        wyswietlacz->setGeometry(QRect(40, 500, 231, 131));

        gridLayout->addWidget(groupBox_3, 0, 0, 2, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        label_pic = new QLabel(groupBox_4);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(520, 60, 161, 291));
        label_pic->setScaledContents(false);
        label_pic->setWordWrap(false);
        horizontalLayoutWidget_4 = new QWidget(groupBox_4);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(500, 360, 195, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        oddalenie = new QPushButton(horizontalLayoutWidget_4);
        oddalenie->setObjectName("oddalenie");

        horizontalLayout_4->addWidget(oddalenie);

        przyblizenie = new QPushButton(horizontalLayoutWidget_4);
        przyblizenie->setObjectName("przyblizenie");

        horizontalLayout_4->addWidget(przyblizenie);

        label_pic2 = new QLabel(groupBox_4);
        label_pic2->setObjectName("label_pic2");
        label_pic2->setGeometry(QRect(60, 110, 291, 201));
        Front_Wave = new QPushButton(groupBox_4);
        Front_Wave->setObjectName("Front_Wave");
        Front_Wave->setGeometry(QRect(150, 360, 93, 29));

        gridLayout->addWidget(groupBox_4, 0, 1, 1, 1);

        gridLayout->setRowStretch(0, 3);
        gridLayout->setRowStretch(1, 2);
        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 5);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(dial_4, &QDial::valueChanged, MainWindow, qOverload<>(&QMainWindow::update));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Knobs", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Dial 1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Dial 2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Dial 3", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Dial 4", nullptr));
        przycisk_pok1->setItemText(0, QCoreApplication::translate("MainWindow", "mute sound", nullptr));
        przycisk_pok1->setItemText(1, QCoreApplication::translate("MainWindow", "mute microphone", nullptr));
        przycisk_pok1->setItemText(2, QCoreApplication::translate("MainWindow", "create new desktop", nullptr));
        przycisk_pok1->setItemText(3, QCoreApplication::translate("MainWindow", "accept changes", nullptr));

        przycisk_pok2->setItemText(0, QCoreApplication::translate("MainWindow", "mute microphone", nullptr));
        przycisk_pok2->setItemText(1, QCoreApplication::translate("MainWindow", "mute sound", nullptr));
        przycisk_pok2->setItemText(2, QCoreApplication::translate("MainWindow", "create new desktop", nullptr));
        przycisk_pok2->setItemText(3, QCoreApplication::translate("MainWindow", "accept changes", nullptr));

        przycisk_pok3->setItemText(0, QCoreApplication::translate("MainWindow", "create new desktop", nullptr));
        przycisk_pok3->setItemText(1, QCoreApplication::translate("MainWindow", "mute sound", nullptr));
        przycisk_pok3->setItemText(2, QCoreApplication::translate("MainWindow", "mute microphone", nullptr));
        przycisk_pok3->setItemText(3, QCoreApplication::translate("MainWindow", "accept changes", nullptr));

        przycisk_pok4->setItemText(0, QCoreApplication::translate("MainWindow", "accept changes", nullptr));
        przycisk_pok4->setItemText(1, QCoreApplication::translate("MainWindow", "mute sound", nullptr));
        przycisk_pok4->setItemText(2, QCoreApplication::translate("MainWindow", "mute microphone", nullptr));
        przycisk_pok4->setItemText(3, QCoreApplication::translate("MainWindow", "create new desktop", nullptr));

        pok1->setItemText(0, QCoreApplication::translate("MainWindow", "change volume", nullptr));
        pok1->setItemText(1, QCoreApplication::translate("MainWindow", "change web window", nullptr));
        pok1->setItemText(2, QCoreApplication::translate("MainWindow", "change desktop", nullptr));
        pok1->setItemText(3, QCoreApplication::translate("MainWindow", "change app focus", nullptr));

        pok2->setItemText(0, QCoreApplication::translate("MainWindow", "change web window", nullptr));
        pok2->setItemText(1, QCoreApplication::translate("MainWindow", "change volume", nullptr));
        pok2->setItemText(2, QCoreApplication::translate("MainWindow", "change desktop", nullptr));
        pok2->setItemText(3, QCoreApplication::translate("MainWindow", "change app focus", nullptr));

        pok3->setItemText(0, QCoreApplication::translate("MainWindow", "change desktop", nullptr));
        pok3->setItemText(1, QCoreApplication::translate("MainWindow", "change volume", nullptr));
        pok3->setItemText(2, QCoreApplication::translate("MainWindow", "change web window", nullptr));
        pok3->setItemText(3, QCoreApplication::translate("MainWindow", "change app focus", nullptr));

        pok4->setItemText(0, QCoreApplication::translate("MainWindow", "change app focus", nullptr));
        pok4->setItemText(1, QCoreApplication::translate("MainWindow", "change volume", nullptr));
        pok4->setItemText(2, QCoreApplication::translate("MainWindow", "change web window", nullptr));
        pok4->setItemText(3, QCoreApplication::translate("MainWindow", "change app focus", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Total knob turn count:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Total click count:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Total distance knob have travelled:", nullptr));
        total_knob_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        total_click_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        distance->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Wykres->setText(QCoreApplication::translate("MainWindow", "Chart", nullptr));
        osiagniecia_przycisk->setText(QCoreApplication::translate("MainWindow", "Achievements", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Mode selection:   ", nullptr));
        zmiana_trybu->setItemText(0, QCoreApplication::translate("MainWindow", "Mode 1", nullptr));
        zmiana_trybu->setItemText(1, QCoreApplication::translate("MainWindow", "Mode 2", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "RGB Mode:", nullptr));
        zmiana_led->setItemText(0, QCoreApplication::translate("MainWindow", "Light Show", nullptr));
        zmiana_led->setItemText(1, QCoreApplication::translate("MainWindow", "Colour Step", nullptr));
        zmiana_led->setItemText(2, QCoreApplication::translate("MainWindow", "R-G-B Transition", nullptr));
        zmiana_led->setItemText(3, QCoreApplication::translate("MainWindow", "Breathing", nullptr));

        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Animations", nullptr));
        label_pic->setText(QCoreApplication::translate("MainWindow", "gora/dol", nullptr));
        oddalenie->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        przyblizenie->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_pic2->setText(QCoreApplication::translate("MainWindow", "machanie", nullptr));
        Front_Wave->setText(QCoreApplication::translate("MainWindow", "Front Wave", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
