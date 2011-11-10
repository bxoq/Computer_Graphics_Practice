/* example:
 * make ex1 && ./ex1 ex1.ps 0 500 300 700
 */

#include <string>
#include <fstream>
#include <iostream>
#include "predef.h"

#ifdef USEBOOST
#include <boost/format.hpp>

using namespace boost;
using namespace std;
#endif

int main(int argc, char *argv[]){
#ifdef USEBOOST
    if( argc != 6 ){
        cerr << format("%s ファイル名 startx starty endx endy") % argv[0] << endl;
        exit(1);
    }
    ofstream fout(argv[1]);
    {
        fout << "%! PS-Adobe-3.0" << endl;
        fout << string(argv[2]) + " " + string(argv[3]) + " " +"moveto" << endl;
        fout << string(argv[4]) + " " + string(argv[5]) + " " + "lineto" << endl;
        fout << "stroke" << endl;
        fout << "showpage" << endl;
    }
    fout.close();
#else
    if( argc != 6 ){
        fprintf(stderr, "%s ファイル名 startx starty endx endy\n", argv[0]);
        exit(1);
    }
    FILE *fout = fopen(argv[1], "wb");
    fprintf(fout, "%%! PS-Adobe-3.0\n");
    fprintf(fout, "%f %f moveto\n", atof(argv[2]), atof(argv[3]));
    fprintf(fout, "%f %f lineto\n", atof(argv[4]), atof(argv[5]));
    fprintf(fout, "stroke\n");
    fprintf(fout, "showpage\n");
    fclose(fout);
#endif
}
