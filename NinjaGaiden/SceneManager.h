#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include"Scene.h"
#include<list>

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void add(Scene* scene);
	void remove(Scene* scene);
	Scene* GetScene(int index);
private:
	list<Scene*> scenes;
};


#endif // !SCENE_MANAGER_H
