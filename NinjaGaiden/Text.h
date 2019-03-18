#ifndef _TEXT_H_
#define _TEXT_H_
#include"Sprite.h"
#include"Camera.h"
#include<stdio.h>
#include<stdlib.h>
class Text
{
private:
	Sprite* wordsheet;
public:
	Text();
	Text(LPDIRECT3DDEVICE9 D3ddv, Camera* camera, D3DCOLOR color);
	~Text();

	void Draw(float x, float y, char* text);
	static char* itc(int a);
};
#endif