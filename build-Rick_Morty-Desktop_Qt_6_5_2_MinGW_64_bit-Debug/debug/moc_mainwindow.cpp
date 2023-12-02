/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Rick_Morty/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
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
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "obstacleMove",
    "",
    "generateObstacles",
    "bulletMove",
    "enemyGeneration",
    "enemyBulletGeneration",
    "colission",
    "cambioEscena",
    "movimientoPersonaje",
    "on_progressBar_valueChanged",
    "value",
    "on_progressBar_Puntuacion_valueChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[11];
    char stringdata5[16];
    char stringdata6[22];
    char stringdata7[10];
    char stringdata8[13];
    char stringdata9[20];
    char stringdata10[28];
    char stringdata11[6];
    char stringdata12[39];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "obstacleMove"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 17),  // "generateObstacles"
        QT_MOC_LITERAL(43, 10),  // "bulletMove"
        QT_MOC_LITERAL(54, 15),  // "enemyGeneration"
        QT_MOC_LITERAL(70, 21),  // "enemyBulletGeneration"
        QT_MOC_LITERAL(92, 9),  // "colission"
        QT_MOC_LITERAL(102, 12),  // "cambioEscena"
        QT_MOC_LITERAL(115, 19),  // "movimientoPersonaje"
        QT_MOC_LITERAL(135, 27),  // "on_progressBar_valueChanged"
        QT_MOC_LITERAL(163, 5),  // "value"
        QT_MOC_LITERAL(169, 38)   // "on_progressBar_Puntuacion_val..."
    },
    "MainWindow",
    "obstacleMove",
    "",
    "generateObstacles",
    "bulletMove",
    "enemyGeneration",
    "enemyBulletGeneration",
    "colission",
    "cambioEscena",
    "movimientoPersonaje",
    "on_progressBar_valueChanged",
    "value",
    "on_progressBar_Puntuacion_valueChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    1,   82,    2, 0x08,    9 /* Private */,
      12,    1,   85,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

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
        // method 'obstacleMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generateObstacles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bulletMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enemyGeneration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enemyBulletGeneration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'colission'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cambioEscena'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'movimientoPersonaje'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_progressBar_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_progressBar_Puntuacion_valueChanged'
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
        case 0: _t->obstacleMove(); break;
        case 1: _t->generateObstacles(); break;
        case 2: _t->bulletMove(); break;
        case 3: _t->enemyGeneration(); break;
        case 4: _t->enemyBulletGeneration(); break;
        case 5: _t->colission(); break;
        case 6: _t->cambioEscena(); break;
        case 7: _t->movimientoPersonaje(); break;
        case 8: _t->on_progressBar_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_progressBar_Puntuacion_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
