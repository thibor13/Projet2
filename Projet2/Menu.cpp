#include "Menu.hpp"
#include <iostream>

Menu::Menu(float width, float height) {

	if (!font.loadFromFile("res/ARIAL.TTF")) {
		cout << "ERROR NO FONT" << endl;
	}

	menu[0].setFont(font);
	menu[0].setString("Jouer");
	menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu[0].setFillColor(Color::Red);

	menu[1].setFont(font);
	menu[1].setString("Quitter");
	menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu[1].setFillColor(Color::Yellow);

	selectedIndex = 0;
}

Menu::~Menu() {

}

void Menu::draw(RenderWindow& window) {

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