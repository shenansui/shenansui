#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>

int main() 
{
	int n, a, b, c, i, m, j;
	scanf("%d", &n);
	for (j = 0; j < n; j++) 
	{
		i = 1;
		scanf("%d %d %d", &a, &b, &c);
		do 
		{
			m = 7 * i + c;
			if (m % 3 == a && m % 5 == b && m >= 10 && m <= 100)
			{
				printf("%d\n", m);
				break;
			}
			if (m > 100)
			{
				printf("Impossible\n");
			}
			i++;
		} while (m <= 100);
	}
	return 0;

}
