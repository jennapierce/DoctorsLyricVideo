// MyShape.java
// Abstratction of objects that are shapes
//
// writen by Scott McDermott
// Date last modified: 9/4/2015
//
import java.awt.*;

public abstract class MyShape {
    public MyColor color;
    public MyPoint center;
    public double rotation;
    
    public MyShape() {
        this.color = new MyColor();
        this.center = new MyPoint();
        this.rotation = 0.0;
        System.out.println("shape created");
    }
 
 	public void setLocation( MyPoint p ) { center.locationX = p.locationX; center.locationY = p.locationY; }
	public void setLocation( double x, double y ) { center.locationX = x; center.locationY = y; }
 
    public abstract double calcArea();
    public abstract boolean draw(Graphics2D ga);
}
