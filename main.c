#include <raylib.h>

#include "game.h"

#define BOARD_IMPLEMENTATION
#include "board.h"

#define SHAPE_IMPLEMENTATION
#include "shape.h"

#define INPUT_IMPLEMENTATION
#include "input.h"

int
main(void)
{
	Vector2 screenSize = (Vector2){ 600, 1000 };
	
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(screenSize.x, screenSize.y, "Infinity TicTacToe");

	Board board = initBoard(GRID, BLACK0, WHITE0);

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		ClearBackground(BLACK);

		updateBoardSize(&board);

		handleInput(&board);

		BeginDrawing();

		drawBoard(&board);

		drawCell(&board);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
