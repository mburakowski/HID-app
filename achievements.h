/**
 * @file achievements.h
 * @brief Definicja klasy Achievements, która obsługuje okno z osiągnięciami użytkownika.
 */
#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Achievements;
}

/**
 * @class Achievements
 * @brief Klasa obsługująca dialog osiągnięć.
 *
 * Klasa Achievements odpowiada za wyświetlanie i aktualizację osiągnięć użytkownika
 * w postaci graficznych pasków postępu.
 */


class Achievements : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy Achievements.
     * @param parent Wskaźnik na rodzica (domyślnie nullptr).
     */
    explicit Achievements(QWidget *parent = nullptr);
    /**
     * @brief Destruktor klasy Achievements.
     */
    ~Achievements();
    /**
     * @brief Całkowita liczba przekręceń wykonanych przez użytkownika.
     */
    int totalTurns;

public slots:
    /**
     * @brief Aktualizuje paski postępu na podstawie całkowitej liczby przekręceń.
     * @param totalTurns Całkowita liczba przekręceń do wyświetlenia.
     */
    void updateProgressBars(int totalTurns);
    /**
     * @brief Zapisuje ustawienia dotyczące osiągnięć użytkownika.
     */
    void saveSettings();



private slots:
    /**
     * @brief Slot obsługujący kliknięcie przycisku resetowania osiągnięć.
     *
     * Resetuje wszystkie postępy i zapisuje zmiany.
     */
    void on_Reset_clicked();

private:
    /**
     * @brief Wskaźnik na interfejs użytkownika klasy Achievements.
     */
    Ui::Achievements *ui;
};

#endif // ACHIEVEMENTS_H
