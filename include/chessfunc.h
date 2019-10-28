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
 * @param
 */ 
void movePiece(
    struct Point *srcpt, 
    struct Point *dstpt, 
    struct Board *board);

/*
 *
 */
void ll_push_point(
    struct pointNode **head_ref, 
    struct Point *new_data);

/*
 *
 */
void ll_push_rect(
    struct rectNode **head_ref,
    SDL_Rect *new_data); 

/*
 *
 */
void ll_print_points(struct pointNode *ll);  

/*
 *
 */ 
char *sideStr(struct Piece *piece);

/*
 *
 */
struct pointNode *getPossibleMoves(
    struct pointNode *ll, 
    struct Piece *piece,
    struct Board *board);

/*
 *
 */
struct rectNode *getMRects(
    struct rectNode *rlist,
    struct pointNode *plist);

/*
 *
 */
int can_move_to(
    struct Piece *piece, 
    struct Point *dstpt, 
    struct Board *board); 