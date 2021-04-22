#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class AudioManager {
public:

	Music menuMusic;
	
	AudioManager() {

		if (!menuMusic.openFromFile("res/audio/gameMusic.wav"))
			printf("erreur: nozic");
		menuMusic.setVolume(40);
		menuMusic.play();
		menuMusic.setLoop(true);
	}
};

