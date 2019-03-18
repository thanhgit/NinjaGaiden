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
	virtual Item* getItem();
	void SetKeyboard(Keyboard* keyboard);

	void setDelta(DWORD _delta);
	virtual string GetType()=0;
	void SetActive(bool _active) {
		this->active = _active;
	}
	bool GetActive() {
		return this->active;
	}

protected:
	bool active;
	Keyboard* keyboard;
	Camera* camera;
	DWORD delta;
	Sprite* body;
};

#endif // !Static_H
