package src.learn.exercise4;

import java.util.Scanner;

public class Demo {
    public static void main(String[] args) {
        String color;
        int speed;
        double radius;
        Fan fan1 = new Fan();
        System.out.println("Fan1 is opening, loading... ...");
        Scanner scan = new Scanner(System.in);
        System.out.print("Please enter the speed: ");
        speed = scan.nextInt();
        System.out.print("Please enter the radius: ");
        radius = scan.nextDouble();
        System.out.print("Please enter the color: ");
        color = scan.next();
        fan1.setSpeed(speed);
        fan1.setRadius(radius);
        fan1.setColor(color);
        System.out.println(fan1.toString());
        fan1.setStatus(false);
        Fan fan2 = new Fan();
        System.out.println("Fan1 is closed, Fan2 is opening, loading... ...");
        System.out.print("Please enter the speed: ");
        speed = scan.nextInt();
        System.out.print("Please enter the radius: ");
        radius = scan.nextDouble();
        System.out.print("Please enter the color: ");
        color = scan.next();
        fan2.setSpeed(speed);
        fan2.setRadius(radius);
        fan2.setColor(color);
        System.out.println(fan2.toString());
        fan2.setStatus(false);
        scan.close();
    }
}