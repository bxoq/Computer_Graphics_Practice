#ifndef LINES_H
#define LINES_H

#include "predef.h"

typedef struct Point Point;
struct Point {
    float x;
    float y;
};

typedef struct Lines Lines;
struct Lines {
    int  n;
    Point *p;
};

int linesRead(FILE* fpt, Lines *l);
int linesDraw(FILE* fpt, Lines l);
bool readLine(FILE *fpt, char* buf, int bufLen);
#endif
