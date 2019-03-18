#include"Camera.h"
#include"Utils.h"

Camera::Camera()
{
	this->nX = 0;
	this->nY = 0;
}

Camera::Camera(int _nX, int _nY) {
	this->nX = _nX;
	this->nY =_nY;
}



Camera::~Camera()
{
}

int Camera::GetX() {
	return this->nX;
}

int Camera::GetY() {
	return this->nY;
}

int Camera::GetWidth()
{
	return this->nWidth;
}

int Camera::GetHeight()
{
	return this->nHeight;
}

Box * Camera::GetBox()
{
	return new Box(this->nX, this->nY,this->nWidth,this->nHeight, 0, 0);
}

void Camera::SetSize(int _nWidth, int _nHeight)
{
	this->nWidth = _nWidth;
	this->nHeight = _nHeight;
}

void Camera::SetCamera(int _nX, int _nY) {
	this->nX = _nX;
	this->nY =_nY;
}

void Camera::TransitionTo(int _nX, int _nY, int _nVelocityX,int _nVelocityY) {
	if (this->nX > _nX) {
		if (this->nY > _nY) {
			this->nX += _nVelocityX;
			this->nY -= _nVelocityY;
		}
		else if(this->nY<_nY){
			this->nX += _nVelocityX;
			this->nY += _nVelocityY;
		}
	}
	else if(this->nX<_nX){
		if (this->nY > _nY) {
			this->nX -= _nVelocityX;
			this->nY -= _nVelocityY;
		}
		else if (this->nY<_nY) {
			this->nX -= _nVelocityX;
			this->nY+=_nVelocityY;
		}
	}
}

void Camera::TransitionBy(int _nAmountX = 1, int _nAmountY = 1) {
	this->nX += _nAmountX;
	this->nY += _nAmountY;
}

