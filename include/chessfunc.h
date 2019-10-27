#include "Board.h"
#include "node.h"

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
void ll_push(
    struct Node **head_ref, 
    struct Point *new_data, 
    size_t data_size);

/*
 *
 */
void ll_print(struct Node *ll);  

/*
 *
 */ 
char *sideStr(struct Piece *piece);

/*
 *
 */
struct Node *getPossibleMoves(
    struct Node *ll, 
    struct Piece *piece,
    struct Board *board);