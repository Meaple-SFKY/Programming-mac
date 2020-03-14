//此类在src.learn.exercise2包里
package src.learn.exercise2;

//使用到java.util.Scanner类，处理输入
import java.util.Scanner;

//定义Exercise2类，包含主方法，可使用Tamperature、Volume、Cycle类
//分别处理第一题、第二题和第三题
public class Exercise2 {
    public static void main(String[] args) {
        String key;
        System.out.print("Please enter the identifier of your question(1, 2 or 3) and exit by '0': ");
        //输入数据
        Scanner scan = new Scanner(System.in);
        //获取临时数据
        Scanner temp = new Scanner(System.in);
        key = scan.nextLine();
        //假如输入的"题号"不是“0”
        while (!key.equals("0"))
        {
            //假如输入的“题号“是“1”，处理第一题的任务
            if (key.equals("1")) {
                //定义一个Tamperature类
                Tamperature tamperature = new Tamperature();
                double celsius;
                System.out.print("Please enter Celsius tamperature: ");
                celsius = temp.nextDouble();
                tamperature.setCelsius(celsius);
                tamperature.trans();
                double fahrenheit = tamperature.getDegreeFahrenheit();
                System.out.println("The Celsius tamperature is " + celsius + " and the Fahrenheit tamperature is " + fahrenheit);
            }
            //假如输入的”题号“是“2”，处理第二题的任务
            else if (key.equals("2")) {
                //定义一个Volume类
                Volume volume = new Volume();
                double radius, value;
                System.out.print("Please enter the radius: ");
                radius = temp.nextDouble();
                volume.setRadius(radius);
                volume.calculate();
                value = volume.getVolume();
                System.out.println("Radius: " + radius + "; Volume: " + value + ".");
            }
            //假如输入的”题号“是”3“，处理第三题任务
            else if (key.equals("3")) {
                //定义一个Cycle类
                Cycle cycle = new Cycle();
                long sum = cycle.getSum();
                System.out.println("The sum is " + sum + ".");
            }
            //假如输入的”题号“不符合要求，要求用户重新输入
            else {
                System.out.println("Trouble happens to the identifier of your question, please check your identifier.");
            }
            //假如用户需要继续检查题目，可直接在此输入题号或退出
            System.out.print("Please enter the identifier of your question(1, 2 or 3) and exit by '0': ");
            key = scan.nextLine();
        }
        System.out.println("Exited!");
        scan.close();
        temp.close();
    }
}