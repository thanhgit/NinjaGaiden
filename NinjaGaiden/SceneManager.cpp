#include"SceneManager.h"
#include"Scene1.h"
#include"Scene2.h"
#include"Scene3.h"
#include<typeinfo>

SceneManager* SceneManager::instance = NULL;

SceneManager * SceneManager::Instance() {
	if (!instance) {
		instance = new SceneManager();
	}

	return instance;
}

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

void SceneManager::pop()
{
	if (this->scenes.size() > 0) {
		this->scenes.pop_back();
	}
}

Scene * SceneManager::GetScene(int index)
{
	int lengthOfSceneList = this->scenes.size();
	if (index < lengthOfSceneList) {
		return this->scenes.at(index);
	}

	return nullptr;
}

Scene * SceneManager::GetSceneCurrent()
{
	int lengthOfSceneList = this->scenes.size();

	return GetScene(lengthOfSceneList-1);
}

bool SceneManager::SameType(Scene * _scene1, Scene * _scene2)
{
	return (typeid(*_scene1) == typeid(*_scene2));
}
