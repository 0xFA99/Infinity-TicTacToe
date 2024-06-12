#include <raylib.h>

#define BOARD_IMPLEMENTATION
#include "board.h"

// #define SHAPE_IMPLEMENTATION
// #include "shape.h"
// 
// #define INPUT_IMPLEMENTATION
// #include "input.h"

#define BLACK0 (Color){ 76, 86, 106, 255 }
#define WHITE0 (Color){ 244, 244, 244, 255 }

int
main(void)
{
	Vector2 screenSize = (Vector2){ 600, 1000};
	
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(screenSize.x, screenSize.y, "Infinity TicTacToe");

	Board board = initBoard(3, BLACK0, WHITE0);

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		ClearBackground(BLACK);

		// handleInput(3);
		updateBoardSize(&board);

		BeginDrawing();

		drawBoard(&board);

		// drawCollision();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
