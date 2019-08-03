// Shape.h
// Class to encapsulate abstract shape properties
//
// writen by Scott McDermott
// Date last modified: 10/19/2015
//
#include "MyShapesGlobals.h"
#include "Color.h"
#include "Point.h"

#pragma once
#if !defined(_SHAPE_H_)
#define _SHAPE_H_

class Shape
{
public:
    // Default Constructor
    Shape(void);
    // Default Destructor
    ~Shape(void);
    // Copy Constructor
    Shape( Shape const & );

public:
    virtual real calcArea() = 0;
    virtual bool draw() = 0;

protected:
    Color myColor;
    Point center;
    real rotation;
};

#endif //_SHAPE_H_