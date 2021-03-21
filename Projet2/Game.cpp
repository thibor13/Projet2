#include "Game.hpp"

void Game::processEvent(sf::Event& event, RenderWindow& window) {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		player.spaceShip.move(-100.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player.spaceShip.move(100.f, 0.f);
}

void Game::GameDraw(RenderWindow& window) {
	
	window.draw(backGround);
	player.PlayerDraw(window);
}

void Game::UpdateGame(double dt) {


}

void Game::SetBg() {

	backGround = RectangleShape(Vector2f(1280, 720));

	if (!bg.loadFromFile("res/BG.JPG"))
		printf("ERR : LOAD FAILED\n");

	backGround.setTexture(&bg);
}

Game::Game() {


	
}

