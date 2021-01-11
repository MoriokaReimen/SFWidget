#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
struct ConfigData
{
    sf::Font font;
    sf::Color font_released_color;
    sf::Color font_pressed_color;
    unsigned int font_size;
    sf::Texture texture;
};
};