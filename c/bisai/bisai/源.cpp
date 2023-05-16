#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


struct bs
{
	int sj;
	int da;
	int db;
};

void jh(int, int);


int main()
{
	
	int n, m, i, l;
	short int* s = 0;
	bs* p = 0;
	scanf("%d %d", n, m);
	p = (bs*)malloc(sizeof(bs) * m);
	s = (short int*)malloc(sizeof(short int) * n);
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			l = getchar();
		}
		s[i] = (int)getchar();
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", p[i].sj, p[i].da, p[i].db);
	}
	for (i = 0; i < m; i++)
	{
		for (l = 0; l < m - i; l++)
		{
			if (p[l].sj > p[l + 1].sj)
			{
				jh(&p[l], &p[l + 1]);
			}
		}
	}









		return 0;
}




void jh(bs* a, bs* b)
{
	bs c = *a;
	*a = *b;
	*b = c;
}
