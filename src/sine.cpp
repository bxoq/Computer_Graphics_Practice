/* example:
 * make sine && ./sine sine.ps 0 500 10 10 10 10
 */

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include "line2.h"

#ifdef USEBOOST
#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost;
using namespace std;
#endif

int main(int argc, char *argv[]){
#ifdef USEBOOST
    if( argc != 8 ){
        cerr << format("%s ファイル名 startx starty k A F phi") % argv[0] << endl;
        exit(1);
    }
    shared_ptr<FILE> fp(fopen(argv[1], "wb"), fclose);
    
    float startx = atof(argv[2]);
    float starty = atof(argv[3]);
    float k = atof(argv[4]);
    float A = atof(argv[5]);
    float F = atof(argv[6]);
    float phi = atof(argv[7]);
    
    string head = string("%! PS-Adobe-3.0\n");
    fwrite(head.c_str(), head.size(), 1, fp.get());
    
    Line line;  
    line.start.x = startx;
    line.start.y = starty;
    line.end.x = startx;
    line.end.y = starty;
    for (float t = 0.; t <= 10.; t += 0.1/F) {
        line.start.x = line.end.x;
        line.start.y = line.end.y;
        line.end.x = line.start.x + k * t;
        line.end.y = line.start.y + A * sin( F * t + phi );
        lineDraw2(fp.get(), line);
    }
    string tail = string("showpage\n");
    fwrite(tail.c_str(), tail.size(), 1, fp.get());
#else
    if( argc != 8 ){
        fprintf(stderr, "%s ファイル名 startx starty k A F phi\n", argv[0]);
        exit(1);
    }
    FILE *fout = fopen(argv[1], "wb");
    
    float startx = atof(argv[2]);
    float starty = atof(argv[3]);
    float k = atof(argv[4]);
    float A = atof(argv[5]);
    float F = atof(argv[6]);
    float phi = atof(argv[7]);
    
    Line line;  
    line.start.x = startx;
    line.start.y = starty;
    line.end.x = startx;
    line.end.y = starty;
    
    fprintf(fout, "%%! PS-Adobe-3.0\n");
    for (float t = 0.; t <= 10.; t += 0.1/F) {
        line.start.x = line.end.x;
        line.start.y = line.end.y;
        line.end.x = line.start.x + k * t;
        line.end.y = line.start.y + A * sin( F * t + phi );
        lineDraw2(fout, line);
    }
    fprintf(fout, "showpage\n");
    
    fclose(fout);
#endif
}
