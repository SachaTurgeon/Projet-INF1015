/********************************************************************************
** Form generated from reading UI file 'projetjeuxechecs.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJETJEUXECHECS_H
#define UI_PROJETJEUXECHECS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjetJeuxEchecs
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProjetJeuxEchecs)
    {
        if (ProjetJeuxEchecs->objectName().isEmpty())
            ProjetJeuxEchecs->setObjectName("ProjetJeuxEchecs");
        ProjetJeuxEchecs->resize(800, 600);
        centralwidget = new QWidget(ProjetJeuxEchecs);
        centralwidget->setObjectName("centralwidget");
        ProjetJeuxEchecs->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProjetJeuxEchecs);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        ProjetJeuxEchecs->setMenuBar(menubar);
        statusbar = new QStatusBar(ProjetJeuxEchecs);
        statusbar->setObjectName("statusbar");
        ProjetJeuxEchecs->setStatusBar(statusbar);

        retranslateUi(ProjetJeuxEchecs);

        QMetaObject::connectSlotsByName(ProjetJeuxEchecs);
    } // setupUi

    void retranslateUi(QMainWindow *ProjetJeuxEchecs)
    {
        ProjetJeuxEchecs->setWindowTitle(QCoreApplication::translate("ProjetJeuxEchecs", "ProjetJeuxEchecs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjetJeuxEchecs: public Ui_ProjetJeuxEchecs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETJEUXECHECS_H
