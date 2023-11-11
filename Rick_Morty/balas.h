#ifndef BALAS_H
#define BALAS_H

#include <QObject>
#include <QWidget>
#include <QGraphicsEllipseItem>

class balas : public QObject
{
    Q_OBJECT
public:
    // constructors
    balas();
    balas(int velx, int vely, QGraphicsEllipseItem* elip);
    balas(const QPointF &mousePos, const QPointF &heroePos);

    ~balas();

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);

    QPointF getPos() const;
    void setPos(QPointF);
    void setPos(int x, int y);

    void moveBy(int x, int y);
    void move();

    // setters and getters
    int getVelx() const;
    void setVelx(int newVelx);
    int getVely() const;
    void setVely(int newVely);
    int getVel() const;
    QGraphicsEllipseItem *getElip() const;
    void setElip(QGraphicsEllipseItem *newElip);
    int getWidth() const;
    int getHeight() const;

    void balasAzules();                          //Pintar fondo de las balas heroe
    void balasAmarillas();




private:
    int velx, vely;
    const int vel = 10, ancho = 10, alto = 10;
    QGraphicsEllipseItem *elip;

};

#endif // BALAS_H
