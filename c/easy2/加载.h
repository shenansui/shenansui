#pragma once
#include <stdio.h>
#include <graphics.h>
#include "tools.h"

IMAGE imgwelcome;//��ӭ����
IMAGE imgnormal;//��������
IMAGE imgpress;//�������
IMAGE imgbg;//��Ϸ����
IMAGE basketball;//�ӵ�
bool updateflag;//����ˢ�±��
IMAGE imgenemy;//�������
IMAGE boom[10];//��ըͼƬ


typedef enum {
	DIRECT_LEFT,
	DIRECT_RIGHT,
	DIRECT_LEFT_OVER,
	DIRECT_RIGHT_OVER,
	DIRECT_LEFT_SHOOT,
	DIRECT_RIGHT_SHOOTL,
	DIRECT_LEFT_UP,
	DIRECT_RIGHT_UP,
	DIRECT_LEFT_DOWN,
	DIRECT_RIGHT_DOWN,
	DIRECT_COUNT
}direct;


//�ӵ��ṹ�����������Ƿ���ڣ�����������ӵ����࣬�ٶȣ���������ԣ�
typedef struct Bullet
{
	int x;
	int y;
	bool exis;
	Bullet* next;
}basket;

basket a;


typedef struct Enemy
{
	int posx;//����
	int posy;
	int boom;//��ըͼƬ֡��
	//int type;//�ɻ�����
	bool exis;//�Ƿ���
	Enemy* next;
}enemy;

enemy* one_enemy;


struct Hero {
	float x, y;//����x,y����

	IMAGE* imgs[DIRECT_COUNT][30];//�Ų�����null
	int leftheadoffset[DIRECT_COUNT][30];
	int leftfoodoffset[DIRECT_COUNT][30];

	int destx;//��ǰĿ��λ��
	int desty;
	direct cur;
	int curimgindex;
	bool walking = false;//��ǰ�Ƿ����ƶ�
	int speed;
	float x0ff;
	float y0ff;


};//�������ǽṹ��
struct Hero hero;

int getlefthead(IMAGE* img) {//����ͷ��ƫ����
	int h = img->getheight();
	int w = img->getwidth();

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			int color = getpixel(col, row);
			if (color != 0) {
				SetWorkingImage();//�ָ�ͼƬ�����Ĭ�Ϲ�����

				return col;
			}
		}
	}
	SetWorkingImage();
}

int getleftfood(IMAGE* img) {
	int h = img->getheight();
	int w = img->getwidth();

	for (int row = h-1; row >=0; row--) {
		for (int col = 0; col < w; col++) {
			int color = getpixel(col, row);
			if (color != 0) {
				SetWorkingImage();//�ָ�ͼƬ�����Ĭ�Ϲ�����

				return col;
			}
		}
	}
	SetWorkingImage();
}

//������Ŀ�ĸ���ͼƬ
void loadresources() {
	initgraph(1400, 600);
	loadimage(&imgwelcome, "res/welcome.png");
	loadimage(&imgnormal, "res/start_normal2.png");
	loadimage(&imgpress, "res/start_press2.png");
	loadimage(&imgbg, "res/bg4.png");
	loadimage(&basketball, "res/bullet2.png");
	loadimage(&imgenemy, "res/enemy.png");
	//����hero��ͼ�����ݿ�
	memset(hero.imgs, 0, sizeof(hero.imgs));
	const char* pathname[DIRECT_COUNT] = {
		"left","right","left_over","right_over","left_shoot","right_shoot",
		"left_stop","right_stop","left_stop","right_stop"
	};

	char name[128];
	for (int i = 0; i < DIRECT_COUNT; i++) {
		for (int j = 0; j < 30; j++) {
			sprintf_s(name, sizeof(name), "res/%s/%d.png",
				pathname[i], j + 1);

			IMAGE* img = new IMAGE;//����һ����ͼƬ�ڴ�

			loadimage(img, name);
			if (img->getwidth() == 0) {
				delete img;
				break;
			}

			float factor = (
				i == DIRECT_LEFT ||
				i == DIRECT_RIGHT ||
				i == DIRECT_LEFT_OVER ||
				i == DIRECT_RIGHT_OVER
				) ? 0.12 : 0.09;


			hero.imgs[i][j] = new IMAGE;
			loadimage(hero.imgs[i][j], name,
				img->getwidth() * factor, img->getheight() * factor,
				true);//����Ƭ��������
			hero.leftheadoffset[i][j] = getlefthead(hero.imgs[i][j]);
			hero.leftfoodoffset[i][j] = getleftfood(hero.imgs[i][j]);
			delete img;
			
		}
	}

}
