#include "Game.hpp"
#include <iostream>
#include "Particle.hpp"
#include "Menu.hpp"

Game::Game(Menu* _menuSet) {

	menuSet = _menuSet;

	if (!sbPlayerFire.loadFromFile("res/audio/laserPlayer.ogg"))
		printf("erreur: no sbLaserPlayer");
}

void Game::processEvent(sf::Event& event, RenderWindow& window) {
	
	switch (event.type) {
	case Event::KeyReleased:
		switch (event.key.code) {
		case Keyboard::Q:
			player.isMovingLeft = false;
			break;
		case Keyboard::D:
			player.isMovingRight = false;
			break;
		case Keyboard::Space:
			laserP.setBuffer(sbPlayerFire);
			laserP.setVolume(75);
			laserP.play();
			float trajectoire = -20;
			bulletManager.BulletPlayerSpawning(trajectoire);
			cout << player.spaceShip.getPosition().x << endl;
			break;
		}
	break;
	}

	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		player.isMovingLeft = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		player.isMovingRight = true;
	}
	if ((gameOver == true && Keyboard::isKeyPressed(Keyboard::Escape)) || (winner == true && Keyboard::isKeyPressed(Keyboard::Escape))) {
		menuSet->isGame = false;
		menuSet->isReset = true;
	}
}

void Game::GameDraw(RenderWindow& window) {
	
	window.draw(backGround);
	window.draw(player.spaceShip);
	bulletManager.BulletRender(window);
	ennemyManager.DrawEnnemy(window);
	window.draw(scoreTxt);
	window.draw(player.hpTxt);
	window.draw(loose);
	window.draw(returnMenu);
	window.draw(wins);
	for (Particles &part : boom) {
		window.draw(part.el);
	}
}

void Game::UpdateGame(double dt, RenderWindow& win) {

	Win();
	GameOver();
	if (gameOver == false && winner == false) {

		player.PlayerUpdate(dt);
		bulletManager.BulletUpdate(dt);
		ennemyManager.UpdateEnnemy(dt);
		Shake(win);

		for (int j = boom.size() - 1; j >= 0; j--) {

			boom[j].update(dt);

			if (boom[j].destroyed == false) {

				if (boom[j].life <= 0) {

					boom[j].destroyed = true;
				}
			}

			if(boom[j].destroyed == true)
				boom.erase(boom.begin() + j);
		}
	}
	scoreTxt.setString(to_string(player.score));
}

void Game::SetPlayerSprite() {

	if (!player.ship.loadFromFile("res/SPACESHIP1.PNG"))
		printf("ERR : LOAD FAILED\n");

	player.spaceShip.setTexture(player.ship);
	player.spaceShip.setOrigin((float)player.ship.getSize().x /2.f,0);
	player.spaceShip.setScale(Vector2f(0.8f, 0.8f));
	player.spaceShip.setPosition(640, 630);
	player.getScalingPos = ((float)player.ship.getSize().x * player.spaceShip.getScale().x) /2.f;
}

void Game::SetBulletEnemy() {

	if (!ennemyManager.bulletEnnemyTexture1.loadFromFile("res/MOBBULLET.PNG"))
		printf("erreur: bullet1 no load");
	if (!ennemyManager.bulletEnnemyTexture2.loadFromFile("res/MOBBULLET2.PNG"))
		printf("erreur: bullet1 no load");
	if (!ennemyManager.bulletEnnemyTexture3.loadFromFile("res/MOBBULLET3.PNG"))
		printf("erreur: bullet1 no load");
	if (!ennemyManager.bulletEnnemyTexture4.loadFromFile("res/MOBBULLET4.PNG"))
		printf("erreur: bullet1 no load");
}

void Game::SetBulletPlayer() {

	bulletManager = BulletManager(this, &player, &ennemyManager);

	if (!bulletManager.bulletTexture.loadFromFile("res/BULLET.PNG"))
		printf("erreur: bullet texture fail load\n");
}

void Game::SetWall() {

	if (!wall.loadFromFile("res/WALL.PNG"))
		printf("error: wall not load");
}

void Game::Wall() {

	wall.create(40, 20);
	wallTexture.loadFromImage(wall);
	walls.setTexture(wallTexture);
	//walls.setPosition(20, 20);
}

void Game::SetScore() {

	if (!fontScore.loadFromFile("res/ARIAL.TTF")) {
		cout << "ERROR NO FONT" << endl;
	}

	scoreTxt.setFont(fontScore);
	scoreTxt.setCharacterSize(20);
	scoreTxt.setFillColor(Color::Green);
	scoreTxt.setPosition(20, 20);
}

void Game::SetEnnemies() {

	ennemyManager = EnnemyManager(this, &bulletManager);

	if(!ennemyManager.ennemyTex1.loadFromFile("res/SHIP1.PNG"))
		printf("erreur: ennemy1 texture fail load\n");
	if (!ennemyManager.ennemyTex2.loadFromFile("res/SHIP2.PNG"))
		printf("erreur: ennemy2 texture fail load\n");
	if (!ennemyManager.ennemyTex3.loadFromFile("res/SHIP3.PNG"))
		printf("erreur: ennemy3 texture fail load\n");
	if (!ennemyManager.ennemyTex4.loadFromFile("res/SHIP4.PNG"))
		printf("erreur: ennemy4 texture fail load\n");
}

void Game::SetBg() {

	backGround = RectangleShape(Vector2f(1280, 720));

	if (!bg.loadFromFile("res/BG.JPG"))
		printf("ERR : LOAD FAILED\n");

	backGround.setTexture(&bg);
}

//enemy die
void Game::CreatesExplode(Vector2f pos, Color color)
{
	for (int i = 0; i < 100; i++)
	{
		Particles p;

		p.x = pos.x;
		p.y = pos.y;

		float x = ((float)rand() / (float)(RAND_MAX)) * (1 - rand() % 3);
		float y = ((float)rand() / (float)(RAND_MAX)) * (1 - rand() % 3);
		p.dx = x * 100.0;
		p.dy = y * 100.0;
		p.el.setFillColor(color);
		boom.push_back(p);
	}
}

void Game::Shake(RenderWindow &win) {

	View v = win.getDefaultView();
	Vector2f viewCenter = v.getCenter();
	Vector2f n(viewCenter);

	n.x += bulletManager.shake * 2 * Dice::randSign();
	n.y += -bulletManager.shake * 2 * Dice::randSign();

	v.setCenter(n);
	win.setView(v);
	bulletManager.shake *= 0.80;
	if (bulletManager.shake <= 0.01)
		bulletManager.shake = 0.0;
}

void Game::GameOver() {

	if (player.hp <= 0 && gameOver == false) {

		gameOver = true;
		loose.setFont(fontScore);
		loose.setFillColor(Color::Green);
		loose.setCharacterSize(40);
		loose.setPosition(600, 260);
		loose.setString("PERDU!!!");

		returnMenu.setFont(fontScore);
		returnMenu.setFillColor(Color::Green);
		returnMenu.setCharacterSize(18);
		returnMenu.setPosition(560, 320);
		returnMenu.setString("échap pour retourner au menu");

		scoreTxt.setPosition(640, 200);
		scoreTxt.setCharacterSize(40);
	}
}

void Game::Win() {

	if (winner == false && ennemyManager.vague == 4 && ennemyManager.ennemies.size() == 0) {

		winner = true;
		wins.setFont(fontScore);
		wins.setCharacterSize(40);
		wins.setFillColor(Color::Green);
		wins.setPosition(600, 260);
		wins.setString("GAGNER!!!");

		returnMenu.setFont(fontScore);
		returnMenu.setFillColor(Color::Green);
		returnMenu.setCharacterSize(18);
		returnMenu.setPosition(560, 320);
		returnMenu.setString("échap pour retourner au menu");

		scoreTxt.setPosition(640, 200);
		scoreTxt.setCharacterSize(40);
	}
}




