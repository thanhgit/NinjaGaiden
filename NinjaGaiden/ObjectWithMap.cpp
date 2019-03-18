#include"ObjectWithMap.h"
#include"Collision.h"
#include"Enemy.h"

ObjectWithMap::ObjectWithMap(Ninja* _ninja):Interaction()
{
	this->ninja = _ninja;
}

ObjectWithMap::~ObjectWithMap()
{
}

void ObjectWithMap::NinjaInteractMap()
{
	Collision* collisionNinja = new Collision(this->ninja->GetBody());
	std::list<Box*>::iterator rec;
	for (rec = this->recs.begin(); rec != this->recs.end(); rec++) {
		collisionNinja->collision(*rec);
		if (collisionNinja->GetDirection() == DOWN) {
			float time = collisionNinja->GetCollisonTime();
			int y = this->ninja->GetBody()->GetY() + time*this->ninja->GetBody()->GetVelocityY()+5;
			this->ninja->normal();
			this->ninja->GetBody()->SetY(y);
		}
	}
}

void ObjectWithMap::interact()
{

	NinjaInteractMap();

	std::list<Object*>::iterator obj;
	for (obj = this->objs.begin(); obj != this->objs.end(); obj++) {
		Collision* collition = new Collision((*obj)->GetBody());
		std::list<Box*>::iterator rec;
		for (rec = this->recs.begin(); rec != this->recs.end(); rec++) {
			collition->collision(*rec);
			if (collition->GetDirection() == DOWN) {
				float time = collition->GetCollisonTime();
				(*obj)->normal();
				int y = (*rec)->GetY() + 26;
				(*obj)->GetBody()->SetY(y);
			} else if(collition->GetDirection() == LEFT) {
				float time = collition->GetCollisonTime();
				(*obj)->normal();
				int x = (*rec)->GetX() + 26;
				(*obj)->GetBody()->SetX(x);
				if (DependTypeEnemy(*obj)) {
					Enemy* enemy = (Enemy*)*obj;
					enemy->changeDirection();
				}
			} else if (collition->GetDirection() == RIGHT) {
				float time = collition->GetCollisonTime();
				(*obj)->normal();
				int x = (*rec)->GetX() - 26;
				(*obj)->GetBody()->SetX(x);
				if (DependTypeEnemy(*obj)) {
					Enemy* enemy = (Enemy*)*obj;
					enemy->changeDirection();
				}
			}
		}
	}
}
