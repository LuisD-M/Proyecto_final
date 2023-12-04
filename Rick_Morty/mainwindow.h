#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QRect>
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
#include <string>
#include <iostream>
#include <QDebug>
#include <fstream>
#include <sstream>

#include <heroe.h>
#include <balas.h>
#include <escolta.h>
#include <alien.h>
#include <rick.h>
#include <morty.h>
#include <obstaculo.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*
 * clase MainWindow es la ventana principal, en esta sucede el juegos
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr, int dificultad=0, short selheroe=0, string name="");   //constructor
    ~MainWindow();  //destructor

private:
    Ui::MainWindow *ui; // contiene la ventana

    QGraphicsScene *scene1; // escena primer nivel
    QGraphicsScene *scene2; // escena segundo nivel
    QGraphicsScene *scene3; // escena tercer nivel
    QGraphicsScene *scenes[3]; // escenas
    QSet<int> keysPressed; // teclas presionadas

    QTimer *timer; // timer general del juego
    QTimer *enemyTimer; // timer que determina cada cuanto se generan los enemigos
    QTimer *timerbalas; // timer que determina cada cuanto se generan las balas enemigas
    QTimer *timerObstaculos; // timer que determina cada cuanto se generan los obstaculos
    QTimer *timerPuntajeNivel3; // timer que aumenta el puntaje (nivel 3)
    heroe *personaje; // heroe escogido

    QList<balas*> allyBullets; // balas aliadas
    QList<balas*> enemyBullets; // balas enemigas
    QList<enemy1*> enemies; // enemigos
    QList<Obstaculo*>obstacles; // obstaculos

    short escena; // numero de la escena
    int dificultad; // dificultad del juego
    short selheroe; // numero del heroe escodigo
    string name;    // almacena nombre de la ventana usuario

    int vidas; // cantidad de vidas
    int puntos; // cantidad de puntos
    bool running; // si el juego sigue corriendo o no

    void eliminaItems(QGraphicsScene *scene); // elimina los items de la escena
    void perdiste(QGraphicsScene *scene); // imprime el mensaje de 'game over'
    void ganaste(QGraphicsScene *scene); // imprime el mensaje de 'you win'

    // sub division por escena de las dinamicas del juego
    void disparoEscena1y2(QPointF mousePos,int escena);
    void movimientoPersonajeEscena1y2();
    void movimientoPersonajeEscena3();
    void movimientoBalaEscena1y2(int escena);
    void movimientoBalaEscena3();
    void generacionEnemigosEscena1y2(int escena);
    void generacionBalaEnemigaEscena1y2(int escena);
    void generacionBalaEnemigaEscena3();
    void colisionEscena1y2(int escena);
    void colisionEscena3();

    void detieneTimers(); // detine los timers al finalizar el juego

    void keyPressEvent(QKeyEvent* event); // detecta cuando una tecla se presiona
    void keyReleaseEvent(QKeyEvent* event); // detecta cuando una tecla deja de presionarse
    void mousePressEvent(QMouseEvent *event); // detecta cuando se da click en pantalla

    void Resultado(string linea, string resu);  // escribe resultado final en un archivo txt


private slots:
    void obstacleMove(); // define el movimiento de los obstaculos (nivel 3)
    void generateObstacles(); // generalos obstacuols (nivel 3)
    void bulletMove(); // define el movimiento de las balas
    void enemyGeneration(); // define la generacion de los enemigos (nivel 1 y 2)
    void enemyBulletGeneration(); // define la generacion de las balas
    void colission(); // hace el manejo de colisiones
    void cambioEscena(); // hace el manejo de cambio de escena para los cambios de niveles
    void movimientoPersonaje(); // define el movimiento del personaje
    void aumentaPuntaje(); // aumenta el puntaje por el tiempo transcurrido (nivel 3)

    void on_progressBar_valueChanged(int value); // actualiza la vida en pantalla
    void on_progressBar_Puntuacion_valueChanged(int value); // actualiza la puntuacion en pantalla

    void update(); // actualiza la posicion de los enemigos para simular movimiento (nivel 2)

};
#endif // MAINWINDOW_H

