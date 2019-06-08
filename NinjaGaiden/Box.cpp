#include"Box.h"
#include<iostream>

using namespace std;

Box::Box()
{
	this->fX = 0;
	this->fY = 0;
	this->nWidth = 0;
	this->nHeight = 0;
	this->fVelocityX = 0;
	this->fVelocityY = 0;
}

void Box::SetBox(Box * other)
{
	this->fX = other->GetX();
	this->fY = other->GetY();
	this->fVelocityX = other->GetVelocityX();
	this->fVelocityY = other->GetVelocityY();
}

Box::Box(float _fX, float _fY)
{
	this->fX = _fX;
	this->fY = _fY;
	this->nWidth = 0;
	this->nHeight = 0;
	this->fVelocityX = 0;
	this->fVelocityY = 0;
}

Box::Box(float _fX, float _fY, int _nWidth, int _nHeight,float _fVelocityX,float _fVelocityY) {
	this->fX = _fX;
	this->fY = _fY;
	this->nWidth = _nWidth;
	this->nHeight = _nHeight;
	this->fVelocityX = _fVelocityX;
	this->fVelocityY = _fVelocityY;
}

Box::~Box()
{
}

void Box::TranslateTo(float _fX, float _fY) {
	this->fX = _fX;
	this->fY = _fY;
}

void Box::TranslateBy(float _fVelocityX, float _fVelocityY) {
	this->fX += _fVelocityX;
	this->fY += _fVelocityY;
	this->fVelocityX = 0;
	this->fVelocityY = 0;
}

Box Box::GetSweptBroadphaseBox() {
	return Box(this->GetVelocityX()>0 ? this->GetX() : this->GetX() + this->GetVelocityX(),
		this->GetVelocityY()>0 ? this->GetY() : this->GetY() + this->GetVelocityY(),
		this->GetVelocityX()>0 ? this->GetWidth() + this->GetVelocityX() : this->GetWidth() - this->GetVelocityX(),
		this->GetVelocityY()>0 ? this->GetHeight() + this->GetVelocityY() : this->GetHeight() - this->GetVelocityY());
}

bool Box::AABBCheck(Box other) {
	Box broadphase = GetSweptBroadphaseBox();
	return !(broadphase.GetX() + broadphase.GetWidth() < other.GetX() ||
		other.GetX() + other.GetWidth() < broadphase.GetX() ||
		broadphase.GetY() + broadphase.GetHeight() < other.GetY() ||
		other.GetY() + other.GetHeight() < broadphase.GetY());
}

float Box::SweptAABB(Box block, float &normalX, float &normalY) {
	Box box1 = *(this);

	Box box2 = block;

	float entryInvX, entryInvY;
	float exitInvX, exitInvY;

	if (box1.GetVelocityX() > 0) {
		entryInvX = box2.GetX() - (box1.GetX() + box1.GetWidth());
		exitInvX = (box2.GetX() + box2.GetWidth()) - box1.GetX();
	}
	else {
		entryInvX = (box2.GetX() + box2.GetWidth()) - box1.GetX();
		exitInvX = box2.GetX() - (box1.GetX() + box1.GetWidth());
	}

	if (box1.GetVelocityY() > 0) {
		entryInvY = box2.GetY() - (box1.GetY() + box1.GetHeight());
		exitInvY = (box2.GetY() + box2.GetHeight()) - box1.GetY();
	}
	else {
		entryInvY = (box2.GetY() + box2.GetHeight()) - box1.GetY();
		exitInvY = box2.GetY() - (box1.GetY() + box1.GetHeight());
	}

	float entryX, entryY;
	float exitX, exitY;

	if (box1.GetVelocityX() == 0.0f) {
		entryX = -std::numeric_limits<float>::infinity();
		exitX = std::numeric_limits<float>::infinity();
	}
	else {
		entryX = entryInvX / box1.GetVelocityX();
		exitX = exitInvX / box1.GetVelocityX();
	}

	if (box1.GetVelocityY() == 0.0f) {
		entryY = -std::numeric_limits<float>::infinity();
		exitY = std::numeric_limits<float>::infinity();
	}
	else {
		entryY = entryInvY / box1.GetVelocityY();
		exitY = exitInvY / box1.GetVelocityY();
	}

	float entryTime, exitTime;

	entryTime = std::fmax(entryX, entryY);
	exitTime = std::fmin(exitX, exitY);

	if (entryTime > exitTime ||
		(entryX<0.0f && entryY<0.0f) ||
		(entryX>1.0f || entryY>1.0f)) {
		//normalX = 0.0f;
		//normalY = 0.0f;
		return 1.0f;
	}
	else {
		if (entryX > entryY) {
			if (entryInvX < 0.0f) {
				normalX = 1.0f;
				normalY = 0.0f;
			}
			else {
				normalX = -1.0f;
				normalY = 0.0f;
			}
		}
		else {
			if (entryInvY < 0.0f) {
				normalX = 0.0f;
				normalY = 1.0f;
			}
			else {
				normalX = 0.0f;
				normalY = -1.0f;
			}
		}
	}

	return entryTime;
}
