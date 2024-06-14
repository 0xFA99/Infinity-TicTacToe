#ifndef INPUT_H
#define INPUT_H

#include "game.h"
#include "board.h"
#include "shape.h"

void handleInput(Board *board);
void drawCell(Board *board);

#ifdef INPUT_IMPLEMENTATION

void
handleInput(Board *board)
{
    mousePos = GetMousePosition();

    for (int i = 0; i < board->grid*board->grid; i++) {

        if (CheckCollisionPointRec(mousePos, cellList[i].rect)) {
            cellList[i].collision = true;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                cellList[i].state = FILLED_X;
            }
        } else {
            cellList[i].collision = false;
        } 
    }
}

void
drawCell(Board *board)
{
    for (int i = 0; i < board->grid*board->grid; i++) {

        if (cellList[i].collision) {
            switch (cellList[i].state) {
                case EMPTY: DrawRectangleRec(cellList[i].rect, BLACK1); break;
                case FILLED_X: {
                    DrawRectangleRec(cellList[i].rect, RED1);
                    drawCross(board, (Vector2){
                        (cellList[i].rect.x - board->startOffset.x)/board->cell + 1,
                        (cellList[i].rect.y - board->startOffset.y)/board->cell + 1
                    },
                    RED0);
                } break;
                case FILLED_O: {
                    DrawRectangleRec(cellList[i].rect, BLUE1);
                    drawRing(board, (Vector2){
                        (cellList[i].rect.x - board->startOffset.x)/board->cell + 1,
                        (cellList[i].rect.y - board->startOffset.y)/board->cell + 1
                    },
                    BLUE0);
                } break;
                default: break;
            }
        } else {
            switch (cellList[i].state) {
                case EMPTY: DrawRectangleRec(cellList[i].rect, BLACK0); break;
                case FILLED_X: {
                    DrawRectangleRec(cellList[i].rect, BLACK0);
                    drawCross(board, (Vector2){
                        (cellList[i].rect.x - board->startOffset.x)/board->cell + 1,
                        (cellList[i].rect.y - board->startOffset.y)/board->cell + 1
                    },
                    RED0);
                } break;
                case FILLED_O: {
                    DrawRectangleRec(cellList[i].rect, BLACK0);
                    drawRing(board, (Vector2){
                        (cellList[i].rect.x - board->startOffset.x)/board->cell + 1,
                        (cellList[i].rect.y - board->startOffset.y)/board->cell + 1
                    },
                    BLUE0);
                } break;
                default: break;
            }
        }
    }
}

#endif
#endif
