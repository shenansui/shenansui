#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void hanoi(int**,int, char, char, char);
void move(int**,char, char);
int sc(char);
void color(const unsigned short textColor);

int bs=0;

int main()
{
	int a,i,l;
	int** p;
	scanf("%d", &a);
	system("mode con cols=66 lines=22");
	p = (int**)malloc(sizeof(int*) * 3);
	for (i = 0; i < 3; i++)
	{
		p[i] = (int*)malloc(sizeof(int) * (a + 1));
		for (l = 0; l <= a; l++)
		{
			p[i][l] = 0;
		}
	}
	p[0][0] = a;
	for (l = 1; l <= a; l++)
	{
		p[0][l] = a-l+1;
	}
	for (i = 0; i < 3; i++)
	{
		for (l = 1; l <= p[i][0]; l++)
		{
			printf("%d ", p[i][l]);
		}
		printf("\n");
	}
	hanoi(p,a, 'A', 'B', 'C');
	printf("\t\t\t总步数：%d\n", bs);
	for (i = 0; i < 3; i++)
	{
		free(p[i]);
	}
	free(p);
	system("pause");
	return 0;
}

void hanoi(int**p,int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(p,a, c);
	}
	else
	{
		hanoi(p,n - 1, a, c, b);
		move(p,a, c);
		hanoi(p,n - 1, b, a, c);
	}
}

void move(int**p,char a, char b)
{
	int t,i;
	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\t%c-->%c\n", a, b);
	p[sc(b)][0]++;
	p[sc(b)][p[sc(b)][0]] = p[sc(a)][p[sc(a)][0]];
	p[sc(a)][p[sc(a)][0]] = 0;
	p[sc(a)][0]--;
	for (i = 0; i < 3; i++)
	{
		printf("\t\t\t第%d排：",i+1);
		for (t = 1; t <= p[i][0]; t++)
		{
			if (i == sc(b) && t == p[i][0]) color(2);
			printf("%d ", p[i][t]);
			color(7);
		}
		printf("\n\n");
	}
	bs++;
	Sleep(100);
}

int sc(char a)
{
	if (a == 'A')
	{
		return 0;
	}
	else if (a == 'B')
	{
		return 1;
	}
	else if (a == 'C')
	{
		return 2;
	}
}

void color(const unsigned short textColor)      //自定义函根据参数改变颜色 
{
	if (textColor >= 0 && textColor <= 15)     //参数在0-15的范围颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //用一个参数，改变字体颜色
	else   //默认的字体颜色是白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}