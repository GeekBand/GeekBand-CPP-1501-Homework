#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QString>
#include "chessboard.h"

class QLabel;
class QMenu;
class QAction;
class QActionGroup;
class QPushButton;

namespace checkers {

    class Window : public QMainWindow, public Colleague
    {
        Q_OBJECT

    public:
        Window();
        virtual void onEvent(const Event& event);
        void setMessage(QString text);
        ~Window();
    private slots:
        void newGame();
        void resign();
        void exit();
    private:
        void createAction();
        void createMenu();

        ChessBoard *chessBoard;
        QLabel *shapeLabel;
        QMenu *gameMenu;
        QAction *newGameAction;
        QAction *resignAction;
        QAction *exitAction;

        QPushButton *newGameButtton;
        QPushButton *resignButton;
    };
}

#endif // WINDOW_H
