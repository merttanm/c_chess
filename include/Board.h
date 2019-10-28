#include "Point.h"

struct Board{
    /*
     * multidimensional array of pointers to points
     * represents the chess board
     */ 
    struct Point board[8][8];

    SDL_Rect *board_rects[8][8];

    char* ROOK;
    char* KNIGHT;
    char* BISHOP;
    char* QUEEN;
    char* KING;
    char* PAWN;
    char* EMPTY;
};