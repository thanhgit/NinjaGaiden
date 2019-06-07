#include "Map.h"
#include"Utils.h"

#include"Ninja.h"

Map::Map()
{
	
}

Map::~Map()
{
	if (map != NULL) {
		for (int i = 0; i < this->nTileTotal; i++) {
			delete map[i];
		}

		delete map;
	}
}

Map::Map(LPDIRECT3DDEVICE9 _d3ddv, Camera* camera, LPWSTR _spriteSheet, LPWSTR _spriteSheet2, char* _fileName)
{
	this->map = nullptr;
	this->recs.clear();
	this->items.clear();
	this->quadtree.clear();
	this->enemies.clear();

	this->camera = camera;
	this->d3ddv = _d3ddv;
}

void Map::Update(DWORD delta)
{
	int startpointcol = (this->camera->GetX()) / Utils::CELL_WIDTH;	
	int startcol = (startpointcol) < 0 ? 0 : startpointcol;

	int startpointrow = (Utils::WORLMAP_HEIGHT - this->camera->GetY()) / Utils::CELL_HEIGHT;
	int startrow = ((startpointrow) < 0 ? 0 : startpointrow) - 1;

	for (int row = 0; row < Utils::VIEWPORT_HEIGHT_COL; row++) {
		for (int col = 0; col < Utils::VIEWPORT_WIDTH_COL; col++) {

			int index = this->arr[(row + startrow) < 0 ? 0 : (row + startrow) ][col + startcol];
			this->imgmap->SetIndex(index);
			this->map[row*Utils::VIEWPORT_WIDTH_COL+col] = this->imgmap;

			float x = (startcol + col)*this->nTileWidth;
			float y = this->camera->GetY() - (row*this->nTileHeight);
			this->map[row*Utils::VIEWPORT_WIDTH_COL+col]->Draw(x,y);
		}
	}

	/*std::list<Static*>::iterator it;
	for (it = this->statics.begin(); it != this->statics.end(); ++it) {
		(*it)->Update();
	}

	std::list<Enemy*>::iterator enemy;
	for (enemy = this->enemies.begin(); enemy != this->enemies.end(); ++enemy) {
		(*enemy)->Update(0);
	}

	std::list<Object*>::iterator rec;
	for (rec = this->recsObj.begin(); rec != this->recsObj.end(); ++rec) {
		(*rec)->Update(0);
	}

	std::list<Item*>::iterator item;
	for (item = this->items.begin(); item != this->items.end(); ++item) {
		(*item)->Update();
	}*/
}

void Map::Draw(float vpx, float vpy)
{
	this->imgmap->SetIndex(15);
	this->imgmap->Draw(vpx, vpy);
}