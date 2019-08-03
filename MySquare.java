// MySquare.java
// Class to encapsulate squares
// writen by Scott McDermott
// Date last modified: 9/14/2015
//
import java.awt.*;

public class MySquare extends MyRectangle {
    public MySquare() {
     System.out.println("square created");
   }
    
    public void setDimensions(double w, double h) {
        this.setDimensions(w);
    }

    public void setDimensions(double w) {
        super.setDimensions(w, w);
    }

    public double calcArea() {
        return super.calcArea();
    }
    
    public boolean draw(Graphics2D ga) {
        return super.draw(ga);
    }
    
}