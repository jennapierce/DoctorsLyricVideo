// Point.h
// Class to encapsulate Point properties
//
// writen by Scott McDermott
// Date last modified: 10/5/2015
//
#include "MyShapesGlobals.h"

#pragma once
#if !defined(_POINT_H_)
#define _POINT_H_

class Point
{
public:
    // Default Constructor
    Point(void);
    // Default Destructor
    ~Point(void);
    // Copy Constructor
    Point(Point const &copySource);

    // Calculate the distance...
    real calcDistance(Point p);

    inline void set(real x, real y) {locationX = x; locationY = y; cout << "x:" << locationX << endl;}
    inline real x() {return locationX;}
    inline real y() {return locationY;}
    inline void x(real newX) {locationX = newX;}
    inline void y(real newY) {locationY = newY;}

private:
    real locationX;
    real locationY;
};

// Globally accessable 
//real calcDistance(Point p1, Point p2);
#endif //_POINT_H_