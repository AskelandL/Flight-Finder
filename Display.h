#pragma once
#include "Button.h"
#include <SFML/Window/Keyboard.hpp>
using namespace std;

class StartScreen
{
	sf::Sprite credits;
	bool isCredits;
	Button fastest;
	Button visual;
	Button credBtn;
	Button exit;
public:
	StartScreen();
	void Draw(sf::RenderWindow& window, int score = -1);
	bool Click(int x, int y);  // bool startScreen
};


// make a class for fastest and for visual too, then convert StartScreen to Game-equivalent? (or make overarching Display class)
class Fastest {
	TextBox depart;
	TextBox arrive;
};

/* for fastest:
each text box has a bool if it is clicked (goes on when clicked, goes off when click outside)
	L> If box is clicked, then if you type on keyboard
		-put letter you typed into string variable (show on screen)
			-don't forget about delete/clear ability
		-alternate option: have 4 boxes and enter each one by one (pain) (don't do this)

*/

class Display {
	bool isStart;
	StartScreen start;
	bool isFastest;
	Fastest fastest;
	bool isVisual;
public:
	Display();
	void Draw(sf::RenderWindow& window); // send draw to respective
	void Click(int x, int y); // send click to respective
	void Type(char letter); // if text box is selected, type a character
};