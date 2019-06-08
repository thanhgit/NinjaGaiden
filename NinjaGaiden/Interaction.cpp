#include"Interaction.h"
#include<typeinfo>
#include"Enemy.h"
#include"Item.h"
#include"Static.h"
#include"Boss.h"

Interaction::Interaction()
{
}

Interaction::~Interaction()
{
}

bool Interaction::DependTypeEnemy(Object * _obj)
{
	Enemy* enemy = (Enemy*)_obj;
	if (enemy != 0) {
		return true;
	}

	return false;
}

bool Interaction::DependTypeItem(Object * _obj)
{
	Item* item = (Item*)_obj;
	if (item != 0) {
		return true;
	}

	return false;
}

bool Interaction::DependTypeStatic(Object * _obj)
{
	Static* statics = (Static*)_obj;
	if (statics != 0) {
		return true;
	}

	return false;
}

bool Interaction::DependTypeBoss(Object * _obj)
{
	Boss* boss = (Boss*)_obj;
	if (boss != 0) {
		return true;
	}

	return false;
}
