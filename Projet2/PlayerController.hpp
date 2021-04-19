#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class PlayerController {
public:

	
	float speed;
	int hp = 3;
	int score;

	Sprite lisSpr;
	Texture lifetxtu;
	Sprite spaceShip;
	Texture ship;

	Vector2f movePlayer;
	Vector2f posPlayer;
	float getScalingPos = 0.f;

	bool isMovingLeft = false;
	bool isMovingRight = false;

	PlayerController();

	void PlayerUpdate(double dt);
};