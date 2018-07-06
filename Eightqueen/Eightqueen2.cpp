#include<iostream>
using namespace std;

//��¼���������������Ŀ��
unsigned short ans = 0;

//��ʾ���̣�
unsigned short chessBoard[9] = { 0 };

//��¼����ʱ�Ƿ�ı������,0������ߣ�1�����ұߣ�2�������·���
bool record[9][9][3] = { false };

//ʹ�û����㷨��̽ÿһ�������ԣ�
void back(int layer);

//�ų����Բ����ܵĵ㣻
void exclusion(unsigned short x, int layer);

//�����һ�������ĺۼ���
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
		//����ȡ��һ���㣻
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