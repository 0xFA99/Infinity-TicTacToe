#ifndef INPUT_H
#define INPUT_H

#include "board.h"

Vector2 mousePos;
static int filled = 0;

void handleInput(Board *board);
void drawCollision(Board *board);

#ifdef INPUT_IMPLEMENTATION

void
handleInput(Board *board)
{

    mousePos = GetMousePosition();
    Rectangle rect = (Rectangle){
        board->startOffset.x,
        board->startOffset.y,
        board->cell,
        board->cell
    };

    if (CheckCollisionPointRec(mousePos, rect)) filled = 1;
    else filled = 0;
}

void
drawCollision(Board *board)
{
    Rectangle rect = (Rectangle){
        board->startOffset.x + board->line/2,
        board->startOffset.y + board->line/2,
        board->cell - board->line,
        board->cell - board->line
    };

    if (filled == 1)
        DrawRectangleRec(rect, BLACK1);
    else
        DrawRectangleRec(rect, BLACK0);
}

#endif
#endif
