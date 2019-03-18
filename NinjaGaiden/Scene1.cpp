#include"Scene1.h"
#include"Static.h"
#include"Item.h"
#define CAMERA_VELOCYTY_X 5
#define CAMERA_VELOCYTY_Y 5

Scene1::Scene1(LPDIRECT3DDEVICE9 _lpD3dDv,Camera* _camera,HWND _hWnd):GameScene(_lpD3dDv,_camera,_hWnd)
{
	log = new Log();
}

Scene1::~Scene1()
{

}
void Scene1::init()
{
	this->GetCamera()->SetCamera(0, 208+16);
	this->GetCamera()->SetSize(256, 208);

	map = new Map(GetDevice(),GetCamera(),NULL,NULL,NULL);
	this->recs = map->GetRecs();

	// player
	this->ninja = new Ninja(GetDevice(), GetCamera(), 350, 100, 16, 32, 0, 0);
	this->ninja->SetKeyboard(this->GetKeyboard());
	this->SetPlayer(this->ninja);

	this->physics = new PhysicalInteraction(this->ninja);
	list<Object*> listObj;
	physics->SetRecs(this->recs);

	stage = 1;
}

void Scene1::update(DWORD delta)
{
	map->Update(delta);
	this->physics->update();

	this->ninja->Update(delta);
}

void Scene1::processInput()
{

	//if (this->GetKeyboard()->KeyDown(DIK_A)) {
	//	this->GetCamera()->TransitionBy(-15, 0);
	//}
	//else if (this->GetKeyboard()->KeyDown(DIK_D)) {
	//	this->GetCamera()->TransitionBy(15, 0);
	//}
	//else if (this->GetKeyboard()->KeyDown(DIK_W)) {
	//	this->GetCamera()->TransitionBy(0, 15);
	//}
	//else if (this->GetKeyboard()->KeyDown(DIK_S)) {
	//	this->GetCamera()->TransitionBy(0, -15);
	//}

	/*if (this->GetKeyboard()->KeyDown(DIK_P)) {
		log->ShowLog("Keypress","presssed");
		this->GetKeyboard()->SetAcquire(false);
	}*/
}

void Scene1::exit()
{

}