#include"RunnerGraphics.h"

RunnerGraphics::RunnerGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->runner = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/runner.png", 4, 4, 17, 33);
}

RunnerGraphics::~RunnerGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void RunnerGraphics::runLeft(float fX, float fY)
{
	int index = this->runner->GetIndex();
	if (index > 1) {
		this->runner->SetIndex(0);
	}

	this->runner->Draw(fX, fY);
	this->runner->Next();
}

void RunnerGraphics::runRight(float fX, float fY)
{
	int index = this->runner->GetIndex();
	if (index <2) {
		this->runner->SetIndex(2);
	}

	this->runner->Draw(fX, fY);
	this->runner->Next();
}
