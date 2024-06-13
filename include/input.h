#ifndef INPUT_H
#define INPUT_H

#include "board.h"

Vector2 mousePos;
static int filled = 0;

// TEMPORARY ARRAY FOR TEST
#define CELL_CAP 9
Rectangle rectList[CELL_CAP];
int colorState[CELL_CAP];

void handleInput(Board *board);
void drawCollision(Board *board);
#ifdef INPUT_IMPLEMENTATION

void
handleInput(Board *board)
{
    mousePos = GetMousePosition();

    for (int i = 0; i < CELL_CAP; i++) {
        rectList[i].x = board->line/2 + board->startOffset.x + board->cell*(i%3);
        rectList[i].y = board->line/2 + board->startOffset.y + board->cell*(i/3);
        rectList[i].width = board->cell - board->line;
        rectList[i].height = board->cell - board->line;
    }

    for (int i = 0; i < CELL_CAP; i++) {
        if (CheckCollisionPointRec(mousePos, rectList[i])) colorState[i] = 1;
        else colorState[i] = 0;
    }
}

void
drawCollision(Board *board)
{
    for (int i = 0; i < CELL_CAP; i++) {
        DrawRectangleRec(rectList[i], BLACK0);

        if (colorState[i]) {
            DrawRectangleRec(rectList[i], BLACK1);
        }
    }
}

#endif
#endif
