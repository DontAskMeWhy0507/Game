#include "Input.h"
#include "Engine.h"
#include "Timer.h"
#include <iostream>

Input* Input::s_Instance = nullptr;

Input::Input(){
    m_KeyStates = SDL_GetKeyboardState(nullptr);
    m_KeyDownTime = 0.0f;
    m_MouseButtonStates = false;
    m_MousePosition = new Vector2D();

}




void Input::Listen(bool Grounded){
    SDL_Event event;
    float dt =  Timer ::GetInstance()->GetDeltaTime();
    if (m_KeyStates[SDL_SCANCODE_SPACE]&&Grounded)
                    m_KeyDownTime += 1.25f*dt;

    if(m_KeyDownTime >40.0f) m_KeyDownTime = 0.0f;





    while(SDL_PollEvent(&event)){

         SDL_GetMouseState(&MouseX, &MouseY);
        std::cout <<MouseX<<" "<<MouseY<<std::endl;
        switch(event.type){
            case SDL_QUIT: Engine::GetInstance()->Quit(); break;
            case SDL_KEYDOWN:
                 KeyDown();
                 break;
            case SDL_KEYUP:
                KeyUp();
                 if (!m_KeyStates[SDL_SCANCODE_SPACE])   m_KeyDownTime = 0.0f;//Reset thời gian khi phím được thả ra
                break;

            case SDL_MOUSEBUTTONDOWN: MouseButtonDown(event); break;
            case SDL_MOUSEBUTTONUP: MouseButtonUp(event); break;
            case SDL_MOUSEMOTION: MouseMotion(event); break;

        }
    }



//
}
void Input::MouseMotion(SDL_Event event){
    m_MousePosition->X = event.motion.x;
    m_MousePosition->Y = event.motion.y;
}

void Input::MouseButtonUp(SDL_Event event){
    if(event.button.button == SDL_BUTTON_LEFT)
        m_MouseButtonStates = false;

}

void Input::MouseButtonDown(SDL_Event event){
    if(event.button.button == SDL_BUTTON_LEFT)
        m_MouseButtonStates = true;
}

bool Input::GetKeyDown(SDL_Scancode key){
    if(m_KeyStates[key] == 1) {
        m_LastKeyDown = key;
        return true;
    }
    return false;
}

//m_keyStates là mảng chứa trạng thái của các phím. Ví dụ phím d được ấn thì m_keyStates[SDL_SCANCODE_D] = 1. Còn không thì = 0
void Input::KeyUp(){
    m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::KeyDown(){
    m_KeyStates = SDL_GetKeyboardState(nullptr);
}


