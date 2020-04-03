package src.practice.robocup;

/*--------------------------     定义Ball类      --------------------------------*/

public class Ball {

    private static double Distance;
    private static double Direction;
    private static double DistChng;
    private static double DirChng;
    private static int Time_Period;

    private void setDistance(String distance) {
        Distance = Double.parseDouble(distance);
    }

    private void setDirection(String direction) {
        Direction = Double.parseDouble(direction);
    }

    private void setDistChng(String distchng) {
        DistChng = Double.parseDouble(distchng);
    }

    private void setDirChng(String dirchng) {
        DirChng = Double.parseDouble(dirchng);
    }

    private void setTime_Period(String time) {
        Time_Period = Integer.parseInt(time);
    }

    public double getDistance() {
        return Distance;
    }

    public double getDirection() {
        return Direction;
    }

    public double getDistChng() {
        return DistChng;
    }

    public double getDirChng() {
        return DirChng;
    }

    public int getTime_Period() {
        return Time_Period;
    }

    public Ball(String time, String distance, String direction, String distchng, String dirchng) {
        setTime_Period(time);
        setDistance(distance);
        setDirection(direction);
        setDistChng(distchng);
        setDirChng(dirchng);
    }
}