#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent, int dificultad, short selheroe) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->dificultad = dificultad;
    this->selheroe = selheroe;

    scene1 = new QGraphicsScene;
    scene2 = new QGraphicsScene;
    scene3 = new QGraphicsScene;
    ui->graphicsView->setScene(scene1);
    escena = 1;

    QImage fondo1(":/Imagenes/Fondo1.jpg");
    QBrush BrochaF1(fondo1);
    ui->graphicsView->setBackgroundBrush(BrochaF1);    //Pinta el fondo del nivel 1 y se escala

    scene1->setSceneRect(ui->graphicsView->contentsRect());
    scene2->setSceneRect(ui->graphicsView->contentsRect());
    scene3->setSceneRect(ui->graphicsView->contentsRect());

    scenes[0] = scene1;
    scenes[1] = scene2;
    scenes[2] = scene3;


    if(selheroe==1)
        personaje = new rick();

    else if(selheroe==2)
        personaje = new morty;

    else
        personaje = new rick();                                 // crea heroe

    scene1->addItem(personaje);                               //Añade a la escena
    personaje->setPos(scene1->width()/2,scene1->height()/2);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, [this]{
        bulletMove();
        colission();
        setFocus();
        cambioEscena();
        movimientoPersonaje();
        obstacleMove();
        update();
    });                                                         //Conecta el temporizador para mover balas
    timer->start(11);                                                             // 16

    timerObstaculos = new QTimer();
    connect(timerObstaculos, SIGNAL(timeout()), this, SLOT(generateObstacles()));
    timerObstaculos->start(1200);

    timerbalas = new QTimer(this);
    connect(timerbalas, SIGNAL(timeout()), this, SLOT(enemyBulletGeneration()));
    timerbalas->start(500); // dificultad

    enemyTimer = new QTimer(this);
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(enemyGeneration()));
    enemyTimer->start(2000);

    timerPuntajeNivel3 = new QTimer(this);
    connect(timerPuntajeNivel3, SIGNAL(timeout()), this, SLOT(aumentaPuntaje()));
    timerPuntajeNivel3->start(3000);

    vidas = 5;
    on_progressBar_valueChanged(vidas);

    puntos = 0;
    on_progressBar_Puntuacion_valueChanged(puntos);

    running = true;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete personaje;
    delete scene1;
    delete scene2;
    delete scene3;
    delete timer;
    delete enemyTimer;
    delete timerbalas;
    delete timerObstaculos;
    delete timerPuntajeNivel3;
    delete personaje;

    for(auto bala : allyBullets )
        delete bala;

    for(auto enemy : enemyBullets )
        delete enemy;

    for(auto enemie : enemies )
        delete enemie;

    for(auto obsta : obstacles )
        delete obsta;

    for(int i=0; i<3; i++)
        delete scenes[i];
}

void MainWindow::movimientoPersonajeEscena1y2()
{
    int step=2;                                         //Velocidad personaje

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
        if (keysPressed.begin() != keysPressed.end())
        {
            switch (*keysPressed.begin())
            {
            case Qt::Key_A:
                personaje->moveBy(-step, 0);
                personaje->setRotation(-90);
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
}

void MainWindow::movimientoPersonajeEscena3()
{
    int jumpvel = -8;
    int slow = 2;
    int step = 3;
    personaje->acelerateBy(0,scene1->sceneRect().height());
    if (keysPressed.contains(Qt::Key_A) && keysPressed.contains(Qt::Key_W))
    {
        personaje->moveBy(-step, 0);
        personaje->jump(jumpvel);
    } else if (keysPressed.contains(Qt::Key_A) && keysPressed.contains(Qt::Key_S))
    {
        personaje->moveBy(-step, 0);
        personaje->smallRect();
    } else if (keysPressed.contains(Qt::Key_D) && keysPressed.contains(Qt::Key_W))
    {
        personaje->moveBy(step-slow, 0);
        personaje->jump(jumpvel);
    } else if (keysPressed.contains(Qt::Key_D) && keysPressed.contains(Qt::Key_S))
    {
        personaje->moveBy(step-slow, 0);
        personaje->smallRect();
    }else if (keysPressed.contains(Qt::Key_W) && keysPressed.contains(Qt::Key_S))
    {
        personaje->jump(jumpvel);
        personaje->smallRect();
    }else {
        if (keysPressed.begin() != keysPressed.end())
        {
            switch (*keysPressed.begin())
            {
            case Qt::Key_A:
                personaje->moveBy(-step, 0);
                break;
            case Qt::Key_D:
                personaje->moveBy(step-slow, 0);
                break;
            case Qt::Key_W:
                personaje->jump(jumpvel);
                break;
            case Qt::Key_S:
                personaje->smallRect();
                break;
            default:
                break;
            }
        }
    }
    if (!keysPressed.contains(Qt::Key_S))
    {
        personaje->bigRect();
    }
}

void MainWindow::movimientoPersonaje()
{
    switch (escena) {
    case 1:
    {
        movimientoPersonajeEscena1y2();
        break;
    }
    case 2:
    {
        movimientoPersonajeEscena1y2();
        break;
    }
    case 3:
    {
        movimientoPersonajeEscena3();
        break;
    }
    default:
        qDebug() << "ERROR: la escena no existe";
        break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    keysPressed.insert(event->key());
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    keysPressed.remove(event->key());
}

void MainWindow::disparoEscena1y2(QPointF mousePos,int escena)
{
    balas *bala = new balas(mousePos, personaje->getPos());                //crea nueva bala desde la posicion del heroe
    bala->balasAzules();
    scenes[escena]->addItem(bala->getElip());
    allyBullets.push_front(bala);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(running){

        QPointF mousePos = ui->graphicsView->mapToScene(event->pos());
        switch (escena) {
        case 1:
        {
            disparoEscena1y2(mousePos, 0);
            break;
        }
        case 2:
        {
            disparoEscena1y2(mousePos, 1);
            break;
        }
        case 3:
        {
            return;
            break;
        }
        default:
            break;
        }
    }
}

void MainWindow::update()
{
    if(escena == 2){
        for (enemy1 *enemigo : enemies)
            enemigo->moveBy(personaje);;
    }
}

void MainWindow::movimientoBalaEscena1y2(int escena)
{
    for (auto it = allyBullets.begin(); it != allyBullets.end();)
    {
        balas *bala = *it;
        bala->move();
        if (bala->getX() > scenes[escena]->width() || bala->getX() < 0-bala->getWidth() || bala->getY() > scenes[escena]->height() || bala->getY() < 0-bala->getHeight())
        {
            scenes[escena]->removeItem(bala->getElip());
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
        if (bala->getX() > scenes[escena]->width() || bala->getX() < 0 - bala->getWidth() || bala->getY() > scenes[escena]->height() || bala->getY() < 0-bala->getHeight())
        {
            scenes[escena]->removeItem(bala->getElip());
            it = enemyBullets.erase(it);
            delete bala;
        }else
        {
            it++;
        }
    }
}

void MainWindow::movimientoBalaEscena3()
{
    for (auto it = enemyBullets.begin(); it != enemyBullets.end();)
    {
        balas *bullet = *it;
        bullet->move();
        if (bullet->getX() > scene3->width())
        {
            scene3->removeItem(bullet->getElip());
            it = enemyBullets.erase(it);
            delete bullet;
        }else
        {
            it++;
        }
    }
}

void MainWindow::bulletMove()
{
    switch (escena) {
    case 1:
    {
        movimientoBalaEscena1y2(0);
        break;
    }
    case 2:
    {
        movimientoBalaEscena1y2(1);
        break;
    }
    case 3:
    {
        movimientoBalaEscena3();
        break;
    }
    default:
        break;
    }
}

void MainWindow::generacionEnemigosEscena1y2(int escena)
{
    int place = rand() % 4 + 1;
    int posy, posx;

    switch (place) {

        case 1: // arriba
        {
            posy = 60;
            posx = rand() % ((int)scenes[escena]->width()- 10 +1 ) + 10;
            break;
        }
        case 2: // abajo
        {
            posy = 533;
            posx = rand() % ((int)scenes[escena]->width()- 10 +1 ) + 10;
            break;
        }
        case 3: // izquierda
        {
            posy = rand() % ((int)scenes[escena]->height() - 89) + 50;
            posx = 20;

            break;
        }
        case 4: // derecha
        {
            posy = rand() % ((int)scenes[escena]->height() - 89) + 50;
            posx = 1050;
            break;
        }
        default:
        {
            posx = scenes[escena]->width()/2;
            posy = scenes[escena]->height()/2;
            qDebug() << "Numero aleatorio generado no es el esperado";
        }
        break;
    }
    enemy1 *villano;
    if (escena == 0)
    {
        villano = new alien();                                    //

    }else
    {
        villano = new escolta();
    }
    scenes[escena]->addItem(villano);
    villano->setPos(posx,posy);
    enemies.push_front(villano);
}

void MainWindow::enemyGeneration()
{
    switch (escena) {
    case 1:
    {
        generacionEnemigosEscena1y2(0);
        break;
    }
    case 2:
    {
        generacionEnemigosEscena1y2(1);

       /* for (auto enemy : enemies)
        {
            enemy->moveBy(personaje);
        } */

    }
    case 3:
    {
        return;
        break;
    }
    default:
        break;
    }
}

void MainWindow::generacionBalaEnemigaEscena1y2(int escena)
{
    for (auto villano: enemies)
    {
        int probability = rand()%11;
        if (probability == 10)
        {
            balas *bala = new balas(personaje->getPos(), villano->getPos());
            bala->balasAmarillas();
            scenes[escena]->addItem(bala->getElip());

            enemyBullets.push_front(bala);
        }
    }
}

void MainWindow::generacionBalaEnemigaEscena3()
{
    int probability = rand()%11;
    int width = 10;
    int height = 10;
    int velx = 5;
    int vely = 0;
    if(probability == 10)
    {
        int probability = rand()%5;
        bool circular = false;
        if (probability == 0) circular = true;
        balas *bullet = new balas(velx,vely,width,height,width,0,circular);
        int posy = rand()%((int)scene3->height()/2-bullet->getHeight());
        bullet->setY(posy+scene3->height()/2);
        scene3->addItem(bullet->getElip());
        enemyBullets.push_back(bullet);
    }
}

void MainWindow::enemyBulletGeneration()
{
    switch (escena) {
    case 1:
    {
        generacionBalaEnemigaEscena1y2(0);
        break;
    }
    case 2:
    {
        generacionBalaEnemigaEscena1y2(1);
        break;
    }
    case 3:
    {
        generacionBalaEnemigaEscena3();
        break;
    }
    default:
        break;
    }
}

void MainWindow::colisionEscena1y2(int escena)
{
    for (auto itEnemy = enemies.begin(); itEnemy != enemies.end();){
        bool erased = false;
        for (auto itBullet = allyBullets.begin(); itBullet != allyBullets.end();){

            if((*itEnemy)->collidesWithItem((*itBullet)->getElip())){

                erased = true;

                scenes[escena]->removeItem((*itBullet)->getElip());
                scenes[escena]->removeItem((*itEnemy));

                balas *bala = (*itBullet);
                enemy1 *enemigo = (*itEnemy);

                itEnemy = enemies.erase(itEnemy);
                itBullet = allyBullets.erase(itBullet);

                puntos++;
                on_progressBar_Puntuacion_valueChanged(puntos);

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

            scenes[escena]->removeItem((*it)->getElip());

            balas *bala = (*it);
            it = enemyBullets.erase(it);

            vidas--;
            on_progressBar_valueChanged(vidas);

            delete (bala);
        }
        else
            it++;
    }
    if(vidas <= 0){
            eliminaItems(scenes[escena]);
            perdiste(scenes[escena]);
    }
}

void MainWindow::colisionEscena3()
{
    for (auto it = enemyBullets.begin(); it != enemyBullets.end();)
    {
        balas *bullet = *it;
        if (personaje->collidesWithItem(bullet->getElip()))
        {
            scene3->removeItem(bullet->getElip());
            it = enemyBullets.erase(it);

            vidas--;
            on_progressBar_valueChanged(vidas);

            delete bullet;
        }else
        {
            it++;
        }
    }
    for (auto it = obstacles.begin(); it != obstacles.end();)
    {
        Obstaculo *obstacle = *it;
        if (personaje->collidesWithItem(obstacle))
        {
            scene3->removeItem(obstacle);
            it = obstacles.erase(it);

            vidas--;
            on_progressBar_valueChanged(vidas);

            delete obstacle;
        }else
        {
            it++;
        }
    }

    if(vidas <= 0){
        eliminaItems(scene3);
        perdiste(scene3);
    }
}

void MainWindow::colission()
{
    switch (escena) {
    case 1:
    {
        colisionEscena1y2(0);
        break;
    }
    case 2:
    {
        colisionEscena1y2(1);
        break;
    }
    case 3:
    {
        colisionEscena3();
        break;
    }
    default:
        break;
    }

}

void MainWindow::generateObstacles()
{
    if (escena == 3)
    {
        float scale = rand()%5+5;
        Obstaculo *obstacle = new Obstaculo(scene3->sceneRect(), scale);
        obstacles.push_front(obstacle);
        scene3->addItem(obstacle);
    }
}

void MainWindow::obstacleMove()
{
    for (auto it = obstacles.begin(); it != obstacles.end();)
    {
        Obstaculo *obstacle = *it;
        obstacle->move();
        if (obstacle->x() < 0 - obstacle->boundingRect().width())
        {
            scene3->removeItem(obstacle);
            it = obstacles.erase(it);
            delete obstacle;
        }else
        {
            it++;
        }
    }
}

void MainWindow::eliminaItems(QGraphicsScene *scene)
{
    scene->removeItem(personaje);

    for (auto enemy : enemies) {
        scene->removeItem(enemy);
        delete enemy;
    }
    enemies.clear();

    for (auto bullet : enemyBullets) {
        scene->removeItem(bullet->getElip());
        delete bullet;
    }
    enemyBullets.clear();

    for (auto obstacle : obstacles) {
        scene->removeItem(obstacle);
        delete obstacle;
    }
    obstacles.clear();

    for (auto bullet : allyBullets) {
        scene->removeItem(bullet->getElip());
        delete bullet;
    }
    allyBullets.clear();


}

void MainWindow::detieneTimers()
{
    (*timer).stop();
    (*timerbalas).stop();
    (*timerObstaculos).stop();
    (*enemyTimer).stop();
    (*timerPuntajeNivel3).stop();
}

void MainWindow::perdiste(QGraphicsScene *scene)
{

    detieneTimers();
    running = false;

    QGraphicsTextItem *gameOverText = new QGraphicsTextItem("Game Over");
    QFont font("Comic Sans MS", 30);
    gameOverText->setFont(font);
    gameOverText->setDefaultTextColor(Qt::black);
    gameOverText->setPos(scene->width() / 2 - 100, scene->height() / 2 - 50);
    scene->addItem(gameOverText);
}

void MainWindow::ganaste(QGraphicsScene *scene)
{

    detieneTimers();
    running = false;

    QGraphicsTextItem *gameOverText = new QGraphicsTextItem("You Win");
    QFont font("Comic Sans MS", 30);
    gameOverText->setFont(font);
    gameOverText->setDefaultTextColor(Qt::black);
    gameOverText->setPos(scene->width() / 2 - 100, scene->height() / 2 - 50);
    scene->addItem(gameOverText);
}

void MainWindow::cambioEscena()
{

    if (escena == 1 && puntos >= 3)
    {
        escena = 2;
        eliminaItems(scene1);

        ui->graphicsView->setScene(scene2);

        QImage fondo2(":/Imagenes/Fondo2.png");
        QBrush BrochaF2(fondo2);

        ui->graphicsView->setBackgroundBrush(BrochaF2);    //Pinta el fondo del nivel 2 y se escala

        scene2->addItem(personaje);
        personaje->setPos(scene1->width()/2,scene1->height()/2);

        puntos = 0;
        on_progressBar_Puntuacion_valueChanged(puntos);

        vidas = 5;
        on_progressBar_valueChanged(vidas);


    }else if(escena == 2 && puntos >= 3)
    {
        escena = 3;
        eliminaItems(scene2);

        ui->graphicsView->setScene(scene3);

        QImage fondo3(":/Imagenes/Fondo3.png");
        QBrush BrochaF3(fondo3);

        ui->graphicsView->setBackgroundBrush(BrochaF3);    //Pinta el fondo del nivel 2 y se escala
        personaje->setRotation(0);

        scene3->addItem(personaje);
        personaje->setLevel3Scale();

        vidas = 5;
        on_progressBar_valueChanged(vidas);

        puntos = 0;
        on_progressBar_Puntuacion_valueChanged(puntos);

    }
}

void MainWindow::aumentaPuntaje()
{
    if(escena == 3)
    {
        puntos++;
        on_progressBar_Puntuacion_valueChanged(puntos);
        if (puntos == 10)
        {
            ganaste(scene3);
        }
    }
}

void MainWindow::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue(value);
    ui->progressBar->setStyleSheet(ui->progressBar->property("defaultStyleSheet").toString() +
        " QProgressBar::chunk { background: red; }");
}

void MainWindow::on_progressBar_Puntuacion_valueChanged(int Pun)
{
    ui->progressBar_Puntuacion->setValue(Pun);
    ui->progressBar_Puntuacion->setStyleSheet(ui->progressBar->property("defaultStyleSheet").toString() +
         " QProgressBar::chunk { background: yellow; }");
}

