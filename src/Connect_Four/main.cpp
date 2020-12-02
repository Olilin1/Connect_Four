#include "gamewindow.h"
#include <QApplication>

GameWindow *window;

short windowConnector(std::vector<std::vector<short>> board){
    short t = window->playerHandler(board);
    return t;
}

int main(int argc, char **argv) {
QApplication app (argc, argv);

QGraphicsScene *myScene = new QGraphicsScene();
window = new GameWindow(myScene);
window->show();
window->setConnector(windowConnector); //God this is a dumb way of handling it
return app.exec();
}
