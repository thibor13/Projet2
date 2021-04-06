#include "Game.hpp"
#include <iostream>

Game::Game() {

	bulletManager = BulletManager(this);
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
		}
	break;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		player.isMovingLeft = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.isMovingRight = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

		//Vector2f trajectoire(player.spaceShip.getPosition().x, -20);
		float trajectoire = -20;
		bulletManager.BulletPlayerSpawning(trajectoire);
		cout << player.spaceShip.getPosition().x << endl;
	}
		
}

void Game::GameDraw(RenderWindow& window) {
	
	window.draw(backGround);
	window.draw(player.spaceShip);
	bulletManager.BulletRender(window);
}

void Game::UpdateGame(double dt) {

	player.PlayerUpdate(dt);
	bulletManager.BulletUpdate(dt);
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

void Game::SetBulletEnnmy() {


}

void Game::SetBulletPlayer() {

	if (!bulletManager.bulletTexture.loadFromFile("res/LASERBALL.PNG"))
		printf("erreur: bullet texture fail load\n");
}

void Game::SetBg() {

	backGround = RectangleShape(Vector2f(1280, 720));

	if (!bg.loadFromFile("res/BG.JPG"))
		printf("ERR : LOAD FAILED\n");

	backGround.setTexture(&bg);
}



