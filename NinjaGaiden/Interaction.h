#ifndef INTERACTION_H
#define INTERACTION_H
#include"Object.h"
class Interaction
{
public:
	Interaction();
	~Interaction();
	virtual void interact()=0;
	bool DependTypeEnemy(Object* _obj);
	bool DependTypeItem(Object* _obj);
	bool DependTypeStatic(Object* _obj);
private:

};
#endif // !INTERACTION_H
