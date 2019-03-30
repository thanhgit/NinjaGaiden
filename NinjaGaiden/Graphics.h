#ifndef GRAPHICS_H
#define GRAPHICS_H
#include<d3d9.h>
#include<d3dx9.h>
#include"Background.h"
#include"Camera.h"
class Graphics 
{
public:
	Graphics();
	~Graphics();

	void InitGraphics(HWND _hWnd, int _nWidthScreen, int _nHeightScreen, bool _bFullScreen);
	void RunGraphics(DWORD delta);
	LPDIRECT3DDEVICE9 GetDevice();

	Camera* GetCamera();

	LPDIRECT3DSURFACE9 GetBackBuffer();

	HWND GetHwnd();

	void SetHwnd(HWND _hWnd);

	virtual void UpdateGraphics(DWORD delta)=0;

private:
	LPDIRECT3D9 lpD3d9;
	LPDIRECT3DDEVICE9 lpD3ddv9;
	LPDIRECT3DSURFACE9 lpBackbuffer;

	LPD3DXSPRITE lpSpriteHandler;

	HWND hWnd;
	Camera* camera;
	int nWidthScreen;
	int nHeightScreen;

};


#endif
