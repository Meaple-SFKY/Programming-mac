#include"mazeplus.hpp"

int main(void) {
    srand((unsigned int)time(NULL));
    int size;
    cout << "Please enter the size" << endl;
    cin >> size;
    Maze maze(size);
    maze.printMaze(maze.MAZE);
    return 0;
}