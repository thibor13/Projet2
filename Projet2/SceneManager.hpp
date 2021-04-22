#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "Game.hpp"

using namespace sf;
using namespace std;

class SceneManager {
public:

	Menu menuSc;
	Game gameSc;

	SceneManager();

	void UpdateScene(double dt, RenderWindow& win);
	void SceneDraw(RenderWindow &window);
	void ProcessInput(Event& event, RenderWindow& window);
	void ResetScene();
};