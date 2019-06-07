#ifndef DOG_RUN_RIGHT
#define DOG_RUN_RIGHT
#include"DogState.h"
#include"DogGraphics.h"

class DogRunRight : public DogState
{
public:
	DogRunRight() {}
	DogRunRight(DogGraphics*);
	~DogRunRight();
	void update(Box* dog);
private:
	DogGraphics* graphics;
};



#endif 
