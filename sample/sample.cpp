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
    form.config().texture.loadFromFile("resource/Texture.png");
    form.config().texture.setSmooth(true);
    form.config().sprite_size = sf::Vector2u(100u, 100u);
    form.config().button_font.loadFromFile("resource/digital-7.ttf");
    form.config().button_font_size = 50;
    form.config().button_font_released_color = sf::Color(0, 0, 0);
    form.config().button_font_pressed_color = sf::Color(255, 255, 0);

    form.config().label_font.loadFromFile("resource/ipamjm.ttf");
    form.config().label_font_size = 60;
    form.config().label_font_color=sf::Color(0, 0, 0);

    auto circle_button = std::make_shared<sf::CircleButton>(20.f);
    circle_button->set_on_pressed_call_back([](){std::cout << "Hello" << std::endl;});
    circle_button->setPosition(500, 500);
    circle_button->set_text("Hello!!");
    form.add_button(circle_button);

    auto rectangle_button = std::make_shared<sf::RectangleButton>(sf::Vector2f{200.f, 200.f});
    rectangle_button->set_on_pressed_call_back([](){std::cout << "Bye" << std::endl;});
    rectangle_button->setPosition(200, 200);
    rectangle_button->set_text("Bye!!");
    form.add_button(rectangle_button);

    auto label = std::make_shared<sf::Label>(sf::Vector2f{100.f,100.f});
    label->set_text("Power Management");
    form.add_button(label);

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
