#ifndef HURT_H
#define HURT_H
#include"Sprite.h"
#include"Object.h"
class Hurt : public Object
{
public:
	Hurt(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Hurt();
	void AttackLeft();
	void AttackRight();
	void Update(DWORD _dt);
	void Dead();
	void SetSteps(int _steps) {
		this->steps = _steps;
	}
private:
	int index;
	int steps;
	// Enum action of hurt
	// 0 : nothing
	// 1 : left
	// 2 : right
	int action;
	
	Sprite* body;
};


#endif // !SMALL_HEART
