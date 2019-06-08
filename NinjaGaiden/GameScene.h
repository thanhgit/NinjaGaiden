#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include"Scene.h"
#include"Map.h"
#include"Object.h"
#include"Sprite.h"
#include"Background.h"
#include"Text.h"
#include"Ninja.h"
#include<ctime>
class GameScene: public Scene
{
public:
	GameScene(LPDIRECT3DDEVICE9 _lpD3dDv, Camera * _camera, HWND _hWnd);
	~GameScene();
	void InitScene();
	void UpdateScene(DWORD delta);
	void ProcessInput();
	void ExitScene();

	virtual void init() = 0;
	virtual void update(DWORD delta) = 0;
	virtual void processInput() = 0;
	virtual void exit() = 0;
protected:
	void SetPlayer(Ninja* _ninja) {
		this->ninja = _ninja;
	}

	void SetEnemy(Enemy* _enemy) {
		this->enemy = _enemy;
	}


	Item* weapon;

	Ninja* ninja;
	Enemy* enemy;

	Sprite* category;
	Sprite* background;

	int m_score;
	Text* txtScore;

	int m_hp_player;
	Text* txtPlayer;
	Sprite** sPlayer;

	int m_hp_enemy;
	Text* txtEnemy;
	Sprite** sEnemy;

	int m_time;
	Text* txtTime;

	int m_stage;
	Text* txtStage;

	int m_heart;
	Text* txtHeart;

	int m_life;
	Text* txtLife;

	clock_t begin;

	void drawHealthPlayer(int value);
	void drawHealthEnemy(int value);
};


#endif // !GAME_SCENE_H
