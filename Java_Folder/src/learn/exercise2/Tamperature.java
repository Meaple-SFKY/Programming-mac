//此类在exercise2包里
package src.learn.exercise2;

//定义Tamperature类，实现摄氏度转华氏度，在主方法中使用
public class Tamperature {
    double degreeFahrenheit, degreeCelsius;
    void setCelsius(double degrees) {
        degreeCelsius = degrees;
    }
    void trans() {
        degreeFahrenheit = (9.0 / 5) * degreeCelsius + 32;
    }
    double getDegreeFahrenheit() {
        //返回华氏度值
        return degreeFahrenheit;
    }
}