#include "Button.h"


//	//	BUTTON	//	//

Button::Button() {
	pos = -1;
	x = LEFT_BORDER;
	y = 0;
}

Button::Button(int pos, string texture) {
	y = BUTTON_HEIGHT;
	if (pos >= 2) {
		y += BUTTON_HEIGHT;
	}
	x = LEFT_BORDER + ((pos % 2) * BUTTON_WIDTH);
	setSprite(texture);
}

void Button::setSprite(string texture) {
	pic.setTexture(TextureManager::GetTexture(texture));
	pic.setPosition(x, y);
}

void Button::Draw(sf::RenderWindow& window) {
	window.draw(pic);
}

bool Button::isPressed(int pressx, int pressy) {
	if (pressx >= x && pressx <= x + BUTTON_WIDTH && pressy >= y && pressy < y + BUTTON_HEIGHT) {
		return true;
	}
	return false;
}
