#ifndef CHECKERSDATA
#define CHECKERSDATA
#include <vector>
#include "colleague.h"

namespace checkers {

    class CheckersMove {
    public:
        int fromRow;
        int fromCol;
        int toRow;
        int toCol;

        CheckersMove(int r1, int c1, int r2, int c2):
            fromRow(r1), fromCol(c1), toRow(r2), toCol(c2){
        }

        bool isJump() const {
            return (fromRow - toRow == 2 || fromRow - toRow == -2);
        }
    };

   typedef std::vector<CheckersMove> LegalMoves;

   class CheckersData : public Colleague {
   public:
       CheckersData();
       void setUpGame();
       const Square& pieceAt(int row, int col) const;
       void getBoard(Square board[][8]) const;
       void makeMove(const CheckersMove* move);
       void makeMove(int fromRow, int fromCol, int toRow, int toCol);
       LegalMoves getLegalMoves(Square player) const;
       LegalMoves getLegalJumpsFrom(Square player, int row, int col) const;
       void onEvent(const Event& event);
       ~CheckersData();
   private:
       bool canJump(Square player, int r1, int c1, int r2, int c2, int r3, int c3) const;
       bool canMove(Square player, int r1, int c1, int r2, int c2) const;
       Square board[8][8];
   };
}

#endif // CHECKERSDATA

