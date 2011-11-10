#include <string>
#include <fstream>
#include <iostream>
#include "line2.h"

#ifdef USEBOOST
#include <boost/format.hpp>
#include <boost/foreach.hpp>

using namespace boost;
using namespace std;
#endif

void lineDraw2(FILE* fpt, Line l){
#ifdef USEBOOST
    vector<string> buf;
    buf.push_back(str(format("%f %f moveto\n") % l.start.x % l.start.y));
    buf.push_back(str(format("%f %f lineto\n") % l.end.x % l.end.y));
    buf.push_back(string("stroke\n"));
    
    BOOST_FOREACH(string str, buf){
        fwrite(str.c_str(), str.size(), 1, fpt);
    }
#else
    fprintf(fpt, "%f %f moveto\n", l.start.x, l.start.y);
    fprintf(fpt, "%f %f lineto\n", l.end.x, l.end.y);
    fprintf(fpt, "stroke\n");
#endif
}
