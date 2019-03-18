#ifndef ENEMY_H
#define ENEMY_H
#include"Sprite.h"
#include"Object.h"
#include"Keyboard.h"

class Enemy : public Object
{
public:
	Enemy(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Enemy();
	void Update();
	void Dead();
	void SetKeyboard(Keyboard* keyboard);

	void setDelta(DWORD _delta);

	virtual void ai(Box* box)=0;

	void SetActive(bool _active) {
		this->active = _active;
	}
	bool GetActive() {
		return this->active;
	}

	virtual void changeDirection();

	int GetDamage() {
		return this->m_damage;
	}

	int GetPoint() {
		return this->m_point;
	}
	
protected:
	bool active;
	Keyboard* keyboard;
	Camera* camera;
	DWORD delta;
	Sprite* body;

	int m_damage;
	int m_point;
};

#endif // !Enemy_H
