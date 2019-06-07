#ifndef RUNNER_RUN_RIGHT
#define RUNNER_RUN_RIGHT
#include"RunnerState.h"
#include"RunnerGraphics.h"

class RunnerRunRight : public RunnerState
{
public:
	RunnerRunRight() {}
	RunnerRunRight(RunnerGraphics*);
	~RunnerRunRight();
	void update(Box* runner);
private:
	RunnerGraphics* graphics;
};



#endif 
