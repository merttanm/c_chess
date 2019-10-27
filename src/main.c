#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#include "../include/chessfunc.h"

/*
 * TODO
 * test pawn movement algorithm
 */

int main(int argc, char** argv){
    struct Board board, *bptr = &board;
    struct Piece piece, *pptr;
    struct Node *list = malloc(sizeof(struct Node));
    SDL_Rect *select_rect, *rectptr;
    select_rect = malloc(sizeof(SDL_Rect));
    initBoard(bptr);
    newGame(bptr);

    int THICK_BOARD, THICK_PIECE; 
    THICK_BOARD = 800;
    THICK_PIECE = 100;
    select_rect->w = THICK_PIECE;
    select_rect->h = THICK_PIECE;

    int mX, mY, last_mX, last_mY, flag, flag2;
    mX = -1;
    mY = -1;
    flag = 0;
    flag2 = 0;

    // returns zero on success else non-zero
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) 
        printf("error initializing SDL: %s\n", SDL_GetError());
    
    // create window 
    SDL_Window* win;
    win = SDL_CreateWindow(
        "Chess", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        THICK_BOARD, 
        THICK_BOARD, 
        0);

    // renderer to render our images 
    SDL_Renderer *rend;
    rend = SDL_CreateRenderer(
        win, 
        -1, 
        SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(
        rend, 
        SDL_BLENDMODE_BLEND);

    SDL_Surface *board_surface;

    SDL_Surface *rook_surface_w, *knight_surface_w, *bishop_surface_w;
    SDL_Surface *queen_surface_w, *king_surface_w, *pawn_surface_w;
    
    SDL_Surface *rook_surface_b, *knight_surface_b, *bishop_surface_b;
    SDL_Surface *queen_surface_b, *king_surface_b, *pawn_surface_b;
    
    board_surface = IMG_Load("../resources/chess_board.png");
    
    rook_surface_w = IMG_Load("../resources/rook_w.png");
    knight_surface_w = IMG_Load("../resources/knight_w.png");
    bishop_surface_w = IMG_Load("../resources/bishop_w.png");
    queen_surface_w = IMG_Load("../resources/queen_w.png");
    king_surface_w = IMG_Load("../resources/king_w.png");
    pawn_surface_w = IMG_Load("../resources/pawn_w.png");

    rook_surface_b = IMG_Load("../resources/rook_b.png");
    knight_surface_b = IMG_Load("../resources/knight_b.png");
    bishop_surface_b = IMG_Load("../resources/bishop_b.png");
    queen_surface_b = IMG_Load("../resources/queen_b.png");
    king_surface_b = IMG_Load("../resources/king_b.png");
    pawn_surface_b = IMG_Load("../resources/pawn_b.png");

    // loads image to our graphics hardware memory. 
    SDL_Texture *board_tex;
    board_tex = SDL_CreateTextureFromSurface(
        rend, 
        board_surface);
    
    SDL_Texture *rook_tex_w;
    rook_tex_w = SDL_CreateTextureFromSurface(
        rend,
        rook_surface_w);
    SDL_Texture *knight_tex_w;
    knight_tex_w = SDL_CreateTextureFromSurface(
        rend,
        knight_surface_w);
    SDL_Texture *bishop_tex_w;
    bishop_tex_w = SDL_CreateTextureFromSurface(
        rend,
        bishop_surface_w);
    SDL_Texture *queen_tex_w;
    queen_tex_w = SDL_CreateTextureFromSurface(
        rend,
        queen_surface_w);
    SDL_Texture *king_tex_w;
    king_tex_w = SDL_CreateTextureFromSurface(
        rend,
        king_surface_w);
    SDL_Texture *pawn_tex_w;
    pawn_tex_w = SDL_CreateTextureFromSurface(
        rend,
        pawn_surface_w);  

    SDL_Texture *rook_tex_b;
    rook_tex_b = SDL_CreateTextureFromSurface(
        rend,
        rook_surface_b);
    SDL_Texture *knight_tex_b;
    knight_tex_b = SDL_CreateTextureFromSurface(
        rend,
        knight_surface_b);
    SDL_Texture *bishop_tex_b;
    bishop_tex_b = SDL_CreateTextureFromSurface(
        rend,
        bishop_surface_b);
    SDL_Texture *queen_tex_b;
    queen_tex_b = SDL_CreateTextureFromSurface(
        rend,
        queen_surface_b);
    SDL_Texture *king_tex_b;
    king_tex_b = SDL_CreateTextureFromSurface(
        rend,
        king_surface_b);
    SDL_Texture *pawn_tex_b;
    pawn_tex_b = SDL_CreateTextureFromSurface(
        rend,
        pawn_surface_b);    


    // clear main-memory 
    SDL_FreeSurface(board_surface);

    SDL_FreeSurface(rook_surface_w);
    SDL_FreeSurface(knight_surface_w);
    SDL_FreeSurface(bishop_surface_w);
    SDL_FreeSurface(queen_surface_w);
    SDL_FreeSurface(king_surface_w);
    SDL_FreeSurface(pawn_surface_w);
    
    SDL_FreeSurface(rook_surface_b);
    SDL_FreeSurface(knight_surface_b);
    SDL_FreeSurface(bishop_surface_b);
    SDL_FreeSurface(queen_surface_b);
    SDL_FreeSurface(king_surface_b);
    SDL_FreeSurface(pawn_surface_b);


    // connect our textures with dest to control position 
    SDL_QueryTexture(board_tex, NULL, NULL, &THICK_BOARD, &THICK_BOARD);

    SDL_QueryTexture(rook_tex_w, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(knight_tex_w, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(bishop_tex_w, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(queen_tex_w, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(king_tex_w, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(pawn_tex_w, NULL, NULL, &THICK_PIECE, &THICK_PIECE);

    SDL_QueryTexture(rook_tex_b, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(knight_tex_b, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(bishop_tex_b, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(queen_tex_b, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(king_tex_b, NULL, NULL, &THICK_PIECE, &THICK_PIECE);
    SDL_QueryTexture(pawn_tex_b, NULL, NULL, &THICK_PIECE, &THICK_PIECE);

    int close = 0; 
    while(!close){

        // event management
        SDL_Event event;  
        while(SDL_PollEvent(&event)){ 
            switch(event.type){ 
                case SDL_QUIT:{
                    close = 1; 
                    break;
                } 

                case SDL_MOUSEBUTTONDOWN:{
                    last_mX = mX;
                    last_mY = mY;
                    mX = event.button.x/100;
                    mY = event.button.y/100;
                    pptr = &board.board[mX][mY].piece;
                    switch(event.button.button){
                        case SDL_BUTTON_LEFT:
                            printf("Click: ");
                            printf(
                                "%s %s AT (%d,%d)\n",
                                sideStr(pptr),
                                board.board[mX][mY].piece.type, 
                                mX, 
                                mY);
                            list = getPossibleMoves(list, pptr, bptr);
                            printf("moves: ");
                            ll_print(list);
                                
                            select_rect->x = mX*100;
                            select_rect->y = mY*100;
                            
                            if(last_mX != mX || last_mY != mY){
                                flag = 1;
                                flag2 = 0;
                            }else if(last_mX == mX && last_mY == mY && flag2 == 1){
                                flag = 1;
                                flag2 = 0;
                            }else if(last_mX == mX && last_mY == mY){
                                flag = 0;
                                flag2 = 1;
                            }

                            break;
                        
                        default: break;
                    }
                }
            }
        }

        // clears the screen 
        SDL_RenderClear(rend);

        // draw board and pieces
        SDL_RenderCopy(rend, board_tex, NULL, NULL);
        for(int x=0; x<8; x++){
            for(int y=0; y<8; y++){
                piece = board.board[x][y].piece;
                rectptr = &piece.dstrect;

                if(piece.side == 0 && piece.type == board.ROOK)
                    SDL_RenderCopy(rend, rook_tex_w, NULL, rectptr);
                else if(piece.side == 1 && piece.type == board.ROOK)
                    SDL_RenderCopy(rend, rook_tex_b, NULL, rectptr); 

                if(piece.side == 0 && piece.type == board.KNIGHT)
                    SDL_RenderCopy(rend, knight_tex_w, NULL, rectptr);
                else if(piece.side == 1 && piece.type == board.KNIGHT)
                    SDL_RenderCopy(rend, knight_tex_b, NULL, rectptr);

                if(piece.side == 0 && piece.type == board.BISHOP)
                    SDL_RenderCopy(rend, bishop_tex_w, NULL, rectptr);
                else if(piece.side == 1 && piece.type == board.BISHOP)
                    SDL_RenderCopy(rend, bishop_tex_b, NULL, rectptr);

                if(piece.side == 0 && piece.type == board.QUEEN)
                    SDL_RenderCopy(rend, queen_tex_w, NULL, rectptr);
                else if(piece.side == 1 && piece.type == board.QUEEN)
                    SDL_RenderCopy(rend, queen_tex_b, NULL, rectptr);

                if(piece.side == 0 && piece.type == board.KING)
                    SDL_RenderCopy(rend, king_tex_w, NULL, rectptr);
                else if(piece.side == 1 && piece.type == board.KING)
                    SDL_RenderCopy(rend, king_tex_b, NULL, rectptr);

                if(piece.side == 0 && piece.type == board.PAWN)
                    SDL_RenderCopy(rend, pawn_tex_w, NULL, rectptr);
                else if(piece.side == 1 && piece.type == board.PAWN)
                    SDL_RenderCopy(rend, pawn_tex_b, NULL, rectptr);
            }
        }

        SDL_SetRenderDrawColor(
            rend,
            0, 0, 150, 100);
        if(flag == 1){
            SDL_RenderFillRect(
                rend, select_rect);
            SDL_RenderDrawRect(
                rend, select_rect);
        }
        
  
        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend); 
  
        // calculates to 60 fps 
        SDL_Delay(1000 / 60);

    }
    // destroy texture 
    SDL_DestroyTexture(board_tex);

    SDL_DestroyTexture(rook_tex_w);
    SDL_DestroyTexture(knight_tex_w);
    SDL_DestroyTexture(bishop_tex_w); 
    SDL_DestroyTexture(queen_tex_w);
    SDL_DestroyTexture(king_tex_w);
    SDL_DestroyTexture(pawn_tex_w);

    SDL_DestroyTexture(rook_tex_b);
    SDL_DestroyTexture(knight_tex_b);
    SDL_DestroyTexture(bishop_tex_b); 
    SDL_DestroyTexture(queen_tex_b);
    SDL_DestroyTexture(king_tex_b);
    SDL_DestroyTexture(pawn_tex_b);
  
    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window
    SDL_DestroyWindow(win);

    // free allocated memory
    free(select_rect);
    destroyBoard(bptr);
    free(list);

    return 0;
}