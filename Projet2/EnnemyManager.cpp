#include "EnnemyManager.hpp"
#include "Game.hpp"
#include <iostream>

using namespace std;
using namespace sf;

EnnemyManager::EnnemyManager(Game* _gaming) {

	gaming = _gaming;
}

void EnnemyManager::UpdateEnnemy(float dt) {

	if (hasSpawned == false) {
		SpawnEnnemy();
		hasSpawned = true;
	}
	
	Time t = timeToMove.getElapsedTime();
	if (t.asSeconds() >= 0.1) {

		if (hitWindow == false) {

			move(1.f, 0.f);
		}
		else if(hitWindow == true){

			move(-1.f, 0.f);
		}
		timeToMove.restart();

		CollisionMob();
	}

	for (int i = ennemies.size() - 1; i >= 0; i--) {

		float trajectoire = -20.f;
		Vector2f enemiesPos = ennemies[i].ennemy.getPosition();

		//bulletManager.BulletEnnemySpawning(trajectoire, dt, enemiesPos);
	}
}

void EnnemyManager::SpawnEnnemy() {

	Ennemy ennemyClass;
	rows = 3;
	numberOfEnnemies = 14;
	
	ennemyClass.ennemy.setScale(0.2f, 0.2f);
	ennemyClass.ennemy.setOrigin(0.1f, 0.1f);
	ennemyClass.ennemy.setTexture(ennemyTex1);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < numberOfEnnemies; j++) {

			ennemyClass.ennemy.setPosition(Vector2f(250 + j * 60, 40 + i * 60));
			ennemyClass.hp = 100;
			ennemyClass.points = 10;
			ennemyClass.speed = 10.f;
			ennemies.push_back(ennemyClass);
		}
	}
}

void EnnemyManager::move(float dirX, float dirY)
{
	for (int i = ennemies.size() - 1; i >= 0; i--) {
		ennemies[i].ennemy.move(ennemies[i].speed * dirX, ennemies[i].speed * dirY);
	}
}

void EnnemyManager::DrawEnnemy(RenderWindow& window) {

	for (Ennemy& rendEnnemy : ennemies)
		window.draw(rendEnnemy.ennemy);
}

void EnnemyManager::CollisionMob() {

	bool needMove = false;

	//coll ---> move down
	for (Ennemy& ennemiesAr : ennemies) {
		if (ennemiesAr.ennemy.getPosition().x <= 0) {
			
			hitWindow = false;
			needMove = true;
		}
		else if (ennemiesAr.ennemy.getPosition().x >= 1220) {
			
			hitWindow = true;
			needMove = true;
		}
	}

	if (needMove == true) {
		for (int i = ennemies.size() - 1; i >= 0; i--) {
			ennemies[i].ennemy.setPosition(Vector2f(ennemies[i].ennemy.getPosition().x, ennemies[i].ennemy.getPosition().y + 20.f));
		}
	}
}

