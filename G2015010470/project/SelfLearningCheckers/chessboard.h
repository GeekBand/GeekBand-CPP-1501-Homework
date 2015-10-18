#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "colleague.h"
#include "checkersdata.h"
#include "checkersstate.h"

namespace checkers {

    class ChessBoard : public QWidget, public Colleague
    {
        Q_OBJECT

    public:
        ChessBoard(QWidget *parent = 0);
        virtual void onEvent(const Event& event);
        QSize minimumSizeHint() const Q_DECL_OVERRIDE;
        QSize sizeHint() const Q_DECL_OVERRIDE;
        QRect getSquareArea(int row, int col) const;
        QRect getChessArea(int row, int col) const;
        QPoint getRowCol(int x, int y) const;
        void sendMessage(std::string msg);
        void doMakeMove(const CheckersMove* move);
        const CheckersData* getCheckersData();
        const CheckersState* getCheckersState();
        void doClickSquare(int row, int col);
        ~ChessBoard();

    protected:
        void mousePressEvent(QMouseEvent* event);
        void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    private:
        const Colleague* state;
        const Colleague* data;
        int selectedRow;
        int selectedCol;
    };

}

#endif // CHESSBOARD_H
