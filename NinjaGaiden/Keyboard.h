#ifndef KEYBOARD_H
#define KEYBOARD_H
#include<Windows.h>
#include<dinput.h>
#define KEYBOARD_BUFFER_SIZE 1024
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	void InputKeyboard(HWND _hWnd);
	void RunKeyboard();
	int KeyDown(int key);
	int KeyUp(int key);
	int KeyPress(int key);
	void SetAcquire(bool _isAcquire) {
		this->isAcquire = _isAcquire;
	}
private:
	char keys[256];
	LPDIRECTINPUT8 lpDI8;
	LPDIRECTINPUTDEVICE8 lpDIdv8;
	HWND hWnd;
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	DIDEVICEOBJECTDATA keyEvent[KEYBOARD_BUFFER_SIZE];
	bool isAcquire;
};


#endif // !KEYBOARD_H
