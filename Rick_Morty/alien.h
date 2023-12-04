#ifndef ALIEN_H
#define ALIEN_H

#include <QObject>
#include "enemy1.h"

/*
 * La clase alien es el enemigo del nivel 1
*/

class alien : public enemy1 //Se hereda de la clase enemy
{
    Q_OBJECT
private:


public:
    explicit alien(QObject *parent = nullptr); // constructor

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // metodo que pinta la instancia en pantalla

signals:
};

#endif // HEROE2_H
