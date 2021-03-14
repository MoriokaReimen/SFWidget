#include "SFWidget/RectangleToggle.hpp"
#include "SFWidget/ConfigData.hpp"


namespace sf {
extern ConfigData config; /* Implemented in ConfigData.cpp */

void RectangleToggle::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(shape_, states);
} 

RectangleToggle::RectangleToggle(const sf::Vector2f& size)
    : on_pressed_call_back_(), on_released_call_back_(), shape_(size), is_toggled_(false)
{
    /* Check if the texture loaded */
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTexture(&config.texture);
        shape_.setTextureRect(sf::IntRect(0, 3 * config.sprite_size.y, config.sprite_size.x, config.sprite_size.y));
    }
}

RectangleToggle::~RectangleToggle()
{
}

/* call back evocation */
void RectangleToggle::on_pressed()
{
    is_toggled_ = !is_toggled_;

    if(on_pressed_call_back_)
    on_pressed_call_back_();
    
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        const auto sprite_x_origin = is_toggled_ ? config.sprite_size.x : 0u;
        shape_.setTextureRect(sf::IntRect(sprite_x_origin, 3 * config.sprite_size.y, config.sprite_size.x, config.sprite_size.y));
    } else {
        shape_.setFillColor(sf::Color::Red);
    }
}

void RectangleToggle::on_released()
{
    if(on_released_call_back_)
    on_released_call_back_();
    if(config.texture.getSize() == sf::Vector2u(0u, 0u))
    {
        shape_.setFillColor(sf::Color::White);
    }
}

void RectangleToggle::on_text_entered(const sf::Uint32& ch)
{
    /* Do nothing */
}

/* call back setter */
void RectangleToggle::set_on_pressed_call_back(const std::function<void()>& func)
{
    on_pressed_call_back_ = func;
}

void RectangleToggle::set_on_released_call_back(const std::function<void()>& func)
{
    on_released_call_back_ = func;
}

/* is functions */
bool RectangleToggle::is_hovering(const sf::Vector2f& mouse_position) const
{
    auto inverse_transform = getInverseTransform();
    auto local_mouse_position = inverse_transform * mouse_position;

    return shape_.getGlobalBounds().contains(local_mouse_position);
}

RectangleToggle::operator bool() const
{
    return is_toggled_;
}
};