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
#include <QDesktopWidget>
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
#include <heroe.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void keyPressEvent(QKeyEvent * event);


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene1;
    QSet<int> keysPressed;
    float x,y,ancho,alto;
    QTimer *timer;
    heroe *personaje;

    void keyPressEvent(QKeyEvent* event);



};
#endif // MAINWINDOW_H