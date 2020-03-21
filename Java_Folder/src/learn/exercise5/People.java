//此类在src.learn.exercise5包里
package src.learn.exercise5;

//定义People类
public class People {
    public String name = new String();
    public static short age;
    public static float salary;
    //有参构造函数
    People(String string, short num, float temp) {
        name = string;
        age = num;
        salary = temp;
    }
    //无参构造函数
    People() {
        name = "";
        age = 0;
        salary = 0f;
    }
    public void printInfo() throws NegativeException {
        //抛出异常
        if (age < 0 || salary < 0) {
            throw new NegativeException();
        }
        System.out.println("Name: " + name + ",  Age: " + age + ",  Salary: " + salary + ".");
    }
}