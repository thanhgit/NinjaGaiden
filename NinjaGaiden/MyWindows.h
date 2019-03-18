#ifndef MYWINDOWS_H
#define MYWINDOWS_H
#include<Windows.h>
#include"Graphics.h"
class MyWindows:public Graphics
{
public:
	MyWindows(HINSTANCE _hInstance, LPTSTR _lpName, int _nCmdShow, int _nWidthScreen, int _nHeightScreen, int _nRate);
	~MyWindows();

	void Init();
	void Run();
	void Update(DWORD delta);
	void UpdateGraphics(DWORD delta);
	virtual void InitSprite() = 0;
	virtual void UpdateSprite(DWORD delta) = 0;
	virtual void InitInput() = 0;
	virtual void UpdateInput() = 0;
	virtual void InitSound() = 0;
	virtual void UpdateSound() = 0;
	virtual void ProcessInput() = 0;
protected:
	HINSTANCE hInstance;
	DWORD delta;
private:
	LPTSTR lpName;
	int nCmdShow;
	int nWidthScreen;
	int nHeightScreen;
	int nFps;

	bool bFullScreen;

	BOOL InitInstance();
	void MyRegisterClass();


	static LRESULT WinProc(HWND _hWnd, UINT _message, LPARAM _lParam, WPARAM _wParam) {
		if (_message == WM_DESTROY) {
			PostQuitMessage(0);
		}

		return DefWindowProc(_hWnd, _message, _lParam, _wParam);
	}
};


#endif // !MYWINDOWS_H
