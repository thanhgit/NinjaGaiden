#ifndef BOSS3_JUMP_LEFT
#define BOSS3_JUMP_LEFT
#include"Boss3State.h"
#include"Boss3Graphics.h"
class Boss3JumpLeft : public Boss3State
{
public:
	Boss3JumpLeft() {}
	Boss3JumpLeft(Boss3Graphics* _graphics);
	~Boss3JumpLeft();
	void update(Box* boss3);
private:
	Boss3Graphics* graphics;
};



#endif
