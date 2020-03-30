#include<iostream>
#include<string>

using namespace std;

void analyze(string);

//定义Ball类
class Ball {

private:
    double Distance;
    double Direction;
    double DistChng;
    double DirChng;
    void setDistance(string distance) {
        Distance = atof(distance.c_str());
    }
    void setDirection(string direction) {
        Direction = atof(direction.c_str());
    }
    void setDisChng(string dischng) {
        DistChng = atof(dischng.c_str());
    }
    void setDirChng(string dirchng) {
        DirChng = atof(dirchng.c_str());
    }
    void setTime_Period(string time) {
        Time_Period = atoi(time.c_str());
    }

public:
    int Time_Period;
    Ball() {
        Distance = 0;
        Direction = 0;
        DistChng = 0;
        DirChng = 0;
        Time_Period = 0;
    }
    Ball(string time, string distance, string direction, string dischng, string dirchng) {
        setTime_Period(time);
        setDistance(distance);
        setDirection(direction);
        setDisChng(dischng);
        setDirChng(dirchng);
    }
    ~Ball();
};

//定义Goal类
class Goal {
    
private:
    double Distance;
    double Direction;
    void setDistance(string distance) {
        Distance = atof(distance.c_str());
    }
    void setDirection(string direction) {
        Direction = atof(direction.c_str());
    }
    void setTime_Period(string time) {
        Time_Period = atoi(time.c_str());
    }
    void setName(string name) {
        Name = name;
    }

public:
    int Time_Period;
    string Name;
    Goal() {
        Distance = 0;
        Direction = 0;
        Time_Period = 0;
    }
    Goal(string time, string name, string distance, string direction) {
        setTime_Period(time);
        setDistance(distance);
        setDirection(direction);
        setName(name);
    }
    ~Goal();
};

//定义Line类
class Line {
    
private:
    double Distance;
    double Direction;
    void setDistance(string distance) {
        Distance = atof(distance.c_str());
    }
    void setDirection(string direction) {
        Direction = atof(direction.c_str());
    }
    void setTime_Period(string time) {
        Time_Period = atoi(time.c_str());
    }
    void setName(string name) {
        Name = name;
    }

public:
    int Time_Period;
    string Name;
    Line() {
        Distance = 0;
        Direction = 0;
        Time_Period = 0;
    }
    Line(string time, string name, string distance, string direction) {
        setTime_Period(time);
        setDistance(distance);
        setDirection(direction);
        setName(name);
    }
    ~Line();
};

//定义Flag类
class Flag {
    
private:
    double Distance;
    double Direction;
    void setDistance(string distance) {
        Distance = atof(distance.c_str());
    }
    void setDirection(string direction) {
        Direction = atof(direction.c_str());
    }
    void setTime_Period(string time) {
        Time_Period = atoi(time.c_str());
    }
    void setName(string name) {
        Name = name;
    }

public:
    int Time_Period;
    string Name;
    Flag() {
        Distance = 0;
        Direction = 0;
        Time_Period = 0;
    }
    Flag(string time, string name, string distance, string direction) {
        setTime_Period(time);
        setDistance(distance);
        setDirection(direction);
        setName(name);
    }
    ~Flag();
};

//定义Teammate类
class Teammate {
    
private:
    double Distance;
    double Direction;
    double DistChng;
    double DirChng;
    double BodyDir;
    double HeadDir;
    void setDistance(string distance) {
        Distance = atof(distance.c_str());
    }
    void setDirection(string direction) {
        Direction = atof(direction.c_str());
    }
    void setDisChng(string dischng) {
        DistChng = atof(dischng.c_str());
    }
    void setDirChng(string dirchng) {
        DirChng = atof(dirchng.c_str());
    }
    void setBodyDir(string bodydir) {
        BodyDir = atof(bodydir.c_str());
    }
    void setHeadDir(string headdir) {
        HeadDir = atof(headdir.c_str());
    }
    void setTime_Period(string time) {
        Time_Period = atoi(time.c_str());
    }
    void setName(string name) {
        Name = name;
    }

public:
    int Time_Period;
    string Name;
    Teammate() {
        Distance = 0;
        Direction = 0;
        DistChng = 0;
        DirChng = 0;
        BodyDir = 0;
        HeadDir = 0;
        Time_Period = 0;
        Name = "";
    }
    Teammate(string name, string time, string distance, string direction, string dischng, string dirchng, string bodydir, string headdir) {
        setName(name);
        setTime_Period(time);
        setDistance(distance);
        setDirection(direction);
        setDisChng(dischng);
        setDirChng(dirchng);
        setBodyDir(bodydir);
        setHeadDir(headdir);
    }
    ~Teammate();
};

//定义Opponent类
class Opponent {
    
private:
    double Distance;
    double Direction;
    double DistChng;
    double DirChng;
    double BodyDir;
    double HeadDir;
    void setDistance(string distance) {
        Distance = atof(distance.c_str());
    }
    void setDirection(string direction) {
        Direction = atof(direction.c_str());
    }
    void setDisChng(string dischng) {
        DistChng = atof(dischng.c_str());
    }
    void setDirChng(string dirchng) {
        DirChng = atof(dirchng.c_str());
    }
    void setBodyDir(string bodydir) {
        BodyDir = atof(bodydir.c_str());
    }
    void setHeadDir(string headdir) {
        HeadDir = atof(headdir.c_str());
    }
    void setTime_Period(string time) {
        Time_Period = atoi(time.c_str());
    }
    void setName(string name) {
        Name = name;
    }

public:
    int Time_Period;
    string Name;
    Opponent() {
        Distance = 0;
        Direction = 0;
        DistChng = 0;
        DirChng = 0;
        BodyDir = 0;
        HeadDir = 0;
        Time_Period = 0;
        Name = "";
    }
    Opponent(string name, string time, string distance, string direction, string dischng, string dirchng, string bodydir, string headdir) {
        setName(name);
        setTime_Period(time);
        setDistance(distance);
        setDirection(direction);
        setDisChng(dischng);
        setDirChng(dirchng);
        setBodyDir(bodydir);
        setHeadDir(headdir);
    }
    ~Opponent();
};

//解析函数
void analyze(string msg) {
    //定义特定字符串
    string Hear = "hear";
    string See = "see";
    string Ball = "ball";
    string Goal = "goal";
    string Line = "line";
    string Flag = "flag";
    string Player = "player";
    string Hfut1 = "hfut1";
    string Hfut2 = "hfut2";

    //从msg信字符字符串中查找特定字符串
    string::size_type index;

    //第一层级，首先查找“hear”/"see"
    index = msg.find(Hear);

    //获取的msg信息中没有“hear”
    if (index == string::npos) {
        index = msg.find(See);

        //获取的msg信息中既没有“hear”, 也没有“see”, 处理为无效信息
        if (index == string::npos) {
            cout << "Sorry, Invalid information received!" << endl;
        }

        //获取的msg信息中有"see"
        else {

            //第二层级，查找对象依次是类型“ball", "goal", "line", "flag", "player”
            index = msg.find(Ball);

            //获取的msg信息中有“ball”,对象类型是足球
            if (index != string::npos) {

            }
        }
        
    }
    else {

    }

}

int main(void) {
    return 0;
}