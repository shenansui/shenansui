#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>



struct biao
{
	char name[20];
	int age;
	char job[20];
	int classes;
	char xib[20];
};

int main()
{
	biao p[10];
	int i, a,n=0;
	for (i = 0;; i++)
	{
		scanf("%d", &a);
		if (a == 0)
		{
			break;
		}
		printf("开始输入\n");
		scanf("%s %d %s",p[i].name, &p[i].age, &p[i].job);
		if (strcmp(p[i].job, "student") == 0)
		{
			scanf("%d", &p[i].classes);
		}
		else
		{
			scanf("%s", p[i].xib);
		}
		n++;
		printf("下一个\n");
	}
	for (i = 0; i < n; i++)
	{
		printf("%s %d %s ", p[i].name, p[i].age, p[i].job);
		if (strcmp(p[i].job,"student")==0)
		{
			printf("%d\n", p[i].classes);
		}
		else
		{
			printf("%s\n", p[i].xib);
		}
	}
	return 0;
}