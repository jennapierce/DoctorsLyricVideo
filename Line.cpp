// Line.cpp
// See header file for structural information
//
// writen by Scott McDermott
// Date last modified: 10/19/2015
//




#include "Line.h"

Line::Line(void) {
   #ifdef _DEBUG
    cout << "Line created..." << endl;
   #endif
        point1.x(0.0);
        point1.y(0.0);
        point2.x(1.0);
        point2.y(0.0);
}

Line::~Line(void) {
   #ifdef _DEBUG
    cout << "Line destroyed..." << endl;
   #endif
}

Line::Line(Line const &copySource) {
   #ifdef _DEBUG
    cout << "Line copied..." << endl;
   #endif
}

real Line::calcArea() {
    return 0.0;
}

bool Line::draw() {
//    real dist = calcDistance(point1, point2);
    return true;
}

