#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
struct ConfigData
{
    sf::Font button_font;
    sf::Color button_font_released_color;
    sf::Color button_font_pressed_color;
    unsigned int button_font_size;

    sf::Font label_font;
    sf::Color label_font_color;
    unsigned int label_font_size;

    sf::Texture texture;
    sf::Vector2u sprite_size;
    ConfigData();
};
};