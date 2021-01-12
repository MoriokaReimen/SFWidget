#include "SFButton/RectangleButton.hpp"
#include "SFButton/ConfigData.hpp"


namespace sf {
extern ConfigData config; /* Implemented in ConfigData.cpp */

void RectangleButton::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(shape_, states);
    if(!text_.getString().isEmpty())
    {
        target.draw(text_, states);
    }
} 

RectangleButton::RectangleButton(const sf::Vector2f& size)
    : on_pressed_call_back_(), on_released_call_back_(), shape_(size)
{
    text_.setFont(config.button_font);
    text_.setFillColor(config.button_font_released_color);
    text_.setCharacterSize(config.button_font_size);

    /* Check if the texture loaded */
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTexture(&config.texture);
        shape_.setTextureRect(sf::IntRect(0, 0, config.sprite_size.x, config.sprite_size.y));
    }
}

RectangleButton::~RectangleButton()
{
}

/* text handling */
void RectangleButton::set_text(const std::string& text, const bool& adjust_shape)
{
    text_.setString(text);
    auto text_bounds = text_.getLocalBounds();
    shape_.setSize(sf::Vector2f(1.5f * text_bounds.width, 1.5f * text_bounds.height));
    const auto circle_bounds = shape_.getLocalBounds();
    text_.setOrigin(text_bounds.left + text_bounds.width/2.f, text_bounds.top + text_bounds.height/2.f);
    text_.setPosition(shape_.getSize().x /2.f, shape_.getSize().y/2.f);
}

std::string RectangleButton::get_text() const
{
    return text_.getString();
}

/* call back evocation */
void RectangleButton::on_pressed()
{
    if(on_pressed_call_back_)
    on_pressed_call_back_();
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTextureRect(sf::IntRect(config.sprite_size.y, 0, config.sprite_size.x, config.sprite_size.y));
    } else {
        shape_.setFillColor(sf::Color::Red);
    }

    if(!text_.getString().isEmpty())
    {
        text_.setFillColor(config.button_font_pressed_color);
    }
}

void RectangleButton::on_released()
{
    if(on_released_call_back_)
    on_released_call_back_();
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTextureRect(sf::IntRect(0, 0, config.sprite_size.x, config.sprite_size.y));
    } else {
        shape_.setFillColor(sf::Color::White);
    }

    if(!text_.getString().isEmpty())
    {
        text_.setFillColor(config.button_font_released_color);
    }
}

/* call back setter */
void RectangleButton::set_on_pressed_call_back(const std::function<void()>& func)
{
    on_pressed_call_back_ = func;
}

void RectangleButton::set_on_released_call_back(const std::function<void()>& func)
{
    on_released_call_back_ = func;
}

/* is functions */
bool RectangleButton::is_hovering(const sf::Vector2f& mouse_position) const
{
    auto inverse_transform = getInverseTransform();
    auto local_mouse_position = inverse_transform * mouse_position;

    return shape_.getGlobalBounds().contains(local_mouse_position);
}

};