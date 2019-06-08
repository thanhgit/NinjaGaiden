#ifndef RUNNER_H
#define RUNNER_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Enemy.h"
#include"RunnerControl.h"
#include"RunnerGraphics.h"
#include<typeinfo.h>
class Runner : public Enemy
{
public:
	Runner(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Runner();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();

	EnemyState* getState();
	void setState(EnemyState* _state);
private:
	RunnerControl * control;
	RunnerGraphics* graphics;
	Box* obj;
};

#endif