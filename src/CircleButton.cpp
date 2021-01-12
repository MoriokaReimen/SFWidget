#include "SFButton/CircleButton.hpp"
#include "SFButton/ConfigData.hpp"
#include <iostream>
namespace sf {
extern ConfigData config; /* Implemented in ConfigData.cpp */

void CircleButton::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(shape_, states);
    if(!text_.getString().isEmpty())
    {
        target.draw(text_, states);
    }
} 

CircleButton::CircleButton(const float& radius)
    : on_pressed_call_back_(), on_released_call_back_(), shape_(radius)
{
    text_.setFont(config.button_font);
    text_.setFillColor(config.button_font_released_color);
    text_.setCharacterSize(config.button_font_size);

    /* Check if the texture loaded */
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTexture(&config.texture);
        shape_.setTextureRect(sf::IntRect(0, config.sprite_size.x, config.sprite_size.x, config.sprite_size.y));
    }
}

CircleButton::~CircleButton()
{
}

/* text handling */
void CircleButton::set_text(const std::string& text)
{
    text_.setString(text);
    auto text_bounds = text_.getLocalBounds();
    shape_.setRadius(1.5f * std::max(text_bounds.width /2.f, text_bounds.height / 2.f));
    const auto circle_bounds = shape_.getLocalBounds();
    text_.setOrigin(text_bounds.left + text_bounds.width/2.f, text_bounds.top + text_bounds.height/2.f);
    text_.setPosition(shape_.getRadius(), shape_.getRadius());
}

std::string CircleButton::get_text() const
{
    return text_.getString();
}

/* call back evocation */
void CircleButton::on_pressed()
{
    if(on_pressed_call_back_)
    on_pressed_call_back_();

    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTextureRect(sf::IntRect(config.sprite_size.x, config.sprite_size.y, config.sprite_size.x, config.sprite_size.y));
    } else {
        shape_.setFillColor(sf::Color::Red);
    }

    if(!text_.getString().isEmpty())
    {
        text_.setFillColor(config.button_font_pressed_color);
    }
}

void CircleButton::on_released()
{
    if(on_released_call_back_)
    on_released_call_back_();

    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTextureRect(sf::IntRect(0, config.sprite_size.y, config.sprite_size.x, config.sprite_size.y));
    } else {
        shape_.setFillColor(sf::Color::White);
    }

    if(!text_.getString().isEmpty())
    {
        text_.setFillColor(config.button_font_released_color);
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