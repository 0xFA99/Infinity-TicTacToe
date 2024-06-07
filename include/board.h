#ifndef BOARD_H
#define BOARD_H

#define BOARD_COLOR (Color) { 59, 66, 82 }

void drawBoard(Vector2 screenSize, int padding, int gridSize);

#ifdef BOARD_IMPLEMENTATION

void
drawBoard(Vector2 screenSize, int padding, int gridSize)
{
	int cellSize = (screenSize.x - 2 * padding) / gridSize;

	for (int i = 1; i < gridSize; i++) {
		DrawLineEx(
				(Vector2){ padding + i*cellSize, padding + i },
				(Vector2){ padding + i*cellSize, screenSize.y - padding + i },
				 8,
				 WHITE);

		DrawLineEx(
				(Vector2){ padding + i, padding + i*cellSize },
				(Vector2){ screenSize.y - padding + i, padding + i*cellSize },
				8,
				WHITE);
	}
}

#endif
#endif
