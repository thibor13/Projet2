#pragma once
#include <cstdlib>

class Dice {
public:
	static int randSign() {
		return (rand() % 2) ? 1 : -1;
	};
	static float randF() {
		return 1.0f * rand() / RAND_MAX;
	};
};
