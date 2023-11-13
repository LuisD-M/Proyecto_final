#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene1 = new QGraphicsScene;
    ui->graphicsView->setScene(scene1);

    QImage fondo1(":/Imagenes/Fondo1.jpg");
    QBrush BrochaF1(fondo1);

    ui->graphicsView->setBackgroundBrush(BrochaF1);    //Pinta el fondo del nivel 1 y se escala
    scene1->setSceneRect(0,0,1080,599);

    personaje = new heroe();                                 // crea heroe
    scene1->addItem(personaje);                               //Añade a la escena
    personaje->setPos(scene1->width()/2,scene1->height()/2);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, [this]{
        bulletMove();
        enemyBulletGeneration();
        colission();
        setFocus();
    });                                                         //Conecta el temporizador para mover balas
    timer->start(10);                                                             // 16

    enemyTimer = new QTimer(this);
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(enemyGeneration()));
    enemyTimer->start(2000);

    puntos = new puntaje;                            //añade puntaje
    scene1->addItem(puntos);
    puntos->setPos(0,0);

    vidas = new vida;
    scene1->addItem(vidas);
    vidas->setPos(1000,0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int step=5;                                         //Velocidad personaje

    keysPressed.insert(event->key());

    if (keysPressed.contains(Qt::Key_A) && keysPressed.contains(Qt::Key_W)){
        personaje->moveBy(-step, -step);
        personaje->setRotation(-45);

    }
    else if (keysPressed.contains(Qt::Key_A) && keysPressed.contains(Qt::Key_S)){
        personaje->moveBy(-step, step);
        personaje->setRotation(225);

    }
    else if (keysPressed.contains(Qt::Key_D) && keysPressed.contains(Qt::Key_W)){
        personaje->moveBy(step, -step);
        personaje->setRotation(45);

    }
    else if (keysPressed.contains(Qt::Key_D) && keysPressed.contains(Qt::Key_S)){
        personaje->moveBy(step, step);
        personaje->setRotation(135);

    }
    else {
        switch (event->key())
        {
        case Qt::Key_A:
            personaje->moveBy(-step, 0);
            personaje->setRotation(0);
            break;
        case Qt::Key_D:
            personaje->moveBy(step, 0);
            personaje->setRotation(0);
            break;
        case Qt::Key_W:
            personaje->moveBy(0, -step);
            personaje->setRotation(-90);
            break;
        case Qt::Key_S:
            personaje->moveBy(0, step);
            personaje->setRotation(90);
            break;
        default:
            break;
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    keysPressed.remove(event->key());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPointF mousePos = ui->graphicsView->mapToScene(event->pos());         //
    balas *bala = new balas(mousePos, personaje->getPos());                //crea nueva bala desde la posicion del heroe
    bala->balasAzules();
    scene1->addItem(bala->getElip());
    allyBullets.push_front(bala);
    setFocus();                                                             //Recibir eventos del teclado y raton
}

void MainWindow::bulletMove()
{
    for (auto it = allyBullets.begin(); it != allyBullets.end();)
    {
        balas *bala = *it;
        bala->move();
        if (bala->getX() > scene1->width() || bala->getX() < 0-bala->getWidth() || bala->getY() > scene1->height() || bala->getY() < 0-bala->getHeight())
        {
            scene1->removeItem(bala->getElip());
            it = allyBullets.erase(it);
            delete bala;
        }else
        {
            it++;
        }
    }

    for (auto it = enemyBullets.begin(); it != enemyBullets.end();)
    {
        balas *bala = *it;
        bala->move();
        if (bala->getX() > scene1->width() || bala->getX() < 0 - bala->getWidth() || bala->getY() > scene1->height() || bala->getY() < 0-bala->getHeight())
        {
            scene1->removeItem(bala->getElip());
            it = enemyBullets.erase(it);
            delete bala;
        }else
        {
            it++;
        }
    }

}

void MainWindow::enemyGeneration()
{
    int place = rand() % 4 + 1;
    int posy, posx;
    switch (place) {

    case 1: // arriba
    {
        posy = 60;
        posx = rand() % ((int)scene1->width()- 10 +1 ) + 10;
        break;
    }
    case 2: // abajo
    {
        posy = 533;
        posx = rand() % ((int)scene1->width()- 10 +1 ) + 10;
        break;
    }
    case 3: // izquierda
    {
        posy = rand() % ((int)scene1->height() - 89) + 50;
        posx = 20;

        break;
    }
    case 4: // derecha
    {
        posy = rand() % ((int)scene1->height() - 89) + 50;
        posx = 1050;
        break;
    }
    default:
    {
        posx = scene1->width()/2;
        posy = scene1->height()/2;
        qDebug() << "Numero aleatorio generado no es el esperado";
    }
    break;
    }
    villano = new enemy1();
    scene1->addItem(villano);
    villano->setPos(posx,posy);
    enemies.push_front(villano);
}

void MainWindow::enemyBulletGeneration()
{
    for (auto villano: enemies)
    {
        int probability = rand()%150;
        if (probability == 10)
        {
            balas *bala = new balas(personaje->getPos(), villano->getPos());
            bala->balasAmarillas();
            scene1->addItem(bala->getElip());

            enemyBullets.push_front(bala);
        }
    }
}

void MainWindow::colission()
{
    for (auto itEnemy = enemies.begin(); itEnemy != enemies.end();){
        bool erased = false;
        for (auto itBullet = allyBullets.begin(); itBullet != allyBullets.end();){

            if((*itEnemy)->collidesWithItem((*itBullet)->getElip())){

                erased = true;

                scene1->removeItem((*itBullet)->getElip());
                scene1->removeItem((*itEnemy));

                balas *bala = (*itBullet);
                enemy1 *enemigo = (*itEnemy);

                itEnemy = enemies.erase(itEnemy);
                itBullet = allyBullets.erase(itBullet);
                puntos->increaseN1();

                delete (enemigo);
                delete (bala);
                break;
            }else
                itBullet++;

        }
        if (!erased) itEnemy++;
    }

    for(auto it = enemyBullets.begin(); it != enemyBullets.end();){
        if(personaje -> collidesWithItem((*it)->getElip())){

            scene1->removeItem((*it)->getElip());

            balas *bala = (*it);

            it = enemyBullets.erase(it);
            vidas->lessVidaN1();

            delete (bala);

        }
        else
            it++;
    }

    if(vidas->getVidaN1()== 0){
        scene1->removeItem(personaje);

        for (auto enemy : enemies) {
            scene1->removeItem(enemy);
            delete enemy;
        }
        enemies.clear();

        for (auto bullet : enemyBullets) {
            scene1->removeItem(bullet->getElip());
            delete bullet;
        }
        enemyBullets.clear();

        QGraphicsTextItem *gameOverText = new QGraphicsTextItem("Game Over");
        QFont font("Comic Sans MS", 30);
        gameOverText->setFont(font);
        gameOverText->setDefaultTextColor(Qt::black);
        gameOverText->setPos(scene1->width() / 2 - 100, scene1->height() / 2 - 50);
        scene1->addItem(gameOverText);

    }
}


