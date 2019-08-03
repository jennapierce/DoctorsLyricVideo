// Ellipse.h
// Class to encapsulate Ellipse properties
//
// writen by Scott McDermott
// Date last modified: 10/23/2015
//
#include "MyShapesGlobals.h"
#include "Shape.h"

#pragma once
#if !defined(_ELLIPSE_H_)
#define _ELLIPSE_H_

class Ellipse : public Shape
{
public:
    // Default Constructor
    Ellipse(void);
    // Default Destructor
    ~Ellipse(void);
    // Copy Constructor
    Ellipse(Ellipse const&);
    
public:
    real calcArea();
    bool draw();
    
public:
    inline real getM() {return majorRadius;}
    inline real getm() {return minorRadius;}
    void setRadius(double M, double m);

private:
    real majorRadius;
    real minorRadius;
};

#endif //_ELLIPSE_H_