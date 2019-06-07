#ifndef DOG_RUN_LEFT
#define DOG_RUN_LEFT
#include"DogState.h"
#include"DogGraphics.h"
class DogRunLeft : public DogState
{
public:
	DogRunLeft() {}
	DogRunLeft(DogGraphics* _graphics);
	~DogRunLeft();
	void update(Box* dog);
private:
	DogGraphics * graphics;
};



#endif
