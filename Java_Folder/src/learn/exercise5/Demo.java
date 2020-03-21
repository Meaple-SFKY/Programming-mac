//此类在src.learn.exercise5包里
package src.learn.exercise5;

//需要调用java.util.Scanner类
import java.util.Scanner;

//定义Demo类，此类包含主方法
public class Demo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请依次输入姓名、年龄和薪水: ");
        //输入年龄，姓名，薪水信息
        String name = scanner.next();
        short age = scanner.nextShort();
        float salary = scanner.nextFloat();
        People people = new People(name, age, salary);
        try {
            people.printInfo();
        } catch(NegativeException e) { //捕获异常
            System.out.println(e);
        }
        scanner.close();
    }
}