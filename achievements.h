#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Achievements;
}

class Achievements : public QDialog
{
    Q_OBJECT

public:
    explicit Achievements(QWidget *parent = nullptr);
    ~Achievements();
    int totalTurns;

public slots:
    void updateProgressBars(int totalTurns);
    //void updateProgressBars();
    void saveSettings();
    //void onProgressBarValueChanged(int progressBarIndex, int value);


private slots:
    void on_Reset_clicked();

private:
    Ui::Achievements *ui;
};

#endif // ACHIEVEMENTS_H
