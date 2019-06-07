#include"RunnerRunRight.h"

RunnerRunRight::RunnerRunRight(RunnerGraphics* _graphics)
{
	this->graphics = _graphics;
}

RunnerRunRight::~RunnerRunRight()
{
}

void RunnerRunRight::update(Box* runner) {
	this->graphics->runRight(runner->GetX(), runner->GetY());

}