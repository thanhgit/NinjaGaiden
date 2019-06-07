#ifndef ITEM_CONTAINER_4_RUN_RIGHT
#define ITEM_CONTAINER_4_RUN_RIGHT
#include"ItemContainer4State.h"
#include"ItemContainer4Graphics.h"

class ItemContainer4RunRight : public ItemContainer4State
{
public:
	ItemContainer4RunRight() {}
	ItemContainer4RunRight(ItemContainer4Graphics*);
	~ItemContainer4RunRight();
	void update(Box* itemContainer4);
private:
	ItemContainer4Graphics* graphics;
};



#endif 
