#include"SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::add(Scene * scene)
{
	if (scene != nullptr) {
		this->scenes.push_back(scene);
	}
}

void SceneManager::remove(Scene * scene)
{
	if (scene != nullptr) {
		this->scenes.remove(scene);
	}
}

Scene * SceneManager::GetScene(int index)
{
	int lengthOfSceneList = this->scenes.size;
	if (index < lengthOfSceneList) {
		std::list<Scene*>::iterator it = this->scenes.begin();
		std::advance(it, index);
		return *it;
	}

	return nullptr;
}
