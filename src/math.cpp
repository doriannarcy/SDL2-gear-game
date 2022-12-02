// struct Vector2f
// {
//     Vector2f();
//     Vector2f(float p_x, float p_y);

//     void print();

//     float x, y;
// };

#include "Math.hpp"

#include <iostream>

Vector2f::Vector2f()
    : x(0.0f), y(0.0f)
{

}

Vector2f::Vector2f(float p_x, float p_y)
    : x(p_x), y(p_y)
{

}

void Vector2f::print()
{
    std::cout << "Vector2f(" << x << "; " << y << ")" << std::endl;
}