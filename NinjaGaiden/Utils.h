#ifndef UTILS_H
#define UTILS_H
#include<Windows.h>
class Utils
{
public:
	const static int WIDTH_SCREEN = 256;
	const static int HEIGHT_SCREEN = 208;

	const static int WORLMAP_WIDTH = 2050;
	const static int WORLMAP_HEIGHT = 208;

	const static int VIEWPORT_WIDTH_COL = 18;
	const static int VIEWPORT_HEIGHT_COL = 14;

	const static int CELL_WIDTH = 16;
	const static int CELL_HEIGHT = 16;

	static void CreateMessage(HWND _hWnd,LPCWSTR _lpText,LPCWSTR _lpCaption,UINT uType=MB_OK) {
		MessageBox(_hWnd, _lpText, _lpCaption, uType);
	}

};

enum COLLISION_DIRECTION
{
	LEFT,
	UP,
	RIGHT,
	DOWN,
	NONE
};

#endif // !UTILS
