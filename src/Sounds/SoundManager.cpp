#include "SoundManager.h"
#include "SDL_mixer.h"
SoundManager* SoundManager::s_Instance = nullptr;

SoundManager::SoundManager(){
    Mix_Init(MIX_INIT_MP3);
    SDL_Init(SDL_INIT_AUDIO);
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
    {
        std::cerr << Mix_GetError() << std::endl;

    }
    SetVolume(10);

}

int SoundManager::LoadMusic(std::string filename)
{
    Mix_Music* Music = Mix_LoadMUS(filename.c_str());
    if (!Music )
    {
        std::cerr <<Mix_GetError() << std::endl;
        return -1;
    }
    filemusic.push_back(Music);
    return filemusic.size()-1;
}
int SoundManager::LoadSound(std::string filename)
{
    Mix_Chunk* m_Effect = Mix_LoadWAV(filename.c_str());
    if (!m_Effect)
    {
        std::cerr << Mix_GetError() << std::endl;
        return -1;
    }
    filesounds.push_back(m_Effect);
    return filesounds.size()-1;
}

void SoundManager::SetVolume (int v)
{
    volume = (MIX_MAX_VOLUME*v)/100;
}

int SoundManager::PlayMusic(int m)
{
    if(Mix_PlayingMusic() == 0)
    {
        Mix_Volume(1,volume);
        Mix_PlayMusic(filemusic[m],-1);
    }
    return 0;
}
int SoundManager::PlaySound(int s)
{
    Mix_Volume(-1,volume);
    //Xử lý tiếng chạy bị lồng vào nhau.
   // if(!Mix_Playing(-1))
    Mix_PlayChannel(-1,filesounds[s],0);
  //  else if(s!=2) Mix_PlayChannel(-1,filesounds[s],0);
    return 0;
}


void SoundManager::quitMixer()
{
    for(int s = 0; s < filesounds.size(); s++)
    {
        Mix_FreeChunk(filesounds[s]);
        filesounds[s] = nullptr;
    }
    for(int s = 0; s < filemusic.size(); s++)
    {
        Mix_FreeMusic(filemusic[s]);
        filemusic[s] = nullptr;
    }
    Mix_Quit();
}

void SoundManager::togglePlay()
{
    if(Mix_PausedMusic() == true){
        Mix_ResumeMusic();
    }
    else {
        Mix_PausedMusic() ;
    }
}






