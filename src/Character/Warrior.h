#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"
#include "Collider.h"
#include "Vector2D.h"

#define JUMP_FORCE 13.0f


#define RUN_FORCE 4.0f
#define ATTACK_TIME 20.0f


class Warrior : public Character
{
    public:
        Warrior(Properties* props);

        void Draw() ;
        void Clean() ;
        void Update(float dt) ;
        bool GetGround() {return m_IsGrounded;};

   private:
        void AnimationState();

    private:
        bool m_IsRunning;
        bool m_IsJumping;
        bool m_IsFalling;
        bool m_IsCeiling;
        bool m_IsWall;
        bool m_IsGrounded;
        bool IsJumpRight;
        bool IsJumpLeft;
        bool IsJumpUp;
        bool IsTheKeyReleased;
        bool LastFalling = false;

        float SoMoi, SoCu;
        float luu;
        float m_JumpForce;
        float m_LasDirection = 1.0f;       //0 is fall down, 1 is fall right, -1 is fall left



        Collider* m_Collider;
        Animation* m_Animation;
        Rigidbody* m_RigidBody;
        Vector2D m_LastSafePosition;
};

#endif // WARRIOR_H
