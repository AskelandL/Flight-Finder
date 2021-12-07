#include "findPath.h"
#include "Random.h"
#include "Display.h"
#include "AdjacencyMatrix.h"

// main file where everything is tied together

int main() {
    // create instance
    // go through loop NODE times and insert node
    int numAirports = 10000;
    int flightTime;
    int operation;
    AdjacencyMatrix myMatrix(numAirports, numAirports);

    for (int i = 0; i < numAirports) {
        for (int j = 0; j < numAirport; j++) {
            flightTime = Random(); //ask how to call random number
;            myMatrix.insertRoute(i, j, flightTime);
        }
    }

    // call Display
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flight Finder");
    Display d = Display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                TextureManager::Clear();
                window.close();
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

    return 1;
}