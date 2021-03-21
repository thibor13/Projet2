#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class PlayerController {
public:

	float speed;
	int hp;
	int score;

	Sprite spaceShip;
	Texture ship;

	Vector2f movePlayer;
	Vector2f posPlayer;

	bool isMovingLeft = false;
	bool isMovingRight = false;

	PlayerController();

	void PlayerUpdate(double dt);
};