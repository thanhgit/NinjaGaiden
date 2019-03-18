#ifndef OBJECT_H
#define OBJECT_H
#include"Box.h"
class Object
{
public:
	Object(){}
	Object(float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Object();
	Box* GetBody() {
		return body;
	}
	void SetHP(int _hp) {
		this->m_hp = _hp;
	}
	int GetHP() {
		return this->m_hp;
	}
	void ChangeHP(int _amount) {
		if (this->m_hp + _amount >= 0) {
			this->m_hp += _amount;
		}
		else {
			this->m_hp = 0;
		}
	}

	virtual void Dead();
	virtual void Update(DWORD _dt);
	virtual void normal();
protected:
	Box* body;
	int m_hp;

};


#endif // !OBJECT_H
