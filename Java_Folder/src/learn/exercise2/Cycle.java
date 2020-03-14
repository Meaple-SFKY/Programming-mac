//此类存在于exercise2包中
package src.learn.exercise2;

//定义Cycle类，使用do-while结构，计算1~100阶乘之和，在主方法中使用
public class Cycle {
    long sum = 0;
    long temp = 1;
    int i = 1;
    long getSum() {
        //使用do-while结构
        do {
            temp *= i++;
            sum += temp;
        } while (i <= 100);
        return sum; //返回结果
    }
}