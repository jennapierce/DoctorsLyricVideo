// Shape.cpp
// See header file for structural information
//
// writen by Scott McDermott
// Date last modified: 10/19/2015
//





#include "Shape.h"

Shape::Shape(void) {
    myColor.set(0, 255, 0);
    center.x(0.0);
    center.y(0.0);
    rotation = 0.0;
   #ifdef _DEBUG
    cout << "Shape created..." << endl;
   #endif
}

Shape::~Shape(void) {
   #ifdef _DEBUG
    cout << "Shape destroyed..." << endl;
   #endif
}

Shape::Shape( Shape const &copySource ) {
   #ifdef _DEBUG
    cout << "Shape copied..." << endl;
   #endif
    myColor = copySource.myColor;
    center = copySource.center;
    rotation = copySource.rotation;
}

