#include"Background.h"
#include<d3dx9.h>
Background::Background(
	LPDIRECT3DDEVICE9 _lpD3Ddv,
	Camera* _camera,
	LPCWSTR _lpFileName,
	int _nWidth,
	int _nHeight)
{
	/*this->lpD3ddv9 = _lpD3Ddv;
	this->camera = _camera;
	this->lpFileName = _lpFileName;
	this->nWidth = _nWidth;
	this->nHeight = _nHeight;
	this->nX = 0;
	this->nY = 0;*/
}

Background::~Background()
{

}

void Background::InitBackground() {
	/*if (D3DXCreateSprite(this->lpD3ddv9, &this->lpSpriteHandler) != D3D_OK) {
		MessageBox(NULL, L"Error Create sprite", L"Error", MB_OK);
	}

	D3DXIMAGE_INFO imageInfo;
	if (D3DXGetImageInfoFromFile(this->lpFileName, &imageInfo) != D3D_OK) {
		MessageBox(NULL, L"Error D3DXGetImageInfoFromFile", L"Error", MB_OK);
	}

	if (D3DXCreateTextureFromFileEx(
		this->lpD3ddv9,
		this->lpFileName,
		imageInfo.Width,
		imageInfo.Height,
		1,
		D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		this->transcolor,
		&imageInfo,
		NULL,
		&this->lpTexture9) != D3D_OK) {
		MessageBox(NULL, L"Error D3DXCreateTextureFromFileEx", L"Error", MB_OK);
	}*/
}


void Background::UpdateBackground() {
	/*RECT rect;
	rect.left = this->nX;
	rect.right = this->nX + 100;
	rect.top = this->nY ;
	rect.bottom = this->nY+100;

	D3DXVECTOR3 center(this->nWidth / 2, this->nHeight / 2, 0);
	D3DXVECTOR3 position(this->nX + (this->nWidth / 2), 600 - this->nY - (nHeight / 2), 0);

	lpSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	D3DXMATRIX output;
	D3DXMatrixTransformation2D(
		&output,
		NULL,
		0.0f,
		NULL,
		NULL,
		0.0f,
		&D3DXVECTOR2(this->camera->GetX(), this->camera->GetY()));
	lpSpriteHandler->SetTransform(&output);
	lpSpriteHandler->Draw(
		this->lpTexture9,
		&rect,
		&center,
		&position,
		transcolor
	);
	lpSpriteHandler->End();*/
}

void Background::SetPosition(int _nX, int _nY) {
	/*this->nX = _nX;
	this->nY = _nY;*/
}