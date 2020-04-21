#ifndef _MAZEPLUS_HPP_
#define _MAZEPLUS_HPP_

#include<iostream> 
#include<ctime>

using namespace std;

#define SQUARE "██"
#define SPACE "  "
#define MYSELF "★"
#define DOWNARROW "↓↓"
#define UPARROW "↑↑"
#define LEFTARRROW "←←"
#define RIGHTARROW "→→"
#define WALLR 2
#define WALL 1
#define ROAD 0
#define READED 1
#define UNREADED 0
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef struct {
    int** array;
    int** read;
    int Start_X_Locat;
    int Start_Y_Locat;
    int End_X_Locat;
    int End_Y_Locat;
    int size;
} mazeInfo;

class Maze {
private:
    int getSeed(void);
    bool ReadJudge(mazeInfo maze, int X_Locat, int Y_Locat);
    bool Around(mazeInfo maze, int X_Locat, int Y_Locat);
    void WallAround(void);
    void EmptyLine(void);

public:
    mazeInfo MAZE;
    Maze(int size);
    ~Maze() {};
    void printMaze(mazeInfo maze);
    void Openpath(mazeInfo& maze, int X_Locat, int Y_Locat);
};

Maze::Maze(int size) {
    MAZE.size = size;
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
    MAZE.Start_X_Locat = 1;
    MAZE.Start_X_Locat = 1;
    MAZE.End_X_Locat = MAZE.size - 2;
    MAZE.End_X_Locat = MAZE.size - 2;
    Openpath(MAZE, 1, 1);
}

int Maze::getSeed(void) {
    return rand() % 4;
}

bool Maze::ReadJudge(mazeInfo maze, int X_Locat, int Y_Locat) {
    if (maze.read[X_Locat][Y_Locat] == READED) {
        return true;
    }
    else {
        return false;
    }
}

bool Maze::Around(mazeInfo maze, int X_Locat, int Y_Locat) {
    if (((X_Locat > 2) && (maze.array[X_Locat - 2][Y_Locat] == WALLR)) || ((X_Locat < maze.size - 3) && (maze.array[X_Locat + 2][Y_Locat] == WALLR))
        || ((Y_Locat > 2) && (maze.array[X_Locat][Y_Locat - 2] == WALLR)) || ((Y_Locat < maze.size - 3) && (maze.array[X_Locat][Y_Locat + 2] == WALLR)))
    {
        return true;
    }
    return false;
}

void Maze::Openpath(mazeInfo& maze, int X_Locat, int Y_Locat) {
    if (X_Locat % 2 == 0) {
        X_Locat -= 1;
    }
    if (Y_Locat % 2 == 0) {
        Y_Locat -= 1;
    }
    while (1) {
        if (Around(maze, X_Locat, Y_Locat) == false) {
            return;
        }
        else {
            maze.array[X_Locat][Y_Locat] = ROAD;
            while (1) {
                int temp = getSeed();
                if (temp == UP && X_Locat > 2 && (maze.array[X_Locat - 2][Y_Locat] == WALLR)) {
                    X_Locat -= 2;
                    maze.array[X_Locat + 1][Y_Locat] = ROAD;
                    maze.array[X_Locat][Y_Locat] = ROAD;
                }
                else if (temp == DOWN && X_Locat < maze.size - 3 && (maze.array[X_Locat + 2][Y_Locat] == WALLR)) {
                    X_Locat += 2;
                    maze.array[X_Locat - 1][Y_Locat] = ROAD;
                    maze.array[X_Locat][Y_Locat] = ROAD;
                }
                else if (temp == LEFT && Y_Locat > 2 && (maze.array[X_Locat][Y_Locat - 2] == WALLR)) {
                    Y_Locat -= 2;
                    maze.array[X_Locat][Y_Locat + 1] = ROAD;
                    maze.array[X_Locat][Y_Locat] = ROAD;
                }
                else if (temp == RIGHT && Y_Locat < maze.size - 3 && (maze.array[X_Locat][Y_Locat + 2] == WALLR)) {
                    Y_Locat += 2;
                    maze.array[X_Locat][Y_Locat - 1] = ROAD;
                    maze.array[X_Locat][Y_Locat] = ROAD;
                }
                else {
                    break;
                }
                Openpath(maze, X_Locat, Y_Locat);
            }
        }
    }
}

void Maze::WallAround(void) {
    for (int i = 0; i < 30; i++) {
        cout << SQUARE;
    }
    cout << endl;
}

void Maze::EmptyLine(void) {
    cout << SQUARE;
    for (int i = 0; i < 28; i++) {
        cout << SPACE;
    }
    cout << SQUARE << endl;
}

void Maze::printMaze(mazeInfo maze) {
    for (int x = 0; x < maze.size; x++) {
        for (int y = 0; y < maze.size; y++) {
            if (maze.array[x][y] == WALL) {
                cout << SQUARE;
            }
            else {
                cout << SPACE;
            }
        }
        cout << endl;
    }
}

#endif