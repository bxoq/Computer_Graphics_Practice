/* example:
 * make ex5 && ./ex5 ex5.ps
 */

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include "line.h"

typedef struct Circle{
  
  /* center point */
  float centerx;
  float centery;
  
  /* radius */
  float radius;
  
  /* fragments */
  int n;
  
  /* each angle */
  float theta;
};

bool drawCircle(FILE* fio, Lines* lines, Circle* circle);
bool freeLineList(LineList* lineList);

int main(int argc, char *argv[]){
  
  Circle circle;
  
  switch (argc) {
    case 2:
      circle.centerx = 200.;
      circle.centery = 500.;
      circle.radius = 100.;
      circle.n = 1000;
      break;
    case 6:
      circle.centerx = atof(argv[2]);
      circle.centery = atof(argv[3]);
      circle.radius = atof(argv[4]);
      circle.n = atoi(argv[5]);
      break;           
    default:
      fprintf(stderr,
              "%s ファイル名 [[centerx] [centery] [radius] [fragments]]\n"
              "This program is designed to draw a circle\n"
              "default config:\n"
              "centerx: 200.0\n"
              "centery: 500.0\n"
              "radius: 100.0\n"
              "fragments: 1000\n", argv[0]);
      exit(1);
      break;
  }
  
  char temp[256];
  sprintf(temp, "%s.tmp", argv[1]);
  FILE *fio = fopen(temp, "wb+");
  
  FILE *fout = fopen(argv[1], "wb");
  
  /* data buffer */
  Lines lines;
  
  lines.n = circle.n;
  lines.p = (Point*)malloc(sizeof(Point) * lines.n);
  circle.theta =  360. / (lines.n - 1);
  
  /* draw request circle */
  drawCircle(fio, &lines, &circle);
  
  /* draw 10 inner circles for testing lineListRead() & lineListDraw()*/
  int i = 0;
  while ( i < 10) {
    circle.radius /= 1.2;
    drawCircle(fio, &lines, &circle);
    ++i;
  }
  
  rewind(fio);
  LineList lineList;
  lineListRead(fio, &lineList);
  lineListDraw(fout, lineList);
  fprintf(fout, "showpage\n");
  free(lines.p);
  freeLineList(&lineList);
  fclose(fio);
  fclose(fout);
}

/* circle:
 * x = xm + rcos(theta)
 * y = ym + rsin(theta)
 */
bool drawCircle(FILE* fio, Lines* lines, Circle* circle){
  float theta = 0.;
  fprintf(fio, "%d\n", lines->n);
  for (int i = 0; i < lines->n; i++) {
    lines->p[i].x = circle->centerx + circle->radius * cos(theta);
    lines->p[i].y = circle->centery + circle->radius * sin(theta);
    fprintf(fio, "%f %f\n", lines->p[i].x, lines->p[i].y);
    theta += circle->theta;
  }    
  return true;
}
