/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
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
    QFormLayout *formLayout_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QComboBox *zmiana_trybu;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QComboBox *zmiana_led;
    QPushButton *Wykres;
    QPushButton *osiagniecia_przycisk;
    QVBoxLayout *verticalLayout_4;
    QLabel *total_knob_count;
    QLabel *total_click_count;
    QLabel *distance;
    QPushButton *languageButton;
    QGraphicsView *wyswietlacz;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *przycisk_pok1;
    QComboBox *przycisk_pok2;
    QComboBox *przycisk_pok3;
    QComboBox *przycisk_pok4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QDial *dial_4;
    QDial *dial_2;
    QDial *dial_3;
    QDial *dial;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_4;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *pok1;
    QComboBox *pok2;
    QComboBox *pok3;
    QComboBox *pok4;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QLabel *label_pic2;
    QLabel *label_pic;
    QPushButton *Front_Wave;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *oddalenie;
    QPushButton *przyblizenie;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1120, 770);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout_2 = new QFormLayout(centralwidget);
        formLayout_2->setObjectName("formLayout_2");
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName("gridLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        zmiana_trybu = new QComboBox(groupBox_3);
        zmiana_trybu->addItem(QString());
        zmiana_trybu->addItem(QString());
        zmiana_trybu->setObjectName("zmiana_trybu");

        verticalLayout_3->addWidget(zmiana_trybu);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        zmiana_led = new QComboBox(groupBox_3);
        zmiana_led->addItem(QString());
        zmiana_led->addItem(QString());
        zmiana_led->addItem(QString());
        zmiana_led->addItem(QString());
        zmiana_led->setObjectName("zmiana_led");

        verticalLayout_2->addWidget(zmiana_led);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);


        gridLayout_2->addLayout(formLayout, 2, 0, 1, 2);

        Wykres = new QPushButton(groupBox_3);
        Wykres->setObjectName("Wykres");

        gridLayout_2->addWidget(Wykres, 1, 0, 1, 1);

        osiagniecia_przycisk = new QPushButton(groupBox_3);
        osiagniecia_przycisk->setObjectName("osiagniecia_przycisk");

        gridLayout_2->addWidget(osiagniecia_przycisk, 1, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        total_knob_count = new QLabel(groupBox_3);
        total_knob_count->setObjectName("total_knob_count");

        verticalLayout_4->addWidget(total_knob_count);

        total_click_count = new QLabel(groupBox_3);
        total_click_count->setObjectName("total_click_count");

        verticalLayout_4->addWidget(total_click_count);

        distance = new QLabel(groupBox_3);
        distance->setObjectName("distance");

        verticalLayout_4->addWidget(distance);


        gridLayout_2->addLayout(verticalLayout_4, 0, 2, 1, 1);

        languageButton = new QPushButton(groupBox_3);
        languageButton->setObjectName("languageButton");

        gridLayout_2->addWidget(languageButton, 3, 0, 1, 1);

        wyswietlacz = new QGraphicsView(groupBox_3);
        wyswietlacz->setObjectName("wyswietlacz");

        gridLayout_2->addWidget(wyswietlacz, 4, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(groupBox_3);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 2);


        formLayout_2->setWidget(0, QFormLayout::LabelRole, groupBox_3);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        przycisk_pok1 = new QComboBox(groupBox);
        przycisk_pok1->addItem(QString());
        przycisk_pok1->addItem(QString());
        przycisk_pok1->addItem(QString());
        przycisk_pok1->addItem(QString());
        przycisk_pok1->setObjectName("przycisk_pok1");

        horizontalLayout_6->addWidget(przycisk_pok1);

        przycisk_pok2 = new QComboBox(groupBox);
        przycisk_pok2->addItem(QString());
        przycisk_pok2->addItem(QString());
        przycisk_pok2->addItem(QString());
        przycisk_pok2->addItem(QString());
        przycisk_pok2->setObjectName("przycisk_pok2");

        horizontalLayout_6->addWidget(przycisk_pok2);

        przycisk_pok3 = new QComboBox(groupBox);
        przycisk_pok3->addItem(QString());
        przycisk_pok3->addItem(QString());
        przycisk_pok3->addItem(QString());
        przycisk_pok3->addItem(QString());
        przycisk_pok3->setObjectName("przycisk_pok3");

        horizontalLayout_6->addWidget(przycisk_pok3);

        przycisk_pok4 = new QComboBox(groupBox);
        przycisk_pok4->addItem(QString());
        przycisk_pok4->addItem(QString());
        przycisk_pok4->addItem(QString());
        przycisk_pok4->addItem(QString());
        przycisk_pok4->setObjectName("przycisk_pok4");

        horizontalLayout_6->addWidget(przycisk_pok4);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        dial_4 = new QDial(groupBox);
        dial_4->setObjectName("dial_4");
        dial_4->setWrapping(false);

        horizontalLayout->addWidget(dial_4);

        dial_2 = new QDial(groupBox);
        dial_2->setObjectName("dial_2");

        horizontalLayout->addWidget(dial_2);

        dial_3 = new QDial(groupBox);
        dial_3->setObjectName("dial_3");

        horizontalLayout->addWidget(dial_3);

        dial = new QDial(groupBox);
        dial->setObjectName("dial");

        horizontalLayout->addWidget(dial);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        progressBar_3 = new QProgressBar(groupBox);
        progressBar_3->setObjectName("progressBar_3");
        progressBar_3->setValue(24);

        horizontalLayout_2->addWidget(progressBar_3);

        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);

        progressBar_2 = new QProgressBar(groupBox);
        progressBar_2->setObjectName("progressBar_2");
        progressBar_2->setValue(24);

        horizontalLayout_2->addWidget(progressBar_2);

        progressBar_4 = new QProgressBar(groupBox);
        progressBar_4->setObjectName("progressBar_4");
        progressBar_4->setValue(24);

        horizontalLayout_2->addWidget(progressBar_4);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pok1 = new QComboBox(groupBox);
        pok1->addItem(QString());
        pok1->addItem(QString());
        pok1->addItem(QString());
        pok1->addItem(QString());
        pok1->setObjectName("pok1");

        horizontalLayout_5->addWidget(pok1);

        pok2 = new QComboBox(groupBox);
        pok2->addItem(QString());
        pok2->addItem(QString());
        pok2->addItem(QString());
        pok2->addItem(QString());
        pok2->setObjectName("pok2");

        horizontalLayout_5->addWidget(pok2);

        pok3 = new QComboBox(groupBox);
        pok3->addItem(QString());
        pok3->addItem(QString());
        pok3->addItem(QString());
        pok3->addItem(QString());
        pok3->setObjectName("pok3");

        horizontalLayout_5->addWidget(pok3);

        pok4 = new QComboBox(groupBox);
        pok4->addItem(QString());
        pok4->addItem(QString());
        pok4->addItem(QString());
        pok4->addItem(QString());
        pok4->setObjectName("pok4");

        horizontalLayout_5->addWidget(pok4);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);


        formLayout_2->setWidget(1, QFormLayout::FieldRole, groupBox);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName("gridLayout_3");
        label_pic2 = new QLabel(groupBox_4);
        label_pic2->setObjectName("label_pic2");
        label_pic2->setLayoutDirection(Qt::RightToLeft);
        label_pic2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_pic2, 0, 0, 1, 1);

        label_pic = new QLabel(groupBox_4);
        label_pic->setObjectName("label_pic");
        label_pic->setScaledContents(false);
        label_pic->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_pic->setWordWrap(false);

        gridLayout_3->addWidget(label_pic, 0, 1, 1, 1);

        Front_Wave = new QPushButton(groupBox_4);
        Front_Wave->setObjectName("Front_Wave");

        gridLayout_3->addWidget(Front_Wave, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        oddalenie = new QPushButton(groupBox_4);
        oddalenie->setObjectName("oddalenie");

        horizontalLayout_4->addWidget(oddalenie);

        przyblizenie = new QPushButton(groupBox_4);
        przyblizenie->setObjectName("przyblizenie");

        horizontalLayout_4->addWidget(przyblizenie);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 1, 1, 1);


        formLayout_2->setWidget(0, QFormLayout::FieldRole, groupBox_4);

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
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Mode selection:   ", nullptr));
        zmiana_trybu->setItemText(0, QCoreApplication::translate("MainWindow", "Mode 1", nullptr));
        zmiana_trybu->setItemText(1, QCoreApplication::translate("MainWindow", "Mode 2", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "RGB Mode:", nullptr));
        zmiana_led->setItemText(0, QCoreApplication::translate("MainWindow", "Light Show", nullptr));
        zmiana_led->setItemText(1, QCoreApplication::translate("MainWindow", "Colour Step", nullptr));
        zmiana_led->setItemText(2, QCoreApplication::translate("MainWindow", "R-G-B Transition", nullptr));
        zmiana_led->setItemText(3, QCoreApplication::translate("MainWindow", "Breathing", nullptr));

        Wykres->setText(QCoreApplication::translate("MainWindow", "Chart", nullptr));
        osiagniecia_przycisk->setText(QCoreApplication::translate("MainWindow", "Achievements", nullptr));
        total_knob_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        total_click_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        distance->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        languageButton->setText(QCoreApplication::translate("MainWindow", "Change Language", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Total knob turn count:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Total click count:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Total distance knob have travelled:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Knobs", nullptr));
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

        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Dial 1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Dial 2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Dial 3", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Dial 4", nullptr));
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
        pok4->setItemText(3, QCoreApplication::translate("MainWindow", "change desktop", nullptr));

        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Animations", nullptr));
        label_pic2->setText(QString());
        label_pic->setText(QString());
        Front_Wave->setText(QCoreApplication::translate("MainWindow", "Front Wave", nullptr));
        oddalenie->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        przyblizenie->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
