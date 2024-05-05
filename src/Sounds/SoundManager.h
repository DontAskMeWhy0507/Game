#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "SDL.h"
#include <string>
#include <vector>
#include <iostream>
#include "SDL_mixer.h"



class SoundManager
{
public:
    static SoundManager* GetInstance() {return s_Instance ? s_Instance : s_Instance = new SoundManager;}

    int LoadMusic(std::string filename);
    int LoadSound(std::string filename);
    void SetVolume(int v);
    int PlayMusic(int m);
    int PlaySound(int s);
    void quitMixer();
    void togglePlay();

private:
    SoundManager();
    std::vector <Mix_Chunk*> filesounds;
    std::vector <Mix_Music*> filemusic;
    static SoundManager* s_Instance;
    int volume;

};

#endif // SOUNDMANAGER_H
