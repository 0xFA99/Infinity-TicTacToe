#ifndef SHAPE_H
#define SHAPE_H

void drawRing(Vector2 position);
void drawCross(int position);

#ifdef SHAPE_IMPLEMENTATION

void
drawRing(Vector2 position)
{
    DrawRing(position, 60.0f, 80.0f, 0.0f, 360.0f, 0.0f, BLUE);
}

void
drawCross(int position)
{
    DrawLineEx(
        (Vector2){ (position/2) - 80, (position/2) - 80 },
        (Vector2){ (position/2) + 80, (position/2) + 80 },
        20,
        RED
    ); 
    DrawLineEx(
        (Vector2){ (position/2) + 80, (position/2) - 80 },
        (Vector2){ (position/2) - 80, (position/2) + 80 },
        20,
        RED
    ); 
}

#endif
#endif