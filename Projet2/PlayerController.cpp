#include "PlayerController.hpp"
#include <iostream>

PlayerController::PlayerController() {
	
}

void PlayerController::PlayerUpdate(double dt) {

	if (isMovingLeft == true) {
		speed = -360.f;
		spaceShip.move(speed * dt, 0);
	}
	if (isMovingRight == true) {
		speed = 360.f;
		spaceShip.move(speed * dt, 0);
	}

	posPlayer = Vector2f(spaceShip.getPosition().x, spaceShip.getPosition().y);

	if (posPlayer.x <= 0) {

		spaceShip.setPosition(Vector2f(0, posPlayer.y));
	}
	if (posPlayer.x  >= 1280 - getScalingPos ) {

		spaceShip.setPosition(Vector2f(1280 - getScalingPos, posPlayer.y));
	}

	if (!hpFont.loadFromFile("res/ARIAL.TTF")) {
		cout << "ERROR NO FONT" << endl;
	}

	hpTxt.setFont(hpFont);
	hpTxt.setCharacterSize(36);
	hpTxt.setPosition(20, 680);
	hpTxt.setFillColor(Color::Green);
	hpTxt.setString(to_string(hp));
}




