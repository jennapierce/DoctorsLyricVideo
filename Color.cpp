// Color.cpp
// See header file for structural information
//
// writen by Scott McDermott
// Date last modified: 10/5/2015
//



#include <iostream>
using namespace std;


#include "Color.h"

Color::Color(void) {
    colorR = 0;     // Red color (0-255)
    colorG = 0;     // Green color (0-255)
    colorB = 0;     // Blue color (0-255)
   #ifdef _DEBUG
    cout << "Color created..." << endl;
   #endif
}

Color::~Color(void) {
   #ifdef _DEBUG
    cout << "Color destroyed..." << endl;
   #endif
}

Color::Color( Color const &copySource ) {
   #ifdef _DEBUG
    cout << "Color copied..." << endl;
   #endif
}