/* example:
 * make sine2 && ./sine2 sine2.ps 0 500 10 10 10 10
 */

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include "lines.h"

int main(int argc, char *argv[]){
    if( argc != 8 ){
        fprintf(stderr, "%s ファイル名 startx starty k A F phi\n", argv[0]);
        exit(1);
    }
    FILE *fout = fopen(argv[1], "wb");
    
    float k = atof(argv[4]);
    float A = atof(argv[5]);
    float F = atof(argv[6]);
    float phi = atof(argv[7]);
    
    Lines lines;
    lines.n = 10. * F / 0.1 + 1;
    lines.p = (Point*)malloc(sizeof(Point) * lines.n);
    
    lines.p[0].x = atof(argv[2]);
    lines.p[0].y = atof(argv[3]);

    fprintf(fout, "%%! PS-Adobe-3.0\n");
    
    float t = 0.;
    for (int i = 1; i < lines.n; i++) {
        lines.p[i].x = lines.p[i-1].x + k * t;
        lines.p[i].y = lines.p[i-1].y + A * sin( F * t + phi );
        t += 0.1/F;
    }
    
    linesDraw(fout, lines);
    fprintf(fout, "showpage\n");
    
    free(lines.p);
    fclose(fout);
}
