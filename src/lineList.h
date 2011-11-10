#ifndef LINELIST_H
#define LINELIST_H

#include "predef.h"
#include "lines.h"

typedef struct LineList LineList;
struct LineList {
    int  n;             /* 一つの点のグループ内の点の個数 */
    Point* p ;          /* グループ内のポイントの点の配列 */
    LineList* next;     /* 次のグループへのポインター */
}; 

int lineListRead(FILE* fpt, LineList *top);
int lineListDraw(FILE* fpt, LineList top);
bool freeLineList(LineList* lineList);
#endif
