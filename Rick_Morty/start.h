#ifndef START_H
#define START_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "mainwindow.h"

/*
 * clase start es la ventana de inicio donde se escogen las condiciones iniciales del juego
*/

namespace Ui {
class start;
}

class start : public QMainWindow
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr); // constructor
    ~start(); // destructor

private slots:
    // manejan que se hace cuando se presionan los distintos botones de la pantalla
    void on_pushButton_clicked();

    void on_DifiMedio_clicked();

    void on_DifiEasy_clicked();

    void on_DifiHard_clicked();

    void on_Rick_clicked();

    void on_Morty_clicked();

private:
    Ui::start *ui; // contiene la ventana
    QMainWindow *gw; // contiene la siguiente ventana a mostrar

    int dificultad=50; // dificultad del juego
    short selheroe=0; // eleccion del heroe
};

#endif // START_H
