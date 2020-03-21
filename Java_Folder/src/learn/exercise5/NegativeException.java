//此类在src.learn.exercise5包里
package src.learn.exercise5;

//异常类，抛出异常<年龄或工资不能为负数，异常类是NegativeException>
public final class NegativeException extends Exception {
    NegativeException() {
        System.out.println("年龄或工资不能为负数，异常类是NegativeException");
    }
}  