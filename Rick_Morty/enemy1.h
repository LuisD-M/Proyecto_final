#ifndef ENEMY1_H
#define ENEMY1_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>
#include <cmath>

#include "heroe.h"

/*
 * clase padre de los enemigos
*/

class enemy1 : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    float velocidad = 0.1; // define la velocidad a la que se mueven los enemigos

protected:
    QPixmap *pixmap1_2; // imagen de los enemigos
    float ancho, alto; // dimensiones de los enemigos

public:
    explicit enemy1(QObject *parent = nullptr); // constructor
    ~enemy1(); // destructor

    QRectF boundingRect() const; // metodo que define las dimensiones del rectangulo que recubre la imagen
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // metodo que pinta en pantalla la instancia

    void moveBy(heroe *heroeptr); // metodo que mueve a los enemigos en direccion al heroe
    QPointF getPos() const; // metodo que obtiene la posicion en pantalla del enemigo

};

#endif // ENEMY1_H


