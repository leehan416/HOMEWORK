package edu.handong.csee.java.university.lecture;

/**
 * This is a student class.
 **/
public




class Student {

    private boolean isSleeping; // cameCase
    private String name;
    private int weight;
    private int bodyTemperature;

    /**
     * This is goToBed method where we can update the isSleeping field.
     **/
    public void goToBed() {
        System.out.println("Going to bed");
        isSleeping = true;
    }

    public void setName(String newStudentName) {
        name = newStudentName;
    }

    public String callName() {
        System.out.println("Here is my name: " + name);
        return name;
    }

    public void running() {
        System.out.println("BodyTemperature is increasing as I run");
        bodyTemperature = bodyTemperature + 2;

    }

    public void haveMedicineForFever() {
        System.out.println("BodyTemperature is decreasing as I have medicine");
        bodyTemperature = bodyTemperature - 2;
    }

}

