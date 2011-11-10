#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "lineList.h"

/*
 * Upon successful completion, each node & point use malloc to alloc memory, 
 * use freeLineList() free up.
 * If an error occurs, lineListRead() return 0.
 */
int lineListRead(FILE* fpt, LineList *top){
    const int bufLen = 256;
    char buf[bufLen];
    
    /* Header part not save any contents, just link to next node */
    LineList* currNode = top;
    currNode->next = (LineList*)malloc(sizeof(LineList));
    
    while(readLine(fpt, buf, bufLen)){
        int n = atoi(buf);
        if (n < 1) return 0;
        
        currNode = currNode->next;
        currNode->n = n;
        currNode->p = (Point*)malloc(sizeof(Point) * n);
        currNode->next = (LineList*)malloc(sizeof(LineList));
        
        int i = 0;
        
        while (i < currNode->n && readLine(fpt, buf, bufLen)) {
            /* FIXME:
             * 1) Direct use atof() is not safe.
             * 2) Only detect single space, maybe spaces or tabs.
             */
            currNode->p[i].x = atof(buf);
            currNode->p[i].y = atof(strchr(buf, ' '));
            ++i;
        }
    }
    currNode->next = NULL; 
    return 1;
}

int lineListDraw(FILE* fpt, LineList top){
    /* Header part not save any contents, just link to next node */
    LineList* currNode = top.next;
    
    while (currNode != NULL) {
        int i = 0;
        fprintf(fpt, "%f %f moveto\n", currNode->p[i].x, currNode->p[i].y);
        
        ++i;
        while (i < currNode->n) {
            fprintf(fpt, "%f %f lineto\n", currNode->p[i].x, currNode->p[i].y);
            ++i;
        }
        fprintf(fpt, "stroke\n");
        currNode = currNode->next;
    }
    return 1;
}

bool freeLineList(LineList* lineList){
    LineList* currNode = lineList->next;
    LineList* reteinNode;
    
    while (currNode != NULL) {
        reteinNode = currNode;
        currNode = currNode->next;
        free(reteinNode->p);
        free(reteinNode);
    }
    return true;
}
