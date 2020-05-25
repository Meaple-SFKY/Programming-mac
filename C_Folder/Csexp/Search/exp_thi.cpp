#include<iostream>

using namespace std;
 
int chessboard[8][8];
 
bool FindPath(int startI,int startJ) {
	//走法的序号
	int queueNumber;
	//开始位置标注为1
	chessboard[startI][startJ]=1;
	//规则走法
	const int posI[8]={1,1,2,2,-1,-1,-2,-2};
	const int posJ[8]={2,-2,1,-1,2,-2,1,-1};
	//当前位置可走方位的计数器
	int posCount=0;
	//考察可走方位最少的那个方位
	int minPosCount;
	//暂时记录各个方位的可走方位数
	int posCountTemp;
	//当前位置的可走方位的坐标
	int nexI[8]={0},nexJ[8]={0};
	//当前位置
	int nowI=startI,nowJ=startJ;
	//待考察的可走方位位置
	int nextI,nextJ;
	//各个方位的可走方位位置
	int nextnextI,nextnextJ;
	
	//寻找路径
	for (queueNumber=2;queueNumber<=64;++queueNumber) {
		posCount=0;//考察新的位置，需归零
		for(int k=0;k<8;++k) {
			nextI=nowI+posI[k];
			nextJ=nowJ+posJ[k];
			//如果超出棋盘范围
			if (nextI>=8||nextI<0||nextJ>=8||nextJ<0) {
				continue;
			}
			//如果还没走过该位置
			if (chessboard[nextI][nextJ]==0) {
				//记录下当前位置的八个方位的可走的方位坐标
				nexI[posCount] = nextI;
				nexJ[posCount] = nextJ;
				++posCount;
			}
		}
		//如果还没走到第64个位置，但是已经没有地方可走，则返回“没有可遍历路径”
		if (posCount==0&&queueNumber<63) {
			return false;
		}
		minPosCount=8;//用一个最大值初始化，才能取到所需的最小值
		//对各个方位进行考察
		for (int posNum=0;posNum<posCount;++posNum) {
			posCountTemp=0;//考察新的位置，需归零
			//对各个方位上各自的方位进行考察
			for (int k=0;k<8;++k) {
				nextnextI=nexI[posNum]+posI[k];
				nextnextJ=nexJ[posNum]+posJ[k];
                //如果超出棋盘范围，注意是nextnextI。复制粘贴保留成nextI是错误的
				if (nextnextI>=8||nextnextI<0||nextnextJ>=8||nextnextJ<0) {
					continue;
				}
				//如果还没走过该位置
				if (chessboard[nextnextI][nextnextJ]==0) {
					++posCountTemp;
				}
 
			}
			if (minPosCount>posCountTemp) {
				minPosCount=posCountTemp;
				nowI=nexI[posNum];//选定好位置之后需更新的是nowI和nowJ
				nowJ=nexJ[posNum];//之前写成了nextI和nextJ，也是复制粘贴保留的错误
			}
 
		}
		chessboard[nowI][nowJ]=queueNumber;//nowI和nowJ
	}
	return true;
}
 
 
int main(void) {
	int startI,startJ;
	for (int i=0;i<8;++i) {
		for (int j=0;j<8;++j)
		{
			chessboard[i][j]=0;
		}
	}
	cout << "请输入开始节点的坐标，并用空格分隔（如2 4）：";
	cin >> startI >> startJ;
	if(FindPath(startI,startJ)) {
		cout << "路径如下: " << endl;
		for (int i=0;i<8;++i) {
			for (int j=0;j<8;++j) {
				cout << chessboard[i][j] << '\t';
			}
			cout << endl;
		}
	}
	else {
		cout << "未找到遍历棋盘所有节点的路径！" << endl;
    }
    
    return 0;
}