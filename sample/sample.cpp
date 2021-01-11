#include <cstdlib>
#include <exception>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <SFButton/SFButton.hpp>

int main()
{
    sf::ContextSettings settings;

    sf::RenderWindow window(sf::VideoMode(1600, 1200), "SFPlot-Sample", sf::Style::Default, settings);

    sf::Form form(window);
    form.get_config().texture.loadFromFile("resource/Texture.png"); 
    auto circle_button = std::make_shared<sf::CircleButton>(20.f);
    circle_button->set_on_pressed_call_back([](){std::cout << "Hello" << std::endl;});
    circle_button->setPosition(500, 500);
    form.add_button(circle_button);
    auto rectangle_button = std::make_shared<sf::RectangleButton>(sf::Vector2f{200.f, 200.f});
    rectangle_button->set_on_pressed_call_back([](){std::cout << "Bye" << std::endl;});
    rectangle_button->setPosition(200, 200);
    form.add_button(rectangle_button);

    while (window.isOpen())
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            form.process_events(event);
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color(30, 30, 30));
        window.draw(form);
        window.display();
    }

    return EXIT_SUCCESS;
}
