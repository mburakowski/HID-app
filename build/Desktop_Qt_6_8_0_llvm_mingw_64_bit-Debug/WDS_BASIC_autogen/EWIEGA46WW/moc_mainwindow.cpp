/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "changeFocus",
    "",
    "encoderValueChanged",
    "value",
    "serialDataReceived",
    "dialValueChanged",
    "dial2ValueChanged",
    "dial3ValueChanged",
    "dial4ValueChanged",
    "progressBarValueChanged",
    "progressBarIndex",
    "totalTurnsChanged",
    "totalTurns",
    "totalTurnsReset",
    "handleEncoderValue",
    "on_dial_4_valueChanged",
    "on_dial_2_valueChanged",
    "on_dial_3_valueChanged",
    "on_dial_valueChanged",
    "on_pushButton_3_clicked",
    "on_pushButton_2_clicked",
    "on_pushButton_4_clicked",
    "on_pushButton_clicked",
    "updateImageSize",
    "deltaY",
    "on_oddalenie_clicked",
    "on_przyblizenie_clicked",
    "wavingImage",
    "on_Front_Wave_clicked",
    "on_osiagniecia_przycisk_clicked",
    "on_zmiana_trybu_currentIndexChanged",
    "index",
    "readSerialData",
    "on_encoderValueChanged",
    "processEncoderData",
    "data",
    "processTOFData",
    "processSensorData",
    "updateChartValues",
    "values",
    "on_Wykres_clicked",
    "on_someProgressBarValueChanged",
    "updateTotalKnobCountLabel",
    "scaleUI",
    "QWidget*",
    "widget",
    "scale",
    "applyScaling",
    "switchLanguage",
    "on_dialComboBox_1_changed",
    "on_dialComboBox_2_changed",
    "on_dialComboBox_3_changed",
    "on_dialComboBox_4_changed",
    "on_buttonComboBox_1_changed",
    "on_buttonComboBox_2_changed",
    "on_buttonComboBox_3_changed",
    "on_buttonComboBox_4_changed",
    "setVolume",
    "changeWebWindow",
    "changeDesktop",
    "changeAppFocus"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  314,    2, 0x06,    1 /* Public */,
       3,    1,  315,    2, 0x06,    2 /* Public */,
       5,    1,  318,    2, 0x06,    4 /* Public */,
       6,    1,  321,    2, 0x06,    6 /* Public */,
       7,    1,  324,    2, 0x06,    8 /* Public */,
       8,    1,  327,    2, 0x06,   10 /* Public */,
       9,    1,  330,    2, 0x06,   12 /* Public */,
      10,    2,  333,    2, 0x06,   14 /* Public */,
      12,    1,  338,    2, 0x06,   17 /* Public */,
      14,    0,  341,    2, 0x06,   19 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    1,  342,    2, 0x0a,   20 /* Public */,
      16,    1,  345,    2, 0x08,   22 /* Private */,
      17,    1,  348,    2, 0x08,   24 /* Private */,
      18,    1,  351,    2, 0x08,   26 /* Private */,
      19,    1,  354,    2, 0x08,   28 /* Private */,
      20,    0,  357,    2, 0x08,   30 /* Private */,
      21,    0,  358,    2, 0x08,   31 /* Private */,
      22,    0,  359,    2, 0x08,   32 /* Private */,
      23,    0,  360,    2, 0x08,   33 /* Private */,
      24,    1,  361,    2, 0x08,   34 /* Private */,
      26,    0,  364,    2, 0x08,   36 /* Private */,
      27,    0,  365,    2, 0x08,   37 /* Private */,
      28,    0,  366,    2, 0x08,   38 /* Private */,
      29,    0,  367,    2, 0x08,   39 /* Private */,
      30,    0,  368,    2, 0x08,   40 /* Private */,
      31,    1,  369,    2, 0x08,   41 /* Private */,
      33,    0,  372,    2, 0x08,   43 /* Private */,
      34,    1,  373,    2, 0x08,   44 /* Private */,
      35,    1,  376,    2, 0x08,   46 /* Private */,
      37,    1,  379,    2, 0x08,   48 /* Private */,
      38,    1,  382,    2, 0x08,   50 /* Private */,
      39,    2,  385,    2, 0x08,   52 /* Private */,
      41,    0,  390,    2, 0x08,   55 /* Private */,
      42,    2,  391,    2, 0x08,   56 /* Private */,
      43,    1,  396,    2, 0x08,   59 /* Private */,
      44,    2,  399,    2, 0x08,   61 /* Private */,
      48,    0,  404,    2, 0x08,   64 /* Private */,
      49,    0,  405,    2, 0x08,   65 /* Private */,
      50,    1,  406,    2, 0x08,   66 /* Private */,
      51,    1,  409,    2, 0x08,   68 /* Private */,
      52,    1,  412,    2, 0x08,   70 /* Private */,
      53,    1,  415,    2, 0x08,   72 /* Private */,
      54,    1,  418,    2, 0x08,   74 /* Private */,
      55,    1,  421,    2, 0x08,   76 /* Private */,
      56,    1,  424,    2, 0x08,   78 /* Private */,
      57,    1,  427,    2, 0x08,   80 /* Private */,
      58,    1,  430,    2, 0x08,   82 /* Private */,
      59,    1,  433,    2, 0x08,   84 /* Private */,
      60,    1,  436,    2, 0x08,   86 /* Private */,
      61,    1,  439,    2, 0x08,   88 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,    4,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QByteArray,   36,
    QMetaType::Void, QMetaType::QByteArray,   36,
    QMetaType::Void, QMetaType::QByteArray,   36,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,    4,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, 0x80000000 | 45, QMetaType::QReal,   46,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'changeFocus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'encoderValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'serialDataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dialValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dial2ValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dial3ValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dial4ValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'progressBarValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'totalTurnsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'totalTurnsReset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleEncoderValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_dial_4_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_dial_2_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_dial_3_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_dial_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateImageSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_oddalenie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_przyblizenie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wavingImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Front_Wave_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_osiagniecia_przycisk_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zmiana_trybu_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'readSerialData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_encoderValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'processEncoderData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'processTOFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'processSensorData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'updateChartValues'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_Wykres_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_someProgressBarValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateTotalKnobCountLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'scaleUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'applyScaling'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchLanguage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_dialComboBox_1_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_dialComboBox_2_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_dialComboBox_3_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_dialComboBox_4_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_buttonComboBox_1_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_buttonComboBox_2_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_buttonComboBox_3_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_buttonComboBox_4_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'changeWebWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'changeDesktop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'changeAppFocus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeFocus(); break;
        case 1: _t->encoderValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->serialDataReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->dialValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->dial2ValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->dial3ValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->dial4ValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->progressBarValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->totalTurnsChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->totalTurnsReset(); break;
        case 10: _t->handleEncoderValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_dial_4_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->on_dial_2_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_dial_3_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_dial_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->on_pushButton_3_clicked(); break;
        case 16: _t->on_pushButton_2_clicked(); break;
        case 17: _t->on_pushButton_4_clicked(); break;
        case 18: _t->on_pushButton_clicked(); break;
        case 19: _t->updateImageSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->on_oddalenie_clicked(); break;
        case 21: _t->on_przyblizenie_clicked(); break;
        case 22: _t->wavingImage(); break;
        case 23: _t->on_Front_Wave_clicked(); break;
        case 24: _t->on_osiagniecia_przycisk_clicked(); break;
        case 25: _t->on_zmiana_trybu_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->readSerialData(); break;
        case 27: _t->on_encoderValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->processEncoderData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 29: _t->processTOFData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 30: _t->processSensorData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 31: _t->updateChartValues((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 32: _t->on_Wykres_clicked(); break;
        case 33: _t->on_someProgressBarValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 34: _t->updateTotalKnobCountLabel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 35: _t->scaleUI((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 36: _t->applyScaling(); break;
        case 37: _t->switchLanguage(); break;
        case 38: _t->on_dialComboBox_1_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 39: _t->on_dialComboBox_2_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 40: _t->on_dialComboBox_3_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 41: _t->on_dialComboBox_4_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 42: _t->on_buttonComboBox_1_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 43: _t->on_buttonComboBox_2_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 44: _t->on_buttonComboBox_3_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 45: _t->on_buttonComboBox_4_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 46: _t->setVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 47: _t->changeWebWindow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 48: _t->changeDesktop((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 49: _t->changeAppFocus((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::changeFocus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::encoderValueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::serialDataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::dialValueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::dial2ValueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::dial3ValueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::dial4ValueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , int );
            if (_t _q_method = &MainWindow::progressBarValueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::totalTurnsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::totalTurnsReset; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::changeFocus()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::encoderValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::serialDataReceived(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::dialValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::dial2ValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::dial3ValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::dial4ValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::progressBarValueChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::totalTurnsChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::totalTurnsReset()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
