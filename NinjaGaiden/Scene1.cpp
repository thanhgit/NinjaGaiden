#include"Scene1.h"
#include"Scene2.h"
#include"Scene3.h"
#include"Static.h"
#include"Item.h"
#include"Map1.h"
#include"SceneManager.h"
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
	this->ninja = new Ninja(GetDevice(), GetCamera(), 50, 55, 16, 32, 0, 0);
	this->ninja->SetKeyboard(this->GetKeyboard());
	this->ninja->setUpdateCamera(true);
	this->SetPlayer(this->ninja);

	//enemies = this->map->GetEnemies();

	this->physics = new PhysicalInteraction(this->ninja);
	this->physics->SetEnemies(enemies);
	this->quadtree = this->map->GetQuadTree();

	list<Object*> listObj;
	physics->SetRecs(this->recs);

	this->m_stage = 1;
	this->m_time = 150;
}

void Scene1::update(DWORD _dt)
{
	if (this->ninja->GetBody()->GetX() > 2048 - this->camera->GetWidth()/2) {
		this->ninja->setUpdateCamera(false);
	}
	else {
		this->ninja->setUpdateCamera(true);
	}

	if (this->ninja->GetBody()->GetX() > 2048) {
		Scene* scene = new Scene2(GetDevice(), GetCamera(), GetHWND());
		scene->SetKeyboard(this->keyboard);
		scene->InitScene();
		SceneManager::Instance()->add(scene);
	}

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
			list<Enemy*> _enemies;
			for (auto obj : this->enemies) {
				if (this->ninja->GetBody()->GetX() - obj->GetBody()->GetX() < 150) {
					_enemies.push_back(obj);
				}
			}

			this->enemies = _enemies;

			this->physics->SetEnemies(this->enemies);
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