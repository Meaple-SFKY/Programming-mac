package src.learn.exercise4;

public class Fan {
    final static int SLOW = 1, MEDIUM = 2, FAST = 3;
    private int speed;
    private boolean on = false;
    private double radius;
    private String color = new String();
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
    Fan() {
        speed = SLOW;
        on = true;
        radius = 5.0;
        color = "blue";
    }
    public String toString() {
        if (getOn() == true) {
            return "Speed: " + getSpeed() + ", Color: " + getColor() + ", Radius: " + getRadius() + ".";
        }
        else {
            return "fan is off";
        }
    }
}