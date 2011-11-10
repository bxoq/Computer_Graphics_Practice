/* example:
 * make ex3 && ./ex3 ex3.ps 0 500 300 700
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
  
  Line line;
  line.start.x = atof(argv[2]);
  line.start.y = atof(argv[3]);
  line.end.x = atof(argv[4]);
  line.end.y = atof(argv[5]);
  
  string head = string("%! PS-Adobe-3.0\n");
  fwrite(head.c_str(), head.size(), 1, fp.get());
  
  lineDraw2(fp.get(), line);
  
  string tail = string("showpage\n");
  fwrite(tail.c_str(), tail.size(), 1, fp.get());
#else
  if( argc != 6 ){
    fprintf(stderr, "%s ファイル名 startx starty endx endy\n", argv[0]);
    exit(1);
  }
  FILE *fout = fopen(argv[1], "wb");
  
  Line line;
  line.start.x = atof(argv[2]);
  line.start.y = atof(argv[3]);
  line.end.x = atof(argv[4]);
  line.end.y = atof(argv[5]);
  
  fprintf(fout, "%%! PS-Adobe-3.0\n");
  lineDraw2(fout, line);
  fprintf(fout, "showpage\n");
  fclose(fout);
#endif
}
