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
		float time = collisionNinja->GetCollisonTime();

		if (collisionNinja->GetDirection() == DOWN) {
			if (this->ninja->IsJumpNormal()) {
				float y = this->ninja->GetBody()->GetY() + time*this->ninja->GetBody()->GetVelocityY() +5;
				this->ninja->normal();
				this->ninja->GetBody()->SetY(y);
			}
			else {
				float y = this->ninja->GetBody()->GetY() + time*this->ninja->GetBody()->GetVelocityY()+5;
				this->ninja->normal();
				this->ninja->GetBody()->SetY(y);
			}

			if (this->ninja->IsJumpParabol()) {
				this->ninja->normal();
			}
		
		}
		else if (collisionNinja->GetDirection() == LEFT) {
			this->ninja->GetBody()->SetX(this->ninja->GetBody()->GetX() + (1 - time) * 16);
		}
		else if (collisionNinja->GetDirection() == RIGHT) {
			this->ninja->GetBody()->SetX(this->ninja->GetBody()->GetX() - (1 - time) * 16);
		}
		else if (collisionNinja->GetDirection() == UP) {
			this->ninja->GetBody()->SetY(this->ninja->GetBody()->GetY() + 25);
		}
	}
}

void ObjectWithMap::EnemiesInteractMap()
{
	std::list<Enemy*>::iterator obj;
	for (obj = this->enemies.begin(); obj != this->enemies.end(); obj++) {
		Collision* collition = new Collision((*obj)->GetBody());
		std::list<Box*>::iterator rec;
		for (rec = this->recs.begin(); rec != this->recs.end(); rec++) {
			collition->collision(*rec);
			if (collition->GetDirection() == DOWN) {
				float time = collition->GetCollisonTime();
				(*obj)->normal();
				float y = (*rec)->GetY() + 40;
				(*obj)->GetBody()->SetY(y);
			}
			else if (collition->GetDirection() == LEFT) {
				float time = collition->GetCollisonTime();
				(*obj)->normal();
				int x = (*rec)->GetX() + 26;
				(*obj)->GetBody()->SetX(x);
				if (DependTypeEnemy(*obj)) {
					Enemy* enemy = (Enemy*)*obj;
					enemy->GetBody()->SetVelocityX(-enemy->GetBody()->GetVelocityX());
				}
			}
			else if (collition->GetDirection() == RIGHT) {
				float time = collition->GetCollisonTime();
				(*obj)->normal();
				int x = (*rec)->GetX() - 26;
				(*obj)->GetBody()->SetX(x);
				if (DependTypeEnemy(*obj)) {
					Enemy* enemy = (Enemy*)*obj;
					enemy->GetBody()->SetVelocityX(-enemy->GetBody()->GetVelocityX());

				}
			}
		}
	}
}

void ObjectWithMap::interact()
{
	NinjaInteractMap();
	EnemiesInteractMap();	
}
