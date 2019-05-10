#include"MyWindows.h"
#include"Utils.h"
MyWindows::MyWindows(HINSTANCE _hInstance, LPTSTR _lpName, int _nCmdShow, int _nWidthScreen, int _nHeightScreen, int _nFps):Graphics()
{
	this->hInstance = _hInstance;
	this->lpName = _lpName;
	this->nCmdShow = _nCmdShow;
	this->nWidthScreen = _nWidthScreen;
	this->nHeightScreen = _nHeightScreen;
	this->nFps = _nFps;
	this->bFullScreen = false;
	this->delta = 0;
}

MyWindows::~MyWindows()
{
}

void MyWindows::Init() {
	MyRegisterClass();
	if (!InitInstance())
		return;

	InitGraphics(this->GetHwnd(),this->nWidthScreen,this->nHeightScreen,this->bFullScreen);
	InitSprite();
	InitInput();
	InitSound();
}

void MyWindows::Run() {
	MSG message;
	DWORD timePerFrame = 1000/this->nFps;
	DWORD start = GetTickCount();
	int done = 0;
	while (!done) {
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			if (message.message == WM_QUIT) {
				done = 1;
			}

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		
		DWORD current = GetTickCount();
		this->delta = (current - start);
		if (this->delta >= timePerFrame) {
			start = current;
			Update(timePerFrame);
		}
		else {			
			Sleep(timePerFrame - this->delta);
		}
	}
}

void MyWindows::Update(DWORD delta) {
	UpdateInput();
	ProcessInput();
	RunGraphics(delta);
	UpdateSound();
}

void MyWindows::UpdateGraphics(DWORD delta) {
	UpdateSprite(delta);
}

void MyWindows::MyRegisterClass() {
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)MyWindows::WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->hInstance;
	wc.hIcon = LoadIcon(this->hInstance, IDI_APPLICATION);
	wc.hCursor = LoadCursor(this->hInstance, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszClassName = this->lpName;
	wc.lpszMenuName = NULL;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);
}

BOOL MyWindows::InitInstance() {
	this->SetHwnd(CreateWindow(
		this->lpName,
		this->lpName,
		(!this->bFullScreen)?WS_OVERLAPPEDWINDOW:(WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP),
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		this->nWidthScreen,
		this->nHeightScreen,
		NULL,
		NULL,
		this->hInstance,
		NULL
	));

	if (!this->GetHwnd())
		return FALSE;

	if (!bFullScreen) {
		RECT ClientRect;
		GetClientRect(this->GetHwnd(), &ClientRect);
		MoveWindow(
			this->GetHwnd(),
			0,
			0,
			this->nWidthScreen + (this->nWidthScreen - ClientRect.right),
			this->nHeightScreen + (this->nHeightScreen - ClientRect.bottom),
			TRUE);
	}

	ShowWindow(this->GetHwnd(), this->nCmdShow);
	UpdateWindow(this->GetHwnd());

	return TRUE;
}
