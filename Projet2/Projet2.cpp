#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "SFML works!");
	window.setVerticalSyncEnabled(true);
	Menu menu(window.getSize().x, window.getSize().y);

	sf::Event event;
	while (window.isOpen()) {

		while (window.pollEvent(event)) { //sort un evenement de la liste pour le traiter

		//scene Manage
			switch (event.type) {

			case Event::KeyReleased:
				switch (event.key.code) {

				case Keyboard::Up:
					menu.MoveUp();
					break;
				case Keyboard::Down:
					menu.MoveDown();
					break;
				case Keyboard::Return:
					switch (menu.getPressedIndex()) {

					case 0:
						//load game scene 

						break;
					case 1:
						//close game
						window.close();
						break;
					}
				}
				break;
			case Event::Closed:
				window.close();
				break;
			}

		}

		window.clear();
		menu.draw(window);
		window.display();
	}
	
}