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
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName(QString::fromUtf8("start"));
        start->resize(800, 600);
        centralwidget = new QWidget(start);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 80, 121, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 180, 80, 24));
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
        pushButton_2->setText(QCoreApplication::translate("start", "DIFICULTAD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
