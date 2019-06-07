#ifndef ITEM_CONTAINER_4_STATE_H
#define ITEM_CONTAINER_4_STATE_H

#include"Box.h"
class ItemContainer4State
{
public:
	ItemContainer4State();
	~ItemContainer4State();
	virtual void update(Box*) = 0;
};

#endif
