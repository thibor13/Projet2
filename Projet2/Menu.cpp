#include "Menu.hpp"
#include <iostream>

Menu::Menu() {

	if (!font.loadFromFile("res/ARIAL.TTF")) {
		cout << "ERROR NO FONT" << endl;
	}

	//float width = 1280, float height = 720;
	menu[0].setString("Jouer");
	menu[0].setPosition(Vector2f(1280 / 2, 720 / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu[0].setFillColor(Color::Red);
	
	menu[1].setString("Quitter");
	menu[1].setPosition(Vector2f(1280 / 2, 720 / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu[1].setFillColor(Color::Yellow);

	selectedIndex = 0;
}

Menu::~Menu() {

}

void Menu::SetFont() {

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		menu[i].setFont(font);
	}
}

void Menu::MenuDraw(RenderWindow& window) {

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {

	if (selectedIndex - 1 >= 0) {

		menu[selectedIndex].setFillColor(Color::Yellow);
		selectedIndex--;
		menu[selectedIndex].setFillColor(Color::Red);
	}
}
void Menu::MoveDown() {

	if (selectedIndex + 1 < MAX_NUMBER_OF_ITEMS) {

		menu[selectedIndex].setFillColor(Color::Yellow);
		selectedIndex++;
		menu[selectedIndex].setFillColor(Color::Red);
	}
}

void Menu::processEvent(sf::Event &event, RenderWindow &win) {

	//scene Manage
	switch (event.type) {

	case Event::KeyReleased:
		switch (event.key.code) {

		case Keyboard::Up:
			MoveUp();
			break;
		case Keyboard::Down:
			MoveDown();
			break;
		case Keyboard::Return:
			switch (getPressedIndex()) {

			case 0:
				//load game scene 

				break;
			case 1:
				//close game
				win.close();
				break;
			}
		}
		break;
	case Event::Closed:
		win.close();
		break;
	}

}

void Menu::MenuUpdate() {

}

