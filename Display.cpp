#include "Display.h"
#include <iostream>

//	//	 DISPLAY	//	//

Display::Display(AdjacencyMatrix* graph) {
	isStart = true;
	isFastest = false;
	isVisual = false;
	this->graph = graph;
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
	if (isFastest && fastest.Type(letter)) {
		findPath();
	}
}

void Display::findPath() {
	vector<TextWrap>* text = fastest.getResults();
	clock_t t;
	float timeTaken;
	pair<int, vector<int>> result;
	string nodes = "";
	int from = graph->convert(fastest.getCommands().first);
	int to = graph->convert(fastest.getCommands().second);
	// implement the finding path for fastest
	if (start.isDjikstra()) {
		text->at(1).addon("Djikstra");
		t = clock();
		result = graph->Dijkstra(from, to);
		timeTaken = clock() - t;
	}
	else {
		text->at(1).addon("BellmanFord");
		t = clock();
		result = graph->BellmanFord(from, to);
		timeTaken = clock() - t;
	}
	// path
	nodes += fastest.getCommands().second;
	for (int i = 0; i < result.second.size(); i++) {
		if (result.second.at(i) == -1) {
			nodes += "->" + fastest.getCommands().first;
			break;
		}
		nodes += "->" + graph->convert(result.second.at(i));
	}
	text->at(5).addon(nodes);
	//add in text
	text->at(2).addon(to_string(timeTaken / CLOCKS_PER_SEC) + " seconds");
	text->at(4).addon(to_string(result.first) + " hours");
}

//	//  STARTSCREEN  //	//

StartScreen::StartScreen() {
	fastestBtn = Button("fastestBtn", (SCREEN_WIDTH / 4) - (BUTTON_WIDTH / 2), SCREEN_HEIGHT/2);
	visualBtn = Button("displayBtn", (3*SCREEN_WIDTH / 4) - (BUTTON_WIDTH / 2), SCREEN_HEIGHT/2);
	credBtn = Button("creditsBtn", (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 3*SCREEN_HEIGHT / 4);
	djik = Button("djikBtn", (SCREEN_WIDTH/2)-(BUTTON_WIDTH/2), SCREEN_HEIGHT/2);
	credits.resize(9);
	for (float i = 0; i < credits.size(); i++) {
		// set text spacing
		credits.at(i).Position(LEFT_BORDER, (SCREEN_HEIGHT / 6) + ((i * TEXT_HEIGHT) * 1.5));
	}
	credits.at(0).addText("Created Dec 2021 for Data Structures Class at UF");
	credits.at(1).addText("Morgan Askeland");
	credits.at(2).addText("Gabrielle Cannella");
	credits.at(3).addText("Tristan McLain");
	credits.at(4).addText("");
	credits.at(5).addText("Finds the shortest path between 100,000 fictional airports");
	credits.at(6).addText("with a choice of two algorithms.");
	isCredits = false;
}

void StartScreen::Draw(sf::RenderWindow& window, int score) {
	if (isCredits) {
		for (TextWrap line : credits) {
			line.Draw(window);
		}
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

bool& StartScreen::isDjikstra() {
	return isDjik;
}

//	//	FASTEST	//	//

Fastest::Fastest() {
	depart = TextBox(true, "", (SCREEN_WIDTH/4) - (BUTTON_WIDTH/2) - BUTTON_BORDER, BUTTON_HEIGHT/2);
	arrive = TextBox(true, "", (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), BUTTON_HEIGHT / 2);
	exit = Button("exitBtn", BUTTON_BORDER + (3*SCREEN_WIDTH / 4) - (BUTTON_WIDTH / 2), BUTTON_HEIGHT / 2);
	deText = TextWrap("DEPARTING", (SCREEN_WIDTH / 4) - (BUTTON_WIDTH / 2) - BUTTON_BORDER, BUTTON_BORDER / 2);
	arrText = TextWrap("ARRIVING", (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), BUTTON_BORDER / 2);
	results.resize(6);
	for (float i = 0; i < results.size(); i++) {
		// set text spacing
		results.at(i).Position((SCREEN_WIDTH / 4) - (BUTTON_WIDTH / 2) - BUTTON_BORDER, (BUTTON_HEIGHT*2) - TEXT_HEIGHT + ((i * TEXT_HEIGHT) * 1.5));
	}
	results.at(0).addText("Airports are ");
	results.at(0).addon(to_string(NAME_LEN) + " letters. Please wait once text is entered.");
	results.at(1).addText("Algorithm Used: ");
	results.at(2).addText("Time Taken: ");
	results.at(3).addText("");
	results.at(4).addText("Flight Time: ");
	results.at(5).addText("Route: ");
}

void Fastest::Draw(sf::RenderWindow& window) {
	depart.Draw(window);
	arrive.Draw(window);
	exit.Draw(window);
	deText.Draw(window);
	arrText.Draw(window);
	for (TextWrap line : results) {
		line.Draw(window);
	}
}

bool Fastest::Click(int x, int y) {
	arrive.Click(x, y);
	depart.Click(x, y);
	return exit.isPressed(x,y);
}

bool Fastest::Type(char letter) {
	// cycle through and see which text box is selected
	if (depart.isPressed()) {
		depart.addText(letter);
	}
	else if (arrive.isPressed()) {
		arrive.addText(letter);
	}
	if (arrive.isComplete() && depart.isComplete()) {
		return true;
	}
	results.at(3).addon("");
	return false;
}

vector<TextWrap>* Fastest::getResults() {
	return &results;
}

pair<string, string> Fastest::getCommands() {
	return make_pair(arrive.getText(), depart.getText());
}