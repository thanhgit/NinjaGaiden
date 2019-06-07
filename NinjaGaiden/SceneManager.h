#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include"Scene.h"
#include<vector>

class SceneManager
{
public:
	static SceneManager* Instance();

	SceneManager();
	~SceneManager();
	void add(Scene* scene);
	void pop();
	Scene* GetScene(int index);
	Scene* GetSceneCurrent();

private:
	bool SameType(Scene* _scene1,Scene * _scene2);

	static SceneManager* instance;
	vector<Scene*> scenes;
};


#endif // !SCENE_MANAGER_H
