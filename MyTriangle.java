// MyTriangle.java
// Class to encapsulate triangles
// writen by Scott McDermott
// Date last modified: 9/14/2015
//
import java.awt.*;

public class MyTriangle extends MyPolygon {
    MyLine line1;
    MyLine line2;
    MyLine line3;

    public MyTriangle() {
        numSides = 3;
        line1 = new MyLine();
        line2 = new MyLine();
        line3 = new MyLine();
    }

	public void set(double x1, double y1, double x2, double y2, double x3, double y3) {
		line1.point1.locationX = x1;
		line1.point1.locationY = y1;
		line1.point2.locationX = x2;
		line1.point2.locationY = y2;
		line2.point1.locationX = x2;
		line2.point1.locationY = y2;
		line2.point2.locationX = x3;
		line2.point2.locationY = y3;
		line3.point1.locationX = x3;
		line3.point1.locationY = y3;
		line3.point2.locationX = x1;
		line3.point2.locationY = y1;
    }

    public double calcArea() {
        // https://www.mathsisfun.com/geometry/herons-formula.html
        double a = line1.calcDistance();
        double b = line2.calcDistance();
        double c = line3.calcDistance();
        double s = (a + b + c) / 2.0;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    public boolean draw(Graphics2D ga) {
		Shape triangle = new Polygon();
		((Polygon)triangle).addPoint((int)(center.x() + line1.x1()), 
									 (int)(center.y() + line1.y1()));
		((Polygon)triangle).addPoint((int)(center.x() + line1.x2()),
									 (int)(center.y() + line1.y2()));
		((Polygon)triangle).addPoint((int)(center.x() + line2.x2()),
									 (int)(center.y() + line2.y2()));
		ga.fill(triangle);

        return true;
    }
    
}