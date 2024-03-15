package edu.handong.csee.java.university.lecture;

import java.util.ArrayList;

public class Classroom {

    private int numOfStudents;
    private int numOfChairs;
    private String classroomNumber;
    private ArrayList<Student> students = new ArrayList<Student>();

    public void setNumOfStudents(int numberOfStduent) {
        System.out.println("Set the number of students: " + numberOfStduent);
        numOfStudents = numberOfStduent;
    }

    public int getNumOfStudents() {
        return numOfStudents;
    }

    public void setNumOfChairs(int numChairs) {
        System.out.println("Set the number of chairs: " + numChairs);
        numOfChairs = numChairs;
    }

    public int getNumOfChairs() {
        return numOfChairs;
    }

    public void setClassroomNumber(String crNumber) {
        System.out.println("Set the room #: " + crNumber);
        classroomNumber = crNumber;
    }

    public String getClassroomNumber() {
        return classroomNumber;
    }

    public void addStudent(Student newStudent) {
        students.add(newStudent);
        numOfStudents = numOfStudents + 1;
    }
}