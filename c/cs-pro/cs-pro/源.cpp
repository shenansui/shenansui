#define _CRT_SECURE_NO_WARNINGS 1
#define WIDETH 120
#define LONGTH 30
#define HAVE_STRUCT_TIMESPEC
#pragma comment(lib, "pthreadVC2.lib")

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <pthread.h>



void* thread(void* arg);
void ks();
void js();

int main()
{
	pthread_t th;
	/*char** p;*/
	int i = 0, ia, ib=0;
	int x, y;
	int wz[100][2];
	char fx='w';
	ks();
	system("pause");
	system("cls");
	pthread_create(&th,NULL,thread,&fx);
	char p[LONGTH][WIDETH+1] = {};
	/*p = (char**)malloc(sizeof(char*) * LONGTH);
	for (i = 0; i < LONGTH; i++)
	{
		p[i] = (char*)malloc(sizeof(char) * WIDETH);
	}*/
	system("mode con cols=140 lines=50");
	for (i = 0; i < LONGTH; i++)
	{
		for (ia = 0; ia <= WIDETH; ia++)
		{
			if(ia==120)
				p[i][ia] = '\n';
			else
				p[i][ia] = '#';
		}
	}
	wz[0][0] = 2;
	wz[0][1] = 1;
	wz[1][1] = WIDETH / 2;
	wz[1][0] = LONGTH / 2;
	wz[2][1] = WIDETH / 2;
	wz[2][0] = LONGTH / 2;
	p[15][36] = '@';
	for (p[wz[1][0]][wz[1][1]] = ' ';fx!='p';)
	{
		for (i = wz[0][0]; i > 0; i--)
		{
			wz[i + 1][0] = wz[i][0];
			wz[i + 1][1] = wz[i][1];
		}
		switch (fx)
		{
		case 'w':
			wz[1][1] = wz[2][1];
			wz[1][0] = wz[2][0]-1;
			break;
		case 's':
			wz[1][1] = wz[2][1];
			wz[1][0] = wz[2][0] + 1;
			break;
		case 'a':
			wz[1][1] = wz[2][1] - 1;
			wz[1][0] = wz[2][0];
			break;
		case 'd':
			wz[1][1] = wz[2][1] + 1;
			wz[1][0] = wz[2][0];
			break;
		default:ib = 1; break;
		}
		if (ib==1||wz[1][0]>LONGTH||wz[1][0]<0||wz[1][1]>=WIDETH||wz[1][1]<0||p[wz[1][0]][wz[1][1]]==' ')
		{
			printf("已死亡");
			fx = 'p';
			break;
		}
		if (p[wz[1][0]][wz[1][1]] == '@' && wz[0][0]<99)
		{
			wz[0][0]++;
			do
			{
				srand(clock());
				x = rand() % 30;
				srand(clock() + 99);
				y = rand() % 120;
			} while (p[x][y] != '#');
			p[x][y] = '@';
		}
		p[wz[wz[0][0]][0]][wz[wz[0][0]][1]] = '#';
		p[wz[1][0]][wz[1][1]] = ' ';
		for (i = 0; i < 30; i++)
		{
			for (ia = 0; ia <= 120; ia++)
			{
				if (p[i][ia] == '@')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					printf("%c", p[i][ia]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else
					printf("%c", p[i][ia]);
			}
		}
		Sleep(10);
		system("cls");
	}
	js();
	return 0;
}


void* thread(void* arg)
{
	for (;;)
	{
		do
		{
			if (*(char*)arg == 'p')
			{
				pthread_exit(NULL);
			}
			*(char*)arg = _getch();
		} while (*(char*)arg=='w'|| *(char*)arg == 's'|| *(char*)arg == 'a'|| *(char*)arg == 'd'|| *(char*)arg == 'p');
		
		
	}

}

void ks()
{
	printf("\n\n\n\n                  按任意键开始游戏\n                  游戏时按‘p’退出");
}


void js()
{
	printf("\n\n\n\n                  感谢游玩");
}

