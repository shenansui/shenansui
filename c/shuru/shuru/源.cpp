#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>


int main()
{
	int n, i;
	scanf("%d", &n);
	char a[2] = {};
	for (i = 0; i < n; i++)
	{
		scanf("%1s", &a);
		if ((a[0] >= 65 && a[0] <= 90) || (a[0] >= 97 && a[0] <= 122) || a[0] >= 48 && a[0] <= 57)
		{
			if (a[0] >= 48 && a[0] <= 57)
			{
				printf("number");
			}
			else
			{
				printf("letter");
			}
		}
		else
		{
			printf("else");
		}
	}
	return 0;
}
