#ifndef NINJA_H
#define NINJA_H
#include"Sprite.h"
#include"Object.h"
#include"Keyboard.h"
#include"Weapon.h"

#include"NinjaControl.h"
#include"NinjaGraphics.h"


#include"Log.h"
#include<typeinfo.h>
class Ninja : public Object
{
public:
	Ninja(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Ninja();
	void Update(DWORD _dt);
	void SetKeyboard(Keyboard* keyboard);

	// basic
	void normal();

	void revival();
	void save();
	void restore();

	void Dead();

	// stand
	bool IsStandLeft();
	bool IsStandRight();
	bool IsStand();

	void ActionStandLeft();
	void ActionStandRight();

	// stand actack
	bool IsActackLeft();
	bool IsActackRight();
	bool IsActack();

	// jump
	bool IsJump();

	bool IsJumpVertical();
	bool IsJumpVerticalLeft();
	bool IsJumpVerticalRight();

	void ActionJumpVerticalLeft(DWORD _dt);
	void ActionJumpVerticalRight(DWORD _dt);

	bool IsJumpParabol();
	bool IsJumpParabolLeft();
	bool IsJumpParabolRight();

	void ActionJumpParabolLeft(DWORD _dt);
	void ActionJumpParabolRight(DWORD _dt);

	//
	bool IsLeft();
	bool IsRight();

	// ninja
	void SetHeart(int _heart) {
		this->m_heart = _heart;
	}
	int GetHeart() {
		return this->m_heart;
	}
	void ChangeHeart(int _amount) {
		if (this->m_heart + _amount >= 0) {
			this->m_heart += _amount;
		}
		else {
			this->m_heart = 0;
		}
	}

	void SetScore(int _score) {
		this->m_score = _score;
	}

	int GetScore() {
		return m_score;
	}

	void ChangeScore(int _amount) {
		if (this->m_score + _amount >= 0) {
			this->m_score += _amount;
		}
		else {
			this->m_score = 0;
		}
	}

	void SetLife(int _life) {
		this->m_life = _life;
	}

	int GetLife() {
		return this->m_life;
	}

	void ChangeLife(int _amount) {
		if (this->m_life + _amount >= 0) {
			this->m_life += _amount;
		}
		else {
			this->m_life = 0;
		}
	}

	// allow jump
	void SetAllowJump(bool _allowJump) {
		this->allowJump = _allowJump;
	}

	bool GetAllowJump() {
		return this->allowJump;
	}

public:
	///////// simon 
	int m_heart;
	int m_score;
	int m_life;
	int m_point;

	float x_save;
	float y_save;
	//
	Log* log;

	bool isRun;
	bool allowJump;

	NinjaControl* control;
	NinjaGraphics* graphics;
	Keyboard* keyboard;
	Camera* camera;
	DWORD delta;

	void ActionRunLeft(DWORD _dt);
	void ActionRunRight(DWORD _dt);
	void ActionStand();

	bool IsRunLeft();
	bool IsRunRight();
	bool IsRun();

	void UpdateCamera();
	void UpdateWeapon();
};

#endif // !SIMON_H