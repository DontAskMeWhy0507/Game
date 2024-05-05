#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"
#include "SDL_image.h"
#include "GameMap.h"
#include "GameStates.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine {

    public:
        static Engine* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Engine();
        }

        bool Init();        //hàm return m_Isrunning = true nếu khởi tạo xong
        bool Clean();       //Nếu hàm IsFunning return false thì xoá bỏ tất cả
        void Quit();        // thay đổi IsRunning == false

        void Update();     // cập nhật trạng thái của vật thông qua deltaTime
        void Render();      //render các nhân vật,nền và map,...
        void Events();      //đợi sự kiện từ bàn phím

        inline GameMap* GetMap(){return m_LevelMap;}   //return m_LevelMap là map của game
        inline bool IsRunning(){return m_IsRunning;}
        inline SDL_Renderer* GetRenderer(){return m_Renderer;}

        State State_Game;

    private:
        Engine(){}
        bool m_IsRunning;

        GameMap* m_LevelMap;
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        static Engine* s_Instance;
};

#endif // ENGINE_H
