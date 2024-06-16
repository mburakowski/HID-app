#include "achievements.h"
#include "ui_achievements.h"
#include <QSettings>

Achievements::Achievements(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Achievements)
    , totalTurns(0)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/MaciejBurakowski(258/Documents/WDS_BASIC/imgs/cup.jpg");
    ui->label_cup->setPixmap(pix.scaled(350, 900, Qt::KeepAspectRatio));

    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    ui->progressBar_3->setValue(0);

    connect(this, &QDialog::finished, this, &Achievements::saveSettings);
}

Achievements::~Achievements()
{
    delete ui;
}

void Achievements::updateProgressBars(int totalTurns)
{
    this->totalTurns = totalTurns;  // Aktualizacja totalTurns

    int progress1 = qMin((totalTurns * 100) / 10, 100);   // 10 przekręceń = 100%
    int progress2 = qMin((totalTurns * 100) / 100, 100);  // 100 przekręceń = 100%
    int progress3 = qMin((totalTurns * 100) / 1000, 100); // 1000 przekręceń = 100%

    ui->progressBar->setValue(progress1);
    ui->progressBar_2->setValue(progress2);
    ui->progressBar_3->setValue(progress3);
}

void Achievements::saveSettings()
{
    QSettings settings("MACIEKCORP", "WDS_BASIC");
    settings.setValue("totalTurns", totalTurns);
}

void Achievements::on_Reset_clicked()
{
    totalTurns = 0; // Resetuj wartość totalTurns

    // Resetuj wartości pasków postępu
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    ui->progressBar_3->setValue(0);

    saveSettings();  // Zapisz zresetowaną wartość
}

