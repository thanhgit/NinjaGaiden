#include"Game.h"
#include"Utils.h"
#include"Scene1.h"
#include<iostream>
using namespace std;
Game::Game(HINSTANCE _hInstance,LPTSTR _lpName,int _nCmdShow,int _nWidthScreen,int _nHeightScreen,int _nFps):MyWindows( _hInstance,  _lpName,  _nCmdShow,  _nWidthScreen,  _nHeightScreen,  _nFps)
{
	
}

Game::~Game()
{

}

void Game::InitInput() {
	if (this->GetHwnd() != NULL) {
		this->scene->GetKeyboard()->InputKeyboard(this->GetHwnd());
	}
}

void Game::UpdateInput() {
	this->scene->GetKeyboard()->RunKeyboard();
}

void Game::ProcessInput() {
	this->scene->ProcessInput();
}

void Game::InitSprite() {
	scene = new Scene1(GetDevice(), GetCamera(), this->GetHwnd());
	this->scene->InitScene();
}

void Game::UpdateSprite(DWORD delta) {	
	this->scene->UpdateScene(delta);
}

void Game::InitSound() {
	if (this->GetHwnd() != NULL) {
		this->scene->GetAudio()->InitAudio(this->GetHwnd());
	}
}

void Game::UpdateSound() {
	
}