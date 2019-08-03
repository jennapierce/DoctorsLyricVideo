// MyPolygon.java
// Abstract class to encapsulate polygon type of objects
// writen by Scott McDermott
// Date last modified: 9/14/2015
//

public abstract class MyPolygon extends MyShape {
    public int numSides;
    public MyPolygon() {
        numSides = 0;
        System.out.println("polygon created");
    }
}