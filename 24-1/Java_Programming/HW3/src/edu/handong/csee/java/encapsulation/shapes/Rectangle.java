/**
 * Package of shapes
*/
package edu.handong.csee.java.encapsulation.shapes;

/**
 *  Rectangle Class 
 */
public class Rectangle {
    private int width = 0;
    private int height = 0;
    private Point origin;
 
    //---------------------------------
    // four constructors

    /**
     * Constructs a new Rectangle on zero
     */
    public Rectangle() {
    	origin = new Point(0, 0);
    }

    /**
     * Constructs a new Rectangle on Point
     * @param p[Point] 
     */
    public Rectangle(Point p) {
   	 origin = p;
    }

    /**
     * Constructs a new Rectangle on Position
     * @param w[int]
     * @param h[int]
    */
    public Rectangle(int w, int h) {
    	origin = new Point(0, 0);
    	width = w;
    	height = h;
    }

    /**
     * Constructs a new Rectangle on Position
     * @param p[Point]
     * @param w[int]
     * @param h[int] 
    */
    public Rectangle(Point p, int w, int h) {
        origin = p;
        width = w;
        height = h;
    }
  
     
    /**
     * move Rectangle 
     * @param x[int]
     * @param y[int]
    */
    public void move(int x, int y) { // a method for moving the rectangle
        //change to setter
        origin.setX(x);
        origin.setY(y);
    }
    
    /**
     * calculate the Area of Rectangle 
     * @return width * height
    */
    public int getArea() { // a method for computing the area of the rectangle
        return width * height;
    }

    //-----------------------------------
    //getter setter

    /**
     * setter of Origin
     * @param origin[Point]
    */
    public void setOrigin(Point origin){
        this.origin = origin;
    }

    /**
     * getter of Origin
     * @return origin[Point]
    */
    public Point getOrigin(){
        return origin;
    }

    /**
     * setter of Width
     * @param width[int]
    */
    public void setWidth(int width){
        this.width = width;
    }

    /**
     * getter of Width
     * @return width[int]
    */
    public int getWidth(){
        return width;
    }

    /**
     * setter of Height
     * @param height[int]
    */
    public void setHeight(int height){
        this.height = height;
    
    }
    
    /**
     * getter of Height
     * @return height[int]
    */
    public int getHeight(){
        return height;
    }
 }