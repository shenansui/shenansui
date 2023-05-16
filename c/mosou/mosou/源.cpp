//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int finishr(int a[], int b);
//int finishb(int a[], int b);
//int sr[6] = { 0 }, sl[6] = { 0 };
//int mh, ml;//mh是红方司令部，ml是蓝方司令部
//int bh[6] = { 0 }, bl[6] = { 0 };//bh是红方司令部不能制造士兵的种数，bl是蓝方
//int main()
//{
//	int n, i;
//	scanf("%d", &n);
//	int M;//红蓝司令部的生命源
//	int dragon, ninja, iceman, lion, wolf;
//	//int gh[6] = { 0,5,6,7,4,3 };
//	//int gl[6] = { 0,6,3,4,5,7 };//对应的攻击力
//	int j;
//	int count = 0;
//	int bei = 0;
//	int red, blue;
//	int fr = 0, fl = 0;//fr,fl用于记录二者是否结束
//	int counth, countl;
//	for (i = 1; i <= n; i++) {
//		int h[6] = { 0 };//用于记录士兵的数量
//		int l[6] = { 0 };
//		fr = 0;
//		fl = 0;
//		scanf("%d", &M);
//		for (j = 1; j < 6; j++) {
//			bh[j] = 0;
//			bl[j] = 0;
//		}
//		ml = M;
//		mh = M;
//		scanf("%d %d %d %d %d", &dragon, &ninja, &iceman, &lion, &wolf);
//		sr[1] = iceman;
//		sr[2] = lion;
//		sr[3] = wolf;
//		sr[4] = ninja;
//		sr[5] = dragon;
//		sl[1] = lion;
//		sl[2] = dragon;
//		sl[3] = ninja;
//		sl[4] = iceman;
//		sl[5] = wolf;
//		printf("Case:%d\n", i);
//		counth = 1;
//		countl = 1;
//		bei = 0;
//		red = 1;
//		blue = 1;
//		for (j = 0; fr + fl != 2; j++) {//j代表时刻
//			bei = 0;
//			red = red % 5;
//			blue = blue % 5;
//			if (fr == 0) {
//				if (j < 10)
//					printf("00%d ", j);
//				else if (j < 100)
//					printf("0%d ", j);
//				else
//					printf("%d ", j);
//				count = 0;
//				switch (red) {
//				case 1:
//					if (mh >= iceman) {
//						mh -= iceman;
//						h[red]++;
//						printf("red iceman %d born with strength 5,%d iceman in red headquarter\n", counth, h[red]);
//						bei = 1;
//						break;
//					}
//					else {
//						bh[red]++;
//						red++;
//						count++;
//					}
//				case 2:
//					if (mh >= lion) {
//						mh -= lion;
//						h[red]++;
//						printf("red lion %d born with strength 6,%d lion in red headquarter\n", counth, h[red]);
//						bei = 1;
//						break;
//					}
//					else {
//						bh[red]++;
//						red++;
//						count++;
//					}
//				case 3:
//					if (mh >= wolf) {
//						mh -= wolf;
//						h[red]++;
//						printf("red wolf %d born with strength 7,%d wolf in red headquarter\n", counth, h[red]);
//						bei = 1;
//						break;
//					}
//					else {
//						bh[red]++;
//						red++;
//						count++;
//					}
//				case 4:
//					if (mh >= ninja) {
//						mh -= ninja;
//						h[red]++;
//						printf("red ninja %d born with strength 4,%d ninja in red headquarter\n", counth, h[red]);
//						bei = 1;
//						break;
//					}
//					else {
//						bh[red]++;
//						red++;
//						count++;
//					}
//				case 5:
//				case 0:
//					if (red == 0)
//						red = 5;
//					if (mh >= dragon) {
//						mh -= dragon;
//						h[red]++;
//						printf("red dragon %d born with strength 3,%d dragon in red headquarter\n", counth, h[red]);
//						bei = 1;
//						break;
//					}
//					else {
//						bh[red]++;
//						count++;
//					}
//				}
//				if (bei == 0) {//判断有无输出
//					red = finishr(bh, count);
//					if (red == 0) {
//						fr = 1;
//						printf("red headquarter stops making warriors\n");
//					}
//					else {
//						switch (red) {
//						case 1:
//							h[red]++;
//							printf("red iceman %d born with strength 5,%d iceman in red headquarter\n", counth, h[red]);
//							break;
//						case 2:
//							h[red]++;
//							printf("red lion %d born with strength 6,%d lion in red headquarter\n", counth, h[red]);
//							break;
//						case 3:
//							h[red]++;
//							printf("red wolf %d born with strength 7,%d wolf in red headquarter\n", counth, h[red]);
//							break;
//						case 4:
//							h[red]++;
//							printf("red ninja %d born with strength 4,%d ninja in red headquarter\n", counth, h[red]);
//							break;
//						}
//						red++;
//					}
//				}
//				else {//有输出则让red加一
//					red++;
//				}
//			}
//			count = 0;
//			bei = 0;
//			if (fl == 0) {
//				if (j < 10)
//					printf("00%d ", j);
//				else if (j < 100)
//					printf("0%d ", j);
//				else
//					printf("%d ", j);
//				switch (blue) {
//				case 1:
//					if (ml >= lion) {
//						ml -= lion;
//						l[blue]++;
//						printf("blue lion %d born with strength 6,%d lion in blue headquarter\n", countl, l[blue]);
//						bei = 1;
//						break;
//					}
//					else {
//						bl[blue]++;
//						blue++;
//						count++;
//					}
//				case 2:
//					if (ml >= dragon) {
//						ml -= dragon;
//						l[blue]++;
//						printf("blue dragon %d born with strength 3,%d dragon in blue headquarter\n", countl, l[blue]);
//						bei = 1;
//						break;
//					}
//					else {
//						bl[blue]++;
//						blue++;
//						count++;
//					}
//				case 3:
//					if (ml >= ninja) {
//						ml -= ninja;
//						l[blue] ++;
//						printf("blue ninja %d born with strength 4,%d ninja in blue headquarter\n", countl, l[blue]);
//						bei = 1;
//						break;
//					}
//					else {
//						bl[blue]++;
//						blue++;
//						count++;
//					}
//				case 4:
//					if (ml >= iceman) {
//						ml -= iceman;
//						l[blue]++;
//						printf("blue iceman %d born with strength 5,%d iceman in blue headquarter\n", countl, l[blue]);
//						bei = 1;
//						break;
//					}
//					else {
//						bl[blue]++;
//						blue++;
//						count++;
//					}
//				case 5:
//				case 0:
//					if (blue == 0)
//						blue = 5;
//					if (ml >= wolf) {
//						ml -= wolf;
//						l[blue]++;
//						printf("blue wolf %d born with strength 7,%d wolf in blue headquarter\n", countl, l[blue]);
//						bei = 1;
//						break;
//					}
//					else {
//						bl[blue]++;
//						count++;
//					}
//				}
//				if (bei == 0) {//判断有无输出
//					blue = finishb(bl, count);//无输出则调用函数判断
//					if (blue == 0) {
//						fl = 1;
//						printf("blue headquarter stops making warriors\n");
//					}
//					else {
//						switch (blue) {
//						case 1:
//							l[blue]++;
//							printf("blue lion %d born with strength 6,%d lion in blue headquarter\n", countl, l[blue]);
//							break;
//						case 2:
//							l[blue]++;
//							printf("blue dragon %d born with strength 3,%d dragon in blue headquarter\n", countl, l[blue]);
//							break;
//						case 3:
//							l[blue]++;
//							printf("blue ninja %d born with strength 4,%d ninja in blue headquarter\n", countl, l[blue]);
//							break;
//						case 4:
//							l[blue]++;
//							printf("blue iceman %d born with strength 5,%d iceman in blue headquarter\n", countl, l[blue]);
//							break;
//						}
//						blue++;
//					}
//				}
//				else {//有输出则让blue加一
//					blue++;
//				}
//			}
//			counth++;
//			countl++;
//		}
//	}
//	return 0;
//}
//int finishr(int a[], int b) {
//	int i;
//	int count = 0;
//	for (i = 1; i < 6; i++) {
//		if (a[i] > 0)
//			count++;
//		else {
//			if (mh > sr[i])
//			{
//				mh -= sr[i];
//				return i;
//			}
//			else {
//				a[i]++;
//				count++;
//			}
//
//		}
//	}
//	if (count == 5)
//		return 0;
//
//}
//int finishb(int a[], int b) {
//	int i;
//	int count = 0;
//	for (i = 1; i < 6; i++) {
//		if (a[i] > 0)
//			count++;
//		else {
//			if (ml > sl[i])
//			{
//				ml -= sl[i];
//				return i;
//			}
//			else {
//				a[i]++;
//				count++;
//			}
//
//		}
//	}
//	if (count == 5)
//		return 0;
//}

