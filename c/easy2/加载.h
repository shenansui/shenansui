#pragma once
#include <stdio.h>
#include <graphics.h>
#include "tools.h"

IMAGE imgwelcome;//欢迎界面
IMAGE imgnormal;//正常界面
IMAGE imgpress;//点击界面
IMAGE imgbg;//游戏背景
IMAGE basketball;//子弹
bool updateflag;//定义刷新标记
IMAGE imgenemy;//定义敌人
IMAGE boom[10];//爆炸图片


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


//子弹结构体包括坐标和是否存在（可自行添加子弹种类，速度，方向等属性）
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
	int posx;//坐标
	int posy;
	int boom;//爆炸图片帧数
	//int type;//飞机类型
	bool exis;//是否存活
	Enemy* next;
}enemy;

enemy* one_enemy;


struct Hero {
	float x, y;//人物x,y坐标

	IMAGE* imgs[DIRECT_COUNT][30];//放不满放null
	int leftheadoffset[DIRECT_COUNT][30];
	int leftfoodoffset[DIRECT_COUNT][30];

	int destx;//当前目标位置
	int desty;
	direct cur;
	int curimgindex;
	bool walking = false;//当前是否在移动
	int speed;
	float x0ff;
	float y0ff;


};//定义主角结构体
struct Hero hero;

int getlefthead(IMAGE* img) {//计算头部偏移量
	int h = img->getheight();
	int w = img->getwidth();

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			int color = getpixel(col, row);
			if (color != 0) {
				SetWorkingImage();//恢复图片处理的默认工作区

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
				SetWorkingImage();//恢复图片处理的默认工作区

				return col;
			}
		}
	}
	SetWorkingImage();
}

//加载项目的各种图片
void loadresources() {
	initgraph(1400, 600);
	loadimage(&imgwelcome, "res/welcome.png");
	loadimage(&imgnormal, "res/start_normal2.png");
	loadimage(&imgpress, "res/start_press2.png");
	loadimage(&imgbg, "res/bg4.png");
	loadimage(&basketball, "res/bullet2.png");
	loadimage(&imgenemy, "res/enemy.png");
	//加载hero的图形数据库
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

			IMAGE* img = new IMAGE;//分配一块新图片内存

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
				true);//对照片进行缩放
			hero.leftheadoffset[i][j] = getlefthead(hero.imgs[i][j]);
			hero.leftfoodoffset[i][j] = getleftfood(hero.imgs[i][j]);
			delete img;
			
		}
	}

}
