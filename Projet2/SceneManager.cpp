#include "SceneManager.hpp"

void SceneManager::UpdateScene(double dt) {

	if (!isGaming) {
		
		menuSc.MenuUpdate();
	}
	else if(isGaming){
		
		gameSc.UpdateGame(dt);
	}
}

void SceneManager::SceneDraw(RenderWindow &window) {

	if (!isGaming) {
		window.clear();
		menuSc.draw(window);
		window.display();
    }
	else if(isGaming){
		window.clear();
		gameSc.draw(window);
		window.display();
	}
	
}

void SceneManager::ProcessInput(Event &event, RenderWindow &window) {

	if (!isGaming) {
		menuSc.processEvent(event, window);
	}
	
	else if (isGaming) {
		gameSc.processEvent(event, window);
	}
	
}

SceneManager::SceneManager() {

}