#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

int main()
{
	int nn, i, a, b = 0, c=0;
	int xi = 0, hui = 0, ls = 0, dp = 0, zdls = 0;
	scanf("%d", &nn);
	for (i = 0; i < nn; i++)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			xi += 1;
		}
		else if (a == 2)
		{
			hui += 1;
		}
		else
		{
			printf("´íÎó");
			break;
		}
		if (xi == hui||i==0)
		{
			dp += 1;
		}
		if (a == b||i==0)
		{
			ls += 1;
			if (ls > zdls)
			{
				if (a == 1 && xi > hui&& (a == c || c == 0))
				{
					zdls = ls;
				}
				if (a == 2 && hui > xi&& (a == c || c == 0))
				{
					zdls = ls;
				}
			}
		}
		if(a!=b)
		{
			if ( xi > hui)
			{
				c = 2;
			}
			if (hui > xi)
			{
				c = 1;
			}
		}
		if(a!=b)
		{
			ls = 1;
		}
		b = a;
	}
	printf("%d %d\n", xi, hui);
	printf("%d\n", dp);
	printf("%d\n", zdls);
}