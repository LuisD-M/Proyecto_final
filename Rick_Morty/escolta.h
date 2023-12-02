#ifndef ESCOLTA_H
#define ESCOLTA_H

#include <QObject>
#include "enemy1.h"

class escolta : public enemy1 //Se hereda de la clase heroe
{
    Q_OBJECT
private:


public:
    explicit escolta(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
};

#endif // HEROE2_H
