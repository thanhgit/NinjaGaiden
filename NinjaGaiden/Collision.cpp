#include"Collision.h"
#include<d3d9.h>

Collision::Collision(Box* _Box)
{
	this->MyBox = _Box;
	this->direction = NONE;
	this->collisionTime = 1.0f;
	this->log = new Log();
}

Collision::~Collision()
{
}

void Collision::collision(Box* other) {

	this->direction = NONE;

	if (this->MyBox->AABBCheck(*other)) {
		float normalX=0.0f, normalY=0.0f;

		this->collisionTime = this->MyBox->SweptAABB(*other,normalX,normalY);
		this->log->ShowLog("collision time ", this->collisionTime);
		if (this->collisionTime <= 1.0f) {
			this->log->ShowLog("......................");
			this->log->ShowLog("Object move:");
			this->log->ShowLog("X= ", this->MyBox->GetX());
			this->log->ShowLog("Y= ", this->MyBox->GetY());
			this->log->ShowLog("Vx= " ,this->MyBox->GetVelocityX());
			this->log->ShowLog("Vy= ", this->MyBox->GetVelocityY());
			this->log->ShowLog("width= ", this->MyBox->GetWidth());
			this->log->ShowLog("height= ", this->MyBox->GetHeight());
			this->log->ShowLog("......................");
			this->log->ShowLog("......................");
			this->log->ShowLog("Object static:");
			this->log->ShowLog("X= ", other->GetX());
			this->log->ShowLog("Y= ", other->GetY());
			this->log->ShowLog("Vx= ", other->GetVelocityX());
			this->log->ShowLog("Vy= ", other->GetVelocityY());
			this->log->ShowLog("width= ", other->GetWidth());
			this->log->ShowLog("height= ", other->GetHeight());
			this->log->ShowLog("......................");
			this->log->ShowLog("Time collision ", collisionTime);
			if (normalX == 1.0f && normalY == 0.0f) {
				this->direction = LEFT;
				this->log->ShowLog("Va cham ben trai");
			}else if (normalX == -1.0f && normalY == 0.0f) {
				this->direction = RIGHT;
				this->log->ShowLog("Va cham ben phai");
			}
			else if (normalX == 0.0f && normalY == 1.0f) {
				this->direction = DOWN;
				this->log->ShowLog("Va cham ben duoi");
			}
			else if (normalX == 0.0f && normalY == -1.0f) {
				this->direction = UP;
				this->log->ShowLog("Va cham ben tren");
			}

			this->log->ShowLog("..............................................................................");

		}

	}

	/*this->MyBox->SetX(this->MyBox->GetX() - this->MyBox->GetVelocityX());
	this->MyBox->SetY(this->MyBox->GetY() - this->MyBox->GetVelocityY());*/
}

float Collision::collision(Box other, float& normalX, float& normalY)
{
	if (this->MyBox->AABBCheck(other)) {
		float collisionTime = this->MyBox->SweptAABB(other, normalX, normalY);
		this->MyBox->SetX(this->MyBox->GetX() + collisionTime*this->MyBox->GetVelocityX());
		this->MyBox->SetY(this->MyBox->GetY() + collisionTime*this->MyBox->GetVelocityY());
		if (collisionTime < 1.0f) {
			if (normalX == 1.0f && normalY == 0.0f) {
				MessageBox(NULL, L"X", L"INFOR", MB_OK);
			}
			else if (normalX == -1.0f && normalY == 0.0f) {
				MessageBox(NULL, L"-X", L"INFOR", MB_OK);
			}
			else if (normalX == 0.0f && normalY == 1.0f) {
				MessageBox(NULL, L"Y", L"INFOR", MB_OK);
			}
			else if (normalX == 0.0f && normalY == -1.0f) {
				MessageBox(NULL, L"Y", L"INFOR", MB_OK);
			}

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

