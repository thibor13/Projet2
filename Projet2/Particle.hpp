#pragma once
#include "SFML/Graphics.hpp"
#include <functional>

using namespace sf;

class Particles
{
public:
    RectangleShape el;

    float          x = 0.0f;
    float          y = 0.0f;

    float          dx = 0.0f;
    float          dy = 0.0f;

    float          life = 0.5f;

    float          scaleX = 1.0;
    float          scaleY = 1.0;

    bool           destroyed = false;

    Particles()
    {
        el = RectangleShape(Vector2f(3, 3));
        el.setOrigin(1.5f, 1.5f);
        el.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        el.setPosition(x, y);
        life = 1;
    }
    void update(float dt)
    {
        x += dx*dt;
        y += dy*dt;

        el.setPosition(x, y);
        el.setRotation(dt * 3.0);

        life -= dt;

        el.setScale(scaleX, scaleY);
    }
};