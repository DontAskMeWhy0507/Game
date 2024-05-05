#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>


class Vector2D
{
    public:
      float X,Y;
    public:
        Vector2D(float x=0, float y=0): X(x), Y(y){}

    public:
        //addition +
        inline Vector2D operator+(const Vector2D& v2) const{
            return Vector2D(X+v2.X,Y+v2.Y);
        }
        //difference -
        inline Vector2D operator-(const Vector2D& v2)const{
            return Vector2D(X-v2.Y,Y-v2.Y);
        }

        // addition +=
        inline friend Vector2D operator+=(Vector2D& p1, const Vector2D& p2){
            p1.X += p2.X;
            p1.Y += p2.Y;
            return p1;
        }

        // subtraction -=
        inline friend Vector2D operator-=(Vector2D& p1, const Vector2D& p2){
            p1.X -= p2.X;
            p1.Y -= p2.Y;
            return p1;
        }

        //multiplication*
        inline Vector2D operator*(const float scalar)const{
            return Vector2D(X*scalar,Y*scalar);
        }

        void Log(std::string msg="")
        {
            std::cout<<msg<<"(X Y) = ("<<X<<" "<<Y<<")"<<std::endl;
        }
};

#endif // VECTOR2D_H
