#include "BulletManager.hpp"
#include "Game.hpp"

using namespace sf;
using namespace std;

BulletManager::BulletManager(Game *_game) {

	game = _game;
}

void BulletManager::BulletRender(RenderWindow &window) {

	for (Bullet& rendBullets : bullets)
		window.draw(rendBullets.bulletP);
		//game->win->draw(rendBullets.bulletP);
}

void BulletManager::BulletUpdate(float dt) {

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
}

void BulletManager::BulletPlayerSpawning(float& trajectoire) {

	Bullet bullet;

	bullet.bulletP.setScale(0.05f, 0.05f);
	bullet.bulletP.setTexture(bulletTexture);
	bullet.traj = trajectoire;
	bullet.bulletP.setOrigin(0.025f, 0.025f);
	bullet.bulletP.setPosition(game->player.spaceShip.getPosition().x, game->player.spaceShip.getPosition().y); // BIG PROBLEM DE SPAWN 
	bullets.push_back(bullet);
}
	