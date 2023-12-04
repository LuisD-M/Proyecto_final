#ifndef BALAS_H
#define BALAS_H

#include <QObject>
#include <QWidget>
#include <QGraphicsEllipseItem>

/*
 * clase balas es la que modela los proyectiles que disparan los enemigos en los 3 niveles y el heroe en los 2 primeros niveles
*/

class balas : public QObject
{
    Q_OBJECT
public:
    // constructores
    balas();
    balas(int velx, int vely, QGraphicsEllipseItem* elip);
    balas(int velx, int vely, int width, int height, int posx=0, int posy=0,bool probability=false);
    balas(const QPointF &mousePos, const QPointF &heroePos);

    ~balas(); // destructor

    // getters y setters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    QPointF getPos() const;
    void setPos(QPointF);
    void setPos(int x, int y);

    void moveBy(int x, int y); // mueve la bala en pantalla una cantidad ingresada
    void move(); // mueve la bala en patalla una velocidad determinada por los atributos velx y vely

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

    // pintan las balas de colores diferentes
    void balasAzules();
    void balasAmarillas();

private:
    int velx, vely; // velocidades en los dos ejes
    const int vel = 10, ancho = 10, alto = 10; // velocidad fija de la bala y sus dimensiones
    QGraphicsEllipseItem *elip; // objeto grafico de la bala
    const bool circular = false; // define si el movimiento de la bala es rectilineo o circular
    float t = 0; // es la variable para hacer el movimiento circular de forma parametrica
    float cirx = 0; // define la posicion del centro en x de la bala cuando esta hace un movimiento circular
};

#endif // BALAS_H
