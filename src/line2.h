#ifndef LINE2_H
#define LINE2_H

#include "predef.h"

typedef struct Point Point;
struct Point {
    float x;
    float y;
};

typedef struct Line Line;
struct Line {
    Point start;
    Point end;
};

void lineDraw2(FILE* fpt, Line l);

#endif
