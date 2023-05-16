#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n, m, q, b=0,c=0;
	scanf("%d %d", &m, &n);
	int i, x, y,o, k = 1;
	char f;
	int lxx = 1, lxy = 1;
	long long lxz=0;
	int** a = (int**)malloc(sizeof(int*) * ( m - 1));
	int** lx = (int**)malloc(sizeof(int*) * (m + n - 2));
	for (i = 0; i < m + n - 2; i++)
	{
		lx[i] = (int*)malloc(sizeof(int) * 2);
	}
	for (i = 0; i < m-1; i++)
	{
		if ((i+1) % 2 == 1)
		{
			q = n;
		}
		else
		{
			q = n + 1;
		}
		a[i] = (int*)malloc(sizeof(int) * (q - 1));
	}
	for (i = 0; i < m; i++)
	{
		for (o = 0; o < n; o++)
		{
			a[i][o] = 0;
		}
	}
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
		{
			break;
		}
		else
		{
			scanf("%c", &f);
			if (f == 78)
			{
				c = 0;
				b = 1;
			}
			if (f == 83)
			{
				c = 0;
				b = -1;
			}
			if (f == 87)
			{
				b = 0;
				c = 1;
			}
			if (f == 69)
			{
				b = 0;
				c = -1;
			}
			a[2 * x - 1 + b][2 * y - 1 + c] = 2;
			k++;
		}
	}
	for(i=0;1;i++)
	{
		if (i == 0)
		{
			if (a[0][0] == 0)
			{
				lx[0][0] = 0;
				lx[0][1] = 0;
				a[0][0] = 1;
			}
			else if (a[1][0] == 0)
			{
				lx[0][0] = 1;
				lx[0][1] = 0;
				a[1][0] = 1;
			}
			
		}
		else
		{
			if (a[lx[lxx - 1][0]][lx[lxx - 1][1] + 1] == 0&&lx[lxx-1][0]<=m-1)
			{
				lx[lxx][1]++;
			}

		}
		if (lx[lxx][0] == m && lx[lxx][1] == n)
		{
			a[lx[lxx][0]][lx[lxx][1]] = 0;
			lxx--;
			lxz++;
		}
		lxz %= 998244353;
		printf("%d", lxz);
	}
	return 0;
}