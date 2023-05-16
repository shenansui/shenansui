#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>


int pl(int a, int b);
void jh(int* a, int* b);

int main()
{
	int x, y, i, z, m, n;
	long long l;
	char c;
	scanf("%d %d", &m,&n);
	l = pl(m + n - 2, m - 1) * pl(m + n - 2,n - 1);
	int a[1000][5];
	for (i = 0; 1; i++)
	{
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
		{
			break;
		}
		scanf("%c", &c);
		if (c == 78 || c == 69)
		{
			a[i][0] = x;
			a[i][1] = y;
			a[i][4] = x + y;
			if (c == 78)
			{
				a[i][2] = x + 1;
				a[i][3] = y;
			}
			else
			{
				a[i][2] = x;
				a[i][3] = y + 1;
			}
		}
		else
		{
			if (c == 83)
			{
				a[i][0] = x - 1;
				a[i][1] = y;
				a[i][2] = x;
				a[i][3] = y;
				a[i][4] = x + y - 1;
			}
			else
			{
				a[i][0] = x;
				a[i][1] = y - 1;
				a[i][2] = x;
				a[i][3] = y;
				a[i][4] = x + y - 1;
			}
		}
	}

	l %= 998244353;
	printf("%lld", l);
	return 0;
}

int pl(int a, int b)
{
	int i,c;
	for (i = 0; i < b; i++)
	{
		a = a * (a - i + 1) / (i + 1);
	}
	return a;
}

void jh(int* a, int* b)
{
	int* t;
	t = a;
	a = b;
	b = t;
}