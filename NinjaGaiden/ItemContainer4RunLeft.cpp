#include"ItemContainer4RunLeft.h"

ItemContainer4RunLeft::ItemContainer4RunLeft(ItemContainer4Graphics * _graphics)
{
	this->graphics = _graphics;
}

ItemContainer4RunLeft::~ItemContainer4RunLeft()
{

}

void ItemContainer4RunLeft::update(Box* itemContainer4) {
	this->graphics->runLeft(itemContainer4->GetX(), itemContainer4->GetY());
}