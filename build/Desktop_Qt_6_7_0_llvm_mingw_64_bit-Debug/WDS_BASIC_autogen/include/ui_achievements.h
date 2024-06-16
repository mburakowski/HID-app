/********************************************************************************
** Form generated from reading UI file 'achievements.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACHIEVEMENTS_H
#define UI_ACHIEVEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Achievements
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_cup;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QPushButton *Reset;

    void setupUi(QDialog *Achievements)
    {
        if (Achievements->objectName().isEmpty())
            Achievements->setObjectName("Achievements");
        Achievements->resize(463, 363);
        buttonBox = new QDialogButtonBox(Achievements);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(100, 310, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_cup = new QLabel(Achievements);
        label_cup->setObjectName("label_cup");
        label_cup->setGeometry(QRect(20, 90, 401, 121));
        horizontalLayoutWidget = new QWidget(Achievements);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 240, 364, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        progressBar_3 = new QProgressBar(horizontalLayoutWidget);
        progressBar_3->setObjectName("progressBar_3");
        progressBar_3->setValue(24);

        horizontalLayout->addWidget(progressBar_3);

        progressBar_2 = new QProgressBar(horizontalLayoutWidget);
        progressBar_2->setObjectName("progressBar_2");
        progressBar_2->setValue(24);

        horizontalLayout->addWidget(progressBar_2);

        progressBar = new QProgressBar(horizontalLayoutWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        horizontalLayoutWidget_2 = new QWidget(Achievements);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(19, 10, 351, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        Reset = new QPushButton(Achievements);
        Reset->setObjectName("Reset");
        Reset->setGeometry(QRect(10, 310, 93, 29));

        retranslateUi(Achievements);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Achievements, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Achievements, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Achievements);
    } // setupUi

    void retranslateUi(QDialog *Achievements)
    {
        Achievements->setWindowTitle(QCoreApplication::translate("Achievements", "Dialog", nullptr));
        label_cup->setText(QCoreApplication::translate("Achievements", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Achievements", "Turn 10 times:", nullptr));
        label_2->setText(QCoreApplication::translate("Achievements", "Turn 100 times:", nullptr));
        label->setText(QCoreApplication::translate("Achievements", "Turn 1000 times:", nullptr));
        Reset->setText(QCoreApplication::translate("Achievements", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Achievements: public Ui_Achievements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACHIEVEMENTS_H
