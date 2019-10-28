#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/chessfunc.h"

void initBoard(struct Board *board){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            board->board_rects[i][j] = malloc(sizeof(SDL_Rect));
            board->board_rects[i][j]->h = 100;
            board->board_rects[i][j]->w = 100;
            board->board_rects[i][j]->x = i*100;
            board->board_rects[i][j]->y = j*100;
        }
    }

    board->ROOK = malloc(sizeof(char)*10);
    board->KNIGHT = malloc(sizeof(char)*10);
    board->BISHOP = malloc(sizeof(char)*10);
    board->QUEEN = malloc(sizeof(char)*10);
    board->KING = malloc(sizeof(char)*10);
    board->PAWN = malloc(sizeof(char)*10);
    board->EMPTY = malloc(sizeof(char)*10);

    strcpy(board->ROOK, "ROOK");
    strcpy(board->KNIGHT, "KNIGHT");
    strcpy(board->BISHOP, "BISHOP");
    strcpy(board->QUEEN, "QUEEN");
    strcpy(board->KING, "KING");
    strcpy(board->PAWN, "PAWN");
    strcpy(board->EMPTY, "EMPTY");
}

void destroyBoard(struct Board *board){
    free(board->ROOK);
    free(board->KNIGHT);
    free(board->BISHOP);
    free(board->QUEEN);
    free(board->KING);
    free(board->PAWN);
    free(board->EMPTY);
}

void newGame(struct Board *board){
    struct Point point;
    struct Piece piece;
    int px = 100;
    for(int x=0; x<8; x++){
        for(int y=0; y<8; y++){
            point.x = x;
            point.y = y;
            

            // rooks
            if((x==0 || x==7) && y==0){
                piece.side = 1;
                piece.type = board->ROOK;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if((x==0 || x==7) && y==7){
                piece.side = 0;
                piece.type = board->ROOK;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // knights
            else if((x==1 || x==6) && y==0){
                piece.side = 1;
                piece.type = board->KNIGHT;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if((x==1 || x==6) && y==7){
                piece.side = 0;
                piece.type = board->KNIGHT;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // bishops
            else if((x==2 || x==5) && y==0){
                piece.side = 1;
                piece.type = board->BISHOP;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if((x==2 || x==5) && y==7){
                piece.side = 0;
                piece.type = board->BISHOP;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // queens
            else if(x==3 && y==0){
                piece.side = 1;
                piece.type = board->QUEEN;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if(x==3 && y==7){
                piece.side = 0;
                piece.type = board->QUEEN;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // kings
            else if(x==4 && y==0){
                piece.side = 1;
                piece.type = board->KING;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if(x==4 && y==7){
                piece.side = 0;
                piece.type = board->KING;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // pawns
            else if(y==1){
                piece.side = 1;
                piece.type = board->PAWN;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if(y==6){
                piece.side = 0;
                piece.type = board->PAWN;
                piece.x = x;
                piece.y = y;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // empties
            else{
                piece.side = -1;
                piece.type = board->EMPTY;
                piece.x = x;
                piece.y = y;
                point.piece = piece;
                board->board[x][y] = point;
            }
        }
    }
}

void movePiece(struct Point *p){
    //code
}

void ll_push_point(struct pointNode **head_ref, struct Point *new_data){
    struct pointNode *new_node = (struct pointNode*)malloc(sizeof(struct pointNode)); 
    new_node->data = malloc(sizeof(struct Point));
    new_node->data = new_data;
    new_node->str_data = malloc(sizeof(char)*10);
    sprintf(
        new_node->str_data, 
        "(%d,%d)", 
        new_node->data->x,
        new_node->data->y);
    (*head_ref)->prev = new_node;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    *head_ref = new_node;
}

void ll_push_rect(struct rectNode **head_ref, SDL_Rect *new_data){
    struct rectNode *new_node = (struct rectNode*)malloc(sizeof(struct rectNode));
    new_node->data = malloc(sizeof(SDL_Rect));
    new_node->data = new_data;
    (*head_ref)->prev = new_node;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    *head_ref = new_node;
}

void ll_print_points(struct pointNode *ll){
    if(ll->data == NULL){
        printf("NULL\n");
    }else{
        while(ll->data != NULL){
            printf("%s ", ll->str_data);
            ll = ll->next;
        }
        printf("\n");
        while(ll->data != NULL){
            ll = ll->prev;
        }
    }
}

char *sideStr(struct Piece *piece){
    if(piece->side == 0)
        return "WHITE";
    else if(piece->side == 1)
        return "BLACK";
    else
        return "EMPTY";
}

struct pointNode *getPossibleMoves(struct pointNode *ll, struct Piece *piece, struct Board *board){
    ll->data = NULL;
    ll->str_data = "";
    ll->next = NULL;
    
    if(strcmp(piece->type, "ROOK") == 0){
        int x = piece->x;
        int y = piece->y;

        // right
        for(x+=1; x < 8; x++){
            if(strcmp(board->board[x][y].piece.type, "EMPTY") == 0){
                ll_push_point(
                    &ll,
                    &board->board[x][y]);
            }else{
                if(board->board[x][y].piece.side == piece->side)
                    break;
                else if(board->board[x][y].piece.side != piece->side){
                    ll_push_point(
                        &ll,
                        &board->board[x][y]);
                    break;
                }
            }
        }
        x = piece->x;

        // left
        for(x-=1; x >= 0; x--){
            if(strcmp(board->board[x][y].piece.type, "EMPTY") == 0){
                ll_push_point(
                    &ll,
                    &board->board[x][y]);
            }else{
                if(board->board[x][y].piece.side == piece->side)
                    break;
                else if(board->board[x][y].piece.side != piece->side){
                    ll_push_point(
                        &ll,
                        &board->board[x][y]);
                    break;
                }
            }
        }
        x = piece->x;

        // up
        for(y-=1; y >= 0; y--){
            if(strcmp(board->board[x][y].piece.type, "EMPTY") == 0){
                ll_push_point(
                    &ll,
                    &board->board[x][y]);
            }else{
                if(board->board[x][y].piece.side == piece->side)
                    break;
                else if(board->board[x][y].piece.side != piece->side){
                    ll_push_point(
                        &ll,
                        &board->board[x][y]);
                    break;
                }
            }
        }
        y = piece->y;

        // down
        for(y+=1; y < 8; y++){
            if(strcmp(board->board[x][y].piece.type, "EMPTY") == 0){
                ll_push_point(
                    &ll,
                    &board->board[x][y]);
            }else{
                if(board->board[x][y].piece.side == piece->side)
                    break;
                else if(board->board[x][y].piece.side != piece->side){
                    ll_push_point(
                        &ll,
                        &board->board[x][y]);
                    break;
                }
            }
        }

        return ll;
    }

    else if(strcmp(piece->type, "KNIGHT") == 0){
        //int x = piece->x;
        //int y = piece->y;
        return ll;
    }

    else if(strcmp(piece->type, "BISHOP") == 0){
        //int x = piece->x;
        //int y = piece->y;
        return ll;
    }

    else if(strcmp(piece->type, "QUEEN") == 0){
        //int x = piece->x;
        //int y = piece->y;
        return ll;
    }

    else if(strcmp(piece->type, "KING") == 0){
        //int x = piece->x;
        //int y = piece->y;
        return ll;
    }

    else if(strcmp(piece->type, "PAWN") == 0){
        int x = piece->x;
        int y = piece->y;
        
        if(piece->side == 0){
            // regular movements
            if(y == 6){
                for(y-=1; y >= piece->y-2; y--){
                    if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0)
                        break;
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }else{
                y-=1;
                if(strcmp(board->board[x][y].piece.type, "EMPTY") == 0)
                    ll_push_point(
                        &ll,
                        &board->board[x][y]);
            }

            // captures
            if(strcmp(board->board[piece->x-1][piece->y-1].piece.type, "EMPTY") != 0
            && piece->x-1 >= 0 && piece->x-1 <= 7
            && piece->y-1 >= 0 && piece->y-1 <= 7){
                ll_push_point(
                    &ll,
                    &board->board[piece->x-1][piece->y-1]);
            }
            if(strcmp(board->board[piece->x+1][piece->y-1].piece.type, "EMPTY") != 0
            && piece->x+1 >= 0 && piece->x+1 <= 7
            && piece->y-1 >= 0 && piece->y-1 <= 7){
                ll_push_point(
                    &ll,
                    &board->board[piece->x+1][piece->y-1]);
            }
        }else if(piece->side == 1){
            // regular movements
            if(y == 1){
                for(y+=1; y <= piece->y+2; y++){
                    if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0)
                        break;
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }else{
                y+=1;
                if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0)
                    ll_push_point(
                        &ll,
                        &board->board[x][y]);
            }

            // captures
            if(strcmp(board->board[piece->x-1][piece->y+1].piece.type, "EMPTY") != 0
            && piece->x-1 >= 0 && piece->x-1 <= 7
            && piece->y+1 >= 0 && piece->y+1 <= 7){
                ll_push_point(
                    &ll,
                    &board->board[piece->x-1][piece->y+1]);
            }
            if(strcmp(board->board[piece->x+1][piece->y+1].piece.type, "EMPTY") != 0
            && piece->x+1 >= 0 && piece->x+1 <= 7
            && piece->y+1 >= 0 && piece->y+1 <= 7){
                ll_push_point(
                    &ll,
                    &board->board[piece->x+1][piece->y+1]);
            }
        }

        return ll;
    }

    else if(strcmp(piece->type, "EMPTY") == 0){
        return ll;
    }
        
    return ll;
}

struct rectNode *getMRects(struct rectNode *rlist, struct pointNode *plist){
    rlist->data = NULL;
    rlist->next = NULL;
    
    SDL_Rect *rptr = malloc(sizeof(SDL_Rect));
    rptr->h = 100;
    rptr->w = 100;

    while(plist->data != NULL){
        rptr->x = plist->data->x*100;
        rptr->y = plist->data->y*100;
        ll_push_rect(
            &rlist,
            rptr);

        plist = plist->next;
    }

    return rlist;
}