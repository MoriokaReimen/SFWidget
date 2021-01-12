#include "SFWidget/Label.hpp"
#include "SFWidget/ConfigData.hpp"
#include <cassert>


namespace sf {
extern ConfigData config; /* Implemented in ConfigData.cpp */

void Label::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(shape_, states);
    if(!text_.getString().isEmpty())
    {
        target.draw(text_, states);
    }
} 

Label::Label(const sf::Vector2f& size)
    : on_pressed_call_back_(), on_released_call_back_(), shape_(size)
{
    text_.setFont(config.label_font);
    text_.setFillColor(config.label_font_color);
    text_.setCharacterSize(config.label_font_size);

    /* Check if the texture loaded */
    if(config.texture.getSize() != sf::Vector2u(0u, 0u))
    {
        shape_.setTexture(&config.texture);
        shape_.setTextureRect(sf::IntRect(0, 2 * config.sprite_size.y, config.sprite_size.x, config.sprite_size.y));
    }
}

Label::~Label()
{
}

/* text handling */
void Label::set_text(const std::string& text, const bool& adjust_shape)
{
    text_.setString(text);
    auto text_bounds = text_.getLocalBounds();
    shape_.setSize(sf::Vector2f(1.2f * text_bounds.width, 1.1f * text_bounds.height));
    const auto circle_bounds = shape_.getLocalBounds();
    text_.setOrigin(text_bounds.left + text_bounds.width/2.f, text_bounds.top + text_bounds.height/2.f);
    text_.setPosition(shape_.getSize().x /2.f, shape_.getSize().y/2.f);
}

std::string Label::get_text() const
{
    return text_.getString();
}

/* call back evocation */
void Label::on_pressed()
{
    /* Do nothing */
}

void Label::on_released()
{
    /* Do nothing */
}

/* call back setter */
void Label::set_on_pressed_call_back(const std::function<void()>& func)
{
    assert(!"This manipulation on label is not implemented");
}

void Label::set_on_released_call_back(const std::function<void()>& func)
{
    assert(!"This manipulation on label is not implemented");
}

/* is functions */
bool Label::is_hovering(const sf::Vector2f& mouse_position) const
{
    auto inverse_transform = getInverseTransform();
    auto local_mouse_position = inverse_transform * mouse_position;

    return shape_.getGlobalBounds().contains(local_mouse_position);
}

};