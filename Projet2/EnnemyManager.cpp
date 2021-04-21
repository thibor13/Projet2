#include "EnnemyManager.hpp"
#include "Game.hpp"
#include <iostream>
#include "BulletManager.hpp"

using namespace std;
using namespace sf;

EnnemyManager::EnnemyManager(Game* _gaming, BulletManager* _bulletMana) {

	gaming = _gaming;
	bulletMana = _bulletMana;
}

void EnnemyManager::chooseTimer(int x, int y) {

	float random = (float)(rand() % 100) / 100.f;
	timer = x + random * (y - x);
}

void EnnemyManager::UpdateEnnemy(float dt) {

	if (vague == 0 && hasSpawned == false) {
		SpawnEnnemy(ennemyTex1, 4, 14, 2, 10, 10.f);
		vague = 1;
		hasSpawned = true;
	}
	else if (ennemies.size() == 0 && vague == 1 && hasSpawned == false) {
		SpawnEnnemy(ennemyTex2, 4, 14, 3, 20, 14.f);
		vague = 2;
		hasSpawned = true;
	}
	else if (ennemies.size() == 0 && vague == 2 && hasSpawned == false) {
		SpawnEnnemy(ennemyTex3, 3, 14, 3, 30, 16.f);
		vague = 3;
		hasSpawned = true;
	}
	else if (ennemies.size() == 0 && vague == 3 && hasSpawned == false) {
		SpawnEnnemy(ennemyTex4, 3, 14, 3, 40, 18.f);
		vague = 4;
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

		if(ennemies[i].hp<=0)
			ennemies.erase(ennemies.begin() + i);
	}

	 
		if (ennemies.size() > 0) {
			//enemy fire
			float time = fireTime.getElapsedTime().asSeconds();
			if (time >= timer) {

				float trajectoire = 20.f;
				Vector2f enemiesPos = ennemies[rand() % (ennemies.size())].ennemy.getPosition();
				if (vague == 1) {
					bulletMana->BulletEnnemySpawning(trajectoire, dt, enemiesPos, bulletEnnemyTexture1, 8.f);
				}
				else if (vague == 2) {
					bulletMana->BulletEnnemySpawning(trajectoire, dt, enemiesPos, bulletEnnemyTexture2, 10.f);
				}
				else if (vague == 3) {
					bulletMana->BulletEnnemySpawning(trajectoire, dt, enemiesPos, bulletEnnemyTexture3, 12.f);
				}
				else if (vague == 4) {
					bulletMana->BulletEnnemySpawning(trajectoire, dt, enemiesPos, bulletEnnemyTexture4, 14.f);
				}
				
				chooseTimer(1.f, 2.f);
				fireTime.restart();
			}
		}
		else if (ennemies.size() == 0) {
			hasSpawned = false;
		}
	
	
}

void EnnemyManager::SpawnEnnemy(Texture &texture, int rows, int numberOfEnemies, int life, int pts, float speedE) {

	Ennemy ennemyClass;
	
	ennemyClass.ennemy.setScale(0.2f, 0.2f);
	ennemyClass.ennemy.setOrigin(0.1f, 0.1f);
	ennemyClass.ennemy.setTexture(texture);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < numberOfEnemies; j++) {

			ennemyClass.ennemy.setPosition(Vector2f(250 + j * 60, 40 + i * 60));
			ennemyClass.hp = life;
			ennemyClass.points = pts;
			ennemyClass.speed = speedE;
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


