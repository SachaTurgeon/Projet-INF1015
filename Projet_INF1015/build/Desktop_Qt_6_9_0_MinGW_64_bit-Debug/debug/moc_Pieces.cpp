/****************************************************************************
** Meta object code from reading C++ file 'Pieces.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Pieces.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Pieces.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
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
struct qt_meta_tag_ZN5PieceE_t {};
} // unnamed namespace

template <> constexpr inline auto Piece::qt_create_metaobjectdata<qt_meta_tag_ZN5PieceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Piece",
        "pieceRemove",
        "",
        "Piece*",
        "piece",
        "pieceSet",
        "std::pair<int,int>",
        "newPosition",
        "oldPosition",
        "hasMoved",
        "requestPieceOnSquare",
        "row",
        "col",
        "changeTurn",
        "getPieceOnSquare"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'pieceRemove'
        QtMocHelpers::SignalData<void(Piece *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'pieceSet'
        QtMocHelpers::SignalData<void(Piece *, std::pair<int,int>, std::pair<int,int>, bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 6, 7 }, { 0x80000000 | 6, 8 }, { QMetaType::Bool, 9 },
        }}),
        // Signal 'requestPieceOnSquare'
        QtMocHelpers::SignalData<void(int, int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'changeTurn'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'getPieceOnSquare'
        QtMocHelpers::SlotData<void(Piece *)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Piece, qt_meta_tag_ZN5PieceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Piece::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5PieceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5PieceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5PieceE_t>.metaTypes,
    nullptr
} };

void Piece::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Piece *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->pieceRemove((*reinterpret_cast< std::add_pointer_t<Piece*>>(_a[1]))); break;
        case 1: _t->pieceSet((*reinterpret_cast< std::add_pointer_t<Piece*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::pair<int,int>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::pair<int,int>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 2: _t->requestPieceOnSquare((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->changeTurn(); break;
        case 4: _t->getPieceOnSquare((*reinterpret_cast< std::add_pointer_t<Piece*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Piece* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Piece* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Piece* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Piece::*)(Piece * )>(_a, &Piece::pieceRemove, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Piece::*)(Piece * , std::pair<int,int> , std::pair<int,int> , bool )>(_a, &Piece::pieceSet, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Piece::*)(int , int )>(_a, &Piece::requestPieceOnSquare, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Piece::*)()>(_a, &Piece::changeTurn, 3))
            return;
    }
}

const QMetaObject *Piece::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Piece::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5PieceE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Piece::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Piece::pieceRemove(Piece * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void Piece::pieceSet(Piece * _t1, std::pair<int,int> _t2, std::pair<int,int> _t3, bool _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 2
void Piece::requestPieceOnSquare(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void Piece::changeTurn()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
namespace {
struct qt_meta_tag_ZN4KingE_t {};
} // unnamed namespace

template <> constexpr inline auto King::qt_create_metaobjectdata<qt_meta_tag_ZN4KingE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "King",
        "kingAdded",
        "",
        "kingDeleted"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'kingAdded'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'kingDeleted'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<King, qt_meta_tag_ZN4KingE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject King::staticMetaObject = { {
    QMetaObject::SuperData::link<Piece::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4KingE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4KingE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN4KingE_t>.metaTypes,
    nullptr
} };

void King::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<King *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->kingAdded(); break;
        case 1: _t->kingDeleted(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (King::*)()>(_a, &King::kingAdded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (King::*)()>(_a, &King::kingDeleted, 1))
            return;
    }
}

const QMetaObject *King::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *King::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4KingE_t>.strings))
        return static_cast<void*>(this);
    return Piece::qt_metacast(_clname);
}

int King::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Piece::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void King::kingAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void King::kingDeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
