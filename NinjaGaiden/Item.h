#ifndef ITEM_H
#define ITEM_H
#include"Sprite.h"
#include"Object.h"
#include"Keyboard.h"
#include<string>
using namespace std;

class Item : public Object
{
public:
	Item(){}
	Item(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Item();
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

	virtual string GetType()=0;
protected:
	bool active;
	Keyboard* keyboard;
	Camera* camera;
	DWORD delta;
	Sprite* body;
};

#endif // !Item_H
