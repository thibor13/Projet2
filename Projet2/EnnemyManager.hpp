#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include "BulletManager.hpp"

using namespace std;
using namespace sf;

class BulletManager;
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
	EnnemyManager(Game* _gaming, BulletManager *_bulletMana);

	Game* gaming = nullptr;
	BulletManager *bulletMana = nullptr;

	

	vector<Ennemy>ennemies;
	bool hasSpawned = false;
	bool isFire = false;
	int vague = 0;
	bool isDied = false;

	void UpdateEnnemy(float dt);
	void SpawnEnnemy(Texture &texture, int rows, int numberOfEnemies, int life, int pts, float speedE);
	void DrawEnnemy(RenderWindow& window);
	void move(float dirX, float dirY);
	void CollisionMob();
	void chooseTimer(int x, int y);
	
	bool hitWindow = false;
	int rows = 0;
	int numberOfEnemies = 0;
	float timer = 0.f;

	Clock timeToMove;
	Clock fireTime;

	Texture ennemyTex1;
	Texture ennemyTex2;
	Texture ennemyTex3;
	Texture ennemyTex4;

	Texture bulletEnnemyTexture1;
	Texture bulletEnnemyTexture2;
	Texture bulletEnnemyTexture3;
	Texture bulletEnnemyTexture4;

	SoundBuffer sbExplosion;
	Sound explode;
	
};