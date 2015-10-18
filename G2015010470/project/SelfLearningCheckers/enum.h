#ifndef ENUM
#define ENUM

enum Square{
    EMPTY,
    RED,
    RED_KING,
    BLACK,
    BLACK_KING
};

enum EventName {
    ACTION_SETUP,
    ACTION_NEWGAME,
    ACTION_RESING,
    ACTION_REVERSE,
    ACTION_MOVE,
    ACTION_EXIT,
    NOTIFY_GAMEOVER,
    NOTIFY_BOARD,
    NOTIFY_STATE,
    NOTIFY_MESSAGE
};


#endif // ENUM

