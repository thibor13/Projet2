#pragma once
#include <SFML/Graphics.hpp>
#include "BulletManager.hpp"

using namespace std;
using namespace sf;

class Game;
class EnnemyManager {
public:

	class Ennemy {
	public:

		Sprite ennemy;
		int hp;
		int points;
		float speed;
	};

	EnnemyManager() {};
	EnnemyManager(Game* _gaming);

	Game* gaming = nullptr;
	BulletManager bulletManager;

	vector<Ennemy>ennemies;
	bool hasSpawned = false;
	bool isFire = false;

	void UpdateEnnemy(float dt);
	void SpawnEnnemy();
	void DrawEnnemy(RenderWindow& window);
	void move(float dirX, float dirY);
	void CollisionMob();
	void chooseTimer(int x, int y);
	
	bool hitWindow = false;
	int rows = 0;
	int numberOfEnnemies = 0;
	float timer = 0.f;
	//float fireTime = 2.f;

	Clock timeToMove;
	Clock fireTime;

	Texture ennemyTex1;
	Texture ennemyTex2;
	Texture ennemyTex3;
	Texture ennemyTex4;
};