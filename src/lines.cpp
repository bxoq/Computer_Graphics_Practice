#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "lines.h"

/*
 * Upon successful completion, l use malloc to alloc memory, must free it manually.
 * If an error occurs, linesRead() return 0.
 */
int linesRead(FILE* fpt, Lines *l){
    const int bufLen = 256;
    char buf[bufLen];
    
    readLine(fpt, buf, bufLen);
    int n = atoi(buf);
    if (n < 1) return 0;
    
    l->n = n;
    l->p = (Point*)malloc(sizeof(Point) * n);
    
    int i = 0;
    while (readLine(fpt, buf, bufLen)) {
        /* FIXME:
         * 1) Direct use atof() is not safe.
         * 2) Only detect single space, maybe spaces or tabs.
         */
        l->p[i].x = atof(buf);
        l->p[i].y = atof(strchr(buf, ' '));
        ++i;
    }
    return 1;
}

int linesDraw(FILE* fpt, Lines l){
    int i = 0;
    fprintf(fpt, "%f %f moveto\n", l.p[i].x, l.p[i].y);
    
    ++i;
    while (i < l.n) {
        fprintf(fpt, "%f %f lineto\n", l.p[i].x, l.p[i].y);
        ++i;
    }
    fprintf(fpt, "stroke\n");
    
    return 1;
}

/* 
 * Upon successful completion, buf will be filled.
 * If end-of-file occurs before any characters are read, 
 * or an error occurs, readLine() return false.
 */
bool readLine(FILE *fpt, char* buf, int bufLen){
    
    fgets(buf, bufLen, fpt);
    
    if (feof(fpt) || ferror(fpt))
        return false;

    return true;
}
