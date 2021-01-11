#include "SFButton/CircleButton.hpp"
#include "SFButton/ConfigData.hpp"
#include <iostream>
namespace sf {
extern ConfigData config; /* Implemented in ConfigData.cpp */

void CircleButton::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(shape_, states);
} 

CircleButton::CircleButton(const float& radius)
    : on_pressed_call_back_(), on_released_call_back_(), shape_(radius)
{
    text_.setFont(config.font);
    text_.setFillColor(config.font_color);
    text_.setCharacterSize(20);

    /* Check if the texture loaded */
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTexture(&config.texture);
        shape_.setTextureRect(sf::IntRect(0, 50, 50, 50));
    }
}

CircleButton::~CircleButton()
{
}

/* call back evocation */
void CircleButton::on_pressed()
{
    if(on_pressed_call_back_)
    on_pressed_call_back_();
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTextureRect(sf::IntRect(50, 50, 50, 50));
    } else {
        shape_.setFillColor(sf::Color::Red);
    }
}

void CircleButton::on_released()
{
    if(on_released_call_back_)
    on_released_call_back_();
    shape_.setFillColor(sf::Color::White);
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTextureRect(sf::IntRect(0, 50, 50, 50));
    } else {
        shape_.setFillColor(sf::Color::White);
    }
}

/* call back setter */
void CircleButton::set_on_pressed_call_back(const std::function<void()>& func)
{
    on_pressed_call_back_ = func;
}

void CircleButton::set_on_released_call_back(const std::function<void()>& func)
{
    on_released_call_back_ = func;
}

/* is functions */
bool CircleButton::is_hovering(const sf::Vector2f& mouse_position) const
{
    auto inverse_transform = getInverseTransform();
    auto local_mouse_position = inverse_transform * mouse_position;

    return shape_.getGlobalBounds().contains(local_mouse_position);
}
};