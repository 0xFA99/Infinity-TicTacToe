#include <raylib.h>

#define BOARD_IMPLEMENTATION
#include "board.h"

int
main(void)
{
	Vector2 screenSize = (Vector2){ 800, 800 };

	InitWindow(screenSize.x, screenSize.y, "Infinity TicTacToe");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		ClearBackground(BLACK);

		BeginDrawing();

		drawBoard(screenSize, 50, 3);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
