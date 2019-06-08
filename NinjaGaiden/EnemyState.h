#ifndef ENEMY_STATE_H
#define ENEMY_STATE_H
#include"Box.h"
class EnemyState
{
public:
	EnemyState();
	~EnemyState();
	virtual void update(Box*) = 0;
private:

};


#endif // !ENEMY_STATE_H
