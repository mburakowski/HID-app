/**
  ******************************************************************************
  * @file           : controller.cpp
  * @brief          : Miejsce tworzenia niektórych funkcji służących do
  *                 kontrolowania urządzeniem.
  *
  ******************************************************************************
  * @attention

  ******************************************************************************
  */


#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "libs/comsuppw.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "libs/dxva2.lib")
#include "controller.h"
#include <QDebug>
#include <Windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <comdef.h>
#include <oleauto.h>
#include "winuser.h"
#include "physicalmonitorenumerationapi.h"
#include "highlevelmonitorconfigurationapi.h"
#include <strsafe.h>
#include <wbemidl.h>
#include <wbemcli.h>
#include <werapi.h>
#include <QKeyEvent>


/**
 * @brief Konstruktor klasy Controller
 * @param parent Wskaźnik na obiekt nadrzędny
 * @details Konstruktor inicjuje interfejsy COM i uzyskuje dostęp do domyślnego urządzenia audio końcowego.
 */
Controller::Controller(QObject *parent) : QObject(parent)
{


    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (SUCCEEDED(hr)) {
        IMMDeviceEnumerator *enumerator;
        hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&enumerator);
        if (SUCCEEDED(hr)) {
            IMMDevice *device;
            hr = enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device);
            if (SUCCEEDED(hr)) {
                hr = device->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&m_pVolume);
                if (!SUCCEEDED(hr)) {
                    qDebug() << "Failed to activate endpoint volume interface";
                }
                device->Release();
            }
            enumerator->Release();
        }
    }

}

/**
 * @brief Funkcja zmieniająca głośność systemu
 * @param value Nowa wartość głośności w skali 0-100
 */
void Controller::volumeChanged(int value) {
    // Przeliczenie wartości z zakresu 0-100 na skalę 0.0-1.0
    float volumeLevel = value / 100.0f;
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (SUCCEEDED(hr)) {
        IMMDeviceEnumerator *enumerator;
        hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&enumerator);
        if (SUCCEEDED(hr)) {
            IMMDevice *device;
            hr = enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device);
            if (SUCCEEDED(hr)) {
                IAudioEndpointVolume *volumeControl;
                hr = device->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&volumeControl);
                if (SUCCEEDED(hr)) {
                    volumeControl->SetMasterVolumeLevelScalar(volumeLevel, NULL);
                    volumeControl->Release();
                }
                device->Release();
            }
            enumerator->Release();
        }
        CoUninitialize();
    }
}

/**
 * @brief Funkcja zmieniająca jasność systemu
 * @param brightnessLevel Nowa wartość jasności w skali 0-100
 * @details Funkcja obsługuje zmianę jasności systemu, jednak implementacja tej funkcji jest jeszcze niedokończona.
 */
void Controller::brightnessChanged(int brightnessLevel) {
    //wróce tu kiedyś
}


/**
 * @brief Funkcja ustawiająca głośność systemu
 * @param volume Nowa wartość głośności w skali 0-100
 */
void Controller::setSystemVolume(int volume)
{
    qDebug() << "Setting system volume to:" << volume; // Dodatkowe debugowanie

    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (SUCCEEDED(hr)) {
        IMMDeviceEnumerator *enumerator;
        hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&enumerator);
        if (SUCCEEDED(hr)) {
            IMMDevice *device;
            hr = enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device);
            if (SUCCEEDED(hr)) {
                IAudioEndpointVolume *volumeControl;
                hr = device->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&volumeControl);
                if (SUCCEEDED(hr)) {
                    float level = volume / 100.0f; // Przeliczenie wartości z zakresu 0-500 na skalę 0.0-1.0
                    volumeControl->SetMasterVolumeLevelScalar(level, NULL);
                    volumeControl->Release();
                }
                device->Release();
            }
            enumerator->Release();
        }
        CoUninitialize();
    }
}


/**
 * @brief Funkcja pobierająca aktualną głośność systemu
 * @return Aktualna głośność systemu w skali 0-100 lub -1 w przypadku błędu
 */
int Controller::getSystemVolume()
{
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (SUCCEEDED(hr)) {
        IMMDeviceEnumerator *enumerator;
        hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&enumerator);
        if (SUCCEEDED(hr)) {
            IMMDevice *device;
            hr = enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device);
            if (SUCCEEDED(hr)) {
                IAudioEndpointVolume *volumeControl;
                hr = device->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&volumeControl);
                if (SUCCEEDED(hr)) {
                    float level;
                    volumeControl->GetMasterVolumeLevelScalar(&level);
                    volumeControl->Release();
                    CoUninitialize();
                    return static_cast<int>(level * 100); // Przeliczenie wartości z zakresu 0.0-1.0 na 0-100
                }
                device->Release();
            }
            enumerator->Release();
        }
        CoUninitialize();
    }
    return -1;
}

/**
 * @brief Funkcja przełączająca wyciszenie systemu
 * @details Funkcja przełącza stan wyciszenia systemu na przeciwny.
 */
void Controller::toggleMute()
{
    if (!m_pVolume) {
        qDebug() << "Volume interface not initialized!";
        return;
    }

    BOOL muteState;
    m_pVolume->GetMute(&muteState);

    m_pVolume->SetMute(!muteState, NULL);
    if (!muteState) {
        qDebug() << "Mute enabled";
    } else {
        qDebug() << "Mute disabled";
    }
}

/**
 * @brief Funkcja przełączająca wyciszenie mikrofonu
 * @details Funkcja przełącza stan wyciszenia mikrofonu na przeciwny.
 */
void Controller::toggleMicrophoneMute() {
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (SUCCEEDED(hr)) {
        IMMDeviceEnumerator* pEnumerator = NULL;
        hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (LPVOID*)&pEnumerator);
        if (SUCCEEDED(hr)) {
            IMMDevice* pDevice = NULL;
            hr = pEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &pDevice);
            if (SUCCEEDED(hr)) {
                IAudioEndpointVolume* pVolume = NULL;
                hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (LPVOID*)&pVolume);
                if (SUCCEEDED(hr)) {
                    BOOL muteState;
                    pVolume->GetMute(&muteState); // Pobierz aktualny stan wyciszenia
                    pVolume->SetMute(!muteState, NULL); // Przełącz stan wyciszenia (jeśli jest wyciszony, to ustaw na nie wyciszony, i odwrotnie)
                    if (!muteState) {
                        qDebug() << "Microphone mute enabled";
                    } else {
                        qDebug() << "Microphone mute disabled";
                    }
                    pVolume->Release();
                }
                pDevice->Release();
            }
            pEnumerator->Release();
        }
        CoUninitialize();
    }
}

/**
 * @brief Funkcja tworząca nowy wirtualny Pulpit
 * @details Funkcja niezbędna do utworzenia wirtualnego pulpitu za pomocą przycisku na urządzeniu
 */
void Controller::createNewDesktop(){
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

/**
 * @brief Funkcja do akceptowania zmian
 * @details Funkcja służy do zatwierdzania zmian za pomocą urządzenia
 */
void Controller::accChanges(){
    keybd_event(VK_RETURN, 0, 0, 0); // Wciśnięcie klawisza Enter
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
}

