#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 2 //number of titles button

class Menu {
public:
	
	Menu();
	~Menu();

	RectangleShape backGroundMenu;
	Texture bgMenu;

	void SetBgMenu();
	void SetFont();
	void MenuDraw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getPressedIndex() { return selectedIndex; }
	void processEvent(sf::Event &event, RenderWindow &win);
	void MenuUpdate();

	bool isGame = false;
	bool isReset = false;

	SoundBuffer sbMenuButton;
	Sound menuButton;

private:
	int selectedIndex;
	Text menu[MAX_NUMBER_OF_ITEMS];
	Font font;
};
