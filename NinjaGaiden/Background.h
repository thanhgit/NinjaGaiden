#ifndef BACKGROUND_H
#define BACKGROUND_H
#include<d3d9.h>
#include"Camera.h"
class Background
{
public:
	Background(LPDIRECT3DDEVICE9 _lpD3Ddv, Camera * camera, LPCWSTR _lpFileName, int _nWidth, int _nHeight);
	~Background();

	void InitBackground();


	void UpdateBackground();

	void SetPosition(int _nX, int _nY);

private:
	/*LPDIRECT3DDEVICE9 lpD3ddv9;

	LPD3DXSPRITE lpSpriteHandler;

	Camera* camera;
	int nWidth, nHeight;
	int nX, nY;

	D3DXCOLOR transcolor;
	LPDIRECT3DTEXTURE9 lpTexture9;

	LPCWSTR lpFileName;*/
};


#endif // !BACKGROUND_H
