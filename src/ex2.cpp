/* example:
 * make ex2 && ./ex2 ex2.ps 0 500 300 700
 */

#include <string>
#include <fstream>
#include <iostream>
#include "line.h"

#ifdef USEBOOST
#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost;
using namespace std;
#endif

int main(int argc, char *argv[]){
#ifdef USEBOOST
    if( argc != 6 ){
        cerr << format("%s ファイル名 startx starty endx endy") % argv[0] << endl;
        exit(1);
    }
    shared_ptr<FILE> fp(fopen(argv[1], "wb"), fclose);
    string head = string("%! PS-Adobe-3.0\n");
    fwrite(head.c_str(), head.size(), 1, fp.get());
    
    lineDraw(fp.get(), atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]));
    
    string tail = string("showpage\n");
    fwrite(tail.c_str(), tail.size(), 1, fp.get());
#else
    if( argc != 6 ){
        fprintf(stderr, "%s ファイル名 startx starty endx endy\n", argv[0]);
        exit(1);
    }
    FILE *fout = fopen(argv[1], "wb");
    fprintf(fout, "%%! PS-Adobe-3.0\n");
    lineDraw(fout, atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]));
    fprintf(fout, "showpage\n");
    fclose(fout);
#endif
}
