package edu.handong.csee.java.university;

import edu.handong.csee.java.university.lecture.Classroom;
import edu.handong.csee.java.university.lecture.Student;

public class Runner {

    public static void main(String[] args) {

        Runner runner = new Runner();
        runner.run(args);

    }

    public void run(String[] args) {

        Student student1 = new Student();
        student1.setName(args[0]);

        Student student2 = new Student();
        student2.setName(args[1]);

        Student student3 = new Student();
        student3.setName(args[2]);


        System.out.println(student1.callName());
        System.out.println(student2.callName());
        System.out.println(student3.callName());

        Classroom NTH412 = new Classroom();

        NTH412.setClassroomNumber("NTH412");
        NTH412.addStudent(student1);
        NTH412.addStudent(student2);
        NTH412.addStudent(student3);

        System.out.println("In " + NTH412.getClassroomNumber() + ", we have " + NTH412.getNumOfStudents());

    }

}

