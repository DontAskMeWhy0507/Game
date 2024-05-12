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
    Vector2D* GetMousePosition(){return m_MousePosition;}
    bool GetMouseButtonDown() {return m_MouseButtonStates;}



    //bool DaClick(int vitrix, int vitriy, SDL_Event event, Uint8 button, int width, int height);



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

    int MouseX, MouseY;
    float m_KeyDownTime ;
    Vector2D* m_MousePosition;
    SDL_Scancode m_LastKeyDown;
    bool m_MouseButtonStates;


};

#endif // INPUT_H
