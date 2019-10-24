#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/chessfunc.h"

void initBoard(struct Board *board){
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
                piece.side = 0;
                piece.type = board->ROOK;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if((x==0 || x==7) && y==7){
                piece.side = 1;
                piece.type = board->ROOK;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // knights
            else if((x==1 || x==6) && y==0){
                piece.side = 0;
                piece.type = board->KNIGHT;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if((x==1 || x==6) && y==7){
                piece.side = 1;
                piece.type = board->KNIGHT;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // bishops
            else if((x==2 || x==5) && y==0){
                piece.side = 0;
                piece.type = board->BISHOP;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if((x==2 || x==5) && y==7){
                piece.side = 1;
                piece.type = board->BISHOP;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // queens
            else if(x==3 && y==0){
                piece.side = 0;
                piece.type = board->QUEEN;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if(x==3 && y==7){
                piece.side = 1;
                piece.type = board->QUEEN;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // kings
            else if(x==4 && y==0){
                piece.side = 0;
                piece.type = board->KING;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if(x==4 && y==7){
                piece.side = 1;
                piece.type = board->KING;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }

            // pawns
            else if(y==1){
                piece.side = 0;
                piece.type = board->PAWN;
                piece.dstrect.h = px;
                piece.dstrect.w = px;
                piece.dstrect.x = x*100;
                piece.dstrect.y = y*100;
                point.piece = piece;
                board->board[x][y] = point;
            }else if(y==6){
                piece.side = 1;
                piece.type = board->PAWN;
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
                point.piece = piece;
                board->board[x][y] = point;
            }
        }
    }
}

void movePiece(struct Point *p){
    //code
}

char *sideStr(struct Piece *piece){
    if(piece->side == 0)
        return "WHITE";
    else if(piece->side == 1)
        return "BLACK";
    else
        return "EMPTY";
}

struct Point **getPossibleMoves(struct Piece *piece){
    return 0;
}