#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

/*
 * clase Obstaculo son los obstaculos del nivel 3
*/

class Obstaculo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Obstaculo(const QRectF &sceneSize, const float scale, QGraphicsItem* im=0); // constructor

    ~Obstaculo(); // destructor

    void moveBy(int x, int y); // metodo que mueve al obstaculo en pantalla
    void move(); // metodo que mueve al obstaculo de acuerdo a la velocidad de la instancia

    // setters and getters
    int getVel() const;
    QGraphicsRectItem *getRect() const;
    void setRect(QGraphicsRectItem *newRect);
    int getWidth() const;
    int getHeight() const;

private:
    const int vel = 5; // velocidad del obstaculo
};

#endif // OBSTACLE_H
