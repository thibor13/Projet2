#include "Game.hpp"
#include <iostream>
#include "Particle.hpp"

Game::Game() {
	
}

void Game::processEvent(sf::Event& event, RenderWindow& window) {
	
	switch (event.type) {
	case Event::KeyReleased:
		switch (event.key.code) {
		case Keyboard::Q:
			player.isMovingLeft = false;
			break;
		case Keyboard::D:
			player.isMovingRight = false;
			break;
		case Keyboard::Space:
			float trajectoire = -20;
			bulletManager.BulletPlayerSpawning(trajectoire);
			cout << player.spaceShip.getPosition().x << endl;
			break;
		}
	break;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		player.isMovingLeft = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.isMovingRight = true;
	}
}

void Game::GameDraw(RenderWindow& window) {
	
	window.draw(backGround);
	window.draw(player.spaceShip);
	bulletManager.BulletRender(window);
	ennemyManager.DrawEnnemy(window);
}

void Game::UpdateGame(double dt) {

	player.PlayerUpdate(dt);
	bulletManager.BulletUpdate(dt);
	ennemyManager.UpdateEnnemy(dt);
}

void Game::SetPlayerSprite() {

	player.spaceShip.setScale(Vector2f(0.8f, 0.8f));

	if (!player.ship.loadFromFile("res/SPACESHIP1.PNG"))
		printf("ERR : LOAD FAILED\n");

	player.spaceShip.setOrigin(0.4f, player.spaceShip.getScale().y);
	player.spaceShip.setPosition(640, 630);
	player.spaceShip.setTexture(player.ship);
	player.getScalingPos = player.ship.getSize().x * player.spaceShip.getScale().x;
}

void Game::SetBulletEnemy() {

	bulletManager = BulletManager(this);

	if (!bulletManager.bulletEnnemyTexture1.loadFromFile("res/MOBBULLET.PNG"))
		printf("erreur: bullet1 no load");
}

void Game::SetBulletPlayer() {

	bulletManager = BulletManager(this);

	if (!bulletManager.bulletTexture.loadFromFile("res/BULLET.PNG"))
		printf("erreur: bullet texture fail load\n");
}

void Game::SetEnnemies() {

	ennemyManager = EnnemyManager(this);

	if(!ennemyManager.ennemyTex1.loadFromFile("res/SHIP1.PNG"))
		printf("erreur: ennemy1 texture fail load\n");
	if (!ennemyManager.ennemyTex2.loadFromFile("res/SHIP2.PNG"))
		printf("erreur: ennemy2 texture fail load\n");
	if (!ennemyManager.ennemyTex3.loadFromFile("res/SHIP3.PNG"))
		printf("erreur: ennemy3 texture fail load\n");
	if (!ennemyManager.ennemyTex4.loadFromFile("res/SHIP4.PNG"))
		printf("erreur: ennemy4 texture fail load\n");
}

void Game::SetBg() {

	backGround = RectangleShape(Vector2f(1280, 720));

	if (!bg.loadFromFile("res/BG.JPG"))
		printf("ERR : LOAD FAILED\n");

	backGround.setTexture(&bg);
}

void Game::CreatesExplode(Vector2f enePos, Color little)
{
	for (int i = 0; i < 100; i++)
	{
		Particles p;
		p.x = enePos.x;
		p.y = enePos.y;

		float x = ((float)rand() / (float)(RAND_MAX)) * (1 - rand() % 3);
		float y = ((float)rand() / (float)(RAND_MAX)) * (1 - rand() % 3);
		p.dx = x * 1000.0;
		p.dy = y * 1000.0;
		p.el.setFillColor(little);
		boom.push_back(p);
	}
}



