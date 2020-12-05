#include "gamewindow.h"

//Whenever the mouse is pressed
void GameWindow::mousePressEvent(QMouseEvent *event)
{
    playerChoice =(event->pos().x()-20)/50; //Log which column the player clicked on
    QGraphicsView::mousePressEvent(event);
}

//Whenever the mouse is moved (To show where the drop happens)
void GameWindow::mouseMoveEvent(QMouseEvent *event){

    mouseCol =(event->pos().x()-20)/50;

    for(int i = 0; i < 7; i++){
        eclipses[0][i]->setVisible(false);
    }
    if (event->pos().x() < 20 || mouseCol > 6 || !makeMove) return;
    eclipses[0][mouseCol]->setVisible(true);
    eclipses[0][mouseCol]->setBrush(game->getTurn() == 1 ? Qt::red : Qt::yellow);
    QGraphicsView::mouseMoveEvent(event);
}


GameWindow::GameWindow(QGraphicsScene *scene)
{
    setMouseTracking(true);

    QStringList alternatives = {"Human","RandomAi","SequentialAi","MinMaxAiV0"};
    listSelection1 = new QComboBox(this);
    listSelection1->addItems(alternatives);
    listSelection2 = new QComboBox(this);
    listSelection2->addItems(alternatives);
    btnStart = new QPushButton("Start game!", this);
    connect(btnStart, SIGNAL(clicked()), this, SLOT(startGame()));
    listSelection1->setGeometry(0,0,100,25);
    listSelection2->setGeometry(100,0,100,25);
    btnStart->setGeometry(200,0,100,25);

    graphicsBoard = new QGraphicsItemGroup();
    game = new ConnectFourGame();
    diameter = 50;
    windowWidth = 390;
    windowHeight = 390;
    mouseCol=0;
    makeMove = false;
    eclipses.resize(7);
    for(int i = 0; i < 7; i++){
        eclipses[i].reserve(7);
    }

    rectangles.reserve(7);
    for(int i = 0; i < 7; i++){
        rectangles.push_back(new QGraphicsRectItem(diameter*i, diameter, diameter, diameter*6));
        graphicsBoard->addToGroup(rectangles[i]);
    }

    for(int i = 0; i < 7; i++){
        for (int j = 0; j <7; j++){
            eclipses[i].push_back(new QGraphicsEllipseItem(diameter*j, diameter*i, diameter, diameter));
            eclipses[i][j]->setAcceptHoverEvents(true);
            if(i ==0 ){
                eclipses[i][j]->setVisible(false);
                scene->addItem(eclipses[i][j]);
            }
            else{
                graphicsBoard->addToGroup(eclipses[i][j]);
            }
        }
    }
    scene->addItem(graphicsBoard);
    graphicsBoard->setVisible(false);

    setFixedSize(windowWidth, windowHeight);
    scene->setSceneRect(0, 0, windowWidth-40, windowHeight-40);
    setScene(scene);
}


void GameWindow::setPlayerConnector(short (*ptr)(std::vector<std::vector<short>>)){
    playerConnector = ptr;
}
void GameWindow::setGraphicsConnector(void (*ptr)(std::vector<std::vector<short>>)){
    graphicsConnector = ptr;
}

short GameWindow::playerHandler(std::vector<std::vector<short>> board){
    start:
    if(mouseCol < 7){
        eclipses[0][mouseCol]->setVisible(true);
        eclipses[0][mouseCol]->setBrush(game->getTurn() == 1 ? Qt::red : Qt::yellow);
    }
    graphicsBoard->setVisible(true);
    makeMove = true;
    playerChoice = -1;

    while(playerChoice == -1) qApp->processEvents();
    makeMove = false;
    if(board[0][playerChoice] != 0) goto start;
    eclipses[0][playerChoice]->setVisible(false);
    return playerChoice;
}

void GameWindow::graphicsHandler(std::vector<std::vector<short>> board){
    graphicsBoard->setVisible(true);

    for(int i = 0; i <6; i++){
        for(int j = 0; j <7;j++){
            if (board[i][j] == 1) eclipses[i+1][j]->setBrush(Qt::red);
            else if (board[i][j] == 2) eclipses[i+1][j]->setBrush(Qt::yellow);
            else eclipses[i+1][j]->setBrush(Qt::white);
        }
    }
    qApp->processEvents();
    _sleep(250);
}

playerFunc GameWindow::textToAI(QString text){
    if(text == "Human") return playerConnector;
    if(text == "RandomAi") return randomAi;
    if(text == "SequentialAi") return sequentialAi;
    if(text == "MinMaxAiV0") return minMaxAiV0;
    return playerConnector;
}

void GameWindow::startGame(){
    player1 = textToAI(listSelection1->currentText());
    player2 = textToAI(listSelection2->currentText());
    listSelection1->setVisible(false);
    listSelection2->setVisible(false);
    btnStart->setVisible(false);
    game->setPlayer1(player1);
    game->setPlayer2(player2);
    game->setGraphics(graphicsConnector);
    game->startGame();
    QMessageBox msgBox;
    switch(game->getStatus()){
    case 1:
        msgBox.setText("Player 1 wins!");
        break;
    case 2:
        msgBox.setText("Player 2 wins!");
        break;
    case 3:
        msgBox.setText("It's a tie!");
        break;
    }
    msgBox.exec();

    listSelection1->setVisible(true);
    listSelection2->setVisible(true);
    btnStart->setVisible(true);
    graphicsBoard->setVisible(false);
}
