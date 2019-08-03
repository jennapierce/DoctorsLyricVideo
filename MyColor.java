// MyColor.java
// Class to encapsulate color properties
//
// writen by Scott McDermott
// Date last modified: 9/11/2015
//


public class MyColor {
    final int MAX_VALUE = 255;
    final int MIN_VALUE = 0;
    private int colorR;     // Red color (0-255)
    private int colorG;     // Green color (0-255)
    private int colorB;     // Blue color (0-255)
    
    public MyColor() {
        colorR = 0;     // Red color (0-255)
        colorG = 0;     // Green color (0-255)
        colorB = 0;     // Blue color (0-255)
    }
    
    public int getR() {return colorR;}
    public int getG() {return colorG;}
    public int getB() {return colorB;}
    
    public void setR(int r) {
        if(r <= MAX_VALUE && r >= MIN_VALUE) colorR = r;
    }
    
    public void setG(int g) {
        if(g <= MAX_VALUE && g >= MIN_VALUE) colorG = g;
    }
    
    public void setB(int b) {
        if(b <= MAX_VALUE && b >= MIN_VALUE) colorB = b;
    }
	
	public void set(int r, int g, int b) {
		setR(r);
		setG(g);
		setB(b);
	}
}