#include<iostream>
using namespace std;

//记录满足条件的情况数目；
unsigned short ans = 0;

//表示棋盘；
unsigned short chessBoard[9] = { 0 };

//记录搜索时是否改变的数据,0代表左边，1代表右边，2代表正下方；
bool record[9][9][3] = { false };

//使用回溯算法试探每一个可能性；
void back(int layer);

//排除所以不可能的点；
void exclusion(unsigned short x, int layer);

//清除上一次搜索的痕迹；
void clean(unsigned short x, int layer);


int main()
{
	back(1);

	cout << ans;

	system("pause");
	return 0;
}

void back(int layer)
{
	unsigned short i, t, p, temp;

	if (layer == 9)
	{
		/*for (int j = 1; j <= 8; j++)
		{
		cout << chessBoard[j] << " ";
		}
		cout << endl;*/
		ans++;
		return;
	}

	if (chessBoard[layer] == 256)
	{
		return;
	}

	p = chessBoard[layer];

	for (i = 1; i <= 8; i++)
	{
		//从右取第一个零；
		t = p | (p + 1);
		temp = t;
		t -= p;
		p = temp;

		if (t > 128)
		{
			break;
		}

		exclusion(t, layer);

		back(layer + 1);

		clean(t, layer);
	}



}

void exclusion(unsigned short x, int layer)
{
	unsigned short t, i, left, right;

	t = 2;

	for (i = layer + 1; i <= 8; i++)
	{
		left = x * t;
		right = x / t;

		t <<= 1;

		if ((chessBoard[i] & x) == 0)
		{
			chessBoard[i] += x;
			record[layer][i][2] = true;
		}

		if ((left <= 128) && ((chessBoard[i] & left) == 0))
		{
			chessBoard[i] += left;
			record[layer][i][0] = true;
		}

		if ((right >= 1) && ((chessBoard[i] & right) == 0))
		{
			chessBoard[i] += right;
			record[layer][i][1] = true;
		}
	}
}

void clean(unsigned short x, int layer)
{
	unsigned short t, i, left, right;

	t = 2;

	for (i = layer + 1; i <= 8; i++)
	{
		left = x * t;
		right = x / t;

		t <<= 1;

		if (record[layer][i][2])
		{
			chessBoard[i] -= x;
			record[layer][i][2] = false;
		}

		if (record[layer][i][0])
		{
			chessBoard[i] -= left;
			record[layer][i][0] = false;
		}

		if (record[layer][i][1])
		{
			chessBoard[i] -= right;
			record[layer][i][1] = false;
		}
	}
}