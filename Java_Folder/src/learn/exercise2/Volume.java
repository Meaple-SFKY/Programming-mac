//此类在src.learn.exercise2包里
package src.learn.exercise2;

//使用到java.lang.Math类
import java.lang.Math;

//定义Volume类，实现由半径求解出球的体积，可在主方法里进行调用
public class Volume {
    double volume, radius;
    void setRadius(double value) {
        radius = value;
    }
    void calculate() {
        volume = (4.0 / 3) * Math.PI * Math.pow(radius, 3.0);
    }
    //获取体积值
    double getVolume() {
        return volume;
    }
}