#include "enemy1.h"
#include <QDebug>

enemy1::enemy1(QObject *parent) : QObject{parent}
{
    pixmap1_2 = nullptr;                     // inicializar puntero de QPixmap
}

enemy1::~enemy1()
{
    delete pixmap1_2;
}

QRectF enemy1::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void enemy1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap1_2,0,0,ancho,alto);
    setScale(0.31);
}

QPointF enemy1::getPos() const
{
    return mapToScene(0,0);
}

void enemy1::moveBy(heroe *heroeptr)
{
    QPointF heroPos = heroeptr->getPos();

    // Calcula la dirección hacia el héroe
    float dx = heroPos.x() - x();
    float dy = heroPos.y() - y();

    float angle = atan(dy/dx);

    if( heroPos.x() < x())
        angle = angle+3.1416;


    // Actualiza la posición del enemigo en la escena

    setPos(x() + velocidad * cos(angle) , y() + velocidad * sin(angle));
}


