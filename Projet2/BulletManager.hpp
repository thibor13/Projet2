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
	float bulletSpeed = 5.f;

	void BulletUpdate();
	void BulletPlayerSpawning(float& trajectoire);
	void BulletEnnemySpawning();
	void BulletRender(RenderWindow& window);
	void BulletUpdate(float dt);
	
	Texture bulletTexture;
	Sprite bulletEnnemy;
	Texture bulletEnnemyTexture;
};
