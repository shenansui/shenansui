#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>


void jh(int* a, int* b);


int main()
{
	int n;
	scanf("%d", &n);
	int* g, * f;
	int i, j;
	int sum = 0;
	g = (int*)malloc(sizeof(int) * n);
	f = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &g[i], &f[i]);
	}
	int* m;
	m = (int*)malloc(sizeof(int) * n);
	m[n - 1] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			if (g[j] > g[j + 1])
			{
				jh(&g[j], &g[j + 1]);
				jh(&f[j], &f[j + 1]);
			}
		}
	}


	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < n; j++) 
		{
			if (j != i)
			{
				sum += g[j];
			}
			if (j == n - 1)
				m[i] = sum - f[i];
		}
	}
	int t = m[0];
	for (i = 0; i < n; i++)
	{
		if (m[i + 1] + g[i] < m[i])
		{
			t = g[i];
			break;
		}
		
	}
	printf("%d", t);
	free(g);
	free(f);
	free(m);

	return 0;

}



void jh(int*a, int*b)
{
	int t = *a;
	*a = *b;
	*b = t;
	return;
}