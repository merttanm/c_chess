/*
 * linked list data structure
 * to hold Point data structures
 */ 
struct pointNode{
    /*
     * pointer to this node's data
     * @note points to NULL if no data
     */
    struct Point *data;
    
    /*
     * char pointer representing
     * the point data as a string
     */ 
    char *str_data;
    
    /*
     * pointer to the next node
     * @note points to NULL if no next node
     */
    struct pointNode *next;

    /*
     * pointer to the previous node
     * @note points to NULL if no previous node
     */
    struct pointNode *prev;
};

/*
 * linked list data structure
 * to hold SDL_Rect pointers
 */ 
struct rectNode{
    /*
     * pointer to this node's data
     * @note points to NULL if no data
     */
    struct SDL_Rect *data;
    
    /*
     * pointer to the next node
     * @note points to NULL if no next node
     */
    struct rectNode *next;

    /*
     * pointer to the previous node
     * @note points to NULL if no previous node
     */
    struct rectNode *prev;
};

/*
 * linked list data structure
 * to hold Piece data structures
 */ 
struct pieceNode{
    /*
     * pointer to this node's data
     * @note points to NULL if no data
     */
    struct Piece *data;
    
    /*
     * pointer to the next node
     * @note points to NULL if no data
     */
    struct pieceNode *next;
    
    /*
     * pointer to the previous node
     * @note points to NULL if no previous node
     */
    struct pieceNode *prev;
};