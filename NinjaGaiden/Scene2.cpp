#include"Scene2.h"
#include"Scene3.h"
#include"Scene1.h"
#include"SceneManager.h"
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
	this->ninja = new Ninja(GetDevice(), GetCamera(), 30, 55, 16, 32, 0, 0);
	this->ninja->SetKeyboard(this->GetKeyboard());
	this->ninja->setUpdateCamera(true);
	this->SetPlayer(this->ninja);

	this->physics = new PhysicalInteraction(this->ninja);
	this->physics->SetEnemies(enemies);
	this->quadtree = this->map->GetQuadTree();

	list<Object*> listObj;
	physics->SetRecs(this->recs);

	this->m_stage = 2;
	this->m_time = 150;
}

void Scene2::update(DWORD _dt)
{
	if (this->ninja->GetBody()->GetX() > 3072 - this->camera->GetWidth() / 2) {
		this->ninja->setUpdateCamera(false);
	}
	else {
		this->ninja->setUpdateCamera(true);
	}

	if (this->ninja->GetBody()->GetX() > 3072) {
		Scene* scene = new Scene3(GetDevice(), GetCamera(), GetHWND());
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

void Scene2::processInput()
{
	
}

void Scene2::exit()
{

}