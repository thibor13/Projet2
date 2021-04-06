#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "PlayerController.hpp"
#include "BulletManager.hpp"

using namespace std;
using namespace sf;

class Game {
public:

	PlayerController player;
	BulletManager bulletManager;

	Game();

	RectangleShape  backGround;
	Texture bg;
	RenderWindow* win = nullptr;

	void SetPlayerSprite();
	void SetBulletPlayer();
	void SetBulletEnnmy();
	void SetBg();
	void processEvent(sf::Event &event, RenderWindow& window);
	void GameDraw(RenderWindow& window);
	void UpdateGame(double dt);

	//SceneManager* sceneMana = nullptr;
};


