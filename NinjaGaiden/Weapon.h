#ifndef WEAPON_H
#define WEAPON_H
#include"Sprite.h"
#include"Object.h"
#include"Keyboard.h"

class Weapon : public Object
{
public:
	Weapon(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Weapon();
	void Update();
	void Dead();
	void SetKeyboard(Keyboard* keyboard);

	void setDelta(DWORD _delta);

protected:
	Keyboard* keyboard;
	Camera* camera;
	DWORD delta;
	Sprite* body;
};

#endif // !Weapon_H
