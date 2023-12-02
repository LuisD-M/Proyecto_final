/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QPushButton *Rick;
    QPushButton *Morty;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName("start");
        start->resize(803, 421);
        centralwidget = new QWidget(start);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(670, 370, 121, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        pushButton->setFont(font);
        DifiMedio = new QPushButton(centralwidget);
        DifiMedio->setObjectName("DifiMedio");
        DifiMedio->setGeometry(QRect(20, 190, 121, 31));
        DifiMedio->setFont(font);
        DifiEasy = new QPushButton(centralwidget);
        DifiEasy->setObjectName("DifiEasy");
        DifiEasy->setGeometry(QRect(20, 150, 121, 31));
        DifiEasy->setFont(font);
        DifiHard = new QPushButton(centralwidget);
        DifiHard->setObjectName("DifiHard");
        DifiHard->setGeometry(QRect(20, 230, 121, 31));
        DifiHard->setFont(font);
        Rick = new QPushButton(centralwidget);
        Rick->setObjectName("Rick");
        Rick->setGeometry(QRect(200, 370, 141, 31));
        Rick->setFont(font);
        Morty = new QPushButton(centralwidget);
        Morty->setObjectName("Morty");
        Morty->setGeometry(QRect(370, 370, 141, 31));
        Morty->setFont(font);
        start->setCentralWidget(centralwidget);
        menubar = new QMenuBar(start);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 803, 21));
        start->setMenuBar(menubar);
        statusbar = new QStatusBar(start);
        statusbar->setObjectName("statusbar");
        start->setStatusBar(statusbar);

        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QMainWindow *start)
    {
        start->setWindowTitle(QCoreApplication::translate("start", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("start", "START", nullptr));
        DifiMedio->setText(QCoreApplication::translate("start", "MEDIUM", nullptr));
        DifiEasy->setText(QCoreApplication::translate("start", "EASY", nullptr));
        DifiHard->setText(QCoreApplication::translate("start", "HARD", nullptr));
        Rick->setText(QCoreApplication::translate("start", "RICK", nullptr));
#if QT_CONFIG(accessibility)
        Morty->setAccessibleDescription(QCoreApplication::translate("start", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(accessibility)
        Morty->setText(QCoreApplication::translate("start", "MORTY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
