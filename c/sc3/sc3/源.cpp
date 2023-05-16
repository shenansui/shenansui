#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
int main()
{
	int a, b=0, c;
	int x, y, n, sum=0;
	scanf("%d%d", &a, &n);
	for (x = 0; x < n; x++)
	{
		for (b=0,y = 0; y <= x; y++)
		{
			b += a * pow(10.0, y);
		}
		sum += b;
	}
	printf("%d\n", sum);
	return 0;
}

