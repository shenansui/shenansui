#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>


int main()
{
	int n, i;
	scanf("%d", &n);
	int a;
	for (i = 0; i < n; i++) 
	{
		scanf("%d", &a);
		if (a > 0 && a % 4 == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
