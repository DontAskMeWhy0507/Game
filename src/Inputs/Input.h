#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"
#include <vector>
#include "Vector2D.h"

class Input
{
public:
    static Input* GetInstance()
    {
        if (s_Instance == nullptr)
            s_Instance = new Input();
        return s_Instance;
    }

    void Listen(bool Grounded);
    bool GetKeyDown(SDL_Scancode key);
    float GetKeyDownTime(){return m_KeyDownTime;}




private:
    Input();
    void KeyUp();
    void KeyDown();

    // mouse button event
        void MouseMotion(SDL_Event event);
        void MouseButtonUp(SDL_Event event);
        void MouseButtonDown(SDL_Event event);

    const Uint8* m_KeyStates;
    static Input* s_Instance;


    float m_KeyDownTime ;
    SDL_Scancode m_LastKeyDown;


};

#endif // INPUT_H
