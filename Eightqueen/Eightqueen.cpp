#include<iostream>
using namespace std;

//用于储存满足条件的结果的个数；
int ans = 0;

//用于储存需要回复的坐标；
int arr[8][100][3];

//用于表示棋盘,true表示可以放置；
bool chessBoard[9][9];

//初始化棋盘；
void initialize();

//使用回溯算法试探每一个可能性；
void back(int layer);

//排除所以不可能的点；
void exclusion(int x, int y);

//清除上一次搜索的痕迹；
void clean(int n);

void test()
{
	int i, j;
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			cout << chessBoard[i][j]<<" ";
		}
		cout << endl;
	}
}

int main()
{

	initialize();

	back(1);

	cout << ans<<endl;



	
	system("pause");
	return 0;
}

void initialize()
{
	int i, j;
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			chessBoard[i][j] = true;
		}
	}
}

void back(int layer)
{

	//满足条件，ans+1；
	if (layer > 8)
	{
		ans++;
		return ;
	}

	int i;
	for (i = 1; i <= 8; i++)
	{
		if (chessBoard[i][layer] == true)
		{
			//排除不符合条件的位置；
			exclusion(i, layer);

			//test();
			//cout << endl<<endl;

			//向下搜索；
			back(layer + 1);

			//清除上一次搜索的痕迹；
			clean(layer);
		}
	}

	

}

void exclusion(int x, int y)
{
	int i, k, a, b,t;

	k = 1;
	t = 1;

	for (i = y+1; i <= 8; i++)
	{
		a = x - t;
		b = x + t;

		//排除同一列；
		if (chessBoard[x][i] == true)
		{
			chessBoard[x][i] = false;

			arr[y][k][1] = x;
			arr[y][k][2] = i;

			k++;

		}

		//排除左下对角线；
		if (a >= 1 && chessBoard[a][i] == true)
		{
			chessBoard[a][i] = false;

			arr[y][k][1] = a;
			arr[y][k][2] = i;

			k++;

		}
		//排除右下对角线；
		if (b <= 8 && chessBoard[b][i] == true)
		{
			chessBoard[b][i] = false;

			arr[y][k][1] = b;
			arr[y][k][2] = i;

			k++;
		}
		t++;
	}


	arr[y][0][0] = k - 1;
}
void clean(int n)
{
	int i,a,b;

	for (i = 1; i <= arr[n][0][0]; i++)
	{
		a = arr[n][i][1];
		b = arr[n][i][2];
		chessBoard[a][b] = true;
	}
}