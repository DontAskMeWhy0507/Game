#ifndef GAMESTATES_H
#define GAMESTATES_H
#include "GameObject.h"
enum class State {
    MENU,
    GAME,
    PAUSE,
    CONTINUE,
    QUIT,
    CONTROLS
};
class GameStates:GameObject
{
    public:


        virtual void Draw()=0;
        virtual void Clean()=0;
        virtual void Update(float dt)=0;

    private:
        GameStates();
};

#endif // GAMESTATES_H
