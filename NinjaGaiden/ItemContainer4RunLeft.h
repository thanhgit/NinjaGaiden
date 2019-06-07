#ifndef ITEM_CONTAINER_4_RUN_LEFT
#define ITEM_CONTAINER_4_RUN_LEFT
#include"ItemContainer4State.h"
#include"ItemContainer4Graphics.h"
class ItemContainer4RunLeft : public ItemContainer4State
{
public:
	ItemContainer4RunLeft() {}
	ItemContainer4RunLeft(ItemContainer4Graphics* _graphics);
	~ItemContainer4RunLeft();
	void update(Box* itemContainer4);
private:
	ItemContainer4Graphics * graphics;
};



#endif
