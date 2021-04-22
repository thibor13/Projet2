#include "SceneManager.hpp"

SceneManager::SceneManager() {

	//initialisations des scènes
	menuSc = Menu();
	menuSc.SetFont();
	menuSc.SetBgMenu();

	gameSc = Game(&menuSc);
	gameSc.SetBg();
	gameSc.SetPlayerSprite();
	gameSc.SetBulletPlayer();
	gameSc.SetEnnemies();
	gameSc.SetBulletEnemy();
	gameSc.SetWall();
	gameSc.SetScore();
}

void SceneManager::ResetScene() {

	menuSc = Menu();
	menuSc.SetFont();
	menuSc.SetBgMenu();

	gameSc = Game(&menuSc);
	gameSc.SetBg();
	gameSc.SetPlayerSprite();
	gameSc.SetBulletPlayer();
	gameSc.SetEnnemies();
	gameSc.SetBulletEnemy();
	gameSc.SetWall();
	gameSc.SetScore();
}

void SceneManager::UpdateScene(double dt, RenderWindow& win) {

	if (menuSc.isGame == false) {
		
		menuSc.MenuUpdate();
		if (menuSc.isReset == true) {
			ResetScene();
			menuSc.isReset = false;
		}
	}
	else if(menuSc.isGame == true){
		
		gameSc.UpdateGame(dt, win);
	}
}

void SceneManager::SceneDraw(RenderWindow &window) {

	if (menuSc.isGame == false) {
		window.clear();
		menuSc.MenuDraw(window);
		window.display();
    }
	else if(menuSc.isGame == true){
		window.clear();
		gameSc.GameDraw(window);
		window.display();
	}
}

void SceneManager::ProcessInput(Event &event, RenderWindow &window) {

	if (menuSc.isGame == false) {
		menuSc.processEvent(event, window);
	}
	
	else if (menuSc.isGame == true) {
		gameSc.processEvent(event, window);
	}
}

