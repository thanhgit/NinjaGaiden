#ifndef ITEM_CONTAINER_4_CONTROL
#define ITEM_CONTAINER_4_CONTROL

#include"ItemContainer4State.h"
#include"ItemContainer4Graphics.h"
#include"Box.h"
class ItemContainer4Control
{
public:
	ItemContainer4Control(ItemContainer4Graphics* _graphics, ItemContainer4State* itemContainer4State, Box* itemContainer4);
	ItemContainer4Control(ItemContainer4State* itemContainer4State, Box* itemContainer4);
	~ItemContainer4Control();
	void changeState(ItemContainer4State* itemContainer4State, Box* itemContainer4);
	ItemContainer4State* getState();
	bool SameType(ItemContainer4State* _state);

	// run
	int indexRun;

private:
	ItemContainer4State* state;
	Box* itemContainer4;

	ItemContainer4Graphics* graphics;

};

#endif
