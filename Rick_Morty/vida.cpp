#include "vida.h"
#include <QFont>

vida::vida(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    punVIDA = 5;
    setPlainText(QString("Vidas: ") + QString::number(punVIDA));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Comic Sans MS",13));
}

void vida::lessVidaN1()
{
    punVIDA--;
    setPlainText(QString("Vidas: ") + QString::number(punVIDA));
}

int vida::getVidaN1()
{
    return punVIDA;
}
