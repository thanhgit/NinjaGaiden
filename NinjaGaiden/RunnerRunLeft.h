#ifndef RUNNER_RUN_LEFT
#define RUNNER_RUN_LEFT
#include"RunnerState.h"
#include"RunnerGraphics.h"
class RunnerRunLeft : public RunnerState
{
public:
	RunnerRunLeft() {}
	RunnerRunLeft(RunnerGraphics* _graphics);
	~RunnerRunLeft();
	void update(Box* runner);
private:
	RunnerGraphics * graphics;
};



#endif
