//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdlib.h>
//#include <stdio.h>
//
//
//int main()
//{
//	int a = 1;
//	int* q = 0;
//	while ((q = (int*)malloc(100 * 1024 * 1024)))
//	{
//		a++;
//	}
//	printf("�ڴ��С��%d", a);
//	free(q);
//}
//#include<stdio.h>
//int main()
//{
//	char str[10];
//	int m = 0, p = 0, q = 0, e = 0, n = 0,i;
//	gets_s(str);
//	for (i=0; str[i] != '\0'; i++)
//	{
//		if ((str[i] >= 'A') && (str[i] <= 'Z'))
//			m++;
//		else if ((str[i] >= 'a') && (str[i] <= 'z'))
//			n++;
//		else if ((str[i] >= '0') && (str[i] <= '9'))
//			p++;
//		else if (str[i] == ' ')
//			q++;
//		else
//			e += 1;
//	}
//	printf("��д��ĸ��%d��\n", m);
//	printf("Сд��ĸ��%d��\n", n);
//	printf("������%d��\n", p);
//	printf("�ո���%d��\n", q);
//	printf("�����ַ���%d��\n", e);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//void ou(float a, float b, float* psum, float* pdiff, float* pride, float* pexce);
//int main()
//{
//    float a, b, sum, diff, ride, exce, * psum, * pdiff, * pride, * pexce;
//    psum = &sum;
//    pdiff = &diff;
//    pride = &ride;
//    pexce = &exce;
//    scanf("%f%f", &a, &b);
//    ou(a, b, psum, pdiff, pride, pexce);
//    printf("��Ϊ: %.0f\n��Ϊ:%.0f\n�˻�Ϊ:%.0f\n��Ϊ:%.0f", sum, diff, ride, exce);
//    return 0;
//}
//void ou(float a, float b, float* psum, float* pdiff, float* pride, float* pexce)
//{
//    *psum = a + b;
//    *pdiff = a - b;
//    *pride = a * b;
//    *pexce = a / b;
//}
//#include <stdio.h>
//
//#define IN 1
//#define OUT 0
//int main()
//{
//	char string[80], str[100][100], c;
//	int i, num = 0, word = OUT, m = 0, j = 0;
//	gets_s(string);
//	for (i = 0; (c = string[i]) != '\0'; i++)
//	{
//		if (c == ' ') word = OUT;
//		if (word == OUT) { num++; word = IN; }
//		str[m][j] = string[i];
//		j++;
//		if (c == ' '&&i!=0)
//		{
//			str[m][j] = '\0';
//			j=0;
//			m++;
//		}
//	}
//	str[m][j] = '\0';
//	printf("There are %d words in the line .", num);
//	printf("���ַ����к������µ���\n");
//	for (i = 0; i < num; i++)
//	{
//		puts(str[i]);
//	}
//	return 0;
//}
#include<stdio.h>
#include<string.h>
struct Student_Inf
{
	char no[10];
	char name[10];
	float grade[3];
	float math, eng, chi;
	float sum = math + eng + chi;
}stu1, stu2;

int main()
{
	int flag1, flag2, flag3;
	printf("��һ��ͬѧ�ĵ�ѧ��:\n");
	gets_s(stu1.no);
	printf("��һ��ͬѧ������:\n");
	gets_s(stu1.name);
	printf("��һ��ͬѧ�����Ƴɼ�:\n");
	scanf_s("%d%d%d", &stu1.chi, &stu1.eng, &stu1.math);
	getchar();
	printf("�ڶ���ͬѧ�ĵ�ѧ��:\n");
	gets_s(stu2.no);
	printf("�ڶ���ͬѧ������:\n");
	gets_s(stu2.name);
	printf("�ڶ���ͬѧ�����Ƴɼ�:\n");
	scanf_s("%d%d%d", &stu2.chi, &stu2.eng, &stu2.math);
	flag1 = (stu1.chi > stu2.chi); flag2 = (stu1.math > stu2.math); flag3 = (stu1.eng > stu2.eng);
	if (stu1.sum > stu2.sum)
		printf("NO1:stu1\nNO2:stu2\n");
	else if (stu1.sum < stu2.sum)
		printf("NO1:stu2\nNO2:stu1\n");
	else
	{
		if (flag1 != 0)printf("NO1:stu1\nNO2:stu2\n");
		else if (flag1 == 0)printf("NO1:stu2\nNO2:stu1\n");
		else
		{
			if (flag2 != 0)printf("NO1:stu1\nNO2:stu2\n");
			else if (flag2 == 0)printf("NO1:stu2\nNO2:stu1\n");
			else
			{
				if (flag1 != 0)printf("NO1:stu1\nNO2:stu2\n");
				else if (flag1 == 0)printf("NO1:stu2\nNO2:stu1\n");
			}
		}
	}

}
