#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//struct ck
//{
//	int a;
//	int b;
//	int c;
//};
//
//int main()
//{
//	struct ck r[50001], temp;
//	r[50000].a = 0;
//	r[50000].b = 0;
//	r[50000].c = 0;
//	int n;
//	scanf("%d", &n);
//	int* g, * f;
//	int i, j;
//	int sum = 0;
//	int count = 0;
//	g = (int*)malloc(sizeof(int) * n);
//	f = (int*)malloc(sizeof(int) * n);
//	for (i = 0; i < n; i++) {
//		scanf("%d %d", &g[i], &f[i]);
//	}
//	int* m;
//	m = (int*)malloc(sizeof(int) * n);
//	for (i = 0; i < n; i++) {
//		sum += g[i];
//	}
//	for (i = 0; i < n; i++) {
//		m[i] = sum - g[i] - f[i];
//	}
//	for (i = 0; i < n; i++) {
//		r[i].a = g[i];
//		r[i].b = f[i];
//		r[i].c = m[i];
//	}
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n - i; j++) {
//			if (r[j].c < r[j + 1].c) {
//				temp = r[j];
//				r[j] = r[j + 1];
//				r[j + 1] = temp;
//			}
//		}
//	}
//	for (i = n - 1; i >= 0; i--) {
//		sum = 0;
//		for (j = n - 1; j > i; j--) {
//			sum += r[j].a;
//		}
//		if (sum > r[i].c)
//			r[i].c = 0;
//		else
//			r[i].c -= sum;
//	}
//	int t = r[0].c;
//	for (i = 0; i < n - 1; i++) {
//		if (r[i].c < r[i + 1].c)
//			t = r[i + 1].c;
//	}
//	printf("%d", t);
//
//	free(g);
//	free(f);
//	free(m);
//
//	return 0;
//
//}


//void main()
//{
//	int i, n, m, a, b, c, da = 0, mi, mx,o;
//	int* p = 0;
//	scanf("%d %d", &n, &m);
//	p = (int*)malloc(sizeof(int) * n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &p[i]);
//	}
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d %d", &mi, &mx);
//		a = (mx - mi + 1) >>1;
//		o = mi + a;
//		for (b = mi - 1; b <= o; b++)
//		{
//			for (c = b; c < mx; c++)
//			{
//				if (p[c] == p[b])
//				{
//					da++;
//				}
//			}
//			if (da > a)
//			{
//				printf("%d\n", p[b]);
//				da = 0;
//				break;
//			}
//			if(b==mx-1)
//			{
//				printf("0\n");
//			}
//			da = 0;
//		}
//	}
//	free(p);
//}


//#define NUMA 10   /*排序个数*/
//
//#include <stdio.h>  /*头文件*/
//
//void jh(int*, int*);   /*函数声明*/
//
//void main()
//{
//	int i, o;     /*变量声明*/
//	int num[NUMA];   /*声明数组，装需要的排序的数*/
//	for (i = 0; i < NUMA; i++)
//	{
//		scanf("%d", &num[i]);   /*输入需要排序的数字*/
//	}
//	for (i = 0; i < NUMA; i++)   /*重复NUMA次*/
//	{
//		for (o = 0; o < NUMA-1; o++)  /*从第一个数到最后一个*/
//		{
//			if (num[o] > num[o + 1])    /*判断大小*/
//			{
//				jh(&num[o], &num[o + 1]);   /*将大的数换到后面*/
//			}
//		}
//	}
//	for (i = 0; i < NUMA; i++)
//	{
//		printf("%d\n", num[i]);    /*输出每个数*/
//	}
//}
//
//
//void jh(int*a, int*b)  /*输入需要交换的两个数的地址，函数主体*/
//{
//	int t = *a;   /*交换a和b*/
//	*a = *b;
//	*b = t;
//}



//struct {
//	int a;
//	int b;
//	char c;
//}g[5000];
//int main()
//{
//	int i = 0;
//	for (;;) 
//	{
//		scanf("%d %d", &g[i].a, &g[i].b);
//		printf("%d\n", g[i].a);
//		if (g[i].a == 0&&g[i].b==0)
//		{
//			break;
//		}
//		g[i].c = getchar();
//		getchar();
//		i++;
//	}
//	return 0;
//}

//int main()
//{
//	int i, b, a[6];
//	for (i = 0; i < 6; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (i = 0; i < 6; i++)
//	{
//		for (b = 0; b < 6; b++)
//		{
//			printf("%d ", a[b-i<0?6-i+b:b-i]);
//			if (b == 5) printf("\n");
//		}
//	}
//}

//int main()
//{
//	int a = 5, b, c = 5, d;
//	d = (c++) + (c++) + (c++);
//	b = (++a) + (++a) + (++a);
//	printf("%d %d", b,d);
//
//
//	return 0;
//}