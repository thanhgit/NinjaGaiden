#ifndef BOSS_H
#define BOSS_H
#include"Sprite.h"
#include"Object.h"
#include"Keyboard.h"
#include"BossState.h"
class Boss: public Object
{
public:
	Boss(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Boss();

	virtual void Update(DWORD _dt) = 0;
	virtual void Dead() = 0;
	virtual void ai(Box* box) = 0;

	void SetActive(bool _active) {
		this->active = _active;
	}
	bool GetActive() {
		return this->active;
	}

	int GetDamage() {
		return this->m_damage;
	}

	int GetPoint() {
		return this->m_point;
	}

	virtual BossState* getState() = 0;
	virtual void setState(BossState* _state) = 0;

protected:
	bool active;
	Keyboard* keyboard;
	Camera* camera;
	DWORD delta;
	Sprite* body;

	int m_damage;
	int m_point;
};


#endif // !BOSS_H
