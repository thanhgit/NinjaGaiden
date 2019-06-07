#include"ItemContainer4RunRight.h"

ItemContainer4RunRight::ItemContainer4RunRight(ItemContainer4Graphics* _graphics)
{
	this->graphics = _graphics;
}

ItemContainer4RunRight::~ItemContainer4RunRight()
{
}

void ItemContainer4RunRight::update(Box* itemContainer4) {
	this->graphics->runRight(itemContainer4->GetX(), itemContainer4->GetY());

}