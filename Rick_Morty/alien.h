#ifndef ALIEN_H
#define ALIEN_H

#include <QObject>
#include "enemy1.h"

class alien : public enemy1 //Se hereda de la clase heroe
{
    Q_OBJECT
private:


public:
    explicit alien(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
};

#endif // HEROE2_H
