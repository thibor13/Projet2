#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SceneManager.hpp"

using namespace std;
using namespace sf;

class Game {
public:

	Game(float width, float height);
	~Game();

	Game(sf::RenderWindow* win);
	void processEvent(sf::Event &event, RenderWindow &win);
	void draw(RenderWindow& window);
	void UpdateGame(double dt);

	//SceneManager* sceneMana = nullptr;
};


