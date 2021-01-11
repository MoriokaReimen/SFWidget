#include "SFButton/RectangleButton.hpp"
#include "SFButton/ConfigData.hpp"


namespace sf {
extern ConfigData config; /* Implemented in ConfigData.cpp */

void RectangleButton::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(shape_, states);

    target.draw(text_, states);
} 

RectangleButton::RectangleButton(const sf::Vector2f& size)
    : on_pressed_call_back_(), on_released_call_back_(), shape_(size)
{
    text_.setFont(config.font);
    text_.setFillColor(config.font_color);
    text_.setCharacterSize(20);
}

RectangleButton::~RectangleButton()
{
}

void RectangleButton::set_text(const std::string& text, const bool& adjust_shape)
{
    text_.setString(text);
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
    shape_.setFillColor(sf::Color::Red);
}

void RectangleButton::on_released()
{
    if(on_released_call_back_)
    on_released_call_back_();
    shape_.setFillColor(sf::Color::White);
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