#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene> //incluir la libreria QgraphicsScene.
#include "cuerpo.h" //incluir la clase cuerpo.
#include "enemigo.h" //incluir la clase villano.
#include <QKeyEvent> //libreria para las teclas
#include <QTimer> //lireria del timer
#include <QDebug> //libreria de debug

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mover_enemigo();

private:
    Ui::MainWindow *ui;
    //escena
    QGraphicsScene *escena; //escena del videojuego

    //timers
    QTimer *timerenemigo;

    //cuerpos
    Cuerpo *nave; // cuerpo prueba
    enemigo *bola1;

    //entorno
    Cuerpo *piso;
    Cuerpo *muroderecho;
    Cuerpo *muroizquierdo;


    //funciones
    void keyPressEvent(QKeyEvent * event); //funcion para las teclas

};
#endif // MAINWINDOW_H

