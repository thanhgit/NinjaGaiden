#ifndef CAMERA_H
#define CAMERA_H
#include"Box.h"

class Camera
{
public:
	Camera();
	Camera(int _nX, int _nY);
	~Camera();

	void SetCamera(int _nX, int _nY);
	void TransitionTo(int _nX, int _nY, int _nVelocityX=1, int _nVelocityY=1);
	void TransitionBy(int _nAmountX, int _nAmountY);


	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	Box* GetBox();
	void SetSize(int _nWidth, int _nHeight);

private:
	int nX;
	int nY;
	int nWidth; 
	int nHeight;
};


#endif // !CAMERA_H
