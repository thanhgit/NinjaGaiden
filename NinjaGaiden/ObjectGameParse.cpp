#include"ObjectGameParse.h"

ObjectGameParse::ObjectGameParse(string line, QNode * node, LPDIRECT3DDEVICE9 d3ddv, Camera* camera): QParse(node)
{
	vector<string> strs = split(line);
	int x =std::atoi(strs.at(0).c_str());
	int y = std::atoi(strs.at(1).c_str());
	int width = std::atoi(strs.at(2).c_str());
	int height = std::atoi(strs.at(3).c_str());
	string type = strs.at(4);
	string name = strs.at(5);

	if (name == "swordman") {
		Enemy* obj = new SwordMan(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "dog") {
		Dog* obj = new Dog(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "runner") {
		Runner* obj = new Runner(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "machinegunguy") {
		MachineGunGuy* obj = new MachineGunGuy(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "machinegunguysit") {
		MachineGunGuySit* obj = new MachineGunGuySit(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "birdbrown") {
		BirdBrown* obj = new BirdBrown(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "batbrown") {
		BatBrown* obj = new BatBrown(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "banshee") {
		Banshee* obj = new Banshee(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "bird") {
		Bird* obj = new Bird(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "itemcontainer4") {
		ItemContainer4* obj = new ItemContainer4(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}

	if (name == "boss3") {
		Boss3* obj = new Boss3(d3ddv, camera, x, Utils::WORLMAP_HEIGHT - y, width, height, 0, 0);
		list<Object*> objs = this->node->getRegion()->getObjs();
		objs.push_back(obj);
		this->node->getRegion()->setObjes(objs);
	}
}

ObjectGameParse::~ObjectGameParse()
{
}
