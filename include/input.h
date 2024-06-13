#ifndef INPUT_H
#define INPUT_H

#include "game.h"
#include "board.h"

void handleInput(Board *board);
void drawCollision(Board *board);

#ifdef INPUT_IMPLEMENTATION

static void
drawCollisionState(int cellIdx, CellState state)
{
    switch (state) {
        case FILLED_X: DrawRectangleRec(cellList[cellIdx], BLACK1); break;
        case FILLED_O: DrawRectangleRec(cellList[cellIdx], BLACK0); break;
        break;
        default: break;
    }
}

void
handleInput(Board *board)
{
    mousePos = GetMousePosition();

    for (int i = 0; i < board->grid*board->grid; i++) {
        if (CheckCollisionPointRec(mousePos, cellList[i]))
            cellStateList[i] = FILLED_X;
        else cellStateList[i] = EMPTY;
    }
}

void
drawCollision(Board *board)
{
    for (int i = 0; i < board->grid*board->grid; i++) {
        DrawRectangleRec(cellList[i], BLACK0);

        if (cellStateList[i]) {
            drawCollisionState(i, cellStateList[i]);
        }
    }
}

#endif
#endif
