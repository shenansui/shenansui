#define _CRT_SECURE_NO_WARNINGS 1
#define BJ(x,b) (b<=1&&b>=-1&&x+b>=0&&x+b<a)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, i, m, x, y, ia, ib, ic, cc, r;
	//a���̴�С��iѭ��������m������x,y����λ�ñ�����ic�ж�����ʱ�ı���
	//r������
	int xa,ya, df = 1;
	//x/y�ж�����ʱƫ�������df�÷�
	int** q = 0;
	//��������
	scanf("%d", &a);
	q = (int**)malloc(sizeof(int*) * a);
	for (i = 0; i < a; i++)
	{
		q[i] = (int*)malloc(sizeof(int) * a);
	}
	//����λ�ô������
	scanf("%d", &m);
	for (ia = 0; ia < a; ia++)
	{
		for (ib = 0; ib < a; ib++)
		{
			q[ia][ib] = 0;//��ʼ������
		}
	}
	for (i = 0; i < m; i++)
	{

		r = i % 2 + 1;//�ж�������
		scanf("%d", &x);
		scanf("%d", &y);//�����µ�λ��
		x -= 1;
		y -= 1;
		if (x >= 0 && x < a && y >= 0 && y < a)//�ж��Ƿ���������
		{
			if (q[x][y] == 0)//�ж��µ�λ���Ƿ�����
			{
				q[x][y] = r;//����
				xa = -1;
				ya = -1;
				while (xa <= 1 && xa >= -1)
				{
					while (ya <= 1 && ya >= -1)
					{
						if (BJ(y, ya))
						{
							ic = 1;
							do//�ж��Ƿ��������������
							{
								if (x + xa * ic < a && x + xa * ic >= 0 && y + ya * ic < a && y + ya * ic >= 0)//�ж��Ƿ��ڱ߽���
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
						if (xa == 0 && ya == 0)//�����µ�λ��
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
				if (df >= 5)//ʤ���ж�
				{
					cc = i + 1;
					if (i < m)
					{
						fflush(stdin);
						i++;
						//����������
					}
					if (r == 1)
					{
						printf("Cat wins!\n");//���ʤ����
					}
					else if (r == 2)
					{
						printf("Dog wins!\n");
					}
					printf("%d", cc);
					break;
				}
				df = 1;//���õ÷�
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
		}//�������
	}
	if (df < 5)
	{
		printf("Draw!");
	}
	for (i = 0; i < a; i++)
	{
		free(q[i]);
	}
	free(q);//�ͷ�����
	return 0;
}