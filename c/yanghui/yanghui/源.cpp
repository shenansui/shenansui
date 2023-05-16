#define _CRT_SECURE_NO_WARNINGS 1
#define N 50



#include <stdio.h>


int main()
{
	int i, a;
	long long int p[N][N];
	p[0][0] = 1;
	for (i = 1; i < N; i++)
	{
		for (a = 0; a <= i; a++)
		{
			if (a == 0 || a == i)
			{
				p[i][a] = 1;
			}
			else
			{
				p[i][a] = p[i - 1][a - 1] + p[i - 1][a];
			}
		}
	}
	printf("第十行第五列：%lld\n", p[9][4]);
	printf("第五十行第二十五列：%lld\n", p[49][24]);

	for (i = 0; i < N; i++)
	{
		for (a = 0; a <= i; a++)
		{
			printf("%lld ", p[i][a]);
		}
		printf("\n");
	}
}