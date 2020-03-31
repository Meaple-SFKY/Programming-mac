package src.practice.robocup;

/*---------------------------     定义Teammate类     ------------------------------*/

public class Teammate {
    private double Distance;
    private double Direction;
    private double DistChng;
    private double DirChng;
    private double BodyDir;
    private double HeadDir;
    private int Time_Period;
    private String Name;

    private void setDistance(String distance) {
        Distance = Double.parseDouble(distance);
    }
    
    private void setDirection(String direction) {
        Direction = Double.parseDouble(direction);
    }
    
    private void setDisChng(String dischng) {
        DistChng = Double.parseDouble(dischng);
    }
    
    private void setDirChng(String dirchng) {
        DirChng = Double.parseDouble(dirchng);
    }
    
    private void setBodyDir(String bodydir) {
        BodyDir = Double.parseDouble(bodydir);
    }
    
    private void setHeadDir(String headdir) {
        HeadDir = Double.parseDouble(headdir);
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
    
    public double getDisChng() {
        return DistChng;
    }
    
    public double getDirChng() {
        return DirChng;
    }
    
    public double getBodyDir() {
        return BodyDir;
    }
    
    public double getHeadDir() {
        return HeadDir;
    }
    
    public int getTime_Period() {
        return Time_Period;
    }
    
    public String getName() {
        return Name;
    }
    
    public Teammate(String name, String time, String distance, String direction, String dischng, String dirchng, String bodydir, String headdir) {
        setName(name);
        setTime_Period(time);
        setDistance(distance);
        setDirection(direction);
        setDisChng(dischng);
        setDirChng(dirchng);
        setBodyDir(bodydir);
        setHeadDir(headdir);
    }
}