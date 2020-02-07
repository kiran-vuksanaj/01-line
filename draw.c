#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  // handle backwards lines
  if( x1 < x0 ) {
    draw_line( x1,y1, x0,y0, s, c );
    return;
  }
  int A = y1 - y0;
  int B = x0 - x1;
  // CASE octant I:
  if( x1 - x0 >= y1 - y0 && y1 > y0 ){
    int d = 2*A + B;
    A *= 2;
    B *= 2;
    while( x0 < x1 ){
      plot(s,c,x0,y0);
      if( d > 0 ){
	y0++;
	d += B;
      }
      x0++;
      d += A;
    }
  } else if( x1 - x0 <= y1 - y0 && y1 > y0 ){
    // CASE octant II
    int d = A + 2*B;
    A *= 2;
    B *= 2;
    while( y0 < y1 ){
      plot(s,c,x0,y0);
      if( d > 0 ){
	x0++;
	d += B;
      }
      y0++;
      d += A;
    }
  }
}
