#include<stdio.h>
#include<math.h>
void Dfs(int layer, int queen[]);
int n, ans = 0;
int main()
{
	int arr[16] = { 0 };
	scanf_s("%d", &n);
	Dfs(1, arr)	
}

void Dfs(int layer, int queen[])
{
	if (layer > n)
	{
		ans++;
	}
	else
	{
		int i, j, bo;
		for (i = 1; i <= n; i++)
		{
			bo = 1;
			for (j = 1; j < layer; j++)
			{
				if ( (i - layer) == (queen[j] - j) ||
					 (i + layer) == (j + queen[j]) ||
						queen[j] == i)
				{
					bo = 0;
					break;
				}
			}
			if (bo)
			{
				queen[layer] = i;
				Dfs(layer + 1, queen);
				queen[layer] = 0;
			}
		}
	}
}