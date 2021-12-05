#include "Display.h"
#include <iostream>

//	//	 DISPLAY	//	//

Display::Display() {
	isStart = true;
	isFastest = false;
	isVisual = false;
}

void Display::Draw(sf::RenderWindow& window) {
	if (isStart) {
		start.Draw(window);
	}
	else if (isFastest) {
		// draw fastest
	}
}

void Display::Click(int x, int y) {
	cout << "you clicked!!" << endl;
}

void Display::Type(char letter) {
	cout << letter << endl;
}

//	//  STARTSCREEN  //	//

StartScreen::StartScreen() {
	fastest = Button(0, "fastestBtn");
	visual = Button(2, "creditsBtn");
	credBtn = Button(1, "displayBtn");
	exit = Button(3, "exitBtn");
	credits.setTexture(TextureManager::GetTexture("creditsScreen"));
	isCredits = false;
}

// return fastestGame
void StartScreen::Draw(sf::RenderWindow& window, int score) {
	if (isCredits) {
		window.draw(credits);
	}
	else {
		fastest.Draw(window);
		credBtn.Draw(window);
		visual.Draw(window);
		exit.Draw(window);
	}
}

bool StartScreen::Click(int x, int y) {
	// find out if clicked a button, configure
	if (isCredits) {
		isCredits = false;
	}
	else if (credBtn.isPressed(x, y)) {
		isCredits = true;
	}
	else if (fastest.isPressed(x, y)) {
		return false;
	}
	return true;
}
