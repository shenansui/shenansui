#include <stdio.h>
#include <graphics.h>//����easy-xͼ�ο�
#include "����.h"//����ͼƬ����
#include "init.h"//��ʼ������,���´��ں���
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




void herowalk(direct direct) {//�ƶ�����
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


void keyevent() {//�������뺯��
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
	while (1) {//��Ϸ��ѭ��
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