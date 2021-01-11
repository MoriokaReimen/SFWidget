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
    sf::Form form;
    auto button = std::make_shared<sf::CircleButton>(form.config());
    button->set_on_pressed_call_back([](){std::cout << "Hello" << std::endl;});
    form.add_button(button);

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
