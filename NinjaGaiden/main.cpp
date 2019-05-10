#include<Windows.h>
#include"Game.h"
#include"Utils.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) {
	Game* game = new Game(hInstance, L"Ninja Gaiden", nCmdShow, 256, 208, 60);
	game->Init();
	game->Run();	
	return 1;
}

