#include"Game.h"
#include"Utils.h"
#include"Scene1.h"
#include"Scene2.h"
#include"Scene3.h"
#include<iostream>
using namespace std;
Game::Game(HINSTANCE _hInstance,LPTSTR _lpName,int _nCmdShow,int _nWidthScreen,int _nHeightScreen,int _nFps):MyWindows( _hInstance,  _lpName,  _nCmdShow,  _nWidthScreen,  _nHeightScreen,  _nFps)
{
	SceneManager::Instance();
	this->keyboard = new Keyboard();
}

Game::~Game()
{

}

void Game::InitInput() {
	if (this->GetHwnd() != NULL) {
		this->keyboard->InputKeyboard(this->GetHwnd());
		//SceneManager::Instance()->GetSceneCurrent()->GetKeyboard()->InputKeyboard(this->GetHwnd());
	}
}

void Game::UpdateInput() {
	if (SceneManager::Instance()->GetSceneCurrent()->GetKeyboard() == NULL) {
		Game::InitInput();
	}

	SceneManager::Instance()->GetSceneCurrent()->GetKeyboard()->RunKeyboard();
}

void Game::ProcessInput() {
	if (this->keyboard->KeyDown(DIK_1)) {
		Scene* scene = new Scene1(GetDevice(), GetCamera(), this->GetHwnd());
		scene->SetKeyboard(this->keyboard);
		scene->InitScene();
		SceneManager::Instance()->add(scene);
	}
	else if (this->keyboard->KeyDown(DIK_2)) {
		Scene* scene = new Scene2(GetDevice(), GetCamera(), this->GetHwnd());
		scene->SetKeyboard(this->keyboard);
		scene->InitScene();
		SceneManager::Instance()->add(scene);
	}
	else if (this->keyboard->KeyDown(DIK_3)) {
		Scene* scene = new Scene3(GetDevice(), GetCamera(), this->GetHwnd());
		scene->SetKeyboard(this->keyboard);
		scene->InitScene();
		SceneManager::Instance()->add(scene);
	}
	SceneManager::Instance()->GetSceneCurrent()->ProcessInput();
}

void Game::InitSprite() {
	Scene* scene1 = new Scene3(GetDevice(), GetCamera(), this->GetHwnd());
	scene1->SetKeyboard(this->keyboard);
	scene1->InitScene();
	SceneManager::Instance()->add(scene1);
}

void Game::UpdateSprite(DWORD delta) {	
	SceneManager::Instance()->GetSceneCurrent()->UpdateScene(delta);
}

void Game::InitSound() {
	if (this->GetHwnd() != NULL) {
		SceneManager::Instance()->GetSceneCurrent()->GetAudio()->InitAudio(this->GetHwnd());
	}
}

void Game::UpdateSound() {
	
}