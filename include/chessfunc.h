#include "Piece.h"
#include "Board.h"

/*
 *
 */ 
void initBoard(struct Board *board);

/*
 *
 */
void destroyBoard(struct Board *board); 

/*
 * sets all pieces to their starting positions
 * @param board pointer to Board data structure
 */ 
void newGame(struct Board *board);

/*
 * moves a piece to the coordinates (x,y)
 * @param p pointer to point on board
 */ 
void movePiece(struct Point *p);

/*
 *
 */ 
char *sideStr(struct Piece *piece);

/*
 *
 */
struct Point **getPossibleMoves(struct Piece *piece); 