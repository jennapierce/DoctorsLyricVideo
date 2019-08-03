// Point.cpp
// See header file for structural information
//
// writen by Scott McDermott
// Date last modified: 10/5/2015
//

#include <math.h>


#include "Point.h"

Point::Point(void) {
   locationX = 0.0;
   locationY = 0.0;
   #ifdef _DEBUG
    cout << "Point created..." << endl;
   #endif
}

Point::~Point(void) {
   #ifdef _DEBUG
    cout << "Point destroyed..." << endl;
   #endif
}

Point::Point(Point const &copySource) {
   #ifdef _DEBUG
    cout << "Point copied..." << endl;
   #endif
 //  talk about copy constructors!!!!
   locationX = copySource.locationX;
   locationY = copySource.locationY;
}


real Point::calcDistance(Point p2) {
    real pow1, pow2;
//    pow1 = pow(locationX - p2.locationX, 2.0);
//    pow2 = pow(locationY - p2.locationY, 2.0);
    cout << x() << " dsds " << p2.x() << endl;
    return sqrt(pow1 + pow2);
}

/*
real calcDistance(Point p1, Point p2) {
    return 1.0;//p1.calcDistance(p2);
}
*/
