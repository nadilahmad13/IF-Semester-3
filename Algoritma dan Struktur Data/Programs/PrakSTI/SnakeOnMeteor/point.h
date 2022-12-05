#ifndef __POINT__
#define __POINT__

#include "boolean.h"

typedef struct {
    int x;
    int y;
}Point;

#define ABSCISSA(p) (p).x
#define ORDINATE(p) (p).y

boolean isPointEqual(Point P1, Point P2);

void createPoint(Point *p , int x, int y);

boolean isOrigin(Point p);

boolean isFirstQuadrant(Point p);

Point translate(Point p, int dx, int dy);

Point copyPoint(Point P);

void movePoint(Point *p, int dx, int dy);

#endif