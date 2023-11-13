#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <QRect>
//#include <QDesktopWidget>
#include <QDebug>
#include <QResizeEvent>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QKeyEvent>
#include <QSet>
#include <QGraphicsEllipseItem>
#include <QFont>
#include <QGraphicsTextItem>

#include <heroe.h>
#include <balas.h>
#include <enemy1.h>
#include <puntaje.h>
#include <vida.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void gameover();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene1;
    QSet<int> keysPressed;
    float x,y,ancho,alto;
    QTimer *timer;
    QTimer *timer1;
    QTimer *enemyTimer;
    heroe *personaje;
    enemy1 *villano;
    puntaje *puntos;
    vida *vidas;

    std::list<balas*> allyBullets;
    std::list<balas*>enemyBullets;
    std::list<enemy1*> enemies;

    short escena;

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void bulletMove();
    void enemyGeneration();
    void enemyBulletGeneration();
    void colission();

};
#endif // MAINWINDOW_H
