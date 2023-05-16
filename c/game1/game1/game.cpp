#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>




int game(int a)
{
	//地图指针
	char* jf = 0;//积分指针
	char* mb= dt(a);
	
	free(mb);
	return 0;
}//游戏主体



void ks()
{
	int a = 0;
	printf("                                            \n");
	printf("                                            \n");
	printf("               1.  开始                     \n");
	printf("               2.  退出                     \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("请输入>>");
	scanf("%d", &a);

	switch(a)
	{
	case 1:
		printf("请输入地图大小(一个整数)>>");
		scanf("%d", &a);
		if (game(a))
		{
			printf("程序错误");
		}
		break;
	case 2:
		break;
	default:
		printf("错误");
		break;
	}
}//开始菜单


char *dt(int a)
{
	char* mb = (char*)malloc(sizeof(char) * a * a);
	int b = 0;
	while (b<=a)
	{
		if (b == a)
		{
			*mb = "n";
			mb++;
		}
		else(b < a);
		{

		}
		b++;
	}
	return mb;
}//地图生成

void yd()
{

}//移动控制


