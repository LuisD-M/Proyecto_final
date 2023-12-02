#include "balas.h"
#include <cmath>

balas::balas(){}

balas::balas(int velx, int vely, QGraphicsEllipseItem *elip)
{
    this->velx = velx;
    this->vely = vely;
    this->elip = elip;
}

balas::balas(const QPointF &mousePos, const QPointF &heroePos)
{
    elip = new QGraphicsEllipseItem(0,0,ancho,alto);

    elip->setPos(heroePos.x(),heroePos.y());

    float angle = atan((mousePos.y()-elip->y())/(mousePos.x()-elip->x()));
    if (mousePos.x() < elip->x())
    {
        angle = angle+3.1416;
    }
    velx = vel*cos(angle);
    vely = vel*sin(angle);

}

balas::balas(int velx, int vely, int width, int height, int posx, int posy, bool probability): ancho(width), alto(height), circular(probability)
{
    elip = new QGraphicsEllipseItem(0,0,width,height);
    elip->setPos(posx,posy);
    this->velx = velx;
    this->vely = vely;
    balasAmarillas();
}

QPointF balas::getPos() const
{
    return elip->scenePos();
}

void balas::setPos(QPointF pos)
{
    elip->setPos(pos);
}

void balas::setPos(int x, int y)
{
    elip->setPos(x,y);
}

balas::~balas()
{
    delete elip;
}

int balas::getX() const
{
    return elip->x();
}
void balas::setX(int x)
{
    elip->setX(x);
}
int balas::getY() const
{
    return elip->y();
}
void balas::setY(int y)
{
    elip->setY(y);
}

void balas::moveBy(int x, int y)
{
    elip->setPos(elip->x()+x,elip->y()+y);
}

void balas::move()
{
    if (circular)
    {
        t += 0.1;
        cirx+=3;
        int y = 450;
        elip->setPos(cirx+50*cos(t),y+50*sin(t));
    }else
    {
        elip->setPos(elip->x()+velx,elip->y()+vely);
    }
}

int balas::getVelx() const
{
    return velx;
}

void balas::setVelx(int newVelx)
{
    velx = newVelx;
}

int balas::getVely() const
{
    return vely;
}

void balas::setVely(int newVely)
{
    vely = newVely;
}

int balas::getVel() const
{
    return vel;
}

QGraphicsEllipseItem *balas::getElip() const
{
    return elip;
}

void balas::setElip(QGraphicsEllipseItem *newElip)
{
    elip = newElip;
}

int balas::getWidth() const
{
    return ancho;
}

int balas::getHeight() const
{
    return alto;
}

void balas::balasAzules()
{
    QBrush blueBrush(Qt::cyan);
    elip->setBrush(blueBrush);
}

void balas::balasAmarillas()
{
    QBrush yellowBrush(Qt::yellow);
    elip->setBrush(yellowBrush);
}




