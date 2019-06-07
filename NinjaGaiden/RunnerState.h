#ifndef RUNNER_STATE_H
#define RUNNER_STATE_H

#include"Box.h"
class RunnerState
{
public:
	RunnerState();
	~RunnerState();
	virtual void update(Box*) = 0;

};

#endif
