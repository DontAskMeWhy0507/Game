#include "CollisionHandler.h"
#include "Engine.h"
#include <iostream>
CollisionHandler* CollisionHandler::s_Instance = nullptr;

CollisionHandler::CollisionHandler(){
    m_CollisionLayer = (TileLayer*)Engine::GetInstance()->GetMap()->GetLayers().back();
    m_CollisionTilemap = m_CollisionLayer->GetTileMap();
}

bool CollisionHandler::CheckCollisionGround(SDL_Rect a, SDL_Rect b){
    int aLeft = a.x;
    int aRight = a.x + a.w;
    int aTop = a.y;
    int aBottom = a.y + a.h;

    int bLeft = b.x;
    int bRight = b.x + b.w;
    int bTop = b.y;
    int bBottom = b.y + b.h;



    if(aTop < bBottom) return true;
    return false;
}

bool CollisionHandler::CheckCollisionWall(SDL_Rect a, SDL_Rect b){
     int aLeft = a.x;
    int aRight = a.x + a.w;
    int aTop = a.y;
    int aBottom = a.y + a.h;

    int bLeft = b.x;
    int bRight = b.x + b.w;
    int bTop = b.y;
    int bBottom = b.y + b.h;


    if (aRight > bLeft) return true;
    if (aLeft < bRight) return true;
    return false;
}

bool CollisionHandler::CheckCollisionCeiling(SDL_Rect a, SDL_Rect b){
    int aLeft = a.x;
    int aRight = a.x + a.w;
    int aTop = a.y;
    int aBottom = a.y + a.h;

    int bLeft = b.x;
    int bRight = b.x + b.w;
    int bTop = b.y;
    int bBottom =  b.y + b.h;


    if (aBottom > bTop) return true;
    return false;
}

bool CollisionHandler::MapCollisionGround(SDL_Rect a){
    int tileSize = 16;
    int RowCount = 600;
    int ColCount = 60;

    int left_tile = a.x/tileSize;
    int right_tile = (a.x + a.w)/tileSize;

    int top_tile = a.y/tileSize;
    int bottom_tile = (a.y + a.h)/tileSize;

    if(left_tile < 0) left_tile = 0;
    if(right_tile > ColCount) right_tile = ColCount;

    if(top_tile < 0) top_tile = 0;
    if(bottom_tile > RowCount) bottom_tile = RowCount;

    for(int i = left_tile; i <= right_tile; ++i){
        for(int j = top_tile; j <= bottom_tile; ++j){
            SDL_Rect tileRect = {(i-1)*tileSize, (j-1)*tileSize, tileSize, tileSize};
            if( m_CollisionTilemap[j][i] > 0 && CheckCollisionGround(a, tileRect) ){
                return true;
            }
        }
    }

    return false;
}
bool CollisionHandler::MapCollisionWall(SDL_Rect a){
    int tileSize = 16;
    int RowCount = 600;
    int ColCount = 60;

    int left_tile = a.x/tileSize;
    int right_tile = (a.x + a.w)/tileSize;

    int top_tile = a.y/tileSize;
    int bottom_tile = (a.y + a.h)/tileSize;

    if(left_tile < 0) left_tile = 0;
    if(right_tile > ColCount) right_tile = ColCount;

    if(top_tile < 0) top_tile = 0;
    if(bottom_tile > RowCount) bottom_tile = RowCount;

    for(int i = left_tile; i <= right_tile; ++i){
        for(int j = top_tile; j <= bottom_tile; ++j){
            SDL_Rect tileRect = {(i-1)*tileSize, (j-1)*tileSize, tileSize, tileSize};
            if( m_CollisionTilemap[j][i] > 0 && CheckCollisionWall(a, tileRect) ){
                return true;
            }
        }
    }

    return false;
}

bool CollisionHandler::MapCollisionCeiling(SDL_Rect a){
    int tileSize = 16;
    int RowCount = 600;
    int ColCount = 60;

    int left_tile = a.x/tileSize;
    int right_tile = (a.x + a.w)/tileSize;

    int top_tile = a.y/tileSize;
    int bottom_tile = (a.y + a.h)/tileSize;

    if(left_tile < 0) left_tile = 0;
    if(right_tile > ColCount) right_tile = ColCount;

    if(top_tile < 0) top_tile = 0;
    if(bottom_tile > RowCount) bottom_tile = RowCount;

    for(int i = left_tile; i <= right_tile; ++i){
        for(int j = top_tile; j <= bottom_tile; ++j){
            SDL_Rect tileRect = {(i-1)*tileSize, (j-1)*tileSize, tileSize, tileSize};
            if( m_CollisionTilemap[j][i] > 0 && CheckCollisionCeiling(a, tileRect) ){
                return true;
            }
        }
    }

    return false;
}
