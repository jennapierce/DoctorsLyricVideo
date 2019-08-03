// Ellipse.cpp
// See header file for structural information
//
// writen by Scott McDermott
// Date last modified: 10/23/2015
//
#include "Ellipse.h"
#include <math.h>

Ellipse::Ellipse(void) {
   #ifdef _DEBUG
    cout << "Ellipse created..." << endl;
   #endif
    majorRadius = 2.0;
    minorRadius = 1.0;
}

Ellipse::~Ellipse(void) {
   #ifdef _DEBUG
    cout << "Ellipse destroyed..." << endl;
   #endif
}

Ellipse::Ellipse(Ellipse const &copySource) {
   #ifdef _DEBUG
    cout << "Ellipse copied..." << endl;
   #endif
}

void Ellipse::setRadius(double M, double m) {
    majorRadius = max(M, m);
    minorRadius = min(M, m);
}

real Ellipse::calcArea() {
    return M_PI * majorRadius * minorRadius;
}

bool Ellipse::draw() {
//    real dist = calcDistance(point1, point2);
    return true;
}

