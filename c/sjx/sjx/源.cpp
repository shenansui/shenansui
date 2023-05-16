#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>

int main() 
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
	{
		int a, b, c;
		scanf("%d,%d,%d", &a, &b, &c);
		if (a + b <= c || a + c <= b || b + c <= a) 
		{
			printf("illegal\n");
		}
		else 
		{
			if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) 
			{
				printf("right\n");
			}
			else 
			{
				if (a * a + b * b > c * c && a * a + c * c > b * b && b * b + c * c > a * a)
					printf("actue\n");
				else
					printf("obtuse\n");
			}
		}
	}
	return 0;
}
