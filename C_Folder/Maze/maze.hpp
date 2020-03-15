#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>

#define SQUARE "██"
#define SPACE "  "
#define MYSELF "★"
#define DOWNARROW "↓↓"
#define UPARROW "↑↑"
#define LEFTARRROW "←←"
#define RIGHTARROW "→→"
#define EXPORT "?"
#define ENTRANCE "?"
#define WALLR 2
#define WALL 1
#define ROAD 0
#define READED 1
#define UNREADED 0
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

typedef struct
{
    int X_Locat;
    int Y_Locat;
} Locat;

typedef struct
{
    int** array;
    int** read;
    Locat Start;
    Locat End;
    int size;
} MAZE;

void printMaze(MAZE);

int getSeed(void)
{
    return rand() % 4;
}

int getSize(void)
{
    int size;
    cout << "Please input the size of your maze (20~60): ";
    cin >> size;
    return size;
}

bool ReadJudge(MAZE maze, int X_Locat, int Y_Locat)
{
    if (maze.read[X_Locat][Y_Locat] == READED)
    {
        return true;
    }
    else
    {
        return false;
    }
}

MAZE initialMaze(MAZE& maze)
{
    maze.size = getSize();
    if (maze.size % 2 == 0)
    {
        maze.size++;
    }
    cout << "Now its size is " << maze.size << " * " << maze.size << "......" << endl;
    int** a = new int* [maze.size];
    int** b = new int* [maze.size];
    for (int i = 0; i < maze.size; i++)
    {
        a[i] = new int[maze.size];
        b[i] = new int[maze.size];
    }
    maze.array = a;
    maze.read = b;
    for (int i = 0; i < maze.size; i++)
    {
        for (int j = 0; j < maze.size; j++)
        {
            maze.array[i][j] = WALL;
            maze.read[i][j] = UNREADED;
        }
    }
    for (int i = 1; i < maze.size - 1; i += 2)
    {
        for (int j = 1; j < maze.size - 1; j += 2)
        {
            maze.array[i][j] = WALLR;
        }
    }
    maze.Start = { 1, 1 };
    maze.End = { maze.size - 2, maze.size - 2 };
    return maze;
}

bool Around(MAZE maze, int X_Locat, int Y_Locat)
{
    if (((X_Locat > 2) && (maze.array[X_Locat - 2][Y_Locat] == WALLR)) || ((X_Locat < maze.size - 3) && (maze.array[X_Locat + 2][Y_Locat] == WALLR))
        || ((Y_Locat > 2) && (maze.array[X_Locat][Y_Locat - 2] == WALLR)) || ((Y_Locat < maze.size - 3) && (maze.array[X_Locat][Y_Locat + 2] == WALLR)))
    {
        return true;
    }
    return false;
}

void Openpath(MAZE& maze, int X_Locat, int Y_Locat)
{
    while (1)
    {
        if (Around(maze, X_Locat, Y_Locat) == false)
        {
            return;
        }
        else
        {
            maze.array[X_Locat][Y_Locat] = ROAD;
            while (1)
            {
                int temp = getSeed();
                if (temp == UP && X_Locat > 2 && (maze.array[X_Locat - 2][Y_Locat] == WALLR))
                {
                    X_Locat -= 2;
                    maze.array[X_Locat + 1][Y_Locat] = ROAD;
                    maze.array[X_Locat][Y_Locat] = ROAD;
                }
                else if (temp == DOWN && X_Locat < maze.size - 3 && (maze.array[X_Locat + 2][Y_Locat] == WALLR))
                {
                    X_Locat += 2;
                    maze.array[X_Locat - 1][Y_Locat] = ROAD;
                    maze.array[X_Locat][Y_Locat] = ROAD;
                }
                else if (temp == LEFT && Y_Locat > 2 && (maze.array[X_Locat][Y_Locat - 2] == WALLR))
                {
                    Y_Locat -= 2;
                    maze.array[X_Locat][Y_Locat + 1] = ROAD;
                    maze.array[X_Locat][Y_Locat] = ROAD;
                }
                else if (temp == RIGHT && Y_Locat < maze.size - 3 && (maze.array[X_Locat][Y_Locat + 2] == WALLR))
                {
                    Y_Locat += 2;
                    maze.array[X_Locat][Y_Locat - 1] = ROAD;
                    maze.array[X_Locat][Y_Locat] = ROAD;
                }
                else
                {
                    break;
                }
                Openpath(maze, X_Locat, Y_Locat);
            }
        }
    }
}

void printMaze(MAZE maze)
{
    for (int x = 0; x < maze.size; x++)
    {
        for (int y = 0; y < maze.size; y++)
        {
            if (maze.array[x][y] == WALL)
            {
                cout << SQUARE;
            }
            else
            {
                cout << SPACE;
            }
        }
        cout << endl;
    }
}
void WallAround(void)
{
    for (int i = 0; i < 30; i++)
    {
        cout << SQUARE;
    }
    cout << endl;
}

void EmptyLine(void)
{
    cout << SQUARE;
    for (int i = 0; i < 28; i++)
    {
        cout << SPACE;
    }
    cout << SQUARE << endl;
}

void Menu(void)
{
    WallAround();
    EmptyLine();
    cout << SQUARE << "  Welcome to the MAZE WORLD!  " << SQUARE << endl;
    EmptyLine();
    WallAround();
    system("pause");
}

void SetSE(MAZE& maze, Locat start, Locat end)
{
    maze.Start = start;
    maze.End = end;
}

void EditMaze(MAZE& maze)
{
    
}