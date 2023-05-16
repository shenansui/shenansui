#include <stdio.h>
#include <graphics.h>//调用easy-x图形库
#include "加载.h"//加载图片函数
#include "init.h"//初始化函数,更新窗口函数
#include <conio.h>
#include "tools.h"

void shoot() 
{
	IMAGE* img = &basketball;
	BeginBatchDraw();
	putimagePNG(a.x, a.y, &basketball);
	fly();
	EndBatchDraw();
}




void herowalk(direct direct) {//移动函数
	if (hero.walking) return;

	hero.walking = true;
	hero.cur = direct;
	hero.curimgindex = 0;

	if (direct == DIRECT_LEFT || direct == DIRECT_RIGHT) {
		if (direct == DIRECT_LEFT) {
			hero.destx = hero.x - 72;
			hero.x0ff = -2;
		}
		else {
			hero.destx = hero.x + 72;
			hero.x0ff = 2;
		}
		hero.desty = hero.y;
		hero.y0ff = 0;
	}
}


void keyevent() {//按键输入函数
	if (_kbhit()) {
		unsigned char ch = _getch();
		if (ch == 224) {
			ch = _getch();
			switch (ch)
			{case 72:
				break;
			case 80:
				break;
			case 75:
				//hero.walking = true;
				herowalk(DIRECT_LEFT);
				printf("%d", 1);
				break;
			case 77:
				//hero.walking = true;
				herowalk(DIRECT_RIGHT);
				break;
			default:
				break;
			}
		}
		else {
			switch (ch)
			{case 49:
				shoot();
			default:
				break;
			}
		}
	}
}


int main(void) {
	loadresources();

	welcome();
	initbasketball();
	int timer = 0;
	while (1) {//游戏主循环
		keyevent();
		timer += getDelay();
		if (timer > 20) {
			timer = 0;
			updateflag = true;
		}

		if (updateflag) {
			updateflag = false;
			updatewindow();
			//updatedata();
		}
		

	}
	return 0;
}