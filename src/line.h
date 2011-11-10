#ifndef LINE_H
#define LINE_H

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

typedef struct Lines Lines;
struct Lines {
  int  n;
  Point *p;
};

typedef struct LineList LineList;
struct LineList {
  int  n;
  Point* p;
  LineList* next;
}; 

void  lineDraw(FILE* fpt, float startx, float starty, float endx, float endy);
void  lineDraw2(FILE* fpt, Line l);
int   linesRead(FILE* fpt, Lines *l);
int   linesDraw(FILE* fpt, Lines l);
bool  readLine(FILE *fpt, char* buf, int bufLen);
int   lineListRead(FILE* fpt, LineList *top);
int   lineListDraw(FILE* fpt, LineList top);
bool  freeLineList(LineList* lineList);

#endif
