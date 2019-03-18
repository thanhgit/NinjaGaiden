#include"Sprite.h"
#include<math.h>
#define PI 3.14159

Sprite::Sprite(LPDIRECT3DDEVICE9 _lpD3ddv9,Camera* _camera,LPWSTR _lpFileName,int _nCount,int _nFpr,int _nWidth,int _nHeight)
{
	this->lpD3ddv9 = _lpD3ddv9;
	this->camera = &(*_camera);
	this->nCount = _nCount;
	this->nFpr = _nFpr;
	this->nWidth = _nWidth;
	this->nHeight = _nHeight;	
	this->nIndex = 0;
	this->transcolor = D3DCOLOR_XRGB(255, 0, 255);
	this->effectcolor = D3DCOLOR_XRGB(255, 255, 255);
	this->fRotation = 0.0f;
	this->fScale = 0.0f;
	this->bFlip = false;
	//this->source = new SourceSprite();
	//return_data= this->source->readElement("sprite_file.txt", "player");
	LoadTexture(_lpFileName);
}

Sprite::Sprite(LPDIRECT3DDEVICE9 _lpD3ddv9, Camera* _camera, LPWSTR _lpFileName, int _nCount, int _nFpr, int _nWidth, int _nHeight,D3DCOLOR _transcolor)
{
	this->lpD3ddv9 = _lpD3ddv9;
	this->camera = &(*_camera);
	this->nCount = _nCount;
	this->nFpr = _nFpr;
	this->nWidth = _nWidth;
	this->nHeight = _nHeight;
	this->nIndex = 0;
	this->transcolor = transcolor;
	this->effectcolor = D3DCOLOR_XRGB(255, 255, 255);
	this->fRotation = 0.0f;
	this->fScale = -1.0f;
	this->bFlip = false;
	
	LoadTexture(_lpFileName);
}

Sprite::~Sprite()
{
}

void Sprite::Draw() {
	RECT rect;
	rect.left = (this->nIndex%this->nFpr)*this->nWidth;
	rect.right = rect.left + this->nWidth;
	rect.top = (this->nIndex / this->nFpr)*this->nHeight;
	rect.bottom = rect.top + this->nHeight;

	D3DXVECTOR3 center(this->nWidth/2, this->nHeight/2, 0);
	D3DXVECTOR3 position(this->fX + (this->nWidth / 2),(this->fY + (nHeight / 2)), 0);

	D3DXMATRIX mt;
	D3DXMatrixIdentity(&mt);
	mt._22 = -1.0f;
	mt._41 = -camera->GetX();
	mt._42 = camera->GetY();
	D3DXVECTOR4 vp_pos;
	D3DXVec3Transform(&vp_pos, &position, &mt);
	D3DXVECTOR3 p(vp_pos.x, vp_pos.y, 0);

	lpSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	lpSpriteHandler->Draw(
		this->lpTexture9,
		&rect,
		&center,
		&p,
		effectcolor
	);
	lpSpriteHandler->End();

}

void Sprite::SetRotation(float _fRotation) {
	this->fRotation = _fRotation;
}

void Sprite::Draw(float _fX, float _fY) {
	this->fX = _fX;
	this->fY = _fY;
	Draw();
}

void Sprite::Next(int bit) {
	if (this->nIndex == 0 && bit<0) {
		this->nIndex = this->nCount-1;
		return;
	}

	this->nIndex = (this->nIndex + bit) % this->nCount;
}

void Sprite::Next(int _index[],int length) {
	this->Next();
	for (int i = 0; i < length; i++) {
		if (this->nIndex == _index[i]) {
			return;
		}
	}
	this->nIndex = _index[0];
}

void Sprite::Next() {
	Next(1);
}


void Sprite::SetScale(float _fScale) {
	this->fScale = _fScale;
}

void Sprite::SetFlip(bool _bFlip)
{
	this->bFlip = _bFlip;
}

void Sprite::SetCamera(Camera * _camera)
{
	this->camera = _camera;
}

void Sprite::LoadTexture(LPWSTR _lpFileName) {

	if (D3DXCreateSprite(this->lpD3ddv9, &this->lpSpriteHandler)!=D3D_OK) {
		MessageBox(NULL, L"Error Create sprite", L"Error", MB_OK);
	}

	D3DXIMAGE_INFO imageInfo;
	if (D3DXGetImageInfoFromFile(_lpFileName, &imageInfo)!=D3D_OK) {
		MessageBox(NULL, L"Error D3DXGetImageInfoFromFile", L"Error", MB_OK);
	}

	if (D3DXCreateTextureFromFileEx(
		this->lpD3ddv9,
		_lpFileName,
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
		&this->lpTexture9)!=D3D_OK) {
		MessageBox(NULL, L"Error D3DXCreateTextureFromFileEx", L"Error", MB_OK);
	}
}

