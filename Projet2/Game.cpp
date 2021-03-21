#include "Game.hpp"

void Game::processEvent(sf::Event& event, RenderWindow& window) {
	
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

	player.spaceShip.setScale(Vector2f(0.18f, 0.18f));

	if (!player.ship.loadFromFile("res/SPACESHIP1.PNG"))
		printf("ERR : LOAD FAILED\n");

	player.spaceShip.setPosition(640, 630);
	player.spaceShip.setTexture(player.ship);
}

void Game::SetBg() {

	backGround = RectangleShape(Vector2f(1280, 720));

	if (!bg.loadFromFile("res/BG.JPG"))
		printf("ERR : LOAD FAILED\n");

	backGround.setTexture(&bg);
}

Game::Game() {


	
}

