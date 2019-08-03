// MyEllipse.java
// Class to encapsulate ellipses
// writen by Scott McDermott
// Date last modified: 9/14/2015
//
import java.awt.*;
import java.awt.geom.*;

public class MyEllipse extends MyShape {
    private double majorRadius;
    private double minorRadius;
    
    public MyEllipse() {
        majorRadius = 2.0;
        minorRadius = 1.0;
   }

    public double getM() {return majorRadius;}
    public double getm() {return minorRadius;}
    
    public void setRadius(double M, double m) {
        majorRadius = M;// Math.max(M, m);
        minorRadius = m;//Math.min(M, m);
    }

    public double calcArea() {
        return Math.PI * majorRadius * minorRadius;
    }
    
    public boolean draw(Graphics2D ga) {
		Shape circle = new Ellipse2D.Double(center.locationX, center.locationY, getM(), getm());
		ga.fill(circle);
		return true;
    }
}