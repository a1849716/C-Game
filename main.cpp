#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 1200), "SCUFFED TETRIS", sf::Style::Close | sf::Style::Titlebar);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
//compiler code
//g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system