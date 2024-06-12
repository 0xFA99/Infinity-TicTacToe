#ifndef BOARD_H
#define BOARD_H

#define CONSTRAINT_PROPORTIONAL 100

typedef struct Board {
    Vector2 startOffset;
    int grid;
    int cell;
    int line;
    Color foreground;
    Color background;
} Board;

Board initBoard(int grid, Color background, Color foreground);
void updateBoardSize(Board *board);
void drawBoard(Board *board);

#ifdef BOARD_IMPLEMENTATION

Board
initBoard(int grid, Color background, Color foreground)
{
    Board board;
    board.grid = grid;
    board.foreground = foreground;
    board.background = background;

    updateBoardSize(&board);

    return board;
}

void
updateBoardSize(Board *board)
{
    int minScreen   = (GetScreenWidth() <= GetScreenHeight())
                    ? GetScreenWidth()
                    : GetScreenHeight();

    board->line = minScreen/CONSTRAINT_PROPORTIONAL;
    board->cell = minScreen/board->grid;
    board->startOffset = (Vector2) {
        GetScreenWidth()/2 - board->cell*board->grid/2,
        GetScreenHeight()/2 - board->cell*board->grid/2
    };
}

static void
drawGridBoard(Vector2 startOffset, int grid, int cell, int width, Color color)
{
    for (int i = 1; i < grid; i++) {
        // Vertical
        DrawLineEx(
            (Vector2){ startOffset.x + cell*i, startOffset.y },
            (Vector2){ startOffset.x + cell*i, startOffset.y + cell*grid },
            width,
            color
        );

        // Horizontal
        DrawLineEx(
            (Vector2){ startOffset.x, startOffset.y + cell*i },
            (Vector2){ startOffset.x + cell*grid, startOffset.y + cell*i },
            width,
            color
        );
    }
}

void
drawBoard(Board *board)
{
    // Draw Board Background
    DrawRectangle(
        board->startOffset.x,
        board->startOffset.y,
        board->cell*board->grid,
        board->cell*board->grid,
        board->background
    );

    // Draw Board Grids
    drawGridBoard(
        board->startOffset,
        board->grid,
        board->cell,
        board->line,
        board->foreground
    );
}

#endif
#endif
