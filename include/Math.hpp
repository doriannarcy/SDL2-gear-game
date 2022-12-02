#pragma once

#include <iostream>

struct Vector2f
{
    Vector2f();
    Vector2f(float p_x, float p_y);

    void print();

    float x, y;
};

struct Color
{
    Color();
    Color(int p_redIntensity, int p_greenIntensity, int p_blueIntensity);
    Color(Color& other);

    void print();

    int redIntensity, greenIntensity, blueIntensity;
};