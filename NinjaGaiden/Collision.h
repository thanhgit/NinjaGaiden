#ifndef COLLISION_H
#define COLLISION_H
#include"Box.h"
#include"Utils.h"
#include"Log.h"
class Collision
{
public:
	Collision(Box * box);
	~Collision();
	void collision(Box* other);
	float collision(Box other, float& normalx, float& normaly);
	void UpdateBody(float _fX, float _fY, float _fVx, float _fVy);
	COLLISION_DIRECTION GetDirection();
	void SetDirection(COLLISION_DIRECTION _direction);
	float GetCollisonTime();
	bool IsCollition();
private:
	Box* MyBox;
	Log* log;
	COLLISION_DIRECTION direction;
	float collisionTime;
};



#endif // !COLLISION_H
