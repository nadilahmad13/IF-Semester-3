#include "point.h"

void createPoint(Point *p , int x, int y) {

    ABSCISSA(*p) = x;
    ORDINATE(*p) = y;

}

boolean isPointEqual(Point P1, Point P2) {

    return (ABSCISSA(P1) == ABSCISSA(P2)) && (ORDINATE(P1) == ORDINATE(P2));

}

boolean isOrigin(Point p) {

    return (ABSCISSA(p) == 0 && ORDINATE(p) == 0);

}

boolean isFirstQuadrant(Point p) {

    return (ABSCISSA(p) >= 0 && ORDINATE(p) >= 0);

}

Point translate(Point p, int dx, int dy) {

    Point np;

    createPoint(&np, ABSCISSA(p) + dx, ORDINATE(p) + dy);

    return np;

}

Point copyPoint(Point P) {
    Point Q;
    ABSCISSA(Q) = ABSCISSA(P);
    ORDINATE(Q) = ORDINATE(P);
    return Q;
}

void movePoint(Point *p, int dx, int dy) {

    ABSCISSA(*p) = ABSCISSA(*p) + dx;
    ORDINATE(*p) = ORDINATE(*p) + dy;

}