#ifndef ESCOLTA_H
#define ESCOLTA_H

#include <QObject>
#include "enemy1.h"

/*
 * clase escolta son los enemigos del nivel 2
*/

class escolta : public enemy1
{
    Q_OBJECT
private:


public:
    explicit escolta(QObject *parent = nullptr); // constructor

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // metodo que pinta en pantalla la instancia

signals:
};

#endif // HEROE2_H
