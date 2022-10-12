#include <iostream>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace sf;
using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(100, 100), "SFML works!");
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));
    rectangle.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
