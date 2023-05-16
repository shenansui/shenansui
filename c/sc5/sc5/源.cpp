#define _CRT_SECURE_NO_WARNINGS 1

#define N 15

#include <stdio.h>

int main()
{
	int i, j,b=0, a[N],t;
	for (i = 0; i < N; i++)
	{
		scanf("%d",& a[i]);
		if (a[i] <= 1)
		{
			printf("ÊäÈë´íÎó");
			i--;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (b=0,j = 0; j < N-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				b = 1;
			}
		}
		if (b == 0)
		{
			break;
		}
	}
	for (b=0,i = 0; i < N; i++)
	{
		for (j = a[i]-1; j > 1; j--)
		{
			if (a[i] == 2) break;
			if (a[i] % j == 0) { b = 1; break; }
		}
		if (b == 0) printf("%d ",a[i]);
		b = 0;
	}
	return 0;
}


