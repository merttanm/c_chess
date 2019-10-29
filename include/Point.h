#include "Piece.h"

struct Point{
    /*
     * x-coordinate of the point
     */ 
    int x;

    /*
     * y-coordinate of the point
     */
    int y;

    /*
     * boolean flag determining whether 
     * this piece is in check by a white piece
     * @note 1 if true
     * @note 0 if false
     */
    int checked_byw;

    /*
     * boolean flag determining whether 
     * this piece is in check by a white piece
     * @note 1 if true
     * @note 0 if false
     */
    int checked_byb;

    /*
     * piece that is currently situated
     * at this point
     */ 
    struct Piece piece;
};