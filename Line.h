// Line.h
// Class to encapsulate Line properties
//
// writen by Scott McDermott
// Date last modified: 10/19/2015
//
#include "MyShapesGlobals.h"
#include "Shape.h"

#pragma once
#if !defined(_LINE_H_)
#define _LINE_H_

class Line : public Shape
{
public:
    // Default Constructor
    Line(void);
    // Default Destructor
    ~Line(void);
    // Copy Constructor
    Line(Line const&);
    
public:
    real calcArea();
    bool draw();

private:
    Point point1;
    Point point2;
};

#endif //_LINE_H_