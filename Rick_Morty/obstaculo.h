#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Obstaculo: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    // constructors
    Obstaculo();
    Obstaculo(const QRectF &sceneSize,const int width, const int height, QObject *parent = nullptr);

    // destructor
    ~Obstaculo();

    //
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    QPointF getPos() const;
    void setPos(QPointF);
    void setPos(int x, int y);
    void moveBy(int x, int y);
    void move();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // setters and getters
    int getVel() const;
    QGraphicsRectItem *getRect() const;
    void setRect(QGraphicsRectItem *newRect);
    int getWidth() const;
    int getHeight() const;

private:
    const int vel = 5;
    QPixmap *pixmap;
    float ancho, alto;
};

#endif // OBSTACULO_H
