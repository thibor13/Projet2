#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "PlayerController.hpp"
#include "BulletManager.hpp"
#include "EnnemyManager.hpp"
#include "Particle.hpp"
#include "Dice.hpp"

using namespace std;
using namespace sf;

class Game {
public:

	PlayerController player;
	BulletManager bulletManager;
	EnnemyManager ennemyManager;
	Dice dice;

	vector<Particles> boom;
	Game();

	RectangleShape  backGround;
	Texture bg;
	RenderWindow* win = nullptr;

	void SetPlayerSprite();
	void SetBulletPlayer();
	void SetBulletEnemy();
	void SetEnnemies();
	void SetBg();
	void processEvent(sf::Event &event, RenderWindow& window);
	void GameDraw(RenderWindow& window);
	void UpdateGame(double dt, RenderWindow& win);
	void CreatesExplode(Vector2f enePos, Color little);
	void Shake(RenderWindow& win);
};


