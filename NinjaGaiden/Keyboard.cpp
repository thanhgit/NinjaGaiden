#include"Keyboard.h"


Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
	this->lpDIdv8->Unacquire();

	if (this->lpDIdv8)
		this->lpDIdv8->Release();

	if (this->lpDI8)
		this->lpDI8->Release();
}

void Keyboard::InputKeyboard(HWND _hWnd) {
	this->hWnd = _hWnd;
	this->isAcquire = true;
	if (DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void **)&this->lpDI8,
		NULL) != DI_OK) {
		MessageBox(NULL, L"Error InitInput", L"Error", MB_OK);
	}

	if (this->lpDI8->CreateDevice(
		GUID_SysKeyboard,
		&this->lpDIdv8,
		NULL) != DI_OK) {
		MessageBox(NULL, L"Error InitInput CreateDevice", L"Error", MB_OK);
	}

	if (this->lpDIdv8->SetDataFormat(&c_dfDIKeyboard) != DI_OK) {
		MessageBox(NULL, L"Error InitInput SetDataFormat", L"Error", MB_OK);
	}

	if (this->lpDIdv8->SetCooperativeLevel(_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND) != DI_OK) {
		MessageBox(NULL, L"Error InitInput SetCooperativeLevel", L"Error", MB_OK);
	}

	if (this->lpDIdv8->Acquire() != DI_OK) {
		//MessageBox(NULL, L"Error InitInput SetCooperativeLevel", L"Error", MB_OK);
	}

	DIPROPDWORD dipdw;
	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE;
	this->lpDIdv8->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
}

int Keyboard::KeyDown(int key) {
	return (keys[key] & 0x80);
}

int Keyboard::KeyUp(int key)
{
	return !(keys[key] & 0x80);
}

int Keyboard::KeyPress(int key)
{
	for (DWORD i = 0; i < dwElements; i++) {
		int KeyCode = keyEvent[i].dwOfs;
		int KeyState = keyEvent[i].dwData;
		if ((KeyState & 0x80) > 0) {
			if (key == KeyCode) {
				return 1;
			}
		}
		else {
			if (key == KeyCode) {
				return 0;
			}
		}
	}

	return 0;
}

void Keyboard::RunKeyboard() {
	if (isAcquire) {
		if (this->lpDIdv8->GetDeviceState(sizeof(keys), (LPVOID)&keys) != DI_OK) {
			InputKeyboard(this->hWnd);
			this->lpDIdv8->Acquire();
		}

		this->lpDIdv8->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), keyEvent, &dwElements, 0);
	}
	else {
		this->lpDIdv8->Unacquire();
	}
}