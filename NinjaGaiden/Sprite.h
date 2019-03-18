#ifndef SPRITE_H
#define SPRITE_H
#include<d3d9.h>
#include<d3dx9.h>
#include"Camera.h"
class Sprite
{
public:
	Sprite(LPDIRECT3DDEVICE9 _lpD3ddv9, Camera* _camera, LPWSTR _lpFileName, int _nCount, int _nFpr, int _nWidth, int _nHeight);
	Sprite(LPDIRECT3DDEVICE9 _lpD3ddv9, Camera * _camera, LPWSTR _lpFileName, int _nCount, int _nFpr, int _nWidth, int _nHeight, D3DCOLOR _transcolor);
	~Sprite();

	int GetIndex() {
		return this->nIndex;
	}
	void SetIndex(int _nIndex) {
		this->nIndex = _nIndex;
	}
	void Draw();
	void SetRotation(float _fRotation);
	void Draw(float _fX, float _fY);
	void Next(int bit);
	void Next(int _index[], int length);
	void Next();
	void SetScale(float _fScale);
	void SetFlip(bool _bFlip);
	void SetCamera(Camera* _camera);
	void SetTranscolor(D3DCOLOR _transcolor) {
		this->transcolor = _transcolor;
	}
	void SetEffectcolor(D3DCOLOR _effectcolor) {
		this->effectcolor = _effectcolor;
	}
private:
	LPDIRECT3DDEVICE9 lpD3ddv9;

	LPD3DXSPRITE lpSpriteHandler;
	LPDIRECT3DTEXTURE9 lpTexture9;

	float fX, fY;
	int nWidth, nHeight;

	int nIndex;
	int nCount;
	int nFpr;
	int bFlip;

	Camera* camera;

	float fRotation;
	float fScale;

	D3DCOLOR transcolor;
	D3DCOLOR effectcolor;

	void LoadTexture(LPWSTR _lpFileName);
};


#endif // !SPRITE_H
