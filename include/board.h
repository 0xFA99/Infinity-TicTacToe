#ifndef BOARD_H
#define BOARD_H

void drawBoard(int gridSize);

#ifdef BOARD_IMPLEMENTATION

void drawBoard(int gridSize)
{
    int minSize = (GetScreenWidth() <= GetScreenHeight()) ? GetScreenWidth() : GetScreenHeight();
    int padding = GetScreenWidth() / 50;
    int cellSize = (minSize - 2 * padding) / gridSize;
	int borderSize = minSize/50;

    for (int i = 1; i < gridSize; i++) {
        DrawLineEx(
            (Vector2){((GetScreenWidth() / 2) - ((cellSize * 3) / 2)) + (i * cellSize), ((GetScreenHeight() / 2) - ((cellSize * 3) / 2)) + padding},
            (Vector2){((GetScreenWidth() / 2) - ((cellSize * 3) / 2)) + (i * cellSize), (((GetScreenHeight() / 2) - ((cellSize * 3) / 2)) + (cellSize * gridSize)) - padding},
            borderSize,
            WHITE
        );

        DrawLineEx(
            (Vector2){((GetScreenWidth() / 2) - ((cellSize * 3) / 2)) + padding, ((GetScreenHeight() / 2) - ((cellSize * 3) / 2)) + (i * cellSize)},
            (Vector2){(((GetScreenWidth() / 2) - ((cellSize * 3) / 2)) + (cellSize * gridSize)) - padding, ((GetScreenHeight() / 2) - ((cellSize * 3) / 2)) + (i * cellSize)},
            borderSize,
            WHITE
        );
    }
}

#endif
#endif
