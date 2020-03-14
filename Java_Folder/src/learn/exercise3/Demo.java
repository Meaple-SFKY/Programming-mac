//此类在src.learn.exercise3包里
package src.learn.exercise3;

//需要使用java.util.Scanner类
import java.util.Scanner;

//定义Demo类，包含主方法
public class Demo {
    public static void main(String[] args) {
        //定义一个Demo类
        Circle circle = new Circle();
        System.out.print("Please enter the radius of your circle: ");
        Scanner scan = new Scanner(System.in);
        double radius = scan.nextInt();
        circle.setRadius(radius);
        circle.showCircle();
        scan.close();
    }
}