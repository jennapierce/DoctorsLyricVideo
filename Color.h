// Color.h
// Class to encapsulate color properties
//
// writen by Scott McDermott
// Date last modified: 10/5/2015
//

#include "MyShapesGlobals.h"

#pragma once
#if !defined(_COLOR_H_)
#define _COLOR_H_


class Color
{
public:
    // Default Constructor
    Color(void);
    // Default Destructor
    ~Color(void);
    // Copy Constructor
    Color( Color const & );

    // Inline get functions
    inline int getR() {return colorR;}
    inline int getG() {return colorG;}
    inline int getB() {return colorB;}
  
    // Inline set functions
    inline void setR(int r) { if( r <= MAX_COLOR_VALUE && r >= MIN_COLOR_VALUE ) colorR = r; }
    inline void setG(int g) { if( g <= MAX_COLOR_VALUE && g >= MIN_COLOR_VALUE ) colorG = g; }
    inline void setB(int b) { if( b <= MAX_COLOR_VALUE && b >= MIN_COLOR_VALUE ) colorB = b; }

    inline void set(int r, int g, int b) {setR(r); setG(g); setB(b); }
private:
    int colorR;     // Red color (0-255)
    int colorG;     // Green color (0-255)
    int colorB;     // Blue color (0-255)
};

#endif //_COLOR_H_