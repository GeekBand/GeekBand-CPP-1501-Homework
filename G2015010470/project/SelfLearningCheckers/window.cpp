#include "chessboard.h"
#include "window.h"
#include <QtGui>
#include <QtWidgets>
using namespace checkers;

Window::Window()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    shapeLabel = new QLabel(tr("Shape:"));
    shapeLabel->setStyleSheet("QLabel { color : lightGreen; }");
    shapeLabel->setFont(QFont("Serif", 12, QFont::Bold, true));
    shapeLabel->setText("Click \"New Game\" to start a new game.");

    setStyleSheet("background-color: darkGreen");
    chessBoard = new ChessBoard(this);
    chessBoard->setStyleSheet("background-color: black");

    newGameButtton = new QPushButton(tr("New Game"));
    newGameButtton->setMinimumWidth(200);
    newGameButtton->setStyleSheet("background-color: lightGray");

    resignButton = new QPushButton(tr("Resign"));
    resignButton->setMinimumWidth(200);
    resignButton->setStyleSheet("background-color: lightGray");

    QGridLayout *boardLayout = new QGridLayout;

    boardLayout->setColumnMinimumWidth(0,30);
    boardLayout->setRowMinimumHeight(0,30);

    boardLayout->addWidget(chessBoard, 1, 1);

    boardLayout->setColumnMinimumWidth(2,30);
    boardLayout->setRowMinimumHeight(2,30);

    boardLayout->addWidget(shapeLabel, 3, 1);

    boardLayout->setRowMinimumHeight(4,30);

    createAction();
    createMenu();

    widget->setLayout(boardLayout);
    widget->setWindowTitle(tr("Checkers"));

    Mediator::getInstance().attach(NOTIFY_MESSAGE, this);
    Mediator::getInstance().attach(NOTIFY_GAMEOVER, this);

    Event e(ACTION_SETUP, this);
    this->fireEvent(e);
}

void Window::createAction() {
    newGameAction = new QAction(tr("&New Game"), this);
    newGameAction->setShortcut(QKeySequence::New);
    newGameAction->setStatusTip(tr("Start a new game."));
    connect(newGameAction, SIGNAL(triggered()), this, SLOT(newGame()));

    resignAction = new QAction(tr("&Resin"), this);
    resignAction->setShortcut(QKeySequence::Refresh);
    resignAction->setStatusTip(tr("Stop this game"));
    connect(resignAction, SIGNAL(triggered()), this, SLOT(resign()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the game"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(exit()));

}

void Window::createMenu() {
    gameMenu = menuBar()->addMenu(tr("&New Game"));
    gameMenu->addAction(newGameAction);
    //gameMenu->addAction(resignAction);
    //gameMenu->addAction(exitAction);
    connect(gameMenu, SIGNAL(triggered()), this, SLOT(newGame()));
}

void Window::newGame() {
    Event e(ACTION_NEWGAME);
    e.setSource(this);
    this->fireEvent(e);
}

void Window::resign() {
    Event e(ACTION_RESING);
    e.setSource(this);
    this->fireEvent(e);
}

void Window::exit() {
    Event e(ACTION_EXIT);
    e.setSource(this);
    this->fireEvent(e);
}

Window::~Window() {
    Mediator::getInstance().detach(NOTIFY_MESSAGE, this);
    Mediator::getInstance().detach(NOTIFY_GAMEOVER, this);
}

void Window::onEvent(const Event& event) {
    if (event.getName() == NOTIFY_MESSAGE) {
        shapeLabel->setText(QString::fromStdString(event.getMessage()));
    } else if (event.getName() == NOTIFY_GAMEOVER) {
        shapeLabel->setText(QString::fromStdString(event.getMessage()));
    }
}
