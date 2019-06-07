#ifndef RUNNER_CONTROL
#define RUNNER_CONTROL

#include"RunnerState.h"
#include"RunnerGraphics.h"
#include"Box.h"
class RunnerControl
{
public:
	RunnerControl(RunnerGraphics* _graphics, RunnerState* runnerState, Box* runner);
	RunnerControl(RunnerState* runnerState, Box* runner);
	~RunnerControl();
	void changeState(RunnerState* runnerState, Box* runner);
	RunnerState* getState();
	bool SameType(RunnerState* _state);

	// run
	int indexRun;

private:
	RunnerState* state;
	Box* runner;

	RunnerGraphics* graphics;

};

#endif
