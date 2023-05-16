#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

void transpose(int a[3][3]);
int fac(int);

int main()
{
	int a, b, c[3][3]={0}, i;
	scanf("%d", &a);
	printf("%d", fac(a));
	for (i = 0; i < 3; i++)
	{
		for (b = 0; b < 3; b++)
		{
			scanf("%d",&c[i][b]);
		}
	}
	transpose(c);
	for (i = 0; i < 3; i++)
	{
		for (b = 0; b < 3; b++)
		{
			printf("%d ", c[i][b]);
		}
		printf("\n");
	}

	return 0;
}


void transpose(int a[3][3])
{
	int i,n,t;
	for (i = 0; i < 3; i++)
	{
		for (n = 0; n < i; n++)
		{
			t = a[i][n];
			a[i][n] = a[n][i];
			a[n][i] = t;
		}
	}
}



int fac(int a)
{
	if (a == 1 || a == 0)
	{
		return 1;
	}
	else
	{
		a *= fac(a - 1);
	}
	return a;
}