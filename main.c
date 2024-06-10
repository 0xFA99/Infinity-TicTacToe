#include <raylib.h>

#define BOARD_IMPLEMENTATION
#include "board.h"

#define SHAPE_IMPLEMENTATION
#include "shape.h"

int
main(void)
{
	Vector2 screenSize = (Vector2){ 600, 1000};
	
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(screenSize.x, screenSize.y, "Infinity TicTacToe");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		ClearBackground(BLACK);

		BeginDrawing();

		drawBoard(3);

		drawRing((Vector2){ 0, 0 }, 3);
		drawRing((Vector2){ 0, 1 }, 3);
		drawRing((Vector2){ 0, 2 }, 3);

		drawRing((Vector2){ 1, 0 }, 3);
		drawRing((Vector2){ 1, 1 }, 3);
		drawRing((Vector2){ 1, 2 }, 3);

		drawRing((Vector2){ 2, 0 }, 3);
		drawRing((Vector2){ 2, 1 }, 3);
		drawRing((Vector2){ 2, 2 }, 3);

		// drawCross(screenSize.x);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
