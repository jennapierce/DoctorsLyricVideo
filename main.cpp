
#include "Color.h"
#include "Point.h"
#include "Line.h"

int main()
{
//    Shape myShape;




    Line myLine;
    Color myColor1, myColor2;
    myColor1.setR(50.0);
    myColor2 = myColor1;
    Point p1;
    Point p2;
    p1.set(5.0, 3.0);
    p2.set(30.0, 12.0);
    real foo = p1.calcDistance(p2);
    
    cout << "Hello World " << foo << " ds " << endl;
  //  int boo;
  //  cin >> boo;
	return 0;
}

