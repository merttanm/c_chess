#include <SDL2/SDL.h>

struct Piece{
    /*
     * represents team of piece
     * @note -1 if empty
     * @note 0 if white
     * @note 1 if black
     */ 
    int side;

    int x;

    int y;

    /*
     *
     */ 
    char *type;

    /*
     *
     */
    SDL_Rect dstrect;
    
};