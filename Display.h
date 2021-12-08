#pragma once
#include "Button.h"
#include "AdjacencyMatrix.h"
#include <SFML/Window/Keyboard.hpp>
#include <time.h>
using namespace std;

class StartScreen
{
	vector<TextWrap> credits;
	bool isCredits;
	Button fastestBtn;
	Button visualBtn;
	Button credBtn;
	Button djik;
	bool isDjik;
public:
	StartScreen();
	void Draw(sf::RenderWindow& window, int score = -1);
	int Click(int x, int y);  // 0 no change, 1 Fastest, 2 display
	bool& isDjikstra();
};


class Fastest {
	TextBox depart;
	TextBox arrive;
	TextWrap deText;
	TextWrap arrText;
	Button exit;
	vector<TextWrap> results;
public:
	Fastest();
	void Draw(sf::RenderWindow& window);
	bool Click(int x, int y);
	bool Type(char letter);
	vector<TextWrap>* getResults();
};

class Display {
	bool isStart;
	StartScreen start;
	bool isFastest;
	Fastest fastest;
	bool isVisual;
	AdjacencyMatrix* graph;
public:
	Display(AdjacencyMatrix* graph);
	void Draw(sf::RenderWindow& window); // send draw to respective
	void Click(int x, int y); // send click to respective
	void Type(char letter); // if text box is selected, type a character
	void findPath();
};