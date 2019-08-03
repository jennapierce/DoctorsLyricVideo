// MyRectangle.java
// Class to encapsulate rectangles
// writen by Scott McDermott
// Date last modified: 9/14/2015
//
import java.awt.*;
import java.awt.geom.*;

public class MyRectangle extends MyPolygon {
    private double width;
    private double height;
    
    public MyRectangle() {
        width = 2.0;
        height = 4.0;
        numSides = 4;
        System.out.println("rectangle created");
    }

    public double getWidth() {return width;}
    public double getHeight() {return height;}
    
    public void setDimensions(double w, double h) {
        this.width = w;
        this.height = h;
    }

    public double calcArea() {
        return width * height;
    }

    public boolean draw(Graphics2D ga) {
		Shape square = new Rectangle2D.Double(center.locationX, center.locationY, getWidth(), getHeight());
		ga.fill(square);
        return true;
    }
    
}