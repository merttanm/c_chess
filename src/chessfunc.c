#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/chessfunc.h"

void initBoard(struct Board *board){
    board->white_pcs = malloc(sizeof(struct pieceNode));
    board->black_pcs = malloc(sizeof(struct pieceNode));

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            board->board_rects[i][j] = malloc(sizeof(SDL_Rect));
            board->board_rects[i][j]->h = 100;
            board->board_rects[i][j]->w = 100;
            board->board_rects[i][j]->x = i*100;
            board->board_rects[i][j]->y = j*100;
        }
    }

    board->ROOK = malloc(sizeof(char)*4);
    board->KNIGHT = malloc(sizeof(char)*6);
    board->BISHOP = malloc(sizeof(char)*6);
    board->QUEEN = malloc(sizeof(char)*5);
    board->KING = malloc(sizeof(char)*4);
    board->PAWN = malloc(sizeof(char)*4);
    board->EMPTY = malloc(sizeof(char)*5);

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
    emptyPieceList(&board->white_pcs);
    emptyPieceList(&board->black_pcs);

    struct Point *point[8][8];
    struct Piece *piece[8][8];
    int px = 100;
    for(int x=0; x<8; x++){
        for(int y=0; y<8; y++){
            point[x][y] = malloc(sizeof(struct Point));
            piece[x][y] = malloc(sizeof(struct Piece));
            piece[x][y]->dstrect = malloc(sizeof(SDL_Rect));
            point[x][y]->x = x;
            point[x][y]->y = y;

            // rooks
            if((x==0 || x==7) && y==0){
                piece[x][y]->side = 1;
                piece[x][y]->type = board->ROOK;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->black_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }else if((x==0 || x==7) && y==7){
                piece[x][y]->side = 0;
                piece[x][y]->type = board->ROOK;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->white_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }

            // knights
            else if((x==1 || x==6) && y==0){
                piece[x][y]->side = 1;
                piece[x][y]->type = board->KNIGHT;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->black_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }else if((x==1 || x==6) && y==7){
                piece[x][y]->side = 0;
                piece[x][y]->type = board->KNIGHT;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->white_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }

            // bishops
            else if((x==2 || x==5) && y==0){
                piece[x][y]->side = 1;
                piece[x][y]->type = board->BISHOP;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->black_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }else if((x==2 || x==5) && y==7){
                piece[x][y]->side = 0;
                piece[x][y]->type = board->BISHOP;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->white_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }

            // queens
            else if(x==3 && y==0){
                piece[x][y]->side = 1;
                piece[x][y]->type = board->QUEEN;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->black_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }else if(x==3 && y==7){
                piece[x][y]->side = 0;
                piece[x][y]->type = board->QUEEN;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->white_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }

            // kings
            else if(x==4 && y==0){
                piece[x][y]->side = 1;
                piece[x][y]->type = board->KING;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->black_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }else if(x==4 && y==7){
                piece[x][y]->side = 0;
                piece[x][y]->type = board->KING;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->white_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }

            // pawns
            else if(y==1){
                piece[x][y]->side = 1;
                piece[x][y]->type = board->PAWN;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->black_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }else if(y==6){
                piece[x][y]->side = 0;
                piece[x][y]->type = board->PAWN;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                ll_push_piece(&board->white_pcs, piece[x][y]);
                board->board[x][y] = *point[x][y];
            }

            // empties
            else{
                piece[x][y]->side = -1;
                piece[x][y]->type = board->EMPTY;
                piece[x][y]->x = x;
                piece[x][y]->y = y;
                piece[x][y]->dstrect->h = px;
                piece[x][y]->dstrect->w = px;
                piece[x][y]->dstrect->x = x*100;
                piece[x][y]->dstrect->y = y*100;
                point[x][y]->piece = *piece[x][y];
                board->board[x][y] = *point[x][y];
            }
        }
    }
}

void movePiece(struct Point *srcpt, struct Point *dstpt, struct Board *board){
    dstpt->piece.dstrect->x = dstpt->x*100;
    dstpt->piece.dstrect->y = dstpt->y*100;

    dstpt->piece.type = srcpt->piece.type;
    srcpt->piece.type = board->EMPTY;

    dstpt->piece.side = srcpt->piece.side;
    srcpt->piece.side = -1;
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

void ll_push_piece(struct pieceNode **head_ref, struct Piece *new_data){
    struct pieceNode *new_node = (struct pieceNode*)malloc(sizeof(struct pieceNode));
    new_node->data = malloc(sizeof(struct Piece));
    new_node->data = new_data;
    (*head_ref)->prev = new_node;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    *head_ref = new_node;
}

void ll_print_points(struct pointNode *ll){
    if(ll->data == NULL)
        printf("NULL\n");
    else{
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
        int x = piece->x;
        int y = piece->y;

        y += 2;
        if(y >= 0 && y < 8){
            x = piece->x+1;
            if(x >= 0 && x < 8){
                if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0){
                    if(board->board[x][y].piece.side != piece->side){
                        ll_push_point(
                            &ll, 
                            &board->board[x][y]);
                    }
                }else{
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }

            x = piece->x-1;
            if(x >= 0 && x < 8){
                if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0){
                    if(board->board[x][y].piece.side != piece->side){
                        ll_push_point(
                            &ll, 
                            &board->board[x][y]);
                    }
                }else{
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }
        }
        x = piece->x;
        y = piece->y;

        y-= 2;
        if(y >= 0 && y < 8){
            x = piece->x+1;
            if(x >= 0 && x < 8){
                if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0){
                    if(board->board[x][y].piece.side != piece->side){
                        ll_push_point(
                            &ll, 
                            &board->board[x][y]);
                    }
                }else{
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }

            x = piece->x-1;
            if(x >= 0 && x < 8){
                if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0){
                    if(board->board[x][y].piece.side != piece->side){
                        ll_push_point(
                            &ll, 
                            &board->board[x][y]);
                    }
                }else{
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }
        }
        x = piece->x;
        y = piece->y;

        x += 2;
        if(x >= 0 && x < 8){
            y = piece->y+1;
            if(y >= 0 && y < 8){
                if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0){
                    if(board->board[x][y].piece.side != piece->side){
                        ll_push_point(
                            &ll, 
                            &board->board[x][y]);
                    }
                }else{
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }

            y = piece->y-1;
            if(y >= 0 && y < 8){
                if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0){
                    if(board->board[x][y].piece.side != piece->side){
                        ll_push_point(
                            &ll, 
                            &board->board[x][y]);
                    }
                }else{
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }
        }
        x = piece->x;
        y = piece->y;

        x-= 2;
        if(x >= 0 && x < 8){
            y = piece->y+1;
            if(y >= 0 && y < 8){
                if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0){
                    if(board->board[x][y].piece.side != piece->side){
                        ll_push_point(
                            &ll, 
                            &board->board[x][y]);
                    }
                }else{
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }

            y = piece->y-1;
            if(y >= 0 && y < 8){
                if(strcmp(board->board[x][y].piece.type, "EMPTY") != 0){
                    if(board->board[x][y].piece.side != piece->side){
                        ll_push_point(
                            &ll, 
                            &board->board[x][y]);
                    }
                }else{
                    ll_push_point(
                        &ll, 
                        &board->board[x][y]);
                }
            }
        }

        return ll;
    }

    else if(strcmp(piece->type, "BISHOP") == 0){
        int x = piece->x;
        int y = piece->y;

        //up-right
        x += 1;
        y -= 1;
        while(x >= 0 && x < 8 && y >= 0 && y < 8){
            if(board->board[x][y].piece.type == board->EMPTY)
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
            else if(board->board[x][y].piece.side != piece->side){
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
                break;
            }else break;
            x += 1;
            y -= 1;
        }
        x = piece->x;
        y = piece->y;

        //up-left
        x -= 1;
        y -= 1;
        while(x >= 0 && x < 8 && y >= 0 && y < 8){
            if(board->board[x][y].piece.type == board->EMPTY)
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
            else if(board->board[x][y].piece.side != piece->side){
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
                break;
            }else break;
            x -= 1;
            y -= 1;
        }
        x = piece->x;
        y = piece->y;

        //down-left
        x -= 1;
        y += 1;
        while(x >= 0 && x < 8 && y >= 0 && y < 8){
            if(board->board[x][y].piece.type == board->EMPTY)
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
            else if(board->board[x][y].piece.side != piece->side){
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
                break;
            }else break;
            x -= 1;
            y += 1;
        }
        x = piece->x;
        y = piece->y;

        //down-right
        x += 1;
        y += 1;
        while(x >= 0 && x < 8 && y >= 0 && y < 8){
            if(board->board[x][y].piece.type == board->EMPTY)
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
            else if(board->board[x][y].piece.side != piece->side){
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
                break;
            }else break;
                
            x += 1;
            y += 1;
        }


        return ll;
    }

    else if(strcmp(piece->type, "QUEEN") == 0){
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
        y = piece->y;
        //up-right
        x += 1;
        y -= 1;
        while(x >= 0 && x < 8 && y >= 0 && y < 8){
            if(board->board[x][y].piece.type == board->EMPTY)
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
            else if(board->board[x][y].piece.side != piece->side){
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
                break;
            }else break;
            x += 1;
            y -= 1;
        }
        x = piece->x;
        y = piece->y;
        //up-left
        x -= 1;
        y -= 1;
        while(x >= 0 && x < 8 && y >= 0 && y < 8){
            if(board->board[x][y].piece.type == board->EMPTY)
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
            else if(board->board[x][y].piece.side != piece->side){
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
                break;
            }else break;
            x -= 1;
            y -= 1;
        }
        x = piece->x;
        y = piece->y;
        //down-left
        x -= 1;
        y += 1;
        while(x >= 0 && x < 8 && y >= 0 && y < 8){
            if(board->board[x][y].piece.type == board->EMPTY)
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
            else if(board->board[x][y].piece.side != piece->side){
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
                break;
            }else break;
            x -= 1;
            y += 1;
        }
        x = piece->x;
        y = piece->y;
        //down-right
        x += 1;
        y += 1;
        while(x >= 0 && x < 8 && y >= 0 && y < 8){
            if(board->board[x][y].piece.type == board->EMPTY)
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
            else if(board->board[x][y].piece.side != piece->side){
                ll_push_point(
                    &ll, 
                    &board->board[x][y]);
                break;
            }else break;
                
            x += 1;
            y += 1;
        }

        return ll;
    }

    else if(strcmp(piece->type, "KING") == 0){
        //int x, y;
        
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
                if(piece->y-1 >= 0)
                    if(strcmp(board->board[x][y-1].piece.type, "EMPTY") == 0)
                        ll_push_point(
                            &ll,
                            &board->board[x][y-1]);
            }

            // captures
            if(piece->x-1 >= 0 && piece->x-1 <= 7
            && piece->y-1 >= 0 && piece->y-1 <= 7
            && board->board[piece->x-1][piece->y-1].piece.side == 1){
                if(strcmp(board->board[piece->x-1][piece->y-1].piece.type, "EMPTY") != 0){
                    ll_push_point(
                        &ll,
                        &board->board[piece->x-1][piece->y-1]);
                }
            }
            if(piece->x+1 >= 0 && piece->x+1 <= 7
            && piece->y-1 >= 0 && piece->y-1 <= 7
            && board->board[piece->x+1][piece->y-1].piece.side == 1){
                if(strcmp(board->board[piece->x+1][piece->y-1].piece.type, "EMPTY") != 0){
                    ll_push_point(
                        &ll,
                        &board->board[piece->x+1][piece->y-1]);
                }
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
                if(piece->y+1 <= 7)
                    if(strcmp(board->board[x][y+1].piece.type, "EMPTY") == 0)
                        ll_push_point(
                            &ll,
                            &board->board[x][y+1]);
            }

            // captures
            if(piece->x-1 >= 0 && piece->x-1 <= 7
            && piece->y+1 >= 0 && piece->y+1 <= 7
            && board->board[piece->x-1][piece->y+1].piece.side == 0){
                if(strcmp(board->board[piece->x-1][piece->y+1].piece.type, "EMPTY") != 0){
                    ll_push_point(
                        &ll,
                        &board->board[piece->x-1][piece->y+1]);
                }
            }
            if(piece->x+1 >= 0 && piece->x+1 <= 7
            && piece->y+1 >= 0 && piece->y+1 <= 7
            && board->board[piece->x+1][piece->y+1].piece.side == 0){
                if(strcmp(board->board[piece->x+1][piece->y+1].piece.type, "EMPTY") != 0){
                    ll_push_point(
                    &ll,
                    &board->board[piece->x+1][piece->y+1]);
                }
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

int can_move_to(struct Piece *piece, struct Point *dstpt, struct Board *board){
    struct pointNode *plist;
    plist = malloc(sizeof(struct pointNode));
    plist = getPossibleMoves(plist, piece, board);

    while(plist->data != NULL){
        if(plist->data->x == dstpt->x && plist->data->y == dstpt->y)
            return 1;
        plist = plist->next;
    }

    free(plist);

    return 0;
}

void emptyPieceList(struct pieceNode **head_ref){
    if((*head_ref)->data == NULL) return;

    struct pieceNode *current = *head_ref; 
    struct pieceNode *next; 
  
    while(current != NULL){ 
        next = current->next; 
        free(current); 
        current = next; 
    }
    
    *head_ref = NULL; 
} 