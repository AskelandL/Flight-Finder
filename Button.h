#pragma once
#include "Definitions.h"
#include <string>
#include "TextureManager.h"


class Button {
protected:
	sf::Sprite pic;
	int x;
	int y;
public:
	Button();
	Button(string texture, int x, int y);
	void setSprite(string texture);
	void Draw(sf::RenderWindow& window);
	bool isPressed(int x, int y);
};

// text box a la Plaque
class TextBox : public Button {
	bool interactive;
	bool pressed;
	string name;
	sf::Text text;
	void SetText(string name);
public:
	TextBox();
	TextBox(bool interactive, string name, int x, int y);
	void Draw(sf::RenderWindow& window);
	void Press(bool down);
	void Position(int x, int y);
	bool Click(int x, int y);
	bool isPressed();
	void addText(char letter);
};