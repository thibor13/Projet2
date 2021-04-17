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

	void UpdateEnnemy(float dt);
	void SpawnEnnemy();
	void DrawEnnemy(RenderWindow& window);
	void move(float dirX, float dirY);
	void CollisionMob();
	
	bool hitWindow = false;
	int rows = 0;
	int numberOfEnnemies = 0;

	Clock timeToMove;

	Texture ennemyTex1;
	Texture ennemyTex2;
	Texture ennemyTex3;
	Texture ennemyTex4;
};