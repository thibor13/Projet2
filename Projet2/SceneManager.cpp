#include "SceneManager.hpp"

void SceneManager::UpdateScene(double dt) {

	if (!isGaming) {
		
		menuSc.MenuUpdate();
	}
	else if(isGaming){
		
		gameSc.UpdateGame(dt);
	}
}

void SceneManager::SceneDraw(RenderWindow &wind) {

	if (!isGaming) {
		wind.clear();
		menuSc.draw(wind);
    }
	else if(isGaming){
		wind.clear();
		gameSc.draw(wind);
	}
	
}

void SceneManager::ProcessInput(Event &event, RenderWindow &window) {

	if(!isGaming)
	menuSc.processEvent(event, window);
	else if(isGaming)
	gameSc.processEvent(event, window);
}