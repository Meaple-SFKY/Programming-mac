//此类在src.learn.exercise3包里
package src.learn.exercise3;

//需要调用java.lang.Math类
import java.lang.Math;

//定义Circle类，实现由半径求解出圆的面积和周长，可在主方法里进行调用
public class Circle {
    public double radius;
    private double area, perimeter;
    public void setRadius(double temp) {
        radius = temp;
    }
    //由半径计算出面积和周长的方法
    private void calculate() {
        area = Math.PI * Math.pow(radius, 2.0);
        perimeter = 2 * Math.PI * radius;
    }
    //展示圆的面积和周长的信息
    public void showCircle() {
        calculate();
        System.out.println("Area: " + area + ", perimeter: " + perimeter + ".");
    }
}