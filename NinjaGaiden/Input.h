#ifndef INPUT_H
#define INPUT_H
#include<dinput.h>
class Input
{
protected:
	Input();
	~Input();
	void InitInput();
	virtual void RunInput() = 0;
protected:
	LPDIRECTINPUT8 lpDI8;
	LPDIRECTINPUTDEVICE8 lpDIdv8;
};


#endif // !INPUT_H
