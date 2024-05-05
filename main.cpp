#include <iostream>
#include "SDL.h"
#include "Engine.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Timer.h"

using namespace std;

int main(int argc, char* argv[]) {

    Engine::GetInstance()->Init(); // Initialize game engine

    //Hàm while để ảnh được render liên tục.
    while(Engine::GetInstance()-> IsRunning()){     //KIEM TRA XEM GAME CO DANG CHAY KHONG
        Engine ::GetInstance()->Events();           //Sự kiện từ người dùng (ví dụ như ấn X để tắt game)
        Engine ::GetInstance()->Update();              //
        Engine ::GetInstance()->Render();               //Render ảnh
        Timer ::GetInstance()->Tick();                  //Khởi tạo lại DeltaTime liên tục

    }


    Engine::GetInstance()->Clean();         //XOA DI SAU KHI CHOI XONG
    return 0;
}
