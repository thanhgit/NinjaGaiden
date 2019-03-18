#ifndef AUDIO_H
#define AUDIO_H
#include"dxaudio.h"
class Audio
{
public:
	Audio();
	~Audio();
	void InitAudio(HWND _hWnd);
	void LoadAudio(LPTSTR _lpFileName);
	void PlayAudio();
	void StopAudio();
	void LoopAudio();
private:
	CSoundManager *dSound;
	CSound* sound;
};



#endif // !SOUND_H
