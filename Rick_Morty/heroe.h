#ifndef HEROE_H
#define HEROE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>

class heroe : public QObject, public QGraphicsItem
{
    Q_OBJECT

    int posx = 20, posy = 20;                                      // posición del heroe en la escena.
    int velocidad=10;



public:
    explicit heroe(QObject *parent = nullptr);

    sprite(int x, int y);                       // Constructor para inicializar  las posiciones posx e posy del sprite
    QTimer *timer1;                                            // Puntero a un QTimer programar actualziacion del sprite
    QPixmap *pixmap1;

    float columnas, ancho, alto;        // Para  determinar la posición y el tamaño del sprite en la hoja de sprites

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    void Actualizacion();                            // actualización periódica del sprite
    void moveBy(int x, int y);

};

#endif // HEROE_H
