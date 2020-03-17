//此类在src.learn.exercise3包里
package src.learn.exercise4;

//需要调用java.util.Scanner类
import java.util.Scanner;

//定义Demo类，此类包含主方法，实现输出电风扇的参数
public class Demo {
    public static void main(String[] args) {
        String color;
        int speed;
        double radius;
        //打开风扇1
        Fan fan1 = new Fan();
        //输入风扇1的参数
        System.out.println("Fan1 is opening, loading... ...");
        Scanner scan = new Scanner(System.in);
        System.out.print("Please enter the speed: ");
        speed = scan.nextInt();
        System.out.print("Please enter the radius: ");
        radius = scan.nextDouble();
        System.out.print("Please enter the color: ");
        color = scan.next();
        //通过Fan私有成员函数设定风扇1状态
        fan1.setSpeed(speed);
        fan1.setRadius(radius);
        fan1.setColor(color);
        //输出风扇1的参数
        System.out.println(fan1.toString());
        //关闭风扇1
        fan1.setStatus(false);
        //打开风扇2
        Fan fan2 = new Fan();
        //输入风扇2的参数
        System.out.println("Fan1 is closed, Fan2 is opening, loading... ...");
        System.out.print("Please enter the speed: ");
        speed = scan.nextInt();
        System.out.print("Please enter the radius: ");
        radius = scan.nextDouble();
        System.out.print("Please enter the color: ");
        color = scan.next();
        //通过Fan私有成员函数设定风扇1状态
        fan2.setSpeed(speed);
        fan2.setRadius(radius);
        fan2.setColor(color);
        //输出风扇2的参数
        System.out.println(fan2.toString());
        //关闭风扇2
        fan2.setStatus(false);
        scan.close();
    }
}