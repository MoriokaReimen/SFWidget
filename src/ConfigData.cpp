#include "SFWidget/ConfigData.hpp"

namespace sf
{
ConfigData config;

ConfigData::ConfigData()
    :
    button_font(), button_font_released_color(sf::Color::Black), button_font_pressed_color(sf::Color::Yellow), button_font_size(50),
    label_font(), label_font_color(sf::Color::Black), label_font_size(60),
    texture(), sprite_size{200u, 200u}
{
    button_font.loadFromFile("resource/digital-7.ttf");
    label_font.loadFromFile("resource/ipamjm.ttf");
    texture.loadFromFile("resource/Texture.png");
}

};
