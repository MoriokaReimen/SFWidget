#include "SFWidget/CircleToggle.hpp"
#include "SFWidget/ConfigData.hpp"
#include <iostream>
namespace sf {
extern ConfigData config; /* Implemented in ConfigData.cpp */

void CircleToggle::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(shape_, states);
} 

CircleToggle::CircleToggle(const float& radius)
    : on_pressed_call_back_(), on_released_call_back_(), shape_(radius), is_toggled_(false)
{
    /* Check if the texture loaded */
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTexture(&config.texture);
        shape_.setTextureRect(sf::IntRect(0, 4 * config.sprite_size.y, config.sprite_size.x, config.sprite_size.y));
    }
}

CircleToggle::~CircleToggle()
{
}

/* call back evocation */
void CircleToggle::on_pressed()
{
    is_toggled_ = !is_toggled_;
    if(on_pressed_call_back_)
    on_pressed_call_back_();

    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        const auto sprite_x_origin = is_toggled_ ? config.sprite_size.x : 0u;
        shape_.setTextureRect(sf::IntRect(sprite_x_origin, 4 * config.sprite_size.y, config.sprite_size.x, config.sprite_size.y));
    } else {
        shape_.setFillColor(sf::Color::Red);
    }
}

void CircleToggle::on_released()
{
    if(on_released_call_back_)
    on_released_call_back_();

    if(config.texture.getSize() == sf::Vector2u(0u, 0u))
    {
        shape_.setFillColor(sf::Color::White);
    }
}

/* call back setter */
void CircleToggle::set_on_pressed_call_back(const std::function<void()>& func)
{
    on_pressed_call_back_ = func;
}

void CircleToggle::set_on_released_call_back(const std::function<void()>& func)
{
    on_released_call_back_ = func;
}

/* is functions */
bool CircleToggle::is_hovering(const sf::Vector2f& mouse_position) const
{
    auto inverse_transform = getInverseTransform();
    auto local_mouse_position = inverse_transform * mouse_position;

    return shape_.getGlobalBounds().contains(local_mouse_position);
}
CircleToggle::operator bool() const
{
    return is_toggled_;
}
};