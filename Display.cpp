#include "Display.h"

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
		fastest.Draw(window);
	}
}

void Display::Click(int x, int y) {
	if (isStart) {
		if (start.Click(x,y) == 1) {
			isFastest = true;
			isStart = false;
		}
	}
	else if (isFastest) {
		if (fastest.Click(x, y)) {
			isFastest = false;
			isStart = true;
		}
	}
}

void Display::Type(char letter) {
	if (isFastest) {
		fastest.Type(letter);
	}
}

//	//  STARTSCREEN  //	//

StartScreen::StartScreen() {
	fastestBtn = Button("fastestBtn", (SCREEN_WIDTH / 4) - (BUTTON_WIDTH / 2), SCREEN_HEIGHT/2);
	visualBtn = Button("displayBtn", (3*SCREEN_WIDTH / 4) - (BUTTON_WIDTH / 2), SCREEN_HEIGHT/2);
	credBtn = Button("creditsBtn", (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 3*SCREEN_HEIGHT / 4);
	djik = Button("djikBtn", (SCREEN_WIDTH/2)-(BUTTON_WIDTH/2), SCREEN_HEIGHT/2);
	credits.setTexture(TextureManager::GetTexture("creditsScreen"));
	isCredits = false;
}

void StartScreen::Draw(sf::RenderWindow& window, int score) {
	if (isCredits) {
		window.draw(credits);
	}
	else {
		fastestBtn.Draw(window);
		credBtn.Draw(window);
		visualBtn.Draw(window);
		djik.Draw(window);
	}
}

int StartScreen::Click(int x, int y) {
	// find out if clicked a button, configure
	// 0 no change, 1 Fastest, 2 display
	if (isCredits) {
		isCredits = false;
	}
	else if (credBtn.isPressed(x, y)) {
		isCredits = true;
	}
	else if (fastestBtn.isPressed(x, y)) {
		// switch to fastest
		return 1;
	}
	else if (djik.isPressed(x, y)) {
		isDjik = !isDjik;
		if (isDjik) {
			djik.setSprite("djikBtn");
		}
		else {
			djik.setSprite("notDjikBtn");
		}
	}
	return 0;
}


//	//	FASTEST	//	//

Fastest::Fastest() {
	depart = TextBox(true, "", (SCREEN_WIDTH/4) - (BUTTON_WIDTH/2) - BUTTON_BORDER, BUTTON_HEIGHT/2);
	arrive = TextBox(true, "", (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), BUTTON_HEIGHT / 2);
	exit = Button("exitBtn", BUTTON_BORDER + (3*SCREEN_WIDTH / 4) - (BUTTON_WIDTH / 2), BUTTON_HEIGHT / 2);
	deText = TextWrap("DEPARTING", (SCREEN_WIDTH / 4) - (BUTTON_WIDTH / 2) - BUTTON_BORDER, BUTTON_BORDER / 2);
	arrText = TextWrap("ARRIVING", (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), BUTTON_BORDER / 2);
}

void Fastest::Draw(sf::RenderWindow& window) {
	depart.Draw(window);
	arrive.Draw(window);
	exit.Draw(window);
	deText.Draw(window);
	arrText.Draw(window);
}

bool Fastest::Click(int x, int y) {
	arrive.Click(x, y);
	depart.Click(x, y);
	return exit.isPressed(x,y);
}

void Fastest::Type(char letter) {
	// cycle through and see which text box is selected
	if (depart.isPressed()) {
		depart.addText(letter);
	}
	else if (arrive.isPressed()) {
		arrive.addText(letter);
	}
}