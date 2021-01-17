#include <cstdlib>
#include <exception>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <SFWidget/SFWidget.hpp>

int main()
{
    sf::ContextSettings settings;

    sf::RenderWindow window(sf::VideoMode(1600, 1200), "SFPlot-Sample", sf::Style::Default, settings);

    sf::Form form(window);

    auto circle_button = form.add_circle_button(20.f);
    circle_button->set_on_pressed_call_back([]()
    {
        std::cout << "Hello" << std::endl;
    });
    circle_button->setPosition(500, 500);
    circle_button->set_text("Hello!!");


    auto rectangle_button = form.add_rectangle_button(sf::Vector2f{200.f, 200.f});
    rectangle_button->set_on_pressed_call_back([]()
    {
        std::cout << "Bye" << std::endl;
    });
    rectangle_button->setPosition(200, 200);
    rectangle_button->set_text("Bye!!");

    auto rectangle_toggle = form.add_rectangle_toggle(sf::Vector2f{50.f, 50.f});
    rectangle_toggle->set_on_pressed_call_back([]()
    {
        std::cout << "5V" << std::endl;
    });
    rectangle_toggle->setPosition(300, 300);

    auto circle_toggle = form.add_circle_toggle(20.f);
    circle_toggle->set_on_pressed_call_back([]()
    {
        std::cout << "3V" << std::endl;
    });
    circle_toggle->setPosition(500, 300);

    auto label = form.add_label(sf::Vector2f{100.f, 100.f});
    label->set_text("Power Management");
    form.add_widget(label);

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
