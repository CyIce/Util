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
	//��¼���Է��õ�λ�ú����ұߵ�1��
	int pos,rightPos;

	if (row != maxNum)
	{
		//�����п��Է��õ�λ����Ϊ1��
		pos = maxNum&~(row | left | right);

		while (pos != 0)
		{
			//��ʾ��һ���ʺ���õ�λ�ã�
			rightPos = pos&(-pos);

			back(row + rightPos, (left + rightPos) << 1, (right + rightPos) >> 1);

			//����һ��������λ����Ϊ0��
			pos -= rightPos;

		}
	}
	else
	{
		//�˸��ʺ��������ɣ������1��
		ans++;
	}
}