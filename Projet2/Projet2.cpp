#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.hpp"
#include "Game.hpp"
#include "SceneManager.hpp"
#include "Lib.hpp"
#include <SFML/Window/Keyboard.hpp>
#include "Dice.hpp"
#include "AudioManager.hpp"

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(sf::VideoMode(1280, 720, 32), "SFML works!");
	window.setVerticalSyncEnabled(true);
	
	AudioManager audio;
	SceneManager sceneManager;

	Event event;

	double frameStart = 0.0;
	double frameEnd = 0.0;
	window.setFramerateLimit(60);

	while (window.isOpen()) {

		double dt = frameEnd - frameStart;
		frameStart = Lib::getTimeStamp();

		while (window.pollEvent(event)) { //sort un evenement de la liste pour le traiter
			sceneManager.ProcessInput(event, window);
		}
		sceneManager.UpdateScene(dt, window);
		sceneManager.SceneDraw(window);

		frameEnd = Lib::getTimeStamp();
	}
}