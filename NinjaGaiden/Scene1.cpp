#include"Scene1.h"
#include"Static.h"
#include"Item.h"
#include"Map1.h"
#define CAMERA_VELOCYTY_X 5
#define CAMERA_VELOCYTY_Y 5

Scene1::Scene1() : GameScene(NULL, NULL, NULL)
{
}

Scene1::Scene1(LPDIRECT3DDEVICE9 _lpD3dDv,Camera* _camera,HWND _hWnd):GameScene(_lpD3dDv,_camera,_hWnd)
{
	log = new Log();
}

Scene1::~Scene1()
{

}
void Scene1::init()
{
	this->GetCamera()->SetCamera(0, 224);
	this->GetCamera()->SetSize(256, 208);

	map = new Map1(GetDevice(),GetCamera(),NULL,NULL,NULL);
	this->recs = map->GetRecs();

	// player
	this->ninja = new Ninja(GetDevice(), GetCamera(), 30, 200, 16, 32, 0, 0);
	this->ninja->SetKeyboard(this->GetKeyboard());
	this->SetPlayer(this->ninja);

	// sword man
	SwordMan* swordMan;
	swordMan = new SwordMan(GetDevice(), GetCamera(), 100, 200, 16, 32, 0, 0);

	// sword man
	BirdBrown* birdBrown;
	birdBrown = new BirdBrown(GetDevice(), GetCamera(), 50, 100, 17, 25, 0, 0);

	enemies = this->map->GetEnemies();
	enemies.push_back(swordMan);
	enemies.push_back(birdBrown);

	this->physics = new PhysicalInteraction(this->ninja);
	this->physics->SetEnemies(enemies);

	list<Object*> listObj;
	physics->SetRecs(this->recs);

	stage = 1;
}

void Scene1::update(DWORD _dt)
{
	map->Update(_dt);
	this->physics->update();

	this->ninja->Update(_dt);

	std::list<Enemy*>::iterator enemy;
	for (enemy = this->enemies.begin(); enemy != this->enemies.end(); enemy++) {
		(*enemy)->Update(_dt);
	}
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