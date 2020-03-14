#include<iostream>
#include"maze.hpp"

using namespace std;

int main(void)
{
    SetConsoleTitle("MAZE");
    Menu();
    system("cls");
    MAZE maze;
    srand((unsigned int)time(NULL));
    initialMaze(maze);
    int x = 1, y = 1;
    Openpath(maze, x, y);
    printMaze(maze);
    system("pause");
    return 0;
}
