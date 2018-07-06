#include<iostream>
using namespace std;

//���ڴ������������Ľ���ĸ�����
int ans = 0;

//���ڴ�����Ҫ�ظ������ꣻ
int arr[8][100][3];

//���ڱ�ʾ����,true��ʾ���Է��ã�
bool chessBoard[9][9];

//��ʼ�����̣�
void initialize();

//ʹ�û����㷨��̽ÿһ�������ԣ�
void back(int layer);

//�ų����Բ����ܵĵ㣻
void exclusion(int x, int y);

//�����һ�������ĺۼ���
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

	//����������ans+1��
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
			//�ų�������������λ�ã�
			exclusion(i, layer);

			//test();
			//cout << endl<<endl;

			//����������
			back(layer + 1);

			//�����һ�������ĺۼ���
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

		//�ų�ͬһ�У�
		if (chessBoard[x][i] == true)
		{
			chessBoard[x][i] = false;

			arr[y][k][1] = x;
			arr[y][k][2] = i;

			k++;

		}

		//�ų����¶Խ��ߣ�
		if (a >= 1 && chessBoard[a][i] == true)
		{
			chessBoard[a][i] = false;

			arr[y][k][1] = a;
			arr[y][k][2] = i;

			k++;

		}
		//�ų����¶Խ��ߣ�
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