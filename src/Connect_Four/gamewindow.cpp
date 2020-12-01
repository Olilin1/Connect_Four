
#include "gamewindow.h"

void QGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event){
qDebug() << "Test";
}

GameWindow::GameWindow(QGraphicsScene *scene)
{
    diameter = 50;
    windowWidth = 390;
    windowHeight = 350;
    eclipses.resize(6);
    for(int i = 0; i < 6; i++){
        eclipses[i].resize(7);
    }

    hitboxes.resize(7);
    for(int i = 0; i < 7; i++){
        hitboxes[i] = new QGraphicsRectItem(diameter*i, 0, diameter, diameter*6);
        scene->addItem(hitboxes[i]);
    }

    for(int i = 0; i < 6; i++){
        for (int j = 0; j <7; j++){
            eclipses[i][j] = new QGraphicsEllipseItem(diameter*j, diameter*i, diameter, diameter);
            eclipses[i][j]->setAcceptHoverEvents(true);
            scene->addItem(eclipses[i][j]);
        }
    }

    setFixedSize(windowWidth, windowHeight);
    scene->setSceneRect(0, 0, windowWidth-40, windowHeight-40);
    setScene(scene);

    this->rotate(180);
}
