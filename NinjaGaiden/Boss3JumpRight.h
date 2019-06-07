#ifndef BOSS3_JUMP_RIGHT
#define BOSS3_JUMP_RIGHT
#include"Boss3State.h"
#include"Boss3Graphics.h"

class Boss3JumpRight : public Boss3State
{
public:
	Boss3JumpRight() {}
	Boss3JumpRight(Boss3Graphics*);
	~Boss3JumpRight();
	void update(Box* boss3);
private:
	Boss3Graphics* graphics;
};

#endif // !BOSS3_JUMP_LEFT
