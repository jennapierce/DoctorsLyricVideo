// MyLine.java
// Class to encapsulate lines
// writen by Scott McDermott
// Date last modified: 9/4/2015
//
import java.awt.*;
import java.awt.geom.*;

public class MyLine extends MyShape {
    public MyPoint point1;
    public MyPoint point2;
    
    public MyLine() {
        point1 = new MyPoint();
        point2 = new MyPoint();
        point1.locationX = 0.0;
        point1.locationY = 0.0;
        point2.locationX = 1.0;
        point2.locationY = 0.0;
    }
	
	public double x1() {return point1.locationX;}
	public double x2() {return point2.locationX;}
	public double y1() {return point1.locationY;}
	public double y2() {return point2.locationY;}

	public void x1(double x) {point1.locationX = x;}
	public void x2(double x) {point2.locationX = x;}
	public void y1(double y) {point1.locationY = y;}
	public void y2(double y) {point2.locationY = y;}

	public void set(double x1, double y1, double x2, double y2) {
        point1.locationX = x1;
        point1.locationY = y1;
        point2.locationX = x2;
        point2.locationY = y2;
	}
    
    public double calcArea() {
        return 0.0;
    }
    
    public boolean draw(Graphics2D ga) {
		Shape line = new Line2D.Double(center.x() + point1.x(), 
									   center.y() + point1.y(), 
									   center.x() + point2.x(), 
									   center.y() + point2.y());
		ga.draw(line); // NOT FILL!!!!
        return true;
    }
    
    public double calcDistance() {
        return point2.calcDistance(point1);
    }
}