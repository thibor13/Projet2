#include "PlayerController.hpp"

PlayerController::PlayerController() {


}

void PlayerController::PlayerUpdate(double dt) {

	if (isMovingLeft == true) {
		speed = -0.02f;
		spaceShip.move(speed * dt, 0);
	}

	if (isMovingRight == true) {
		speed = 0.02f;
		spaceShip.move(speed * dt, 0);
	}
}



