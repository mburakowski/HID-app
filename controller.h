#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <endpointvolume.h>
#include <QObject>

/**
 * @brief Klasa Controller odpowiedzialna za kontrolę głośności i jasności systemu.
 *
 * Klasa dziedziczy po QObject i zawiera metody do kontrolowania głośności oraz jasności systemu.
 */
class Controller : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy Controller.
     *
     * @param parent Wskaźnik na obiekt nadrzędny (rodzica) kontrolera.
     */
    explicit Controller(QObject *parent = nullptr);

    /**
     * @brief Ustawia głośność systemu na podaną wartość.
     *
     * @param volume Poziom głośności do ustawienia.
     */
    void setSystemVolume(int volume);

    /**
     * @brief Pobiera aktualny poziom głośności systemu.
     *
     * @return Aktualny poziom głośności systemu.
     */
    int getSystemVolume();

    /**
     * @brief Przełącza stan wyciszenia systemu.
     */
    void toggleMute();

    /**
     * @brief Przełącza stan wyciszenia mikrofonu.
     */
    void toggleMicrophoneMute();

    /**
     * @brief Tworzy nowy wirtualny pulpit
     */
    void createNewDesktop();

    /**
     * @brief Akceptuje zmiany
     */
    void accChanges();


public slots:
    /**
     * @brief Slot wywoływany w przypadku zmiany głośności systemu.
     *
     * @param volumeLevel Nowy poziom głośności.
     */
    void volumeChanged(int volumeLevel);

    /**
     * @brief Slot wywoływany w przypadku zmiany jasności systemu.
     *
     * @param brightnessLevel Nowy poziom jasności.
     */
    void brightnessChanged(int brightnessLevel);

private:
    IAudioEndpointVolume *m_pVolume; /**< Wskaźnik na obiekt interfejsu głośności systemu. */
};

#endif // CONTROLLER_H

