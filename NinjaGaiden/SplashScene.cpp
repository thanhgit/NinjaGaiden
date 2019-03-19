#include"SplashScene.h"
#define CAMERA_VELOCYTY_X 5
#define CAMERA_VELOCYTY_Y 5

SplashScene::SplashScene(LPDIRECT3DDEVICE9 _lpD3dDv, Camera* _camera, HWND _hWnd) :Scene(_lpD3dDv, _camera, _hWnd)
{
	log = new Log();
}

SplashScene::~SplashScene()
{

}
void SplashScene::InitScene()
{
	this->GetCamera()->SetCamera(0, 432);

	log->ShowLog("Khoi tao man hinh");

	this->deltaTime = 0;
}

void SplashScene::UpdateScene(DWORD delta)
{

}

void SplashScene::ProcessInput()
{

}

void SplashScene::ExitScene()
{

}