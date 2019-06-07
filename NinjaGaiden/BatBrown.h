#ifndef BAT_BROWN_H
#define BAT_BROWN_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Enemy.h"
#include"BatBrownControl.h"
#include"BatBrownGraphics.h"

class BatBrown : public Enemy
{
public:
	BatBrown(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~BatBrown();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();
private:
	BatBrownControl * control;
	BatBrownGraphics* graphics;
	Box* obj;
};

#endif