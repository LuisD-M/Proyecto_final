#ifndef RICK_H
#define RICK_H

#include <QObject>
#include "heroe.h"

class rick : public heroe                          //Se hereda de la clase heroe
{
    Q_OBJECT
private:


public:
    explicit rick(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
};

#endif // HEROE2_H
