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

Vector2f& Vector2f::operator+= (Vector2f const& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vector2f operator+ (Vector2f const& term1, Vector2f const& term2)
{
    const Vector2f result (term1.x + term2.x, term1.y + term2.y);
    return result;
}

Color::Color()
    : redIntensity(0), greenIntensity(0), blueIntensity(0)
{

}

Color::Color(int p_redIntensity, int p_greenIntensity, int p_blueIntensity)
    : redIntensity(p_redIntensity), greenIntensity(p_greenIntensity), blueIntensity(p_blueIntensity)
{

}

Color::Color(Color& other)
    : redIntensity(other.redIntensity), greenIntensity(other.greenIntensity), blueIntensity(other.blueIntensity)
{
    
}

void Color::print()
{
    std::cout << "ColorRGB(" << redIntensity << "; " << greenIntensity
        << "; " << blueIntensity << ")" << std::endl;
}
