#ifndef STATIC_H
#define STATIC_H
#include"Sprite.h"
#include"Object.h"
#include"Keyboard.h"
#include"Item.h"

class Static : public Object
{
public:
	Static(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Static();
	void Update();
	void Dead();
	
	void SetKeyboard(Keyboard* keyboard);

	void setDelta(DWORD _delta);

	void SetActive(bool _active) {
		this->active = _active;
	}
	bool GetActive() {
		return this->active;
	}

	Item* getItem() {
		return this->item;
	}
protected:
	bool active;
	Keyboard* keyboard;
	Camera* camera;
	DWORD delta;
	Sprite* body;
	Item* item;
};

#endif // !Static_H
