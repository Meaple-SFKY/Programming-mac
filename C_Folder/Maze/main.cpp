#include "maze.hpp"

int main(void) {
    srand((unsigned int)time(NULL));
    int size;
    Point entrance, destination;
    cout << "Please enter the size: ";
    cin >> size;
    cout << "Please enter the X-axis and the Y-axis of your entrance: ";
    cin >> entrance.X_Locat >> entrance.Y_Locat;
    cout << "Please enter the X-axis and the Y-axis of your destination: ";
    cin >> destination.X_Locat >> destination.Y_Locat;
    Maze maze(size);
    maze.setStartPoint(entrance);
    maze.setEndPoint(destination);
    maze.printMaze(maze.MAZE);
    return 0;
}