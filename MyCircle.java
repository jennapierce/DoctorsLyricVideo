// MyCircle.java
// Class to encapsulate circles
// writen by Scott McDermott
// Date last modified: 9/14/2015
//
import java.awt.*;

public class MyCircle extends MyEllipse {
    public MyCircle() {
        System.out.println("circle created");
    }


    public void setRadius(double M, double m) {
        this.setRadius(M);
    }
    
    public void setRadius(double r) {
        super.setRadius(r, r);
    }

    public double calcArea() {
        return super.calcArea();
    }
    
    public boolean draw(Graphics2D ga) {
		return super.draw(ga);
    }
}