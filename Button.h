#pragma once
#include "Definitions.h"
#include <string>
#include "TextureManager.h"
using namespace std;


class Button {
protected:
	sf::Sprite pic;
	int pos;
	int x;
	int y;
public:
	Button();
	Button(int pos, string texture);
	void setSprite(string texture);
	void Draw(sf::RenderWindow& window);
	bool isPressed(int x, int y);
};

// text box a la Plaque
class TextBox : public Button {
	bool interactive;
	class Name {
		sf::Sprite one;
		sf::Sprite two;
		sf::Sprite three;
		sf::Sprite four;
	public:
		string name;
		Name() {
			name = "    ";
		}
		void Set(string name) { this->name = name; }
		void Add(char i);
		void Draw(sf::RenderWindow& window, string name);
	};
	Name nameDisplay;
public:
	TextBox() {
		nameDisplay = Name();
		interactive = false;
	}
	TextBox(bool interactive, string name);
	void Draw(sf::RenderWindow& window, string name);
	void Restart(string texture);
};