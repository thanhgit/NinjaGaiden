#ifndef BOSS3_STAND_RIGHT
#define BOSS3_STAND_RIGHT
#include"Boss3State.h"
#include"Boss3Graphics.h"

class Boss3StandRight : public Boss3State
{
public:
	Boss3StandRight() {}
	Boss3StandRight(Boss3Graphics*);
	~Boss3StandRight();
	void update(Box* boss3);
private:
	Boss3Graphics* graphics;
};



#endif 
