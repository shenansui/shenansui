#define _CRT_SECURE_NO_WARNINGS
#define DX 50

#include "zz.h"

int main()
{
	int a = 1, b = 2;
	jh(&a, &b);
	printf("%d %d", a, b);
	return 0;
}

void he(int* a, int* b,int* c)
{
	*c = *a + *b;
}

void ca(int* a, int* b, int* c)
{
	*c = *a - *b;
}

void ji(int* a, int* b, int* c)
{
	*c = *a * *b;
}

void sa(int* a, int* b, int* c)
{
	*c=*a / *b;
}

void zftj(int a[5], char* p, int b)
{
	int i;
	for (i = 0; i < b; i++)
	{
		if (p[i] >= 'A' && p[i] <= 'Z')
		{
			a[0]++;
		}
		else if (p[i] >= 'a' && p[i] <= 'z')
		{
			a[1]++;
		}
		else if (p[i] >= '0' && p[i] <= '9')
		{
			a[2]++;
		}
		else if (p[i] == ' ')
		{
			a[3]++;
		}
		else if (p[i] == '\0') break;
		else
		{
			a[4]++;
		}
	}
}





void shuc(int* p, int a)
{
	int i;
	for (i = 0; i < a; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	return;
}

void jh(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

void transpose(int a[3][3])
{
	int i, n, t;
	for (i = 0; i < 3; i++)
	{
		for (n = 0; n < i; n++)
		{
			t = a[i][n];
			a[i][n] = a[n][i];
			a[n][i] = t;
		}
	}
	return;
}

void paixu(int* p, int a)
{
	int i, j, c=0;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				jh(&p[j], &p[j + 1]);
				c = 1;
			}
		}
		if (c == 0) break;
	}
}

int* strzczf(char* p, int a)
{
	int i, d = 0, x = 0, s = 0, q = 0, k = 0;
	int* sc;
	sc = (int*)malloc(5 * sizeof(int));
	for (i = 0; i < a; i++)
	{
		if (p[i] >= 'a' || p[i] <= 'z') x++;
		else if (p[i] >= 'A' || p[i] <= 'Z') d++;
		else if (p[i] >= '0' || p[i] <= '9') s++;
		else if (p[i] >= ' ') k++;
		else q++;
	}
	return sc;
}