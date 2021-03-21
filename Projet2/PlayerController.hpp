#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class PlayerController {
public:

	Sprite spaceShip;
	Texture ship;

	float speed;
	int hp;
	int score;

	Vector2f movePlayer;
	Vector2f posPlayer;

	void PlayerDraw(RenderWindow &window);
};