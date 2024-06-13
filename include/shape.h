#ifndef SHAPE_H
#define SHAPE_H

#include "game.h"
#include "board.h"

void drawRing(Board *board, Vector2 position, Color color);
void drawCross(Board *board, Vector2 position, Color color);

#ifdef SHAPE_IMPLEMENTATION

void
drawRing(Board *board, Vector2 position, Color color)
{
    // void DrawCircle(int centerX, int centerY, float radius, Color color); // Draw a color-filled circle
    // DrawCircle(
    //     board->startOffset.x + board->cell*position.x - board->cell/2,
    //     board->startOffset.y + board->cell*position.y - board->cell/2,
    //     board->cell/3,
    //     color
    // );
    // DrawCircle(
    //     board->startOffset.x + board->cell*position.x - board->cell/2,
    //     board->startOffset.y + board->cell*position.y - board->cell/2,
    //     board->cell/4,
    //     BLACK0
    // );

    // void DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);
    DrawRing(
        (Vector2){
            board->startOffset.x + board->cell*position.x - board->cell/2,
            board->startOffset.y + board->cell*position.y - board->cell/2,
        },
        board->cell/4,
        board->cell/3,
        0,
        360,
        0,
        color
    );

}

void
drawCross(Board *board, Vector2 position, Color color)
{
    // void DrawLineEx(Vector2 board->startPos, Vector2 endPos, float thick, Color color);                       // Draw a line (using triangles/quads)
    int size = board->cell/3 - board->cell/4;

    DrawLineEx(
        (Vector2) {
            board->startOffset.x + board->cell*position.x - board->cell/2 - board->cell/3 + size,
            board->startOffset.y + board->cell*position.y - board->cell/2 - board->cell/3 + size
        },
        (Vector2) {
            board->startOffset.x + board->cell*position.x - board->cell/2 + board->cell/3 - size,
            board->startOffset.y + board->cell*position.y - board->cell/2 + board->cell/3 - size
        },
        size,
        color
    );
    DrawLineEx(
        (Vector2) {
            board->startOffset.x + board->cell*position.x - board->cell/2 + board->cell/3 - size,
            board->startOffset.y + board->cell*position.y - board->cell/2 - board->cell/3 + size
        },
        (Vector2) {
            board->startOffset.x + board->cell*position.x - board->cell/2 - board->cell/3 + size,
            board->startOffset.y + board->cell*position.y - board->cell/2 + board->cell/3 - size
        },
        size,
        color
    );
}

#endif
#endif
