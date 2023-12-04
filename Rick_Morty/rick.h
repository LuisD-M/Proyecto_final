#ifndef RICK_H
#define RICK_H

#include <QObject>
#include "heroe.h"

/*
 * clase rick el heroe Rick
*/

class rick : public heroe
{
    Q_OBJECT
private:


public:
    explicit rick(QObject *parent = nullptr); // constructor

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // metodo que pinta en pantalla la instancia

signals:
};

#endif // HEROE2_H
