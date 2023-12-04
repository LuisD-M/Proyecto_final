#ifndef START_H
#define START_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <string>

#include "mainwindow.h"

using namespace std;


namespace Ui {
class start;
}

class start : public QMainWindow
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();

private slots:
    void on_pushButton_clicked();

    void on_DifiMedio_clicked();

    void on_DifiEasy_clicked();

    void on_DifiHard_clicked();

    void on_Rick_clicked();

    void on_Morty_clicked();


private:
    Ui::start *ui;            // Variable para la ventana que se muestra primero
    QMainWindow *gw;

    int dificultad=10000000;
    short selheroe=0;
    string name;
};

#endif // START_H
