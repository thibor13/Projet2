#include "Game.hpp"

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
		
}

void Game::GameDraw(RenderWindow& window) {
	
	window.draw(backGround);
	window.draw(player.spaceShip);
}

void Game::UpdateGame(double dt) {

	player.PlayerUpdate(dt);
}

void Game::SetPlayerSprite() {

	player.spaceShip.setScale(Vector2f(0.20f, 0.20f));

	if (!player.ship.loadFromFile("res/SPACESHIP1.PNG"))
		printf("ERR : LOAD FAILED\n");

	player.spaceShip.setOrigin(0.10f, player.spaceShip.getScale().y);
	player.spaceShip.setPosition(640, 630);
	player.spaceShip.setTexture(player.ship);
	player.getScalingPos = player.ship.getSize().x * player.spaceShip.getScale().x;
}

void Game::SetBg() {

	backGround = RectangleShape(Vector2f(1280, 720));

	if (!bg.loadFromFile("res/BG.JPG"))
		printf("ERR : LOAD FAILED\n");

	backGround.setTexture(&bg);
}

Game::Game() {


	
}

