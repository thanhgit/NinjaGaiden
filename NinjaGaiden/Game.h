#ifndef GAME_H
#define GAME_H
#include<Windows.h>
#include"Utils.h"
#include"MyWindows.h"
#include"Sprite.h"
#include"Keyboard.h"
#include"Audio.h"
#include"Background.h"
#include"Camera.h"
#include"Map.h"
#include"SceneManager.h"
#include<list>

class Game :public MyWindows
{
public:
	Game(HINSTANCE _hInstace, LPTSTR _lpName, int _nCmdShow, int _nWidthScreen, int _nHeightScreen, int _nRate);
	~Game();

	void InitInput();
	void InitSprite();
	void InitSound();

	void UpdateSprite(DWORD delta);
	void UpdateInput();
	void UpdateSound();

	void ProcessInput();
private:
	Keyboard* keyboard;
};


#endif
