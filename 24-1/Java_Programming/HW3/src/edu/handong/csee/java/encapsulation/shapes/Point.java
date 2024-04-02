package edu.handong.csee.java.encapsulation.shapes;

/**
 * point class
 */
public class Point {
    private int x = 0;
    private int y = 0;
    
    /**
     * Constructs a new Point.
     * @param a[int]
     * @param b[int]
     */
    public Point(int a, int b) {// a constructor!
    	x = a;
    	y = b;
    }


    //----------------------------
    //getter setter

    /**
     * setter of X
     * @param x[int]
     * 
    */
    public void setX(int x){
        this.x = x;
    }

    /**
     * getter of X
     * @return x[int]
    */
    public int getX(){
        return x;
    }

    /**
     * setter of Y
     * @param y[int]
    */
    public void setY(int y){
        this.y = y;
    }

    /**
     * getter of Y
     * @return y[int]
    */
    public int getY() {
        return y;
    }
}