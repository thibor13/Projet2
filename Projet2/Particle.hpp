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

    float          life = 5.0f;

    float          scaleX = 1.0;
    float          scaleY = 1.0;

    bool           destroyed = false;

    Particles()
    {
        el = RectangleShape(Vector2f(8, 8));
        el.setOrigin(4, 4);
        el.setFillColor(Color::Red);
        el.setPosition(x, y);
        life = 20;
    }
    void update(float dt)
    {
        x += dx*dt;
        y += dy*dt;

        el.setPosition(x, y);
        el.setRotation(dt * 3.0);

        life -= dt;

        el.setScale(scaleX, scaleY);
        /*if (life <= 10.0) {
            dx *= 0.98;
            dy = 0.98;
        }/

        if (life <= 20.0) {
            scaleX *= 0.99;
            scaleY = 0.99;
        }
        if (scaleX<0.1 ||scaleY<0.1) {
            destroyed = true;
        }
        /if (el.getGlobalBounds().intersects(ele.getGlobalBounds())
        {

        }*/
    }
};