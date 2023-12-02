#ifndef MORTY_H
#define MORTY_H

#include <QObject>
#include "heroe.h"

class morty : public heroe                          //Se hereda de la clase heroe
{
    Q_OBJECT
private:


public:
    explicit morty(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
};

#endif // HEROE2_H
