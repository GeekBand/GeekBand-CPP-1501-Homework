#include "window.h"
#include "checkersdata.h"
#include "checkersstate.h"
#include "mediator.h"
#include "player.h"
#include "movestrategy.h"
#include <QApplication>
using namespace checkers;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CheckersData* board = new CheckersData;
    CheckersState* state = new CheckersState;
    MoveStrategy* strategy = new MovesRandom;
    Player* mechinePlayer = new Player(strategy);
    Window w;

    w.show();

    return a.exec();
}
