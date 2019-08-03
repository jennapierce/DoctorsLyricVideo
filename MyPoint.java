// MyPoint.java
// Class to encapsulate point properties
//
// writen by Scott McDermott
// Date last modified: 9/4/2015
//

public class MyPoint {
    public double locationX;
    public double locationY;
    
    public MyPoint() {
        locationX = 0.0;
        locationY = 0.0;
    }

    public double calcDistance(MyPoint p) {
        return Math.sqrt(
            Math.pow(this.locationX - p.locationX, 2) +
            Math.pow(this.locationY - p.locationY, 2) );
    }
    
	public double x() {return locationX;}
	public double y() {return locationY;}

	public void x(double x) {locationX = x;}
	public void y(double y) {locationY = y;}

    public static double calcDistance(MyPoint p1, MyPoint p2) {
        return p1.calcDistance(p2);
    }
}

   