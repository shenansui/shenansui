#define _CRT_SECURE_NO_WARNINGS 1
#define BJ(x,b) (b<=1&&b>=-1&&x+b>=0&&x+b<a)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, i, m, x, y, ia, ib, ic, cc, r;
	//a棋盘大小，i循环变量，m局数，x,y下棋位置变量，ic判断五子时的倍数
	//r下棋人
	int xa,ya, df = 1;
	//x/y判断五子时偏差变量，df得分
	int** q = 0;
	//棋盘数组
	scanf("%d", &a);
	q = (int**)malloc(sizeof(int*) * a);
	for (i = 0; i < a; i++)
	{
		q[i] = (int*)malloc(sizeof(int) * a);
	}
	//申请位置存放棋盘
	scanf("%d", &m);
	for (ia = 0; ia < a; ia++)
	{
		for (ib = 0; ib < a; ib++)
		{
			q[ia][ib] = 0;//初始化棋盘
		}
	}
	for (i = 0; i < m; i++)
	{

		r = i % 2 + 1;//判断下棋人
		scanf("%d", &x);
		scanf("%d", &y);//输入下的位置
		x -= 1;
		y -= 1;
		if (x >= 0 && x < a && y >= 0 && y < a)//判断是否在棋盘内
		{
			if (q[x][y] == 0)//判断下的位置是否有棋
			{
				q[x][y] = r;//下棋
				xa = -1;
				ya = -1;
				while (xa <= 1 && xa >= -1)
				{
					while (ya <= 1 && ya >= -1)
					{
						if (BJ(y, ya))
						{
							ic = 1;
							do//判断是否有五个连续棋子
							{
								if (x + xa * ic < a && x + xa * ic >= 0 && y + ya * ic < a && y + ya * ic >= 0)//判断是否在边界内
								{
									if (q[x + xa * ic][y + ya * ic] == r)
									{
										df++;
									}
									else
									{
										if (ic > 0)
										{
											ic = 0;
										}
										else
										{
											break;
										}
									}
								}
								else
								{
									if (ic > 0)
									{
										ic = 0;
									}
									else
									{
										break;
									}
								}
								if (ic == -5)
								{
									break;
								}
								if (ic > 0)
								{
									ic++;
								}
								else
								{
									ic--;
								}
							} while (1);
						}
						if (df >= 5)
						{
							break;
						}
						df = 1;
						ya++;
						if (xa == 0 && ya == 0)//跳过下的位置
						{
							ya++;
						}
					}
					if (df >= 5)
					{
						break;
					}
					xa++;
					ya = -1;
				}
				if (df >= 5)//胜利判定
				{
					cc = i + 1;
					if (i < m)
					{
						fflush(stdin);
						i++;
						//结束后输入
					}
					if (r == 1)
					{
						printf("Cat wins!\n");//输出胜利人
					}
					else if (r == 2)
					{
						printf("Dog wins!\n");
					}
					printf("%d", cc);
					break;
				}
				df = 1;//重置得分
			}
			else
			{
				printf("Wrong!");
				continue;
			}
		}
		if (df >= 5)
		{
			break;
		}
		for (ia = 0; ia < a; ia++)
		{
			for (ib = 0; ib < a; ib++)
			{
				printf("%d ", q[ia][ib]);
			}
			printf("\n");
		}//输出棋盘
	}
	if (df < 5)
	{
		printf("Draw!");
	}
	for (i = 0; i < a; i++)
	{
		free(q[i]);
	}
	free(q);//释放棋盘
	return 0;
}