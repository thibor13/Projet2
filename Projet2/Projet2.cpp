#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "Game.hpp"
#include "SceneManager.hpp"
#include "Lib.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(sf::VideoMode(1280, 720, 32), "SFML works!");
	window.setVerticalSyncEnabled(true);
	//Menu menu(window.getSize().x, window.getSize().y);
	SceneManager* sceneManager = nullptr;

	//Game game(window.getSize().x, window.getSize().y);

	double frameStart = 0.0;
	double frameEnd = 0.0;
	window.setFramerateLimit(60);
	
	Event event;

	while (window.isOpen()) {

		double dt = frameEnd - frameStart;
		frameStart = Lib::getTimeStamp();

		while (window.pollEvent(event)) { //sort un evenement de la liste pour le traiter
			sceneManager->ProcessInput(event, window);
			sceneManager->UpdateScene(dt);
			//menu.processEvent(event, window);
		}
		sceneManager->SceneDraw(window);
		//window.clear();
		//menu.draw(window);
		window.display();
	}
	
}