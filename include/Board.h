#include "Point.h"

struct Board{
    /*
     * multidimensional array of pointers to points
     * representing the chess board
     */ 
    struct Point board[8][8];

    /*
     * linked list data structure
     * containing pointers to all white pieces
     */ 
    struct pieceNode *white_pcs;
    
    /*
     * linked list data structure
     * containing pointers to all black pieces
     */
    struct pieceNode *black_pcs;

    /*
     * array of rect pointers representing 
     * each point on the board; 
     * used for drawing movement rects
     */ 
    SDL_Rect *board_rects[8][8];

    /* 
     * char pointer to ROOK type
     * represented as a string
     * @note "ROOK"
     */
    char* ROOK;

    /* 
     * char pointer to KNIGHT type
     * represented as a string
     * @note "KNIGHT"
     */
    char* KNIGHT;

    /* 
     * char pointer to BISHOP type
     * represented as a string
     * @note "BISHOP"
     */
    char* BISHOP;
    
    /* 
     * char pointer to QUEEN type
     * represented as a string
     * @note "QUEEN"
     */
    char* QUEEN;
    
    /* 
     * char pointer to KING type
     * represented as a string
     * @note "KING"
     */
    char* KING;

    /* 
     * char pointer to PAWN type
     * represented as a string
     * @note "PAWN"
     */
    char* PAWN;

    /* 
     * char pointer to EMPTY type
     * represented as a string
     * @note "EMPTY"
     */
    char* EMPTY;
};