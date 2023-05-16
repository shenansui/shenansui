#define _CRT_SECURE_NO_WARNINGS 1
#define N 10


#include <stdio.h>
#include <stdlib.h>

int pd(int);
int GetData(int*);
void Sort(int* p, int a);

int main()
{
	int* p = 0;
	int b,i;
	p = (int*)malloc(sizeof(int) * N);
	b=GetData(p);
	Sort(p,b);
	for (i = 0; i < b; i++)
	{
		printf("%d ", p[i]);
	}

	return 0;
}



int pd(int a)
{
	int i;
	if (a >= 2)
	{
		for (i = 2; i < a; i++)
		{
			if (a % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return -1;
	}
}

int GetData(int*p)
{
	int i;
	for (i = 0;; i++)
	{
		scanf("%d", &p[i]);
		if (p[i] == 0)
		{
			break;
		}
		if (i % 10 == 9)
		{
			p = (int*)realloc(p, N + i + 1);
		}
	}
	return i;
}

void Sort(int*p,int a)
{
	int i, t, ia;
	for (ia = 0; ia < a; ia++)
	{
		for (i = 0; i < a-ia; i++)
		{
			if (p[i] < p[i + 1])
			{
				t = p[i];
				p[i] = p[i + 1];
				p[i + 1] = t;
			}
		}
	}
	return;
}