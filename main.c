#include <raylib.h>

#define BOARD_IMPLEMENTATION
#include "board.h"

#define SHAPE_IMPLEMENTATION
#include "shape.h"

int
main(void)
{
	Vector2 screenSize = (Vector2){ 800, 800 };

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(screenSize.x, screenSize.y, "Infinity TicTacToe");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		ClearBackground(BLACK);

		BeginDrawing();

		drawBoard(screenSize, 50, 3);

		drawRing((Vector2){ screenSize.x/2, screenSize.y/2 });
		drawCross(screenSize.x);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
