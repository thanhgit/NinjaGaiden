#include "Text.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Text::Text()
{
}

Text::~Text()
{
}

Text::Text(LPDIRECT3DDEVICE9 D3ddv,Camera* camera, D3DCOLOR color)
{
	if (camera == NULL) {
		camera = new Camera(0, 422);
	}

	wordsheet = new Sprite(D3ddv, camera, L"data/Resources/WordSheet.bmp", 256, 16, 8, 8, D3DCOLOR_XRGB(0, 0, 0));
	wordsheet->SetTranscolor(color);
}

void Text::Draw(float x, float y, char* text)
{
	for (int i = 0; i < strlen(text); i++)
	{
		wordsheet->SetIndex(text[i]);
		wordsheet->Draw(x + 8 + i * 8, y + 8);
	}
}

char* Text::itc(int a)
{
	char* str = new char[10];
	//str = _itoa(a, str, 10);
	return str = "";
}