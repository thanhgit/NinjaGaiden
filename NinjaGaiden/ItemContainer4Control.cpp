#include"ItemContainer4Control.h"

#include"ItemContainer4RunLeft.h"
#include"ItemContainer4RunRight.h"

#include<typeinfo>

ItemContainer4Control::ItemContainer4Control(ItemContainer4Graphics * _graphics, ItemContainer4State * itemContainer4tate, Box * itemContainer4)
{
	this->graphics = _graphics;
	this->itemContainer4 = itemContainer4;
	this->state = itemContainer4tate;
	this->state->update(this->itemContainer4);
}

ItemContainer4Control::ItemContainer4Control(ItemContainer4State* _state, Box* _itemContainer4)
{
	this->itemContainer4 = _itemContainer4;
	this->state = _state;
	this->state->update(this->itemContainer4);
}

ItemContainer4Control::~ItemContainer4Control()
{
}

void ItemContainer4Control::changeState(ItemContainer4State * _state, Box* _itemContainer4)
{

	this->itemContainer4 = _itemContainer4;
	this->state = _state;
	if (SameType(new ItemContainer4RunLeft()) || SameType(new ItemContainer4RunRight())) {
		if (this->indexRun > 2) {
			this->indexRun = 0;
			if (SameType(new ItemContainer4RunLeft())) {
				this->state = new ItemContainer4RunLeft(this->graphics);
			}
			else {
				this->state = new ItemContainer4RunRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(Utils::ANIMATE_TIME);
		}
	}

	this->state->update(this->itemContainer4);
}

ItemContainer4State * ItemContainer4Control::getState()
{
	return this->state;
}

bool ItemContainer4Control::SameType(ItemContainer4State * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}