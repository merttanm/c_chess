#include <SDL2/SDL.h>

struct Piece{
    /*
     * represents team of piece
     * @note -1 if empty
     * @note 0 if white
     * @note 1 if black
     */ 
    int side;

    /*
     * x-coordinate of piece
     */ 
    int x;

    /*
     * y-coordinate of piece
     */
    int y;

    /*
     * type of piece
     * @note "ROOK" if rook
     * @note "KNIGHT" if knight
     * @note "BISHOP" if bishop
     * @note "QUEEN" if queen
     * @note "KING" if king
     * @note "PAWN" if pawn
     * @note "EMPTY" if N/A
     */ 
    char *type;

    /*
     * rect representing the position of
     * the sprite of this piece
     */
    SDL_Rect *dstrect;
};