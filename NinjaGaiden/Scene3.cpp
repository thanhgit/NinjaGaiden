#include"Scene3.h"
#include"Static.h"
#include"Item.h"
#include"Map3.h"
#define CAMERA_VELOCYTY_X 5
#define CAMERA_VELOCYTY_Y 5

Scene3::Scene3() : GameScene(NULL, NULL, NULL)
{
}

Scene3::Scene3(LPDIRECT3DDEVICE9 _lpD3dDv, Camera* _camera, HWND _hWnd) :GameScene(_lpD3dDv, _camera, _hWnd)
{
	log = new Log();
}

Scene3::~Scene3()
{

}
void Scene3::init()
{
	this->GetCamera()->SetCamera(0, 224);
	this->GetCamera()->SetSize(256, 208);

	map = new Map3(GetDevice(), GetCamera(), NULL, NULL, NULL);
	this->recs = map->GetRecs();

	// player
	this->ninja = new Ninja(GetDevice(), GetCamera(), 30, 200, 16, 32, 0, 0);
	this->ninja->SetKeyboard(this->GetKeyboard());
	this->ninja->setUpdateCamera(false);
	this->SetPlayer(this->ninja);

	this->physics = new PhysicalInteraction(this->ninja);
	this->physics->SetEnemies(enemies);
	this->quadtree = this->map->GetQuadTree();

	list<Object*> listObj;
	physics->SetRecs(this->recs);

	this->stage = 3;
}

void Scene3::update(DWORD _dt)
{
	map->Update(_dt);
	this->physics->update();

	this->ninja->Update(_dt);

	for (auto node : this->quadtree) {
		if (node->getRegion()->getObjs().size() == 0) {
			continue;
		}
		else if (node->containCamera(camera->GetX(), camera->GetY(), camera->GetWidth(), camera->GetHeight())) {
			for (auto obj : node->getRegion()->getObjs()) {
				Enemy* enemy = (Enemy*)obj;
				this->enemies.push_back(enemy);
			}

			node->getRegion()->clearObjects();

			this->physics->SetEnemies(this->enemies);
			//this->quadtree.remove(node);
		}
	}

	std::list<Enemy*>::iterator enemy;

	for (enemy = this->enemies.begin(); enemy != this->enemies.end(); enemy++) {

		if ((*enemy)->GetBody()->GetY() > 300) {
			this->enemies.remove(*enemy);
		}
		else {
			(*enemy)->Update(_dt);
		}

	}
}

void Scene3::processInput()
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

void Scene3::exit()
{

}