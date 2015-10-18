#include <vector>
#include "checkersdata.h"
#include "event.h"
using namespace checkers;

CheckersData::CheckersData(){
    Mediator::getInstance().attach(ACTION_SETUP, this);
    Mediator::getInstance().attach(ACTION_NEWGAME, this);
    Mediator::getInstance().attach(ACTION_MOVE, this);
}

CheckersData::~CheckersData() {
    Mediator::getInstance().detach(ACTION_SETUP, this);
    Mediator::getInstance().detach(ACTION_NEWGAME, this);
    Mediator::getInstance().detach(ACTION_MOVE, this);
}

void CheckersData::setUpGame() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (row % 2 == col % 2) {
                if (row < 3)
                    this->board[row][col] = BLACK;
                else if (row > 4)
                    board[row][col] = RED;
                else
                    board[row][col] = EMPTY;
            } else {
                board[row][col] = EMPTY;
            }
        }
    }
}

const Square& CheckersData::pieceAt(int row, int col) const {
    return this->board[row][col];
}

void CheckersData::getBoard(Square board[][8]) const {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = this->board[i][j];
        }
    }
}

void CheckersData::makeMove(const CheckersMove *move) {
    makeMove(move->fromRow, move->fromCol, move->toRow, move->toCol);
}

void CheckersData::makeMove(int fromRow, int fromCol, int toRow, int toCol) {
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = EMPTY;
    if (fromRow - toRow == 2 || fromRow - toRow == -2) {
        int jumpRow = (fromRow + toRow) / 2;
        int jumpCol = (fromCol + toCol) / 2;
        board[jumpRow][jumpCol] = EMPTY;
    }
    if (toRow == 0 && board[toRow][toCol] == RED)
        board[toRow][toCol] = RED_KING;
    if (toRow == 7 && board[toRow][toCol] == BLACK)
        board[toRow][toCol] = BLACK_KING;
}

LegalMoves CheckersData::getLegalMoves(Square player) const {
    LegalMoves moves;
    if (player != RED && player != BLACK)
        return moves;

    Square playerKing;
    if (player == RED)
        playerKing = RED_KING;
    else
        playerKing = BLACK_KING;

    //check for any possible jumps
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (board[row][col] == player || board[row][col] == playerKing) {
                if (canJump(player, row, col, row+1, col+1, row+2, col+2))
                    moves.push_back(CheckersMove(row, col, row+2, col+2));
                if (canJump(player, row, col, row-1, col+1, row-2, col+2))
                    moves.push_back(CheckersMove(row, col, row-2, col+2));
                if (canJump(player, row, col, row+1, col-1, row+2, col-2))
                    moves.push_back(CheckersMove(row, col, row+2, col-2));
                if (canJump(player, row, col, row-1, col-1, row-2, col-2))
                    moves.push_back(CheckersMove(row, col, row-2, col-2));
            }
        }
    }

    // check for any regular moves
    if (moves.size() == 0) {
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                if (board[row][col] == player || board[row][col] == playerKing) {
                    if (canMove(player, row, col, row+1, col+1))
                        moves.push_back(CheckersMove(row, col, row+1, col+1));
                    if (canMove(player, row, col, row-1, col+1))
                        moves.push_back(CheckersMove(row, col, row-1, col+1));
                    if (canMove(player, row, col, row+1, col-1))
                        moves.push_back(CheckersMove(row, col, row+1, col-1));
                    if (canMove(player, row, col, row-1, col-1))
                        moves.push_back(CheckersMove(row, col, row-1, col-1));
                }
            }
        }
    }

    return moves;
}

LegalMoves CheckersData::getLegalJumpsFrom(Square player, int row, int col) const {
    LegalMoves moves;
    if (player != RED && player != BLACK)
        return moves;
    int playerKing;
    if (player == RED)
        playerKing = RED_KING;
    else
        playerKing = BLACK_KING;

    if (board[row][col] == player || board[row][col] == playerKing) {
        if (canJump(player, row, col, row+1, col+1, row+2, col+2))
            moves.push_back(CheckersMove(row, col, row+2, col+2));
        if (canJump(player, row, col, row-1, col+1, row-2, col+2))
            moves.push_back(CheckersMove(row, col, row-2, col+2));
        if (canJump(player, row, col, row+1, col-1, row+2, col-2))
            moves.push_back(CheckersMove(row, col, row+2, col-2));
        if (canJump(player, row, col, row-1, col-1, row-2, col-2))
            moves.push_back(CheckersMove(row, col, row-2, col-2));
    }

    return moves;
}

bool CheckersData::canJump(Square player, int r1, int c1, int r2, int c2, int r3, int c3) const {
    if (r3 < 0 || r3 >=8 || c3 < 0 || c3 >= 8)
        return false;

    if (this->board[r3][c3] != EMPTY)
        return false;

    if (player == RED) {
        if (board[r1][c1] == RED && r3 > r1)
            return false;
        if (board[r2][c2] != BLACK && board[r2][c2] != BLACK_KING)
            return false;
        return true;
    } else {
        if (board[r1][c1] == BLACK && r3 < r1)
            return false;
        if (board[r2][c2] != RED && board[r2][c2] != RED_KING)
            return false;
        return true;
    }

}

bool CheckersData::canMove(Square player, int r1, int c1, int r2, int c2) const {
    if (r2 < 0 || r2 >=8 || c2 < 0 || c2 >= 8)
        return false;

    if (this->board[r2][c2] != EMPTY)
        return false;

    if (player == RED) {
        if (board[r1][c1] == RED && r2 > r1)
            return false;
        return true;
    } else {
        if (board[r1][c1] == BLACK && r2 < r1)
            return false;
        return true;
    }
}

void CheckersData::onEvent(const Event& event) {
    if(event.getName() == ACTION_NEWGAME || event.getName() == ACTION_SETUP) {
        setUpGame();
        Event e(NOTIFY_BOARD);
        e.setSource(this);
        this->fireEvent(e);
    } else if (event.getName() == ACTION_MOVE) {
        const CheckersMove* move = ((MoveEvent&)event).getMove();
        makeMove(move);
        Event e(NOTIFY_BOARD);;
        e.setSource(this);
        this->fireEvent(e);
    }
}
