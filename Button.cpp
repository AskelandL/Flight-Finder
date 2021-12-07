#include "Button.h"


//	//	BUTTON	//	//

Button::Button() {
	x = LEFT_BORDER;
	y = 0;
}

Button::Button(string texture, int x, int y) {
	this->x = x;
	this->y = y;
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


//	//	TEXTBOX	//	//

TextBox::TextBox() {
	SetText("");
	interactive = true;
	x = 0;
	y = 0;
	setSprite("TextBox");
	pressed = false;
}

TextBox::TextBox(bool interactive, string name, int x, int y) {
	SetText(name);
	this->interactive = interactive;
	this->x = x;
	this->y = y;
	text.setPosition(x + BUTTON_BORDER, y + BUTTON_BORDER);
	pressed = false;
	setSprite("TextBox");
}

void TextBox::SetText(string name) {
	this->name = name;
	text.setFont(TextureManager::GetFont(FONT));
	text.setString(name);
	text.setCharacterSize(24); // in pixels, not points!
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void TextBox::Draw(sf::RenderWindow& window) {
	window.draw(pic);
	window.draw(text);
}

void TextBox::Press(bool down) {
	if (interactive && down) {
		setSprite("pressedText");
		pressed = true;
	}
	else if (interactive) {
		setSprite("textBox");
		pressed = false;
	}
}

void TextBox::Position(int x, int y) {
	this->x = x;
	this->y = y;
	setSprite("TextBox");
}

bool TextBox::Click(int x, int y) {
	if (interactive && Button::isPressed(x, y)) {
		Press(true);
		return true;
	}
	Press(false);
	return false;
}

bool TextBox::isPressed() {
	return pressed;
}

void TextBox::addText(char letter) {
	if (name.size() < NAME_LEN && isalpha(letter + 65)) {
		name = name + (char)(letter + 65);
	}
	else if (letter == sf::Keyboard::Backspace && name.size() > 0) {
		name = name.erase(name.size() - 1);
	}
	SetText(name);
}
