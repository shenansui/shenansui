#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>




int game(int a)
{
	//��ͼָ��
	char* jf = 0;//����ָ��
	char* mb= dt(a);
	
	free(mb);
	return 0;
}//��Ϸ����



void ks()
{
	int a = 0;
	printf("                                            \n");
	printf("                                            \n");
	printf("               1.  ��ʼ                     \n");
	printf("               2.  �˳�                     \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("������>>");
	scanf("%d", &a);

	switch(a)
	{
	case 1:
		printf("�������ͼ��С(һ������)>>");
		scanf("%d", &a);
		if (game(a))
		{
			printf("�������");
		}
		break;
	case 2:
		break;
	default:
		printf("����");
		break;
	}
}//��ʼ�˵�


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
}//��ͼ����

void yd()
{

}//�ƶ�����


