#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerController.hpp"
#include "EnnemyManager.hpp"

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
	BulletManager(Game* _games, PlayerController* _player, EnnemyManager* _enemyManager);

	Game* game = nullptr;
	PlayerController* player = nullptr;
	EnnemyManager* enemyManager = nullptr;

	vector<Bullet> bullets;
	vector<Bullet> enemyBullets;
	float playerBulletSpeed = 5.f;
	float enemyBulletSpeed = 6.f;

	bool isHit = false;
	Clock timeToNextHit;
	double shake = 0.0;

	void BulletPlayerSpawning(float& trajectoire);
	void BulletEnnemySpawning(float& trajectoire, float dt, Vector2f posMob, Texture &texture, float bulletSpeed);
	void BulletRender(RenderWindow& window);
	void BulletUpdate(float dt);
	
	Texture bulletTexture;
	Texture bulletBoss;
};
