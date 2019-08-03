import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;


// http://docs.oracle.com/javase/7/docs/api/java/awt/Frame.html
public class DrawingCanvas extends Frame {
	public Graphics2D ga;
	public final int MAX_SHAPES = 10;
	public final int MAX_WIDTH = 800;
	public final int MAX_HEIGHT = 600;
	public Rectangle bounds = new Rectangle(0, 0, MAX_WIDTH, MAX_HEIGHT);
	public MyShape[] myShapes = new MyShape[MAX_SHAPES];
	public int lastShapeIndex = 0;
	int drawNum = 0;

	public DrawingCanvas() {
	}

	public void createDrawing() {
		myShapes[lastShapeIndex] = new MyEllipse();
		myShapes[lastShapeIndex].color.set(255, 0, 0);
		lastShapeIndex++;
		
		myShapes[lastShapeIndex] = new MyRectangle();
		myShapes[lastShapeIndex].color.set(180, 180, 180);
		lastShapeIndex++;

		myShapes[lastShapeIndex] = new MyTriangle();
		myShapes[lastShapeIndex].color.set(0, 255, 0);
		lastShapeIndex++;

 		myShapes[lastShapeIndex] = new MyLine();
		myShapes[lastShapeIndex].color.set(0, 255, 25);
		lastShapeIndex++;

		updateDrawing();
	}

	public void updateDrawing() {
		((MyEllipse)myShapes[0]).setRadius(70.0, 100.0);// - MAX_WIDTH)/MAX_WIDTH);
		myShapes[0].setLocation((bounds.width/2.0) - 35.0, 100.0);
		
		((MyRectangle)myShapes[1]).setDimensions(100.0, 200.0);
		myShapes[1].setLocation((bounds.width/2.0) - 50.0, 195.0);

		((MyTriangle)myShapes[2]).set(-25.0, 25.0, 0.0, -25.0, 25.0, 25.0);
		myShapes[2].setLocation((bounds.width/2.0), 5.0 + 80.0);

		((MyLine)myShapes[3]).set(0.0, 0.0, 400.0, 0.0);
		myShapes[3].setLocation((bounds.width/2.0) - 200.0, 395.0);
	}

	public void paint(Graphics g) {
		ga = (Graphics2D)g;
		int oldw = bounds.width;
		int oldh = bounds.height;
		bounds = this.getBounds();
		if( (bounds.width != oldw) || (bounds.height != oldh) ) {
			updateDrawing();
			revalidate();
			repaint();
		}
		else {
//		System.out.println("drawing... " + drawNum++);
			for(int i=0; i<lastShapeIndex; i++ ) {
//			System.out.println("drawing..." + i + " out of " + lastShapeIndex);
				ga.setPaint(new Color(myShapes[i].color.getR(),
									  myShapes[i].color.getG(),
									  myShapes[i].color.getB()));
				myShapes[i].draw(ga);
			}
		}
	}
}

