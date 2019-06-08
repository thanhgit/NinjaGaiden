#ifndef RUNNER_STATE_H
#define RUNNER_STATE_H
#include"EnemyState.h"
#include"Box.h"
class RunnerState: public EnemyState
{
public:
	RunnerState();
	~RunnerState();
	virtual void update(Box*) = 0;

};

#endif
