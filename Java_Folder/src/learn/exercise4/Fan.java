//此类在src.learn.exercise3包里
package src.learn.exercise4;

//定义Fan类
public class Fan {
    //设定三个静态变量，表示风扇速度
    final static int SLOW = 1, MEDIUM = 2, FAST = 3;
    //speed变量用于指定风扇速度
    private int speed;
    //on变量用于指定风扇状态（开关）默认关闭
    private boolean on = false;
    //radius变量用于指定风扇半径
    private double radius;
    //color变量用于指定风扇颜色
    private String color = new String();
    //set方法
    public void setSpeed(int num) {
        speed = num;
    }
    public void setRadius(double size) {
        radius = size;
    }
    public void setColor(String beautify) {
        color = beautify;
    }
    public void setStatus(boolean status) {
        on = status;
    }
    //get方法
    private String getSpeed() {
        if (speed == 1) {
            return "SLOW";
        }
        else if (speed == 2) {
            return "MEDIUM";
        }
        else {
            return "FAST";
        }
    }
    private boolean getOn() {
        return on;
    }
    private double getRadius() {
        return radius;
    }
    private String getColor() {
        return color;
    }
    //构造器，无参数，打开风扇
    Fan() {
        speed = SLOW;
        on = true;
        radius = 5.0;
        color = "blue";
    }
    //打印风扇状态
    public String toString() {
        if (getOn() == true) {
            return "Speed: " + getSpeed() + ", Color: " + getColor() + ", Radius: " + getRadius() + ".";
        }
        else {
            return "fan is off";
        }
    }
}