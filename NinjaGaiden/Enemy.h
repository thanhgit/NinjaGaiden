#ifndef ENEMY_H
#define ENEMY_H
#include"Sprite.h"
#include"Object.h"
#include"Keyboard.h"
#include"EnemyState.h"

class Enemy : public Object
{
public:
	Enemy(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Enemy();

	virtual void Update(DWORD _dt)=0;
	virtual void Dead()=0;
	virtual void ai(Box* box)=0;

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

	virtual EnemyState* getState() = 0;
	virtual void setState(EnemyState* _enemy) = 0;
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
