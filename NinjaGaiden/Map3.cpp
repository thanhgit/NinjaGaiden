#include "Map3.h"
#include"Utils.h"
#include"Boss3.h"


Map3::Map3()
{}

Map3::~Map3()
{

}

Map3::Map3(LPDIRECT3DDEVICE9 _d3ddv, Camera* camera, LPWSTR _spriteSheet, LPWSTR _spriteSheet2, char* _fileName)
	: Map(_d3ddv, camera, _spriteSheet, _spriteSheet2, _fileName)
{
	ReadMap("data/map3/map.txt");
	ReadRecs("data/map3/maprecs.txt");
	ReadStatics("data/map3/mapitems.txt");
	ReadEnemies("data/map3/mapenemies.txt");
	ReadQuadtree("data/map3/mapquadtree.txt");
	this->imgmap = new Sprite(this->d3ddv, this->camera, L"data/map3/map.png", 80, 80, 16, 16, D3DCOLOR_XRGB(255, 255, 0));
	this->map = (Sprite**)malloc(sizeof(Sprite *)*(Utils::VIEWPORT_WIDTH_COL*Utils::VIEWPORT_HEIGHT_COL));
}

void Map3::ReadMap(char* _filename)
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

void Map3::ReadRecs(char * _filename)
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

			Box* box = new Box(x, Utils::WORLMAP_HEIGHT - y - height / 2 - 5, width, height, 0, 0);
			this->recs.push_back(box);
			Rec* rec = new Rec(this->d3ddv, this->camera, x, Utils::WORLMAP_HEIGHT - y - height / 2 - 5, width, height, 0, 0);
			this->recsObj.push_back(rec);
		}
	}

	myfile.close();
}

void Map3::ReadStatics(char * _filename)
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
				}
				else if (col == 6) {
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

void Map3::ReadEnemies(char * _fileName)
{
	fstream myfile(_fileName, ios::in);
	string line = "";
	int count = 0;
	int row = 0;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			string raw = line;
			float x = 0;
			float y = 0;
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

			if (type == "zombie") {
				Enemy* obj = new SwordMan(this->d3ddv, this->camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
				this->enemies.push_back(obj);
			}
		}
	}

	myfile.close();
}

void Map3::ReadQuadtree(char * _fileName)
{
	fstream myfile(_fileName, ios::in);
	string line = "";

	if (myfile.is_open()) {
		list<Object*> objs;
		getline(myfile, line);
		QNode* temp = new QNode("1", 0, 0, 0, 0, 0, objs);
		QParse* qparse = new NodeIdLevelParse(line, temp);
		while (getline(myfile, line)) {
			string raw = line;
			switch (qparse->getParseType(raw))
			{
			case NODEID_LEVEL_PARSE:
				this->quadtree.push_back(temp);
				temp = new QNode("1", 0, 0, 0, 0, 0, objs);;
				qparse = new NodeIdLevelParse(raw, temp);
				break;
			case OBJECT_GAME_PARSE:
				qparse = new ObjectGameParse(raw, temp, d3ddv, camera);
				break;
			case REGION_PARSE:
				qparse = new RegionParse(raw, temp);
				break;
			}
		}

		this->quadtree.push_back(temp);
	}

	myfile.close();
}

