# 1

Point类型成员名|含义
--------------|---
int X_Locat|点的横坐标
int Y_Locat|点的纵坐标

Continuity类型成员名|含义
------------------|----
bool ifUp|当前方块（road）是否可向上
bool ifDown|当前方块（road）是否可向下
bool ifLeft|当前方块（road）是否可向左
bool ifRight|当前方块（road）是否可向右

Node类型成员名|含义
------------|-----
string type|当前方块类型：road(leave, fork, branch), wall
string state|当前方块状态：unread, readed, visited
Continuity continuity|当前方块与周围四个方块的可通性

mazeInfo类型成员名|含义
----------------|----
int** array|储存基本信息wall/road
int** read|创建迷宫时判断当前方块的状态
Node** graph|从array生成的更高级的封装更多信息的方块的二维指针
Point startPoint|起点
Point endPoint|终点
int size|迷宫大小
int pointNum|创建迷宫的ROAD节点数

类成员名|属性|作用
-------|---|----
int getSeed(void)|private|获取随机数
bool readJudge(mazeInfo maze, Point pointReadJudge)|private|创建迷宫时判断当前方块的状态
bool around(mazeInfo maze, Point pointAround)|private|创建迷宫时判断当前方块是否可以向周围扩展
void setPointNum(void)|private|根据迷宫信息设置迷宫ROAD节点数
bool ifIsEntrance(int i, int j)|private|判断当前方块是否是起点
bool ifIsDedication(int i, int j)|private|判断当前方块是否是终点
Point unreadedEntrance(int i, int j)|private|当前方块是起点，状态为UNREADTYPE
Point unreadedBranch(int i, int j)|private|当前方块是树枝（双向通），状态为UNREADTYPE
Point unreadedFork(int i, int j)|private|当前方块是树杈（三向通或四向通），状态为UNREADTYPE
Point unreadedLeave(int i, int j)|private|当前方块是树叶（单向通），状态为UNREADTYPE
Point readedEntrance(int i, int j)|private|当前方块是起点，状态为READEDTYPE
Point readedBranch(int i, int j)|private|当前方块是树枝（双向通），状态为READEDTYPE
Point readedFork(int i, int j)|private|当前方块是树杈（三向通或四向通），状态为READEDTYPE
mazeInfo MAZE|public|存储信息的mazeInfo类型变量
Maze(int size)|public|构造函数，随机生成迷宫，传入值为迷宫大小
Maze(string name)|public|构造函数，从文件获取迷宫信息，传入值为文件名
~Maze() {}|public|析构函数
void printMaze(mazeInfo maze)|public|根据MAZE储存的信息打印迷宫，传入值为mazeInfo类型
void setStartPoint(Point pointStartPoint)|public|设置起点，传入值为Point类型
void setEndPoint(Point pointStartPoint)|public|设置终点，传入值为Point类型
void editWallPoint(Point pointSetWall)|public|编辑迷宫，将当前方块设为wall，传入值为Point类型
void editRoadPoint(Point pointSetRoad)|public|编辑迷宫，将当前方块设为road，传入值为Point类型
void openpath(mazeInfo& maze, Point pointOpenPath)|public|递归随机生成迷宫函数，传入值为mazeInfo类型，Point类型
void setInfoFromFile(string name)|public|从文件创建迷宫，传入值为string类型的文件名
void setGraphFromArray(void)|public|从基础的array生成封装有多种信息的Node类型的二维指针
void getPath(void)|public|生成从起点到终点的路径，无参数传入
