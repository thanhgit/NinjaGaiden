#include"Scene2.h"
#include"Static.h"
#include"Item.h"
#include"Map2.h"
#define CAMERA_VELOCYTY_X 5
#define CAMERA_VELOCYTY_Y 5

Scene2::Scene2() : GameScene(NULL, NULL, NULL)
{
}

Scene2::Scene2(LPDIRECT3DDEVICE9 _lpD3dDv, Camera* _camera, HWND _hWnd) :GameScene(_lpD3dDv, _camera, _hWnd)
{
	log = new Log();
}

Scene2::~Scene2()
{

}
void Scene2::init()
{
	this->GetCamera()->SetCamera(0, 224);
	this->GetCamera()->SetSize(256, 208);

	map = new Map2(GetDevice(), GetCamera(), NULL, NULL, NULL);
	this->recs = map->GetRecs();

	// player
	this->ninja = new Ninja(GetDevice(), GetCamera(), 30, 200, 16, 32, 0, 0);
	this->ninja->SetKeyboard(this->GetKeyboard());
	this->SetPlayer(this->ninja);

	this->physics = new PhysicalInteraction(this->ninja);
	list<Object*> listObj;
	physics->SetRecs(this->recs);

	stage = 1;
}

void Scene2::update(DWORD delta)
{
	map->Update(delta);
	this->physics->update();

	this->ninja->Update(delta);
}

void Scene2::processInput()
{


}

void Scene2::exit()
{

}