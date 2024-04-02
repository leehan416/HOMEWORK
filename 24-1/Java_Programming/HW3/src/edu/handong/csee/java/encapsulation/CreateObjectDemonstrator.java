package edu.handong.csee.java.encapsulation;

import edu.handong.csee.java.encapsulation.shapes.*;

/** 
 *  Running program on this class. <br />
 *  create instance of shapes.<br />
 *  set the shape's attribute.<br />
 *  move this shapes.
*/
public class CreateObjectDemonstrator {

    /**
     * main method
     * @param args[String[]] 
    */
    public static void main(String[] args) {
        CreateObjectDemonstrator myRunner = new CreateObjectDemonstrator();

       myRunner.run();
    }

    /**
     * process method
    */
    public void run() {		
        // Declare and create a point object and two rectangle objects.
        Point originOne = new Point(23, 94);
        Rectangle rectOne = new Rectangle(originOne, 100, 200);
        Rectangle rectTwo = new Rectangle(50, 100);
		

        // display rectOne's width, height, and area
        System.out.println("Width of rectOne: " + rectOne.getWidth());
        System.out.println("Height of rectOne: " + rectOne.getHeight());
        System.out.println("Area of rectOne: " + rectOne.getArea());
       		
        // set rectTwo's position
        rectTwo.setOrigin(originOne);

        // display rectTwo's position
        System.out.println("X Position of rectTwo: " + rectTwo.getOrigin().getX());
        System.out.println("Y Position of rectTwo: " + rectTwo.getOrigin().getY());
		
        // move rectTwo and display its new position
        rectTwo.move(40, 72);
        System.out.println("X Position of rectTwo: " + rectTwo.getOrigin().getX());
        System.out.println("Y Position of rectTwo: " + rectTwo.getOrigin().getY());
    }
}