#ifndef SHAPE_H
#define SHAPE_H

void drawRing(Vector2 position, int gridSize);
void drawCross(int position);

#ifdef SHAPE_IMPLEMENTATION

void
drawRing(Vector2 position, int gridSize)
{
    int minSize = (GetScreenWidth() <= GetScreenHeight()) ? GetScreenWidth() : GetScreenHeight();
    int padding = GetScreenWidth() / 50;
    int cellSize = (minSize - 2 * padding) / gridSize;
    float ringSize = (float)30*cellSize/100;

    DrawRing(
        (Vector2) {
            (((GetScreenWidth()/2) - ((cellSize*gridSize)/2)) + (((position.x*cellSize)) + cellSize/2)),
            (((GetScreenHeight()/2) - ((cellSize*gridSize)/2)) + (((position.y*cellSize)) + cellSize/2))
        },
        80*ringSize/100, ringSize, 0.0f, 360.0f, 0.0f, BLUE);
}

void
drawCross(int position)
{
    DrawLineEx(
        (Vector2){ (position/2) - 80, (position/2) - 80 },
        (Vector2){ (position/2) + 80, (position/2) + 80 },
        20,
        RED
    ); 
    DrawLineEx(
        (Vector2){ (position/2) + 80, (position/2) - 80 },
        (Vector2){ (position/2) - 80, (position/2) + 80 },
        20,
        RED
    ); 
}

#endif
#endif