#include"Collision.h"
#include<d3d9.h>

Collision::Collision(Box* _Box)
{
	this->MyBox = _Box;
	this->direction = NONE;
	this->collisionTime = 1.0f;
}

Collision::~Collision()
{
}

void Collision::collision(Box* other) {

	this->direction = NONE;

	if (this->MyBox->AABBCheck(*other)) {
		float normalX = 0.0f, normalY = 0.0f;

		this->collisionTime = this->MyBox->SweptAABB(*other, normalX, normalY);
		if (normalX == 1.0f && normalY == 0.0f) {
			this->direction = LEFT;
		}
		else if (normalX == -1.0f && normalY == 0.0f) {
			this->direction = RIGHT;
		}
		else if (normalX == 0.0f && normalY == 1.0f) {
			this->direction = DOWN;
		}
		else if (normalX == 0.0f && normalY == -1.0f) {
			this->direction = UP;
		}

	}
}

float Collision::collision(Box other, float& normalX, float& normalY)
{
	if (this->MyBox->AABBCheck(other)) {
		float collisionTime = this->MyBox->SweptAABB(other, normalX, normalY);
		this->MyBox->SetX(this->MyBox->GetX() + collisionTime*this->MyBox->GetVelocityX());
		this->MyBox->SetY(this->MyBox->GetY() + collisionTime*this->MyBox->GetVelocityY());
		if (collisionTime < 1.0f) {

			return collisionTime;
		}
	}
	return 1.0f;
}


void Collision::UpdateBody(float _fX, float _fY, float _fVx, float _fVy)
{
	this->MyBox->SetX(_fX);
	this->MyBox->SetY(_fY);
	this->MyBox->SetVelocityX(_fVx);
	this->MyBox->SetVelocityY(_fVy);
}

COLLISION_DIRECTION Collision::GetDirection()
{
	return this->direction;
}

void Collision::SetDirection(COLLISION_DIRECTION _direction)
{
	this->direction = _direction;
}

float Collision::GetCollisonTime()
{
	return this->collisionTime;
}

bool Collision::IsCollition()
{
	bool up = this->direction == UP;
	bool down = this->direction == DOWN;
	bool right = this->direction == RIGHT;
	bool left = this->direction == LEFT;
	if (up || down || right || left) {
		return true;
	}
	else {
		return false;
	}

	return up || down || right || left;
}

