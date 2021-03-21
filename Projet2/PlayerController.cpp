#include "PlayerController.hpp"

void PlayerController::PlayerDraw(RenderWindow &window) {

	spaceShip.setScale(Vector2f(0.18f, 0.18f));

	if(!ship.loadFromFile("res/SPACESHIP1.PNG"))
		printf("ERR : LOAD FAILED\n");
	
	spaceShip.setPosition(640, 630);
	spaceShip.setTexture(ship);
	window.draw(spaceShip);
}



