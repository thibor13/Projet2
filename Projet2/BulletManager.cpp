#include "BulletManager.hpp"
#include "Game.hpp"

using namespace sf;
using namespace std;

BulletManager::BulletManager(Game *_game) {

	game = _game;
}

void BulletManager::BulletRender(RenderWindow &window) {

	for (Bullet& rendBullets : bullets) {
		window.draw(rendBullets.bulletP);
	}
		
	/*for (Bullet& rendEnemyBullets : enemyBullets)
		window.draw(rendEnemyBullets.bulletP);*/
}

void BulletManager::BulletUpdate(float dt) {

	//player
	for (int i = bullets.size() - 1; i >= 0; i--) {

		bullets[i].bulletP.setPosition(bullets[i].bulletP.getPosition().x, bullets[i].bulletP.getPosition().y + bullets[i].traj * dt * bulletSpeed);

		Vector2f posBullets = bullets[i].bulletP.getPosition();

		if (bullets[i].isDestroyed == false) {
			if (posBullets.x > 1280 || posBullets.y > 720 || posBullets.x < 0 || posBullets.y < 0) {
				bullets[i].isDestroyed = true;
			}
		}

		if (bullets[i].isDestroyed == true)
			bullets.erase(bullets.begin() + i);
	}

	//enemy
/*	for (int i = enemyBullets.size() - 1; i >= 0; i--) {

		//enemyBullets[i].bulletP.setPosition(enemyBullets[i].bulletP.getPosition().x, enemyBullets[i].bulletP.getPosition().y + enemyBullets[i].traj * dt * bulletSpeed);

		Vector2f posEnemyBullets = enemyBullets[i].bulletP.getPosition();

		if (enemyBullets[i].isDestroyed == false) {
			if (posEnemyBullets.x > 1280 || posEnemyBullets.y > 720 || posEnemyBullets.x < 0 || posEnemyBullets.y < 0)
				enemyBullets[i].isDestroyed = true;
		}

		if (enemyBullets[i].isDestroyed == true)
			enemyBullets.erase(enemyBullets.begin() + i);
	}*/
}

void BulletManager::BulletPlayerSpawning(float& trajectoire) {

	Bullet bullet;

	bullet.bulletP.setScale(0.4f, 0.4f);
	bullet.bulletP.setTexture(bulletTexture);
	bullet.traj = trajectoire;
	bullet.bulletP.setOrigin(0.2f, 0.2f);
	bullet.bulletP.setPosition(game->player.spaceShip.getPosition().x, game->player.spaceShip.getPosition().y); 
	bullets.push_back(bullet);
}

void BulletManager::BulletEnnemySpawning(float& trajectoire, float dt, Vector2f posMob) {

	/*Bullet enemyBullet;

	float fireTime = 0.f;
	fireTime -= dt;

	enemyBullet.bulletP.setScale(0.4f, 0.4f);
	enemyBullet.bulletP.setTexture(bulletEnnemyTexture1);
	enemyBullet.traj = trajectoire;
	enemyBullet.bulletP.setOrigin(0.2f, 0.2f);
	enemyBullet.bulletP.setPosition(posMob);
	enemyBullets.push_back(enemyBullet);*/
}
	