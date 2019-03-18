#include"Audio.h"

Audio::Audio()
{
	this->dSound = new CSoundManager();
}

Audio::~Audio()
{
}

void Audio::InitAudio(HWND _hWnd) {
	if (this->dSound->Initialize(_hWnd, DSSCL_PRIORITY) != DS_OK) {
		MessageBox(NULL, L"Error Initialize", L"Error", MB_OK);
	}

	if (this->dSound->SetPrimaryBufferFormat(2, 2205, 16) != DS_OK) {
		MessageBox(NULL, L"Error SetPrimaryBufferFormat", L"Error", MB_OK);
	}
}

void Audio::LoadAudio(LPTSTR _lpFileName) {
	if (this->dSound->Create(&sound, _lpFileName)!=DS_OK) {
		MessageBox(NULL, L"Error Create", L"Error", MB_OK);
	}
}

void Audio::PlayAudio() {
	this->sound->Play();
}

void Audio::StopAudio() {
	this->sound->Stop();
}

void Audio::LoopAudio() {
	this->sound->Play(0,DSBPLAY_LOOPING);
}