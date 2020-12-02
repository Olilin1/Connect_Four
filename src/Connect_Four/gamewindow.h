#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPushButton>
#include <QComboBox>
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <vector>
#include "gameLibrary.hpp"
typedef short(*playerFunc)(std::vector<std::vector<short>>);
typedef void(*graphicsFunc)(std::vector<std::vector<short>>);

class GameWindow : public QGraphicsView
{
    Q_OBJECT

private:
    int diameter;
    int windowHeight, windowWidth;
    int mouseCol;
    int playerChoice;
    bool makeMove;

    QGraphicsScene *mainScene;
    ConnectFourGame *game;

    QComboBox *listSelection1;
    QComboBox *listSelection2;
    QPushButton *btnStart;

    playerFunc player1;
    playerFunc player2;
    playerFunc playerConnector;
    graphicsFunc graphicsConnector;

    QGraphicsItemGroup *graphicsBoard;
    std::vector<std::vector<QGraphicsEllipseItem*>> eclipses;
    std::vector<QGraphicsRectItem*> hitboxes;

public:
    GameWindow(QGraphicsScene *scene);
    void setPlayer1 (playerFunc);
    void setPlayer2 (playerFunc);
    void setPlayerConnector (playerFunc);
    void setGraphicsConnector (graphicsFunc);
    short playerHandler(std::vector<std::vector<short>>);
    void graphicsHandler(std::vector<std::vector<short>>);
    playerFunc textToAI(QString);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void startGame();

};

#endif // GAMEWINDOW_H
