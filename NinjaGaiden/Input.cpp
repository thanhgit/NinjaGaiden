#include"Input.h"
#include"Keyboard.h"
#include<typeinfo>
Input::Input()
{
	this->lpDI8 = NULL;
	this->lpDIdv8 = NULL;
}

Input::~Input()
{
	this->lpDIdv8->Unacquire();

	if (this->lpDIdv8)
		this->lpDIdv8->Release();

	if (this->lpDI8)
		this->lpDI8->Release();
}

void Input::InitInput() {
	if (DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void **)&this->lpDI8,
		NULL) != DI_OK) {
		MessageBox(NULL, L"Error InitInput", L"Error", MB_OK);

		/*if (typeid(_input)==typeid(Keyboard)) {
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
				MessageBox(NULL, L"Error InitInput Acquire", L"Error", MB_OK);
			}
		}
		else{
			if (this->lpDI8->CreateDevice(
				GUID_SysMouse,
				&this->lpDIdv8,
				NULL) != DI_OK) {
				MessageBox(NULL, L"Error InitInput CreateDevice", L"Error", MB_OK);
			}

			if (this->lpDIdv8->SetDataFormat(&c_dfDIMouse) != DI_OK) {
				MessageBox(NULL, L"Error InitInput SetDataFormat", L"Error", MB_OK);
			}

			if (this->lpDIdv8->SetCooperativeLevel(_hWnd, DISCL_EXCLUSIVE | DISCL_FOREGROUND) != DI_OK) {
				MessageBox(NULL, L"Error InitInput SetCooperativeLevel", L"Error", MB_OK);
			}

			if (this->lpDIdv8->Acquire() != DI_OK) {
				MessageBox(NULL, L"Error InitInput Acquire", L"Error", MB_OK);
			}
		}*/
	}

}
