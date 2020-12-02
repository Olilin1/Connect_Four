#include "gamewindow.h"
#include <QApplication>

GameWindow *window;

short windowPlayerConnector(std::vector<std::vector<short>> board){
    short t = window->playerHandler(board);
    return t;
}

void windowGraphicsConnector(std::vector<std::vector<short>> board){
window->graphicsHandler(board);
return;
}

int main(int argc, char **argv) {
QApplication app (argc, argv);

QGraphicsScene *myScene = new QGraphicsScene();
window = new GameWindow(myScene);
window->show();
window->setPlayerConnector(windowPlayerConnector); //God this is a dumb way of handling it
window->setGraphicsConnector(windowGraphicsConnector);
return app.exec();
}
