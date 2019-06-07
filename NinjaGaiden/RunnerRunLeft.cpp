#include"RunnerRunLeft.h"

RunnerRunLeft::RunnerRunLeft(RunnerGraphics * _graphics)
{
	this->graphics = _graphics;
}

RunnerRunLeft::~RunnerRunLeft()
{

}

void RunnerRunLeft::update(Box* runner) {
	this->graphics->runLeft(runner->GetX(), runner->GetY());
}