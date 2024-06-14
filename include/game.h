#ifndef GAME_H
#define GAME_H

// COLORS
#define BLACK0  (Color){ 55, 62, 77, 255 } 
#define BLACK1  (Color){ 76, 86, 106, 255 }
#define WHITE0  (Color){ 244, 244, 244, 255 }
#define WHITE1  (Color){ 255, 255, 255, 255 }
#define BLUE0   (Color){ 99, 197, 234, 255 }
#define BLUE1   (Color){ 122, 147, 234, 255 }
#define RED0    (Color){ 250, 90, 164, 255 }
#define RED1    (Color){ 250, 116, 178, 255 }

#define GRID 3

typedef enum CellState { EMPTY = 0, FILLED_X, FILLED_O } CellState;

typedef struct SCell {
    Rectangle rect;
    CellState state;
    bool collision;
} SCell;

SCell cellList[GRID*GRID] = { 0 };
Vector2 mousePos;

#endif