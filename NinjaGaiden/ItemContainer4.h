#ifndef ITEM_CONTAINER_H
#define ITEM_CONTAINER_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Enemy.h"
#include"ItemContainer4Control.h"
#include"ItemContainer4Graphics.h"

class ItemContainer4 : public Enemy
{
public:
	ItemContainer4(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~ItemContainer4();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();
private:
	ItemContainer4Control * control;
	ItemContainer4Graphics* graphics;
	Box* obj;
};

#endif