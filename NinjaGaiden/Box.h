#ifndef BOX_H
#define BOX_H
#include"Utils.h"
class Box
{
public:
	Box();
	void SetBox(Box* other);
	Box(float _fX, float _fY);
	Box(float _fX, float _fY, int _nWidth, int _nHeight,float _fVelocityX=0,float _fVelocityY=0);
	~Box();

	void TranslateTo(float _fX, float _fY);

	void TranslateBy(float _fVelocityX, float _fVelocityY);


	bool AABBCheck(Box _box);
	float SweptAABB(Box block, float & normalX, float & normalY);

	void SetX(float _fX) {
		this->fX = _fX;
	}
	float GetX() {
		return this->fX;
	}
	void SetY(float _fY) {
		this->fY = _fY;
	}
	float GetY() {
		return this->fY;
	}

	int GetWidth() {
		return this->nWidth;
	}

	int GetHeight() {
		return this->nHeight;
	}

	void SetVelocityX(float _fVelocityX) {
		this->fVelocityX = _fVelocityX;
	}
	float GetVelocityX() {
		return this->fVelocityX;
	}
	void SetVelocityY(float _fVelocityY) {
		this->fVelocityY = _fVelocityY;
	}
	float GetVelocityY() {
		return this->fVelocityY;
	}

	void SetWidth(int _nWidth) {
		this->nWidth = _nWidth;
	}

	void SetHeight(int _nHeight) {
		this->nHeight = _nHeight;
	}

private:
	float fX, fY;
	int nWidth, nHeight;
	float fVelocityX, fVelocityY;

	Box GetSweptBroadphaseBox();

};


#endif // !BOX_H
