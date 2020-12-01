#include "gamewindow.h"
#include <QApplication>

GameWindow *window;

short testAi(std::vector<std::vector<short>>){
    qDebug() << "HWO";
    while(true) qApp->processEvents();
    return 5;
}

int main(int argc, char **argv) {
QApplication app (argc, argv);

QGraphicsScene *myScene = new QGraphicsScene();
window = new GameWindow(myScene);
window->show();
window->game = new ConnectFourGame(testAi, testAi);

return app.exec();
}
