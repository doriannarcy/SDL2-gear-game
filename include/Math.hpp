#pragma once

#include <iostream>

struct Vector2f
{
    Vector2f();
    Vector2f(float p_x, float p_y);

    void print();

    Vector2f& operator+= (Vector2f const& other);

    float x, y;
};

Vector2f operator+ (Vector2f const& term1, Vector2f const& term2);

struct Color
{
    Color();
    Color(int p_redIntensity, int p_greenIntensity, int p_blueIntensity);
    Color(Color& other);

    void print();

    int redIntensity, greenIntensity, blueIntensity;
};