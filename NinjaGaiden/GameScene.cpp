#include"GameScene.h"
// weapon




GameScene::GameScene(LPDIRECT3DDEVICE9 _lpD3dDv, Camera* _camera, HWND _hWnd) :Scene(_lpD3dDv, _camera, _hWnd)
{
	this->m_time = 180;
	this->m_stage = 1;
	this->m_heart = 10;
	this->m_life = 0;
	this->m_hp_player = 16;
	this->m_hp_enemy = 16;
}

GameScene::~GameScene()
{

}
void GameScene::InitScene()
{
	this->background = new Sprite(GetDevice(), new Camera(0, 422), L"data/Resources/blackboard.png", 1, 1, 260, 40);
	this->txtScore = new Text(GetDevice(),NULL, D3DCOLOR_XRGB(255,0,255));
	this->txtPlayer = new Text(GetDevice(), NULL, D3DCOLOR_XRGB(255, 0, 255));
	this->txtEnemy = new Text(GetDevice(), NULL, D3DCOLOR_XRGB(255, 0, 255));
	this->txtTime = new Text(GetDevice(), NULL, D3DCOLOR_XRGB(255, 0, 255));
	this->txtStage = new Text(GetDevice(), NULL, D3DCOLOR_XRGB(255, 0, 255));
	this->txtHeart = new Text(GetDevice(), NULL, D3DCOLOR_XRGB(255, 0, 255));
	this->txtLife = new Text(GetDevice(), NULL, D3DCOLOR_XRGB(255, 0, 255));

	this->category = new Sprite(GetDevice(), new Camera(0, 422), L"data/Resources/heal.png", 3, 3, 5, 8);
	this->sPlayer = (Sprite**)malloc(sizeof(Sprite *)*(16));
	this->sEnemy = (Sprite**)malloc(sizeof(Sprite *)*(16));


	begin = clock();
	this->init();

}

void GameScene::UpdateScene(DWORD delta)
{

	this->update(delta);

	this->background->Draw(0, 342+40);
	char bufferScore[33];
	sprintf(bufferScore, "SCORE-00%d", this->ninja->GetScore());
	this->txtScore->Draw(0, 342+60, bufferScore);

	clock_t end = clock();
	int elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	this->m_time = 180 - elapsed_secs;
	char bufferTime[33];
	sprintf(bufferTime, "TIMER-%d", this->m_time);
	this->txtTime->Draw(0, 342 +50, bufferTime);

	char bufferStage[33];
	sprintf(bufferStage, "STAGE-3-%d", this->m_stage);
	this->txtStage->Draw(120, 342 + 60, bufferStage);

	this->txtPlayer->Draw(120, 342 + 50, "NINJA-");

	char bufferHeat[33];
	sprintf(bufferHeat, "H-%d", this->ninja->GetHeart());
	this->txtHeart->Draw(35, 342 + 38, bufferHeat);

	this->txtEnemy->Draw(120, 342 + 40, "ENEMY-");

	char bufferLife[33];
	sprintf(bufferLife, "P-%d", this->ninja->GetLife());
	this->txtLife->Draw(0, 342 + 38, bufferLife);

	drawHealthEnemy(this->enemy==nullptr?16:this->enemy->GetHP());
	drawHealthPlayer(this->ninja->GetHP());
}

void GameScene::ProcessInput()
{
	if (GetKeyboard()->KeyDown(DIK_1)) {
		this->ninja->revival();
	}
	else if (GetKeyboard()->KeyDown(DIK_2)) {
		this->ninja->save();
	}
	else if (GetKeyboard()->KeyDown(DIK_3)) {
		this->ninja->restore();
	}
	else if (GetKeyboard()->KeyDown(DIK_4)) {
		this->ninja->GetBody()->SetVelocityX(0);
		this->ninja->GetBody()->SetVelocityY(0);
		this->ninja->GetBody()->SetX(3200);
		this->ninja->GetBody()->SetY(300);
	}

	this->processInput();
}

void GameScene::ExitScene()
{
	if (this->sPlayer != NULL) {
		for (int i = 0; i < 16; i++) {
			delete this->sPlayer[i];
		}

		delete this->sPlayer;
	}

	if (this->sEnemy != NULL) {
		for (int i = 0; i < 16; i++) {
			delete this->sEnemy[i];
		}

		delete this->sEnemy;
	}

	this->exit();
}

void GameScene::drawHealthPlayer(int value)
{
	for(int index=0; index<16;index++){
		if (index < value) {
			this->category->SetIndex(0);
			sPlayer[index] = this->category;
		}
		else {
			this->category->SetIndex(1);
			sPlayer[index] = this->category;
		}

		sPlayer[index]->Draw(180 +index*4, 342 + 58);
	}
}

void GameScene::drawHealthEnemy(int value)
{
	for (int index = 0; index<16; index++) {
		if (index < value) {
			this->category->SetIndex(2);
			sEnemy[index] = this->category;
		}
		else {
			this->category->SetIndex(1);
			sEnemy[index] = this->category;
		}

		sEnemy[index]->Draw(180 + index * 4, 342 + 48);
	}
}
