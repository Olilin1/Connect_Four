#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPushButton>
#include <QComboBox>
#include <vector>
#include <QDebug>
#include "gameLibrary.hpp"
typedef short(*playerFunc)(std::vector<std::vector<short>>);

class GameWindow : public QGraphicsView
{
    Q_OBJECT

private:
    int diameter;
    int windowHeight, windowWidth;

    QGraphicsScene *mainScene;
    ConnectFourGame *game;

    QComboBox *listSelection1;
    QComboBox *listSelection2;
    QPushButton *btnStart;

    playerFunc player1;
    playerFunc player2;
    playerFunc connector;

    QGraphicsItemGroup *board;
    std::vector<std::vector<QGraphicsEllipseItem*>> eclipses;
    std::vector<QGraphicsRectItem*> hitboxes;

public:
    GameWindow(QGraphicsScene *scene);
    void setPlayer1 (playerFunc);
    void setPlayer2 (playerFunc);
    void setConnector (playerFunc);
    short playerHandler(std::vector<std::vector<short>>);
    playerFunc textToAI(QString);

public slots:
    void startGame();

};

#endif // GAMEWINDOW_H
