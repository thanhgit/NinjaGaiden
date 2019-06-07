#include"RunnerControl.h"

#include"RunnerRunLeft.h"
#include"RunnerRunRight.h"

#include<typeinfo>

RunnerControl::RunnerControl(RunnerGraphics * _graphics, RunnerState * runnertate, Box * runner)
{
	this->graphics = _graphics;
	this->runner = runner;
	this->state = runnertate;
	this->state->update(this->runner);
}

RunnerControl::RunnerControl(RunnerState* _state, Box* _runner)
{
	this->runner = _runner;
	this->state = _state;
	this->state->update(this->runner);
}

RunnerControl::~RunnerControl()
{
}

void RunnerControl::changeState(RunnerState * _state, Box* _runner)
{

	this->runner = _runner;
	this->state = _state;
	if (SameType(new RunnerRunLeft()) || SameType(new RunnerRunRight())) {
		if (this->indexRun > 2) {
			this->indexRun = 0;
			if (SameType(new RunnerRunLeft())) {
				this->state = new RunnerRunLeft(this->graphics);
			}
			else {
				this->state = new RunnerRunRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(Utils::ANIMATE_TIME);
		}
	}

	this->state->update(this->runner);
}

RunnerState * RunnerControl::getState()
{
	return this->state;
}

bool RunnerControl::SameType(RunnerState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}