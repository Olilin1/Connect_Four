#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPushButton>
#include <vector>
#include <QDebug>
#include "gameLibrary.hpp"


class GameWindow : public QGraphicsView
{
    Q_OBJECT

public:
    int diameter;
    int windowHeight, windowWidth;

    QGraphicsScene *mainScene;
    ConnectFourGame *game;

    std::vector<std::vector<QGraphicsEllipseItem*>> eclipses;
    std::vector<QGraphicsRectItem*> hitboxes;




public:
    GameWindow(QGraphicsScene *scene);


public slots:

};

#endif // GAMEWINDOW_H
