#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>

class Obstaculo: public QObject
{
    Q_OBJECT
public:
    // constructors
    Obstaculo();
    Obstaculo(QGraphicsRectItem* rect);
    Obstaculo(const QRectF &sceneSize,const QRectF &size);
    Obstaculo(const QRectF &sceneSize,const int width, const int height);

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

    // setters and getters
    int getVel() const;
    QGraphicsRectItem *getRect() const;
    void setRect(QGraphicsRectItem *newRect);
    int getWidth() const;
    int getHeight() const;

private:
    const int vel = 5;
    QGraphicsRectItem *rect;
};

#endif // OBSTACULO_H
