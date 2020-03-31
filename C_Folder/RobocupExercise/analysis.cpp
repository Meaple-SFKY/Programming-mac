#include<iostream>
#include<string>

using namespace std;

void analyze(string);

/********************************************************************************/
/*--------------------------      定义类         --------------------------------*/
/********************************************************************************/

/*--------------------------     定义Ball类      --------------------------------*/

class Ball {

private:
    double Distance;
    double Direction;
    double DistChng;
    double DirChng;
    int Time_Period;
    void setDistance(string distance);
    void setDirection(string direction);
    void setDistChng(string distchng);
    void setDirChng(string dirchng);
    void setTime_Period(string time);

public:
    double getDistance();
    double getDirection();
    double getDistChng();
    double getDirChng();
    int getTime_Period();
    Ball(string time, string distance, string direction, string distchng, string dirchng);
    ~Ball();
};

void Ball::setDistance(string distance) {
    Distance = atof(distance.c_str());
}
void Ball::setDirection(string direction) {
    Direction = atof(direction.c_str());
}
void Ball::setDistChng(string distchng) {
    DistChng = atof(distchng.c_str());
}
void Ball::setDirChng(string dirchng) {
    DirChng = atof(dirchng.c_str());
}
void Ball::setTime_Period(string time) {
    Time_Period = atoi(time.c_str());
}

double Ball::getDistance() {
    return Distance;
}
double Ball::getDirection() {
    return Direction;
}
double Ball::getDistChng() {
    return DistChng;
}
double Ball::getDirChng() {
    return DirChng;
}
int Ball::getTime_Period() {
    return Time_Period;
}

Ball::Ball(string time, string distance, string direction, string distchng, string dirchng) {
    setTime_Period(time);
    setDistance(distance);
    setDirection(direction);
    setDistChng(distchng);
    setDirChng(dirchng);
}

/*-------------------------------     定义Goal类      ------------------------------*/

class Goal {
    
private:
    double Distance;
    double Direction;
    void setDistance(string distance);
    void setDirection(string direction);
    void setTime_Period(string time);
    void setName(string name);

public:
    int Time_Period;
    string Name;
    double getDistance();
    double getDirection();
    int getTime_Period();
    string getName();
    Goal(string time, string name, string distance, string direction);
    ~Goal();
};

void Goal::setDistance(string distance) {
    Distance = atof(distance.c_str());
}

void Goal::setDirection(string direction) {
    Direction = atof(direction.c_str());
}

void Goal::setTime_Period(string time) {
    Time_Period = atoi(time.c_str());
}

void Goal::setName(string name) {
    Name = name;
}

double Goal::getDistance() {
    return Distance;
}

double Goal::getDirection() {
    return Direction;
}

int Goal::getTime_Period() {
    return Time_Period;
}

string Goal::getName() {
    return Name;
}

Goal::Goal(string time, string name, string distance, string direction) {
    setTime_Period(time);
    setDistance(distance);
    setDirection(direction);
    setName(name);
}

/*-------------------------------      定义Line类      -------------------------------*/

class Line {
    
private:
    double Distance;
    double Direction;
    void setDistance(string distance);
    void setDirection(string direction);
    void setTime_Period(string time);
    void setName(string name);

public:
    int Time_Period;
    string Name;
    double getDistance();
    double getDirection();
    int getTime_Period();
    string getName();
    Line(string time, string name, string distance, string direction);
    ~Line();
};

void Line::setDistance(string distance) {
    Distance = atof(distance.c_str());
}
void Line::setDirection(string direction) {
    Direction = atof(direction.c_str());
}
void Line::setTime_Period(string time) {
    Time_Period = atoi(time.c_str());
}
void Line::setName(string name) {
    Name = name;
}

double Line::getDistance() {
    return Distance;
}

double Line::getDirection() {
    return Direction;
}

int Line::getTime_Period() {
    return Time_Period;
}

string Line::getName() {
    return Name;
}

Line::Line(string time, string name, string distance, string direction) {
    setTime_Period(time);
    setDistance(distance);
    setDirection(direction);
    setName(name);
}

/*-----------------------------      定义Flag类     ------------------------------------*/

class Flag {
    
private:
    double Distance;
    double Direction;
    void setDistance(string distance);
    void setDirection(string direction);
    void setTime_Period(string time);
    void setName(string name);

public:
    int Time_Period;
    string Name;
    double getDistance();
    double getDirection();
    int getTime_Period();
    string getName();
    Flag(string time, string name, string distance, string direction);
    ~Flag();
};

void Flag::setDistance(string distance) {
    Distance = atof(distance.c_str());
}

void Flag::setDirection(string direction) {
    Direction = atof(direction.c_str());
}

void Flag::setTime_Period(string time) {
    Time_Period = atoi(time.c_str());
}

void Flag::setName(string name) {
    Name = name;
}

double Flag::getDistance() {
    return Distance;
}

double Flag::getDirection() {
    return Direction;
}

int Flag::getTime_Period() {
    return Time_Period;
}

string Flag::getName() {
    return Name;
}

Flag::Flag(string time, string name, string distance, string direction) {
    setTime_Period(time);
    setDistance(distance);
    setDirection(direction);
    setName(name);
}

/*-------------------------------     定义Teammate类     --------------------------------------*/

class Teammate {
    
private:
    double Distance;
    double Direction;
    double DistChng;
    double DirChng;
    double BodyDir;
    double HeadDir;
    void setDistance(string distance);
    void setDirection(string direction);
    void setDisChng(string dischng);
    void setDirChng(string dirchng);
    void setBodyDir(string bodydir);
    void setHeadDir(string headdir);
    void setTime_Period(string time);
    void setName(string name);

public:
    int Time_Period;
    string Name;
    double getDistance();
    double getDirection();
    double getDisChng();
    double getDirChng();
    double getBodyDir();
    double getHeadDir();
    int getTime_Period();
    string getName();
    Teammate(string name, string time, string distance, string direction, string dischng, string dirchng, string bodydir, string headdir);
    ~Teammate();
};

void Teammate::setDistance(string distance) {
    Distance = atof(distance.c_str());
}

void Teammate::setDirection(string direction) {
    Direction = atof(direction.c_str());
}

void Teammate::setDisChng(string dischng) {
    DistChng = atof(dischng.c_str());
}

void Teammate::setDirChng(string dirchng) {
    DirChng = atof(dirchng.c_str());
}

void Teammate::setBodyDir(string bodydir) {
    BodyDir = atof(bodydir.c_str());
}

void Teammate::setHeadDir(string headdir) {
    HeadDir = atof(headdir.c_str());
}

void Teammate::setTime_Period(string time) {
    Time_Period = atoi(time.c_str());
}

void Teammate::setName(string name) {
    Name = name;
}

double Teammate::getDistance() {
    return Distance;
}

double Teammate::getDirection() {
    return Direction;
}

double Teammate::getDisChng() {
    return DistChng;
}

double Teammate::getDirChng() {
    return DirChng;
}

double Teammate::getBodyDir() {
    return BodyDir;
}

double Teammate::getHeadDir() {
    return HeadDir;
}

int Teammate::getTime_Period() {
    return Time_Period;
}

string Teammate::getName() {
    return Name;
}

Teammate::Teammate(string name, string time, string distance, string direction, string dischng, string dirchng, string bodydir, string headdir) {
    setName(name);
    setTime_Period(time);
    setDistance(distance);
    setDirection(direction);
    setDisChng(dischng);
    setDirChng(dirchng);
    setBodyDir(bodydir);
    setHeadDir(headdir);
}

/*---------------------------      定义Opponent类     ----------------------------------------------------*/

class Opponent {
    
private:
    double Distance;
    double Direction;
    double DistChng;
    double DirChng;
    double BodyDir;
    double HeadDir;
    void setDistance(string distance);
    void setDirection(string direction);
    void setDisChng(string dischng);
    void setDirChng(string dirchng);
    void setBodyDir(string bodydir);
    void setHeadDir(string headdir);
    void setTime_Period(string time);
    void setName(string name);

public:
    int Time_Period;
    string Name;
    double getDistance();
    double getDirection();
    double getDisChng();
    double getDirChng();
    double getBodyDir();
    double getHeadDir();
    int getTime_Period();
    string getName();
    Opponent(string name, string time, string distance, string direction, string dischng, string dirchng, string bodydir, string headdir);
    ~Opponent();
};

void Opponent::setDistance(string distance) {
    Distance = atof(distance.c_str());
}

void Opponent::setDirection(string direction) {
    Direction = atof(direction.c_str());
}

void Opponent::setDisChng(string dischng) {
    DistChng = atof(dischng.c_str());
}

void Opponent::setDirChng(string dirchng) {
    DirChng = atof(dirchng.c_str());
}

void Opponent::setBodyDir(string bodydir) {
    BodyDir = atof(bodydir.c_str());
}

void Opponent::setHeadDir(string headdir) {
    HeadDir = atof(headdir.c_str());
}

void Opponent::setTime_Period(string time) {
    Time_Period = atoi(time.c_str());
}

void Opponent::setName(string name) {
    Name = name;
}

double Opponent::getDistance() {
    return Distance;
}

double Opponent::getDirection() {
    return Direction;
}

double Opponent::getDisChng() {
    return DistChng;
}

double Opponent::getDirChng() {
    return DirChng;
}

double Opponent::getBodyDir() {
    return BodyDir;
}

double Opponent::getHeadDir() {
    return HeadDir;
}

int Opponent::getTime_Period() {
    return Time_Period;
}

string Opponent::getName() {
    return Name;
}

Opponent::Opponent(string name, string time, string distance, string direction, string dischng, string dirchng, string bodydir, string headdir) {
    setName(name);
    setTime_Period(time);
    setDistance(distance);
    setDirection(direction);
    setDisChng(dischng);
    setDirChng(dirchng);
    setBodyDir(bodydir);
    setHeadDir(headdir);
}

/********************************************************************************/
/*--------------------------      类定义结束       ------------------------------*/
/********************************************************************************/

//解析函数
void analyze(string msg) {

    //定义特定字符串
    string Hear = "hear";
    string See = "see";
    string Ball_ = "ball";
    string Goal_ = "goal";
    string Line_ = "line";
    string Flag_ = "flag";
    string Player_ = "player";
    string Hfut1 = "hfut1";
    string Hfut2 = "hfut2";

    int len = msg.length();
    int i;

    char* p = NULL;

    //从信息msg字符串中查找特定字符串
    string::size_type index;

    //首先查找“hear”/“see”
    index = msg.find(See);

    //成功“see”
    if (index != string::npos) {
        for (i = 0; i < len - 4; i++) {

            if (*(p + i) == 'h' && *(p + i + 1) == 'e' && *(p + i + 2) == 'a' && *(p + i + 3) == 'r') {
                break;
            }
            //查找对象类型依次是“ball", "goal", "line", "flag", "player”
            if (*(p + i) == 's' && *(p + i + 1) == 'e' && *(p + i + 2) == 'e') {
                
                string Time_ = NULL;
                while (*(p + i) != ' ') {
                    i++;
                }
                i++;

                while (*(p + i) != ' ') {
                    Time_ += *(p + i);
                    i++;
                }

                if (*(p + i) == 'b' && *(p + i + 1) == 'a' && *(p + i + 2) == 'l' && *(p + i + 3) == 'l') {
                    string Distance_ = NULL;
                    string Direction_ = NULL;
                    string DistChng_ = NULL;
                    string DirChng_ = NULL;

                    while (*(p + i)!= ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        Distance_ += *(p + i);
                        i++;
                    }
                
                    while (*(p + i) != ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        Direction_ += *(p + i);
                        i++;
                    }
                
                    while (*(p + i) != ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        DistChng_ += *(p + i);
                        i++;
                    }
                
                    while (*(p + i) != ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        DirChng_ += *(p + i);
                        i++;
                    }

                    Ball ball(Time_, Distance_, Direction_, DistChng_, DirChng_);

                    cout << "在 " << ball.getTime_Period() << " 周期 see " << Ball_ << "距离我的 Distance 是 " << ball.getDistance() << ", Direction 是 "
                     << ball.getDirection() << ", DistChng 是 " << ball.getDistChng() << ", DirChng 是 " << ball.getDirChng() << "; ";
                }

                if (*(p + i) == 'g' && *(p + i + 1) == 'o' && *(p + i + 2) == 'a' && *(p + i + 3) == 'l') {
                    string Distance_ = NULL;
                    string Direction_ = NULL;
                    string Name_ = NULL;

                    i += 5;

                    while (*(p + i) != ')') {
                        Name_ += *(p + i);
                        i++;
                    }

                    while (*(p + i)!= ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        Distance_ += *(p + i);
                        i++;
                    }
                
                    while (*(p + i) != ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        Direction_ += *(p + i);
                        i++;
                    }

                    Goal goal(Time_, Name_, Distance_, Direction_);

                    cout << "在 " << goal.getTime_Period() << " 周期 see " << Goal_ << " " << goal.getName() << " 距离我的 Distance 是 " << goal.getDistance() << ", Direction 是 "
                     << goal.getDirection() << "; ";
                }

                if (*(p + i) == 'l' && *(p + i + 1) == 'i' && *(p + i + 2) == 'n' && *(p + i + 3) == 'e') {
                    string Distance_ = NULL;
                    string Direction_ = NULL;
                    string Name_ = NULL;

                    i += 5;

                    while (*(p + i) != ')') {
                        Name_ += *(p + i);
                        i++;
                    }

                    while (*(p + i)!= ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        Distance_ += *(p + i);
                        i++;
                    }
                
                    while (*(p + i) != ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        Direction_ += *(p + i);
                        i++;
                    }

                    Line line(Time_, Name_, Distance_, Direction_);

                    cout << "在 " << line.getTime_Period() << " 周期 see " << Line_ << " " << line.getName() << " 距离我的 Distance 是 " << line.getDistance() << ", Direction 是 "
                     << line.getDirection() << "; ";
                }

                if (*(p + i) == 'f') {
                    string Distance_ = NULL;
                    string Direction_ = NULL;
                    string Name_ = NULL;

                    i += 2;

                    while (*(p + i) != ')') {
                        Name_ += *(p + i);
                        i++;
                    }

                    while (*(p + i)!= ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        Distance_ += *(p + i);
                        i++;
                    }
                
                    while (*(p + i) != ' ') {
                        i++;
                    }
                    i++;

                    while (*(p + i) != ' ') {
                        Direction_ += *(p + i);
                        i++;
                    }

                    Flag flag(Time_, Name_, Distance_, Direction_);

                    cout << "在 " << flag.getTime_Period() << " 周期 see " << Flag_ << " " << flag.getName() << " 距离我的 Distance 是 " << flag.getDistance() << ", Direction 是 "
                     << flag.getDirection() << "; ";
                }

                if (*(p + i) == 'p' && *(p + i + 1) == 'l' && *(p + i + 2) == 'a' && *(p + i + 3) == 'y' && *(p + i + 4) == 'e' && *(p + i + 5) == 'r') {
                    string Distance_ = NULL;
                    string Direction_ = NULL;
                    string DistChng_ = NULL;
                    string DirChng_ = NULL;
                    string BodyDir_ = NULL;
                    string HeadDir_ = NULL;
                    string Name_ = NULL;

                    i += 7;

                    if (*(p + i) == 'h' && *(p + i + 1) == 'f' && *(p + i + 2) == 'u' && *(p + i + 3) == 't' && *(p + i + 4) == '1') {

                        while (*(p + i)!= ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ')') {
                            Name_ += *(p + i);
                            i++;
                        }

                        while (*(p + i)!= ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            Distance_ += *(p + i);
                            i++;
                        }
                
                        while (*(p + i) != ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            Direction_ += *(p + i);
                            i++;
                        }

                        while (*(p + i)!= ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            DistChng_ += *(p + i);
                            i++;
                        }
                
                        while (*(p + i) != ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            DirChng_ += *(p + i);
                            i++;
                        }
                
                        while (*(p + i) != ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            BodyDir_ += *(p + i);
                            i++;
                        }
                
                        while (*(p + i) != ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            HeadDir_ += *(p + i);
                            i++;
                        }

                        Teammate teammate(Time_, Name_, Distance_, Direction_, DistChng_, DirChng_, BodyDir_, HeadDir_);

                        cout << "在 " << teammate.getTime_Period() << " 周期 see " << Line_ << " " << teammate.getName() << " 距离我的 Distance 是 " << teammate.getDistance() << ", Direction 是 "
                         << teammate.getDirection() << ", BodyDir 是 " << teammate.getBodyDir() << ", HeadDir 是 " << teammate.getHeadDir() << "; ";
                    }

                    else if (*(p + i) == 'h' && *(p + i + 1) == 'f' && *(p + i + 2) == 'u' && *(p + i + 3) == 't' && *(p + i + 4) == '2') {

                        while (*(p + i)!= ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ')') {
                            Name_ += *(p + i);
                            i++;
                        }

                        while (*(p + i)!= ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            Distance_ += *(p + i);
                            i++;
                        }
                
                        while (*(p + i) != ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            Direction_ += *(p + i);
                            i++;
                        }

                        while (*(p + i)!= ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            DistChng_ += *(p + i);
                            i++;
                        }
                
                        while (*(p + i) != ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            DirChng_ += *(p + i);
                            i++;
                        }
                
                        while (*(p + i) != ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            BodyDir_ += *(p + i);
                            i++;
                        }
                
                        while (*(p + i) != ' ') {
                            i++;
                        }
                        i++;

                        while (*(p + i) != ' ') {
                            HeadDir_ += *(p + i);
                            i++;
                        }

                        Opponent opponent(Time_, Name_, Distance_, Direction_, DistChng_, DirChng_, BodyDir_, HeadDir_);

                        cout << "在 " << opponent.getTime_Period() << " 周期 see " << Line_ << " " << opponent.getName() << " 距离我的 Distance 是 " << opponent.getDistance() << ", Direction 是 "
                         << opponent.getDirection() << ", BodyDir 是 " << opponent.getBodyDir() << ", HeadDir 是 " << opponent.getHeadDir() << "; ";
                    }
                }
            }
        }
        cout << endl;

    }

    index = msg.find (Hear);

    //成功“hear”
    if (index != string::npos) {

        string Time_;
        string Dir_;
        string message_;

        for (i = 0; i < len; i++) {

            if (*(p + i) == 's' && *(p + i + 1) == 'e' && *(p + i + 2) == 'e') {
                break;
            }

            if (*(p + i) == 'h' && *(p + i + 1) == 'e' && *(p + i + 2) == 'a' && *(p + i + 3) == 'r') {
                
                while (*(p + i) != ' ') {
                    i++;
                }
                i++;

                while (*(p + i) != ' ') {
                    Time_ += *p;
                }

                while (*(p + i) != ' ') {
                    i++;
                }
                i++;

                while (*(p + i) != ' ') {
                    Dir_ += *p;
                }

                while (*(p + i) != ' ') {
                    i++;
                }
                i++;

                while (*(p + i) != ' ') {
                    message_ += *p;
                }

                cout << "在 " << Time_ << " 周期 hear 从 " << Dir_ << " 方向听到了 " << message_ << "; " ;
            }
        }
        cout << endl;
    }
}

int main(void) {
    string msg = "(hear 1022 -30 passto(23,24))(see 1022 ((ball) 20 -20 1 -2) ((player hfut1 2) 23 45 0.5 1 22 40 ) ((goal r) 12 20))";
    analyze(msg);
    return 0;
}