#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game;
class BulletManager {
public:

	class Bullet {
	public:

		Sprite bulletP;
		float traj;
		bool isDestroyed = false;
		
	};

	BulletManager() {};
	BulletManager(Game* _games);

	Game* game = nullptr;

	vector<Bullet> bullets;
	vector<Bullet> enemyBullets;
	float bulletSpeed = 5.f;

	void BulletPlayerSpawning(float& trajectoire);
	void BulletEnnemySpawning(float& trajectoire, float dt, Vector2f posMob);
	void BulletRender(RenderWindow& window);
	void BulletUpdate(float dt);
	
	Texture bulletTexture;
	Texture bulletEnnemyTexture1;
	Texture bulletEnnemyTexture2;
	Texture bulletEnnemyTexture3;
	Texture bulletBoss;
};
