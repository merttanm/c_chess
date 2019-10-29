#include "Board.h"
#include "node.h"

/*
 * initiates board safely
 * @param board pointer to board data structure
 */ 
void initBoard(struct Board *board);

/*
 * destroys board safely
 * @param board pointer to board data structure
 */
void destroyBoard(struct Board *board); 

/*
 * sets all pieces to their starting positions
 * @param board pointer to Board data structure
 */ 
void newGame(struct Board *board);

/*
 * moves piece at srcpt to dstpt
 * @param srcpt pointer to point containing piece to be moved
 * @param dstpt pointer to point to be moved to
 * @param board pointer to board data structure
 */ 
void movePiece(
    struct Point *srcpt, 
    struct Point *dstpt, 
    struct Board *board);

/*
 * push a point onto a linked list
 * @param head_ref head node of linked list
 * @param new_data data to be pushed onto list
 */
void ll_push_point(
    struct pointNode **head_ref, 
    struct Point *new_data);

/*
 * push a rect onto a linked list
 * @param head_ref head node of linked list
 * @param new_data data to be pushed onto list
 */
void ll_push_rect(
    struct rectNode **head_ref,
    SDL_Rect *new_data); 

/*
 * push a piece onto a linked list
 * @param head_ref head node of linked list
 * @param new_data data to be pushed onto list
 */
void ll_push_piece(
    struct pieceNode **head_ref,
    struct Piece *new_data); 

/*
 * print out the points in a point linked list
 * @param ll linked list containing points or NULL
 */
void ll_print_points(struct pointNode *ll);  

/*
 * team of a piece represented as a string
 * @param piece pointer to any piece
 * @return "WHITE" if piece->side == 0
 * @return "BLACK" if piece->side == 1
 * @return "EMPTY" if piece->side == -1
 */ 
char *sideStr(struct Piece *piece);

/*
 * get a linked list of all the possible moves
 * of a given piece
 * @param ll point linked list to write to
 * @param piece pointer to piece to find possible moves for
 * @param board pointer to board data structure
 * @return linked list of points that piece may move to
 */
struct pointNode *getPossibleMoves(
    struct pointNode *ll, 
    struct Piece *piece,
    struct Board *board);

/*
 * get a linked list of rects 
 * representing the squares in which 
 * a piece may move to
 * @param rlist linked list of rects to write to
 * @param plist linked list of points to write to
 * @return linked list of rects that represent 
 * where a piece may move to
 */
struct rectNode *getMRects(
    struct rectNode *rlist,
    struct pointNode *plist);

/*
 * boolean variable determining whether
 * piece may move to dstpt or not.
 * @param piece pointer to piece to check
 * @param dstpt pointer to point to check
 * @param board pointer to board data structure
 * @return 1 if true
 * @return 0 if false
 */
int can_move_to(
    struct Piece *piece, 
    struct Point *dstpt, 
    struct Board *board);