#ifndef MORTY_H
#define MORTY_H

#include <QObject>
#include "heroe.h"

/*
 * clase morty el heroe Morty
*/

class morty : public heroe
{
    Q_OBJECT
private:


public:
    explicit morty(QObject *parent = nullptr); // constructor

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // metodo que pinta en pantalla la instancia

signals:
};

#endif // HEROE2_H

