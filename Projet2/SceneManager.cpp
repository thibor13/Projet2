#include "SceneManager.hpp"

SceneManager::SceneManager() {

	//initialisations des scènes
	gameSc = Game();
	gameSc.SetBg();
	
	menuSc = Menu();
	menuSc.SetFont();
	menuSc.SetBgMenu();
}

void SceneManager::UpdateScene(double dt) {

	if (menuSc.isGame == false) {
		
		menuSc.MenuUpdate();
	}
	else if(menuSc.isGame == true){
		
		gameSc.UpdateGame(dt);
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

