#include "gamewindow.h"

void QGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event){
qDebug() << "Test";
}

GameWindow::GameWindow(QGraphicsScene *scene)
{
    QStringList alternatives = {"Human","RandomAi","SequentialAi"};
    listSelection1 = new QComboBox(this);
    listSelection1->addItems(alternatives);
    listSelection2 = new QComboBox(this);
    listSelection2->addItems(alternatives);
    btnStart = new QPushButton("Start game!", this);
    connect(btnStart, SIGNAL(clicked()), this, SLOT(startGame()));
    listSelection1->setGeometry(0,0,100,25);
    listSelection2->setGeometry(100,0,100,25);
    btnStart->setGeometry(200,0,100,25);

    board = new QGraphicsItemGroup();
    game = new ConnectFourGame();
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
        board->addToGroup(hitboxes[i]);
    }

    for(int i = 0; i < 6; i++){
        for (int j = 0; j <7; j++){
            eclipses[i][j] = new QGraphicsEllipseItem(diameter*j, diameter*i, diameter, diameter);
            eclipses[i][j]->setAcceptHoverEvents(true);
            board->addToGroup(eclipses[i][j]);
        }
    }
    scene->addItem(board);
    board->setVisible(false);

    setFixedSize(windowWidth, windowHeight);
    scene->setSceneRect(0, 0, windowWidth-40, windowHeight-40);
    setScene(scene);
}

void GameWindow::setPlayer1 (short (*ptr)(std::vector<std::vector<short>>)){
    player1 = ptr;
}
void GameWindow::setPlayer2 (short (*ptr)(std::vector<std::vector<short>>)){
    player2 = ptr;
}
void GameWindow::setConnector(short (*ptr)(std::vector<std::vector<short>>)){
    connector = ptr;
}
short GameWindow::playerHandler(std::vector<std::vector<short>>){
    return 5;
}
playerFunc GameWindow::textToAI(QString text){
    if(text == "Human") return connector;
    if(text == "RandomAi") return randomAi;
    if(text == "SequentialAi") return sequentialAi;
    return connector;
}

void GameWindow::startGame(){
    player1 = textToAI(listSelection1->currentText());
    player2 = textToAI(listSelection2->currentText());
    listSelection1->setVisible(false);
    listSelection2->setVisible(false);
    btnStart->setVisible(false);
    game->setPlayer1(player1);
    game->setPlayer2(player2);
    game->startGame();
}
