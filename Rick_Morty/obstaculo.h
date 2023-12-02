#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class Obstaculo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    // constructors
    Obstaculo(const QRectF &sceneSize, const float scale, QGraphicsItem* im=0);

    // destructor
    ~Obstaculo();

    //
    void moveBy(int x, int y);
    void move();

    // setters and getters
    int getVel() const;
    QGraphicsRectItem *getRect() const;
    void setRect(QGraphicsRectItem *newRect);
    int getWidth() const;
    int getHeight() const;

private:
    const int vel = 5;
};

#endif // OBSTACLE_H
