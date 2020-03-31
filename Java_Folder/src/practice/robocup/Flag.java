package src.practice.robocup;

/*----------------------------      定义Flag类     ------------------------------*/

public class Flag {
    private double Distance;
    private double Direction;
    private int Time_Period;
    private String Name;

    private void setDistance(String distance) {
        Distance = Double.parseDouble(distance);
    }

    private void setDirection(String direction) {
        Direction = Double.parseDouble(direction);
    }

    private void setTime_Period(String time) {
        Time_Period = Integer.parseInt(time);
    }

    private void setName(String name) {
        Name = name;
    }

    public double getDistance() {
        return Distance;
    }

    public double getDirection() {
        return Direction;
    }

    public int getTime_Period() {
        return Time_Period;
    }

    public String getName() {
        return Name;
    }

    public Flag(String time, String name, String distance, String direction) {
        setTime_Period(time);
        setDistance(distance);
        setDirection(direction);
        setName(name);
    }
}