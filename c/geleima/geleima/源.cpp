#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>




int main()
{
	char* a = 0;
	int i, n, l,o;
	long long k, b;
	scanf("%d", &n);
	a = (char*)malloc(sizeof(char) * (n + 1));
	scanf("%lld", &k);
	for (i = 0; i < n + 1; i++)
	{
		if (i < n)
		{
			a[i] = 48;
		}
		else
		{
			a[n] = 0;
		}
	}
	for (i = n-1; i >= 0; i--)
	{
		if (k != 1)
		{
			b = 2;
				
			for (o = 0; o < i; o++)
			{
				b *= 2;
			}

			l =(int) k / b;
		}
		else
		{
			l = 0;
		}
		if (l >= 1)
		{
			a[n-i-1] = 49;
			b = 2;
			for (o = 0; o < i; o++)
			{
				b *= 2;
			}
			k -= b;
		}
	}
	printf("%s", a);


	return 0;
}


