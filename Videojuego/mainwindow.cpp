#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    int nivel=1; //inicializacion de nivel

    ui->setupUi(this);
    escena = new QGraphicsScene; //crear la escena del juego
    ui->graphicsView->setScene(escena); //agregar el graphicsView
    escena->setSceneRect(0,0,1000,698); //darle un tamaño a la escena


    if(nivel==1) //nivel 1
    {
        //agregar personaje principal
        nave = new Cuerpo(475,600,50,50);
        escena->addItem(nave);

        //agregar enemigo
        bola1 = new enemigo(30,30,50,50,20,0);
        escena->addItem(bola1);

        //agregar piso
        piso = new Cuerpo(500,650,1000,50);
        escena->addItem(piso);

        //agrego muro derecho
        muroderecho = new Cuerpo(1025,350,50,800);
        escena->addItem(muroderecho);

        //agrego muro izquierdo
        muroizquierdo = new Cuerpo(-25,350,50,800);
        escena->addItem(muroizquierdo);

        timerenemigo = new QTimer;
        connect(timerenemigo,SIGNAL(timeout()),this,SLOT(mover_enemigo()));
        timerenemigo->start(15);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mover_enemigo()
{
    qDebug() <<"pos en x: "<<bola1->getPosx();
    qDebug() <<"pos en y: "<<bola1->getPosy();
    //ui->graphicsView->centerOn(bola1);
    bola1->actualizarposicion(); //actualiza la posicion
    bola1->actualizarvelocidad(); //actualiza la velocidad
    bola1->setX(bola1->getPosx()); //setea la posicion en x
    bola1->setY(-bola1->getPosy());//setea la posicion en y

    if(bola1->collidesWithItem(piso))
    {
        if(bola1->getDir()==1)
        {
            bola1->setAngulo(80);
            bola1->setVel(100);
            bola1->actualizarposicion(); //actualiza la posicion
            bola1->actualizarvelocidad(); //actualiza la velocidad
            bola1->setX(bola1->getPosx()); //setea la posicion en x
            bola1->setY(-bola1->getPosy());//setea la posicion en y
        }
        if(bola1->getDir()==2)
        {
            bola1->setAngulo(100);
            bola1->setVel(100);
            bola1->actualizarposicion(); //actualiza la posicion
            bola1->actualizarvelocidad(); //actualiza la velocidad
            bola1->setX(bola1->getPosx()); //setea la posicion en x
            bola1->setY(-bola1->getPosy());//setea la posicion en y
        }
    }

    if (bola1->collidesWithItem(muroderecho))
    {
        bola1->setDir(2);
        bola1->setAngulo(100);
        bola1->actualizarposicion(); //actualiza la posicion
        bola1->actualizarvelocidad(); //actualiza la velocidad
        bola1->setX(bola1->getPosx()); //setea la posicion en x
        bola1->setY(-bola1->getPosy());//setea la posicion en
    }

    if (bola1->collidesWithItem(muroizquierdo))
    {
        bola1->setDir(1);
        bola1->setAngulo(80);
        bola1->actualizarposicion(); //actualiza la posicion
        bola1->actualizarvelocidad(); //actualiza la velocidad
        bola1->setX(bola1->getPosx()); //setea la posicion en x
        bola1->setY(-bola1->getPosy());//setea la posicion en
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //tecla D
    if(event->key()==Qt::Key_D)
    {
        if(nave->getPosx()<970)
        {
            nave->mover_derecha(); //mover hacia la derecha
        }
    }

    //tecla A
    if(event->key()==Qt::Key_A)
    {
        if(nave->getPosx()>25)
        {
            nave->mover_izquierda();//mover hacia la izquierda
        }
    }
}
