#include "Engine.h"
#include "TextureManager.h"
#include "Input.h"
#include "Warrior.h"
#include "SDL.h"
#include "Timer.h"
#include "MapParser.h"
#include <iostream>
#include "Camera.h"
#include "SoundManager.h"
#include "Vector2D.h"
#include <fstream>

Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;
//SoundManager* SoundManager::s_Instance = nullptr;

bool Engine::Init(){

    if(SDL_Init(SDL_INIT_VIDEO)!=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)!= 0){
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    //để có thể mở rộng game toàn màn hình hoặc thu nhỏ lại tùy ý

    m_Window = SDL_CreateWindow("Soft Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);
    if(m_Window == nullptr){
        SDL_Log("Failed to create Window: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);        //the renderer uses hardware acceleration and the renderer uses hardware acceleration
    if(m_Renderer == nullptr){
        SDL_Log("Failed to create Renderer: %s", SDL_GetError());
        return false;
    }


    if(!MapParser::GetInstance()->Load()){
        std::cout << "Failed to load map" << std::endl;
        return false;
    }

    m_LevelMap = MapParser::GetInstance()->GetMap("level1");

    // load texturere
    TextureManager::GetInstance()->Load("player", "assets/ide.png");
    TextureManager::GetInstance()->Load("player_run", "assets/Run.png");

    TextureManager::GetInstance()->Load("play", "assets/Menu/Play.png");
    TextureManager::GetInstance()->Load("playred", "assets/Menu/Playred.png");

    TextureManager::GetInstance()->Load("load", "assets/Menu/Load.png");
    TextureManager::GetInstance()->Load("loadred", "assets/Menu/Loadred.png");

    TextureManager::GetInstance()->Load("volumeup", "assets/Menu/volumeup.png");
    TextureManager::GetInstance()->Load("volumeupred", "assets/Menu/volumeupred.png");

    TextureManager::GetInstance()->Load("volumedown", "assets/Menu/volumedown.png");
    TextureManager::GetInstance()->Load("volumedownred", "assets/Menu/volumedownred.png");

    TextureManager::GetInstance()->Load("volumemute", "assets/Menu/volumemute.png");
    TextureManager::GetInstance()->Load("volumemutered", "assets/Menu/volumemutered.png");




    TextureManager::GetInstance()->Load("quit", "assets/Menu/Quit.png");
    TextureManager::GetInstance()->Load("quitred", "assets/Menu/Quitred.png");

    TextureManager::GetInstance()->Load("controls", "assets/Menu/Controls.png");
    TextureManager::GetInstance()->Load("controlsred", "assets/Menu/Controlsred.png");
    TextureManager::GetInstance()->Load("controlsin", "assets/Menu/Controlsin.png");

    TextureManager::GetInstance()->Load("Background1", "assets/Images/spring.png");
    TextureManager::GetInstance()->Load("Background2", "assets/Images/he.png");
    TextureManager::GetInstance()->Load("Background3", "assets/Images/thu.png");
    TextureManager::GetInstance()->Load("Background4", "assets/Images/dong.png");
    TextureManager::GetInstance()->Load("Background5", "assets/Images/6.png");
    TextureManager::GetInstance()->Load("Background6", "assets/Images/final.png");

    TextureManager::GetInstance()->Load("Jump", "assets/Jump.png");
    TextureManager::GetInstance()->Load("Fall", "assets/Fall.png");
    TextureManager::GetInstance()->Load("Crouch", "assets/Crouch.png");

    TextureManager::GetInstance()->Load("Menu", "assets/Images/menu.png");


    player = new Warrior (new Properties ("player",300,9330,200,200));       //(Chỉ số id,x,y,width,height)
    //x,y được lưu vào m_Transform. x,y là tọa độ của ảnh trên cửa sổ game


    Camera::GetInstance()->SetTarget(player->GetOrigin());
    //GetOrigin ở trong class GameObject


    //Load Musice
    SoundManager::GetInstance()->LoadMusic("assets/sounds/MainSound.mp3");
    SoundManager::GetInstance()->LoadSound("assets/sounds/JumpSound.wav");
    SoundManager::GetInstance()->LoadSound("assets/sounds/wall.mp3");
    SoundManager::GetInstance()->LoadSound("assets/sounds/Run.mp3");


            SoundManager::GetInstance()->PlayMusic(0);

    //
    State_Game = State::MENU;
    return m_IsRunning = true;
}

void Engine::Events(){
        bool Grounded = player->GetGround();
        Input::GetInstance()->Listen(Grounded);
        if(State_Game == State::MENU)
        {if(Input::GetInstance()->GetMouseButtonDown())
        {
            Vector2D* mouse =  Input::GetInstance()->GetMousePosition();
            if(mouse->X >=100&&mouse->Y>=50&&mouse->X<=400&mouse->Y<=150)
            {
                State_Game = State::GAME;

            }
            if(mouse->X >=100&&mouse->Y>=500&&mouse->X<=400&mouse->Y<=600) m_IsRunning = false;
            if(mouse->X >=100&&mouse->Y>=350&&mouse->X<=400&mouse->Y<=450)
            {

                State_Game = State::CONTROLS;
            }
            if(mouse->X >=100&&mouse->Y>=200&&mouse->X<=400&mouse->Y<=300)
            {
                State_Game = State::CONTINUE;
                    player->change();
            }

        }}
        if(Input::GetInstance()->GetMouseButtonDown())
           {
               Vector2D* mouse =  Input::GetInstance()->GetMousePosition();
               if(mouse->X >=10&&mouse->Y>=10&&mouse->X<=46&mouse->Y<=46&&State_Game == State::CONTROLS)
                {
                    std::cout <<"plus";
                    SoundManager::GetInstance()->PlusVolume(10);
                }
            if(mouse->X >=50&&mouse->Y>=10&&mouse->X<=86&mouse->Y<=46&&State_Game == State::CONTROLS)
                {
                                        std::cout <<"minus";

                    SoundManager::GetInstance()->MinusVolume(10);
                }
            if(mouse->X >=90&&mouse->Y>=10&&mouse->X<=126&mouse->Y<=46&&State_Game == State::CONTROLS)
                {
                                        std::cout <<"mute";

                    SoundManager::GetInstance()->MuteVolume();
                }
           }

        if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN))   State_Game = State::GAME;
        if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_ESCAPE))   State_Game = State::MENU;
}

void Engine::Update(){
    float dt= Timer::GetInstance()->GetDeltaTime();
        Vector2D Test(0,0);
    switch(State_Game)
    {
    case State::MENU:
        //Camera::GetInstance()->SetTarget(&Test);
    break;


    case State::GAME:
        player->Update(dt);
        //Cho nhân vật di chuyển khi có sự kiện từ bàn phím

        //load music
        SoundManager::GetInstance()->PlayMusic(0);
        // float t = Input::GetInstance()->GetKeyDownTime();
        //std::cout<<t<<std::endl;
        //Load map
        m_LevelMap->Update();
        Camera::GetInstance()->Update();
    break;

    case State::CONTINUE:
        player->Update(dt);
        //Cho nhân vật di chuyển khi có sự kiện từ bàn phím

        //load music
        // float t = Input::GetInstance()->GetKeyDownTime();
        //std::cout<<t<<std::endl;
        //Load map
        m_LevelMap->Update();
        Camera::GetInstance()->Update();
    break;

}
}
void Engine::Render(){
            Vector2D* mouse =  Input::GetInstance()->GetMousePosition();

   switch(State_Game)
   {
    case State::GAME:
        SDL_SetRenderDrawColor(m_Renderer, 124, 418, 954, 955);             //Màu nền của gamme
        SDL_RenderClear(m_Renderer);                                        //Xóa bỏ nền đen mặc định gây nhiều lỗi
       /*Load ảnh theo thứ tự nền xong rồi mới nhân vật. Nếu không nhân vật sẽ ở sau nền*/

        TextureManager::GetInstance()->Draw("Background1",0,4250,1504,800);
        TextureManager::GetInstance()->Draw("Background2",0,3450,1504,800);
        TextureManager::GetInstance()->Draw("Background3",0,2650,1504,800);
        TextureManager::GetInstance()->Draw("Background4",0,1850,1504,800);
        TextureManager::GetInstance()->Draw("Background5",0,1050,1504,800);
        TextureManager::GetInstance()->Draw("Background6",0,500,1504,800);


        m_LevelMap->Render();                                           //Tạo map tiled
        // render texture
        player->Draw();                                                     //vẽ player lên trên game
        SDL_RenderPresent(m_Renderer);                                       //Update m_Renderer lên màn hình sau khi nó được tạo mới
    break;



   case State::CONTINUE:
        SDL_SetRenderDrawColor(m_Renderer, 124, 418, 954, 955);             //Màu nền của gamme
        SDL_RenderClear(m_Renderer);                                        //Xóa bỏ nền đen mặc định gây nhiều lỗi
       /*Load ảnh theo thứ tự nền xong rồi mới nhân vật. Nếu không nhân vật sẽ ở sau nền*/

        TextureManager::GetInstance()->Draw("Background1",0,4250,1504,800);
        TextureManager::GetInstance()->Draw("Background2",0,3450,1504,800);
        TextureManager::GetInstance()->Draw("Background3",0,2650,1504,800);
        TextureManager::GetInstance()->Draw("Background4",0,1850,1504,800);
        TextureManager::GetInstance()->Draw("Background5",0,1050,1504,800);
        TextureManager::GetInstance()->Draw("Background6",0,500,1504,800);


        m_LevelMap->Render();                                           //Tạo map tiled
        // render texture
        player->Draw();                                                     //vẽ player lên trên game
        SDL_RenderPresent(m_Renderer);                                       //Update m_Renderer lên màn hình sau khi nó được tạo mới
    break;

            case State::CONTROLS:

             SDL_SetRenderDrawColor(m_Renderer, 124, 418, 954, 955);
            SDL_RenderClear(m_Renderer);
            TextureManager::GetInstance()->DrawMenu("controlsin",0,0,960,640);


             if(mouse->X >=10&&mouse->Y>=10&&mouse->X<=46&mouse->Y<=46&&State_Game == State::CONTROLS)
                {
                    TextureManager::GetInstance()->DrawMenu("volumeupred",10,10,36,36);
                }
                else             TextureManager::GetInstance()->DrawMenu("volumeup",10,10,36,36);

            if(mouse->X >=50&&mouse->Y>=10&&mouse->X<=86&mouse->Y<=46&&State_Game == State::CONTROLS)
                {
                                    TextureManager::GetInstance()->DrawMenu("volumedownred",50,10,36,36);
                }
                else             TextureManager::GetInstance()->DrawMenu("volumedown",50,10,36,36);

            if(mouse->X >=90&&mouse->Y>=10&&mouse->X<=126&mouse->Y<=46&&State_Game == State::CONTROLS)
                {
                                TextureManager::GetInstance()->DrawMenu("volumemutered",90,10,36,36);

                }
                else             TextureManager::GetInstance()->DrawMenu("volumemute",90,10,36,36);






            SDL_RenderPresent(m_Renderer);
        break;
    case State::MENU:
        SDL_SetRenderDrawColor(m_Renderer, 124, 418, 954, 955);
        SDL_RenderClear(m_Renderer);
        TextureManager::GetInstance()->DrawMenu("Menu",0,0,960,640);//vẽ background lên trên texture.(x,y,width,height)

            if(mouse->X >=100&&mouse->Y>=50&&mouse->X<=400&mouse->Y<=150)TextureManager::GetInstance()->DrawMenu("playred",100,50,300,100);
            else    TextureManager::GetInstance()->DrawMenu("play",100,50,300,100);
            if(mouse->X >=100&&mouse->Y>=200&&mouse->X<=400&mouse->Y<=300)TextureManager::GetInstance()->DrawMenu("loadred",100,200,300,100);
            else    TextureManager::GetInstance()->DrawMenu("load",100,200,300,100);
            if(mouse->X >=100&&mouse->Y>=350&&mouse->X<=400&mouse->Y<=450)        TextureManager::GetInstance()->DrawMenu("controlsred",100,350,300,100);
            else    TextureManager::GetInstance()->DrawMenu("controls",100,350,300,100);
            if(mouse->X >=100&&mouse->Y>=500&&mouse->X<=400&mouse->Y<=600)        TextureManager::GetInstance()->DrawMenu("quitred",100,500,300,100);
            else    TextureManager::GetInstance()->DrawMenu("quit",100,500,300,100);

        SDL_RenderPresent(m_Renderer);
        break;
   }

}

bool Engine::Clean(){
    TextureManager::GetInstance()->Clean();         //Clean của TextủeManager
    MapParser::GetInstance()->Clean();              //Clean của MapParser

    SDL_DestroyRenderer(m_Renderer);                //Clean Renderer
    SDL_DestroyWindow(m_Window);                    //Clean Window
    IMG_Quit();                                       //thoát khỏi sdl img
    SDL_Quit();                                     //thoát khỏi sdl

}

void Engine::Quit(){            //dùng trong function Events của class engine. Cốt để thoát khỏi vòng lặp while
    m_IsRunning = false;
}
