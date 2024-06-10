#ifndef SHAPE_H
#define SHAPE_H

void drawRing(Vector2 position, int gridSize);
void drawCross(Vector2 position, int gridSize);

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
        80*ringSize/100,
        ringSize, 0.0f, 360.0f, 0.0f, BLUE);
}

void
drawCross(Vector2 position, int gridSize)
{
    int minSize = (GetScreenWidth() <= GetScreenHeight()) ? GetScreenWidth() : GetScreenHeight();
    int padding = GetScreenWidth() / 50;
    int cellSize = (minSize - 2 * padding) / gridSize;
    float crossSize = (float)50*cellSize/100;

    DrawLineEx(
        (Vector2){
            GetScreenWidth()/2 - cellSize*gridSize/2 + position.x*cellSize + cellSize/2 - crossSize/2,
            GetScreenHeight()/2 - cellSize*gridSize/2 + position.y*cellSize + cellSize/2 - crossSize/2
        },
        (Vector2){
            GetScreenWidth()/2 - cellSize*gridSize/2 + position.x*cellSize + cellSize/2 + crossSize/2,
            GetScreenHeight()/2 - cellSize*gridSize/2 + position.y*cellSize + cellSize/2 + crossSize/2
        },
        15*crossSize/100,
        RED
    ); 
    DrawLineEx(
        (Vector2){
            GetScreenWidth()/2 - cellSize*gridSize/2 + position.x*cellSize + cellSize/2 + crossSize/2,
            GetScreenHeight()/2 - cellSize*gridSize/2 + position.y*cellSize + cellSize/2 - crossSize/2
        },
        (Vector2){
            GetScreenWidth()/2 - cellSize*gridSize/2 + position.x*cellSize + cellSize/2 - crossSize/2,
            GetScreenHeight()/2 - cellSize*gridSize/2 + position.y*cellSize + cellSize/2 + crossSize/2
        },
        15*crossSize/100,
        RED
    ); 
}

#endif
#endif