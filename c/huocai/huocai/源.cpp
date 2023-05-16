#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void jh(int* a, int* b);
void paixu(int* p, int a);

void main()
{
	int a,i,j,l;
	int h[10] = {7,2,5,5,4,5,6,3,7,6};
	int sc;
	int fh = 4;
	int b[10][10][10];
	int c[1000];
	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (l = 0; l <= 9; l++)
			{
				b[i][j][l] = h[i] + h[j] + h[l] + fh;
				if (i + j == l)
				{
					c[l + j * 10 + i * 100] = b[i][j][l];
				}
				else
				{
					c[l + j * 10 + i * 100] = 0;
				}
			}
		}
	}
	paixu(c, 1000);
	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (l = 0; l <= 9; l++)
			{
				printf("%d ",c[l + j * 10 + i * 100]);
			}
			printf("\n");
		}
		printf("\n");
	}
	

	return;
}

void paixu(int* p, int a)
{
	int i, j, c = 0;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a - 1; j++)
		{
			if (p[j] < p[j + 1])
			{
				jh(&p[j], &p[j + 1]);
				c = 1;
			}
		}
		if (c == 0) break;
	}
}

void jh(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
	return;
}