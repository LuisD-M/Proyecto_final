/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *DifiMedio;
    QPushButton *DifiEasy;
    QPushButton *DifiHard;
    QLabel *label;
    QPushButton *Rick;
    QPushButton *Morty;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName(QString::fromUtf8("start"));
        start->resize(800, 400);
        centralwidget = new QWidget(start);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 300, 121, 41));
        DifiMedio = new QPushButton(centralwidget);
        DifiMedio->setObjectName(QString::fromUtf8("DifiMedio"));
        DifiMedio->setGeometry(QRect(40, 120, 121, 31));
        DifiEasy = new QPushButton(centralwidget);
        DifiEasy->setObjectName(QString::fromUtf8("DifiEasy"));
        DifiEasy->setGeometry(QRect(40, 70, 121, 31));
        DifiHard = new QPushButton(centralwidget);
        DifiHard->setObjectName(QString::fromUtf8("DifiHard"));
        DifiHard->setGeometry(QRect(40, 170, 121, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 101, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        Rick = new QPushButton(centralwidget);
        Rick->setObjectName(QString::fromUtf8("Rick"));
        Rick->setGeometry(QRect(290, 240, 141, 41));
        Morty = new QPushButton(centralwidget);
        Morty->setObjectName(QString::fromUtf8("Morty"));
        Morty->setGeometry(QRect(540, 240, 141, 41));
        start->setCentralWidget(centralwidget);
        menubar = new QMenuBar(start);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        start->setMenuBar(menubar);
        statusbar = new QStatusBar(start);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        start->setStatusBar(statusbar);

        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QMainWindow *start)
    {
        start->setWindowTitle(QCoreApplication::translate("start", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("start", "JUGAR", nullptr));
        DifiMedio->setText(QCoreApplication::translate("start", "MEDIUM", nullptr));
        DifiEasy->setText(QCoreApplication::translate("start", "EASY", nullptr));
        DifiHard->setText(QCoreApplication::translate("start", "HARD", nullptr));
        label->setText(QCoreApplication::translate("start", "DIFICULTAD", nullptr));
        Rick->setText(QCoreApplication::translate("start", "RICK", nullptr));
        Morty->setText(QCoreApplication::translate("start", "MORTY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
