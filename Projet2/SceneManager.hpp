#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "Game.hpp"

using namespace sf;
using namespace std;

class SceneManager {
public:

	void UpdateScene(double dt);
	void SceneDraw(RenderWindow &window);
	void ProcessInput(Event& event, RenderWindow& window);

	Menu menuSc;
	Game gameSc;

	bool isGaming = false;
};