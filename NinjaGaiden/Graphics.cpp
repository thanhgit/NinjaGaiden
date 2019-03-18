#include"Graphics.h"
#include"Utils.h"

Utils utils;
Graphics::Graphics()
{
	this->lpD3d9 = NULL;
	this->lpD3ddv9 = NULL;
	this->lpBackbuffer = NULL;
	this->camera = new Camera(0, 240);
}

Graphics::~Graphics()
{
	if (this->lpBackbuffer)
		this->lpBackbuffer->Release();

	if (this->lpD3ddv9)
		this->lpD3ddv9->Release();

	if (this->lpD3d9)
		this->lpD3ddv9->Release();

}

void Graphics::InitGraphics(HWND _hWnd,int _nWidthScreen,int _nHeightScreen,bool _bFullScreen) {
	this->hWnd = _hWnd;
	this->nWidthScreen = _nWidthScreen;
	this->nHeightScreen = _nHeightScreen;

	this->lpD3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (!this->lpD3d9) {
		MessageBox(NULL, L"ERROR D3D9", L"INFO", MB_OK);
		return;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	if (!_bFullScreen) {
		d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
		d3dpp.Windowed = TRUE;
	}
	else {
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		d3dpp.Windowed = FALSE;
	}

	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = this->nWidthScreen;
	d3dpp.BackBufferHeight = this->nHeightScreen;
	d3dpp.hDeviceWindow = this->hWnd;

	this->lpD3d9->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		this->hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&this->lpD3ddv9);

	if (!this->lpD3ddv9) {
		Utils::CreateMessage(this->hWnd,L"error lpD3ddv9",L"error");
		return;
	}

	this->lpD3ddv9->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &this->lpBackbuffer);
	D3DXCreateSprite(this->lpD3ddv9, &this->lpSpriteHandler);
}

void Graphics::RunGraphics(DWORD delta) {
	if (!this->lpD3ddv9) {
		Utils::CreateMessage(this->hWnd, L"error d3ddevice", L"error");
		return;
	}
	this->lpD3ddv9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	this->lpD3ddv9->BeginScene();

	UpdateGraphics(delta);

	this->lpD3ddv9->EndScene();

	this->lpD3ddv9->Present(0, 0, 0, 0);
}

LPDIRECT3DDEVICE9 Graphics::GetDevice()
{
	return this->lpD3ddv9;
}

Camera * Graphics::GetCamera()
{
	return this->camera;
}

LPDIRECT3DSURFACE9 Graphics::GetBackBuffer()
{
	return this->lpBackbuffer;
}

HWND Graphics::GetHwnd()
{
	return this->hWnd;
}

void Graphics::SetHwnd(HWND _hWnd)
{
	this->hWnd = _hWnd;
}
