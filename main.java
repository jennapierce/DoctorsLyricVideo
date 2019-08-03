// main.java
// Engine to draw shapes
//
// writen by Scott McDermott
// Date last modified: 9/4/2015
//
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

public class main {
    public static void main(String []args) {
		DrawingCanvas dc = new DrawingCanvas();
	    dc.createDrawing();

  		System.out.println("Hello, World!");

		// Set the drawing stuff...
		dc.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent we){
				System.exit(0);
			}
		});
		dc.setTitle("Little People!");
		dc.setBackground(new Color(55, 55, 95));
		dc.setSize(dc.MAX_WIDTH, dc.MAX_HEIGHT);
		dc.setVisible(true);

    }
}

