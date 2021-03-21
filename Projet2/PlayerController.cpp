#include "PlayerController.hpp"

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
}



