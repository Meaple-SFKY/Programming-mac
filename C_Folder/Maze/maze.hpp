#ifndef _MAZE_HPP_
#define _MAZE_HPP_

#include <fstream>
#include <iostream>
#include <sstream> 
#include <ctime>
#include <string>

#define SQUARE "██"
#define SPACE "  "
#define MYSELF "★★"
#define DOWNARROW "↓↓"
#define UPARROW "↑↑"
#define LEFTARRROW "←←"
#define RIGHTARROW "→→"
#define ENTRANCE "◉◉"
#define DESTINATION "▼▲"
#define WALLR 2
#define WALL 1
#define ROAD 0
#define READED 1
#define UNREADED 0
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define LEAVETYPE "leave"
#define FORKTYPE "fork"
#define BRANCHTYPE "branch"
#define WALLTYPE "wall"
#define UNREADTYPE "unread"
#define READEDTYPE "readed"
#define VISITEDTYPE "visited"
#define HISTORYUP "up"
#define HISTORYDOWN "down"
#define HISTORYLEFT "left"
#define HISTORYRIGHT "right"
#define HISTORYNOPS "no"

using namespace std;

typedef struct point {
    int X_Locat;
    int Y_Locat;
} Point;

typedef struct {
    bool ifUp;
    bool ifDown;
    bool ifLeft;
    bool ifRight;
} Continuity;

typedef struct {
    string type;
    string state;
    string visitHistory;
    Continuity continuity;
} Node;

typedef struct {
    Node priorNode;
    Node nextNode;
    Point* passBy;
} Edge;

typedef struct {
    int** array;
    int** read;
    Node** graph;
    Point startPoint;
    Point endPoint;
    int size;
    int pointNum;
} mazeInfo;

class Maze {
private:
    int getSeed(void);
    string mode;

    bool readJudge(mazeInfo maze, Point pointReadJudge);
    bool around(mazeInfo maze, Point pointAround);
    void wallAround(void);
    void emptyLine(void);
    void setPointNum(void);

public:
    mazeInfo MAZE;

    Maze(int size);
    ~Maze() {};

    void setGraphFromArray(void);
    void setMode(string modeStr);
    string getMode(void);
    void printMaze(mazeInfo maze);
    void setStartPoint(Point pointStartPoint);
    void setEndPoint(Point pointStartPoint);
    void editWallPoint(Point pointSetWall);
    void editRoadPoint(Point pointSetRoad);
    void openpath(mazeInfo& maze, Point pointOpenPath);
    void setInfoCommon(void);
    void setInfoFromFile(string fileNamePath);
    void getPath(void);
};

Maze::Maze(int size) {
    MAZE.size = size;
    Point pointOpenPath;

    pointOpenPath.X_Locat = 1;
    pointOpenPath.Y_Locat = 1;

    if (MAZE.size % 2 == 0) {
        MAZE.size++;
    }

    cout << "Now its size is " << MAZE.size << " * " << MAZE.size << "......" << endl;
    int** a = new int* [MAZE.size];
    int** b = new int* [MAZE.size];
    for (int i = 0; i < MAZE.size; i++) {
        a[i] = new int[MAZE.size];
        b[i] = new int[MAZE.size];
    }
    MAZE.array = a;
    MAZE.read = b;

    for (int i = 0; i < MAZE.size; i++) {
        for (int j = 0; j < MAZE.size; j++) {
            MAZE.array[i][j] = WALL;
            MAZE.read[i][j] = UNREADED;
        }
    }
    for (int i = 1; i < MAZE.size - 1; i += 2) {
        for (int j = 1; j < MAZE.size - 1; j += 2) {
            MAZE.array[i][j] = WALLR;
        }
    }

    MAZE.startPoint.X_Locat = 1;
    MAZE.startPoint.Y_Locat = 1;
    MAZE.endPoint.X_Locat = MAZE.size - 2;
    MAZE.endPoint.Y_Locat = MAZE.size - 2;

    openpath(MAZE, pointOpenPath);
}

int Maze::getSeed(void) {
    return rand() % 4;
}

void Maze::setGraphFromArray(void) {
    Node** a = new Node* [MAZE.size];
    for (int i = 0; i < MAZE.size; i++) {
        a[i] = new Node[MAZE.size];
    }

    MAZE.graph = a;
    for (int i = 0; i < MAZE.size; i++) {
        for (int j = 0; j < MAZE.size; j++) {
            if (MAZE.array[i][j] == WALL) {
                MAZE.graph[i][j].type = WALLTYPE;
                MAZE.graph[i][j].state = VISITEDTYPE;
                MAZE.graph[i][j].visitHistory = HISTORYNOPS;
                MAZE.graph[i][j].continuity.ifUp = false;
                MAZE.graph[i][j].continuity.ifDown = false;
                MAZE.graph[i][j].continuity.ifLeft = false;
                MAZE.graph[i][j].continuity.ifRight = false;
            }
            else {
                int temp = 0;
                if (MAZE.array[i - 1][j] == ROAD) {
                    temp++;
                    MAZE.graph[i][j].continuity.ifLeft = true;
                }
                if (MAZE.array[i + 1][j] == ROAD) {
                    temp++;
                    MAZE.graph[i][j].continuity.ifRight = true;
                }
                if (MAZE.array[i][j - 1] == ROAD) {
                    temp++;
                    MAZE.graph[i][j].continuity.ifUp = true;
                }
                if (MAZE.array[i][j + 1] == ROAD) {
                    temp++;
                    MAZE.graph[i][j].continuity.ifDown = true;
                }
                if (temp == 1) {
                    MAZE.graph[i][j].type = LEAVETYPE;
                }
                else if (temp == 2) {
                    MAZE.graph[i][j].type = BRANCHTYPE;
                }
                else {
                    MAZE.graph[i][j].type = FORKTYPE;
                }
                MAZE.graph[i][j].state = UNREADTYPE;

                MAZE.graph[i][j].visitHistory = HISTORYNOPS;
            }
        }
    }
}

bool Maze::readJudge(mazeInfo maze, Point pointReadJudge) {
    if (maze.read[pointReadJudge.X_Locat][pointReadJudge.Y_Locat] == READED) {
        return true;
    }
    else {
        return false;
    }
}

bool Maze::around(mazeInfo maze, Point pointAround) {
    if (((pointAround.X_Locat > 2) && (maze.array[pointAround.X_Locat - 2][pointAround.Y_Locat] == WALLR)) || ((pointAround.X_Locat < maze.size - 3) && (maze.array[pointAround.X_Locat + 2][pointAround.Y_Locat] == WALLR))
        || ((pointAround.Y_Locat > 2) && (maze.array[pointAround.X_Locat][pointAround.Y_Locat - 2] == WALLR)) || ((pointAround.Y_Locat < maze.size - 3) && (maze.array[pointAround.X_Locat][pointAround.Y_Locat + 2] == WALLR)))
    {
        return true;
    }
    return false;
}

void Maze::openpath(mazeInfo& maze, Point pointOpenPath) {
    if (pointOpenPath.X_Locat % 2 == 0) {
        if (pointOpenPath.X_Locat == 0) {
            pointOpenPath.X_Locat++;
        }
        else {
            pointOpenPath.X_Locat--;
        }
    }
    if (pointOpenPath.Y_Locat % 2 == 0) {
        if (pointOpenPath.Y_Locat == 0) {
            pointOpenPath.Y_Locat++;
        }
        else {
            pointOpenPath.Y_Locat--;
        }
    }

    while (1) {
        if (around(maze, pointOpenPath) == false) {
            return;
        }
        else {
            maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
            while (1) {
                int temp = getSeed();
                if (temp == UP && pointOpenPath.X_Locat > 2 && (maze.array[pointOpenPath.X_Locat - 2][pointOpenPath.Y_Locat] == WALLR)) {
                    pointOpenPath.X_Locat -= 2;
                    maze.array[pointOpenPath.X_Locat + 1][pointOpenPath.Y_Locat] = ROAD;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
                }
                else if (temp == DOWN && pointOpenPath.X_Locat < maze.size - 3 && (maze.array[pointOpenPath.X_Locat + 2][pointOpenPath.Y_Locat] == WALLR)) {
                    pointOpenPath.X_Locat += 2;
                    maze.array[pointOpenPath.X_Locat - 1][pointOpenPath.Y_Locat] = ROAD;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
                }
                else if (temp == LEFT && pointOpenPath.Y_Locat > 2 && (maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat - 2] == WALLR)) {
                    pointOpenPath.Y_Locat -= 2;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat + 1] = ROAD;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
                }
                else if (temp == RIGHT && pointOpenPath.Y_Locat < maze.size - 3 && (maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat + 2] == WALLR)) {
                    pointOpenPath.Y_Locat += 2;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat - 1] = ROAD;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
                }
                else {
                    break;
                }
                openpath(maze, pointOpenPath);
            }
        }
    }
}

void Maze::wallAround(void) {
    for (int i = 0; i < 30; i++) {
        cout << SQUARE;
    }
    cout << endl;
}

void Maze::emptyLine(void) {
    cout << SQUARE;
    for (int i = 0; i < 28; i++) {
        cout << SPACE;
    }
    cout << SQUARE << endl;
}

void Maze::setPointNum(void) {
    int num = 0;

    for (int i = 0; i < MAZE.size; i++) {
        for (int j = 0; j < MAZE.size; j++) {
            if (MAZE.array[i][j] == ROAD) {
                num++;
            }
        }
    }

    MAZE.pointNum = num;
}

void Maze::setMode(string modeStr) {
    mode = modeStr;
}

string Maze::getMode(void) {
    return mode;
}

void Maze::printMaze(mazeInfo maze) {
    for (int i = 0; i < maze.size; i++) {
        if (i < 10) {
            cout << i << " ";
        }
        else {
            cout << i;
        }
    }
    cout << endl;

    for (int x = 0; x < maze.size; x++) {
        for (int y = 0; y < maze.size; y++) {
            if (x == MAZE.startPoint.X_Locat && y == MAZE.startPoint.Y_Locat) {
                cout << ENTRANCE;
            }
            else if (x == MAZE.endPoint.X_Locat && y == MAZE.endPoint.Y_Locat) {
                cout << DESTINATION;
            }
            else if (maze.array[x][y] == WALL) {
                cout << SQUARE;
            }
            else {
                cout << SPACE;
            }
        }
        cout << " " << x << endl;
    }
}

void Maze::setStartPoint(Point start) {
    if (MAZE.array[start.X_Locat][start.Y_Locat] == WALL) {
        cout << "The entrance is already part of the wall, please reset the entrance..." << endl;
    }
    else {
        MAZE.startPoint.X_Locat = start.X_Locat;
        MAZE.startPoint.Y_Locat = start.Y_Locat;
    }
}

void Maze::setEndPoint(Point end) {
    if (MAZE.array[end.X_Locat][end.Y_Locat] == WALL) {
        cout << "The destination is already part of the wall, please reset the destination..." << endl;
    }
    else {
        MAZE.endPoint.X_Locat = end.X_Locat;
        MAZE.endPoint.Y_Locat = end.Y_Locat;
    }
}

void Maze::editWallPoint(Point pointSetWall) {
    MAZE.array[pointSetWall.X_Locat][pointSetWall.Y_Locat] = WALL;
}

void Maze::editRoadPoint(Point pointSetRoad) {
    MAZE.array[pointSetRoad.X_Locat][pointSetRoad.Y_Locat] = ROAD;
}

void Maze::setInfoFromFile(string fileNamePath) {
    ifstream infoFile(fileNamePath);
    string temp;
    int j = 0;
    stringstream stringToInteger;

    if (!infoFile.is_open()) {
        cout << "File failed to open." << endl;
    }

    while (getline(infoFile, temp)) {
        for (int i = 0; i < temp.length(); i++) {
            stringToInteger.clear();
            stringToInteger << temp.substr(i, 0);
            stringToInteger >> MAZE.array[j][i];
        }
        j++;
    }

    infoFile.close();
}

void Maze::getPath(void) {
    
}

#endif