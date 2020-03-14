//exercise包里
package src.learn.exercise1;  

import java.util.Scanner;  

//声明Exercise1类
public class Exercise1 {
    public static void main(String[] args)
    {
        System.out.println("Please input your name: ");
        //调用Scanner方法
        Scanner scanner = new Scanner(System.in);  
        String name = scanner.next();
        System.out.println(name + " like Java very much.");
        scanner.close();
    }
}