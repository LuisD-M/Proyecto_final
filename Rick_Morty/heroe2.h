#ifndef HEROE2_H
#define HEROE2_H

#include <QObject>
#include "heroe.h"

class heroe2 : public heroe                          //Se hereda de la clase heroe
{
    Q_OBJECT
private:


public:
    explicit heroe2(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
};

#endif // HEROE2_H
