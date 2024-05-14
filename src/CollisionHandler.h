#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "SDL.h"
#include <vector>
#include "TileLayer.h"
#include "GameMap.h"

class CollisionHandler{

    public:
        bool MapCollision(SDL_Rect a);
        bool CheckCollision(SDL_Rect a,SDL_Rect b);

        bool CheckCollisionGround(SDL_Rect a, SDL_Rect b);
        bool MapCollisionGround(SDL_Rect a);

        bool CheckCollisionCeiling(SDL_Rect a, SDL_Rect b);
        bool MapCollisionCeiling(SDL_Rect a);

        bool CheckCollisionWall(SDL_Rect a,SDL_Rect b);
        bool MapCollisionWall(SDL_Rect a);



        inline static CollisionHandler* GetInstance(){ return s_Instance = (s_Instance != nullptr)? s_Instance : new CollisionHandler();}

    private:
        CollisionHandler();
        TileMap m_CollisionTilemap;     // Là vector 2 chiều chứa thông tin về các tile trong map.
        TileLayer* m_CollisionLayer;    //là layer chứ thông tin của map.
        static CollisionHandler* s_Instance;
};

#endif // COLLISIONHANDLER_H
