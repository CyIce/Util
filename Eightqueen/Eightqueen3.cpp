#include<iostream>
using namespace std;

void back(int row, int left, int right);

int maxNum, ans;

int main()
{
	int n;
	cin >> n;

	maxNum = (1 << n) - 1;
	ans = 0;

	back(0, 0, 0);

	cout << ans;

	system("pause");
	return 0;
}
void back(int row, int left, int right)
{
	//记录可以放置的位置和最右边的1；
	int pos,rightPos;

	if (row != maxNum)
	{
		//将所有可以放置的位置置为1；
		pos = maxNum&~(row | left | right);

		while (pos != 0)
		{
			//表示下一个皇后放置的位置；
			rightPos = pos&(-pos);

			back(row + rightPos, (left + rightPos) << 1, (right + rightPos) >> 1);

			//将上一次搜索的位置置为0；
			pos -= rightPos;

		}
	}
	else
	{
		//八个皇后均放置完成，结果加1；
		ans++;
	}
}