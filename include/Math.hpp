#pragma once

#include <iostream>

struct Vector2f
{
    Vector2f();
    Vector2f(float p_x, float p_y);

    void print();

    float x, y;
};