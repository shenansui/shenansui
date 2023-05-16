#define _CRT_SECURE_NO_WARNINGS 1
//测试文件



#include <stdio.h>
#include <math.h>
#include <string.h>


//初始化
int i = 3;
int ii, iii;
int ix[9] = { 0 };
void main()
{
	int xh = 1;
	int a = 0;
	if (!scanf_s("%d", &a))
	{
		printf("输入不符合格式请重新输入");
	}
	else
	{
		while (xh <= a)
		{
			if (i < 10 && i >= 3)
			{
				ii = 1;
			}
			else
			{

				ii = 1;
				iii = i;
				while (iii >= 10)
				{
					iii = iii / 10;
					ii++;
				}
			}//判断位数
			int iq = i;
			double iz = (double)(ii - 1);
			int sl = 0;
			//分开每位的数字
			while (iz >= 0)
			{
				int ic = iq % 10;
				iq = iq / 10;
				ix[sl] = ic;
				iz--;
				sl++;
			}
			//计算平方和
			int il = 0;//平方和
			int xha = 0;//数组位置
			while (xha <= 9)
			{
				if (xha <= ii - 1)
				{
					il = il + pow(ix[xha], ii);
				}
				else
				{
					break;
				}
				xha++;
			}
			if (il == i)
			{
				printf("%d\n", i);
			}
			i++;
			xh++;
		}
	}
	
}