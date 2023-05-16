#pragma once
#include <stdio.h>
#include <graphics.h>
#include "加载.h"
#include "tools.h"
#include <malloc.h>
int x = 348;
int y = 388;//开始图形的（x,y)坐标
int l = 0;

void initbasketball(){
	a.x = hero.x + hero.imgs[0][0]->getwidth();
	a.y = hero.y - hero.imgs[0][0]->getheight() / 2 - 20;
	a.exis = true;
}

void fly() {
	if (a.x >= 1350 || a.exis == false) {
		return;
	}
	else {
		a.x += 5;
	}
}

void inithero() {//初始化主角
	hero.speed = 2;
	hero.x = 400;
	hero.y = 355;
	hero.destx = hero.x;
	hero.desty = hero.y;
	hero.cur = DIRECT_RIGHT;
	hero.curimgindex = 8;
}

void initdate() {
	inithero();
	updateflag = true;
}

void welcome() {//初始界面函数
	putimage(0, 0, &imgwelcome);
	putimage(x, y, &imgnormal);
	while (1) {
		MOUSEMSG msg = GetMouseMsg();//捕获鼠标信息

		if (msg.uMsg == WM_MOUSEMOVE ||//移动时变换状态
			msg.uMsg == WM_LBUTTONDBLCLK || msg.uMsg == WM_LBUTTONUP) {
			if (msg.x > x && msg.x < x + imgnormal.getheight() &&
				msg.y > y && msg.y < y + imgnormal.getheight()) {
				putimage(x, y, &imgpress);
				if (msg.uMsg == WM_LBUTTONUP) {
					break;
				}

			}
			else
				putimage(x, y, &imgnormal);
		}
	}

	initdate();
}



void updatehero() {
	IMAGE* img = hero.imgs[hero.cur][hero.curimgindex];

	int x = hero.x - hero.leftfoodoffset[hero.cur][hero.curimgindex];
	int y = hero.y - img->getheight();
	
	putimagePNG(x, y, img);
	if (hero.walking == false) {
		return;
	}
	else {
		hero.x += hero.x0ff;
		hero.y += hero.y0ff;
		if (hero.x == hero.destx) {
			hero.walking = false;
			return;
		}
	}
}

void updatenemy() {
	putimagePNG(1086, 256, &imgenemy);

}





void updatewindow() {
	BeginBatchDraw();
	putimage(0, 0, &imgbg);
	updatenemy();
	putimagePNG(1086, 256, &imgenemy);
	putimagePNG(a.x, a.y, &basketball);
	fly();
	updatehero();
	updatedatahero();
	EndBatchDraw();
	

}

void updatedatahero() {//更新人物
	
}
