#include "Random.h"
#include "Display.h"
#include "AdjacencyMatrix.h"
#include <iostream>

// main file where everything is tied together

int main() {
    // create instance
    // go through loop NODE times and insert node
    int flightTime = NODES;
    AdjacencyMatrix myMatrix(NODES);
    cout << "loading";

    for (int i = 0; i < NODES; i++) {
        myMatrix.insertRoute(0, i, 13);
        myMatrix.insertRoute(i, 1, 13);
    }
    cout << "..." << endl;
    myMatrix.insertRoute(1, 0, 13);
    for (int i = 2; i < NODES; i++) {
        for (int j = 0; j < NODES; j++) {
            flightTime = 0;
            if (Random::Int(0, 1)) {
                flightTime = Random::Int(0, 9);
            }
            myMatrix.insertRoute(i, j, flightTime);
        }
        if (i % 100 == 0) {
            cout << "|";
        }
    }
    cout << endl;

    cout << "starting!" << endl;

    // call Display
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flight Finder");
    Display d = Display(&myMatrix); // should take in AdjacencyMatrix

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                TextureManager::Clear();
                window.close();
                return 0;
            }
            else if (event.type == sf::Event::KeyPressed) {
                d.Type(event.key.code);
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // screen is clicked
                    d.Click(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }
        window.clear(BACK_COLOR);
        d.Draw(window);
        window.display();
    }

    return 0;
}