#ifndef BOSS3_STAND_LEFT
#define BOSS3_STAND_LEFT
#include"Boss3State.h"
#include"Boss3Graphics.h"
class Boss3StandLeft : public Boss3State
{
public:
	Boss3StandLeft() {}
	Boss3StandLeft(Boss3Graphics* _graphics);
	~Boss3StandLeft();
	void update(Box* boss3);
private:
	Boss3Graphics * graphics;
};



#endif
