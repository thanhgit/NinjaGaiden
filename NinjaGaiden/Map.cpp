#include "Map.h"
#include"Utils.h"

#include"Ninja.h"

Map::Map()
{}

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
	this->camera = camera;
	this->d3ddv = _d3ddv;
	ReadMap("data/map1.txt");
	ReadRecs("data/map1recs.txt");
	ReadStatics("data/map1items.txt");
	ReadEnemies("data/map1enemies.txt");
	this->imgmap = new Sprite(this->d3ddv, this->camera, L"data/map1.png", 80, 80, 16, 16, D3DCOLOR_XRGB(255, 255, 0));
	this->map = (Sprite**)malloc(sizeof(Sprite *)*(Utils::VIEWPORT_WIDTH_COL*Utils::VIEWPORT_HEIGHT_COL));
}

void Map::Update(DWORD delta)
{
	int startpointcol = (this->camera->GetX()) / Utils::CELL_WIDTH;	
	int startcol = (startpointcol) < 0 ? 0 : startpointcol;

	int startpointrow = (Utils::WORLMAP_HEIGHT - this->camera->GetY()) / Utils::CELL_HEIGHT;
	int startrow = ((startpointrow) < 0 ? 0 : startpointrow) - 1;

	for (int row = 0; row < Utils::VIEWPORT_HEIGHT_COL; row++) {
		for (int col = 0; col < Utils::VIEWPORT_WIDTH_COL; col++) {

			int index = this->arr[row + startrow][col + startcol];
			this->imgmap->SetIndex(index);
			this->map[row*Utils::VIEWPORT_WIDTH_COL+col] = this->imgmap;

			float x = (startcol + col)*this->nTileWidth;
			float y = this->camera->GetY() - (row*this->nTileHeight);
			this->map[row*Utils::VIEWPORT_WIDTH_COL+col]->Draw(x,y);
		}
	}

	std::list<Static*>::iterator it;
	for (it = this->statics.begin(); it != this->statics.end(); ++it) {
		(*it)->Update();
	}

	std::list<Enemy*>::iterator enemy;
	for (enemy = this->enemies.begin(); enemy != this->enemies.end(); ++enemy) {
		(*enemy)->Update();
	}

	std::list<Object*>::iterator rec;
	for (rec = this->recsObj.begin(); rec != this->recsObj.end(); ++rec) {
		(*rec)->Update(0);
	}

	/*std::list<Ladder*>::iterator ladder;
	for (ladder = this->ladders.begin(); ladder != this->ladders.end(); ++ladder) {
		(*ladder)->Update();
	}*/

	std::list<Item*>::iterator item;
	for (item = this->items.begin(); item != this->items.end(); ++item) {
		(*item)->Update();
	}
}

void Map::Draw(float vpx, float vpy)
{
	this->imgmap->SetIndex(15);
	this->imgmap->Draw(vpx, vpy);
}


void Map::ReadMap(char* _filename)
{
	fstream myfile(_filename, ios::in);
	string line = "";
	int count = 0;
	int row = 0;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (count == 0) {
				nTileCountWidth = stoi(line.substr(0, line.find_first_of(" ")));
				nTileCountHeight = stoi(line.substr(line.find_first_of(" ") + 1));
				nTileWidth = 16;
				nTileHeight = 16;
			}		
			else if (count > 0) {
				string raw = line;
				for (int col = 0; col < nTileCountWidth; col++) {
					string value = raw.substr(0, raw.find_first_of(" "));
					this->arr[row][col] = stoi(value);
					raw.erase(0, raw.find_first_of(" ") + 1);
				}

				row = row + 1;

			}

			count = count + 1;
		}
	}

	myfile.close();
}

void Map::ReadRecs(char * _filename)
{
	fstream myfile(_filename, ios::in);
	string line = "";
	int count = 0;
	int row = 0;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			string raw = line;
			int x = 0;
			int y = 0;
			int width = 0;
			int height = 0;
			for (int col = 0; col < 6; col++) {
				string value = raw.substr(0, raw.find_first_of(" "));
				if (col == 0) {
					x = stoi(value);
				}
				else if (col == 1) {
					y = stoi(value);
				}
				else if (col == 2) {
					width = stoi(value);
				}
				else if (col == 3) {
					height = stoi(value);
				}
				raw.erase(0, raw.find_first_of(" ") + 1);
			}

			Box* box = new Box(x,Utils::WORLMAP_HEIGHT - y - height/2, width, height, 0, 0);
			this->recs.push_back(box);
			Rec* rec = new Rec(this->d3ddv, this->camera, x, Utils::WORLMAP_HEIGHT - y - height/2 , width, height,0,0);
			this->recsObj.push_back(rec);
		}
	}

	myfile.close();
}

void Map::ReadStatics(char * _filename)
{
	fstream myfile(_filename, ios::in);
	string line = "";
	int count = 0;
	int row = 0;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			string raw = line;
			int x = 0;
			int y = 0;
			int width = 0;
			int height = 0;
			string type = "";
			string itemName = "";
			for (int col = 0; col < 7; col++) {
				string value = raw.substr(0, raw.find_first_of(" "));
				if (col == 0) {
					x = stoi(value);
				}
				else if (col == 1) {
					y = stoi(value);
				}
				else if (col == 2) {
					width = stoi(value);
				}
				else if (col == 3) {
					height = stoi(value);
				}
				else if (col == 5) {
					itemName = value;
				}else if (col == 6) {
					type = value;
				}

				raw.erase(0, raw.find_first_of(" ") + 1);
			}

			/*if (type == "bigfire") {
				Static* obj = new BigFire(this->d3ddv, this->camera, x, Utils::WORLMAP_HEIGHT - y - 10, width, height, 0, 0, itemName);
				this->statics.push_back(obj);
			}*/
		}
	}

	myfile.close();
}


void Map::ReadEnemies(char * _fileName)
{
	fstream myfile(_fileName, ios::in);
	string line = "";
	int count = 0;
	int row = 0;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			string raw = line;
			int x = 0;
			int y = 0;
			int width = 0;
			int height = 0;
			string type = "";
			string itemName = "";
			for (int col = 0; col < 6; col++) {
				string value = raw.substr(0, raw.find_first_of(" "));
				if (col == 0) {
					x = stoi(value);
				}
				else if (col == 1) {
					y = stoi(value);
				}
				else if (col == 2) {
					width = stoi(value);
				}
				else if (col == 3) {
					height = stoi(value);
				}
				else if (col == 5) {
					type = value;
				}

				raw.erase(0, raw.find_first_of(" ") + 1);
			}

			/*if (type == "zombie") {
				Enemy* obj = new Zombie(this->d3ddv, this->camera, x, Utils::WORLMAP_HEIGHT - y , width, height, 0, 0);
				this->enemies.push_back(obj);
			}*/
		}
	}

	myfile.close();
}

