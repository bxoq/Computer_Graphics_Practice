#include <string>
#include <fstream>
#include <iostream>
#include "line.h"

#ifdef USEBOOST
#include <boost/format.hpp>
#include <boost/foreach.hpp>

using namespace boost;
using namespace std;
#endif

void lineDraw(FILE* fpt, float startx, float starty, float endx, float endy){
#ifdef USEBOOST
    vector<string> buf;
    buf.push_back(str(format("%f %f moveto\n") % startx % starty));
    buf.push_back(str(format("%f %f lineto\n") % endx % endy));
    buf.push_back(string("stroke\n"));
    
    BOOST_FOREACH(string str, buf){
        fwrite(str.c_str(), str.size(), 1, fpt);
    }
#else
    fprintf(fpt, "%f %f moveto\n", startx, starty);
    fprintf(fpt, "%f %f lineto\n", endx, endy);
    fprintf(fpt, "stroke\n");
#endif
}
