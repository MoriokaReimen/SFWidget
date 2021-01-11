#include "SFButton/CircleButton.hpp"
#include "SFButton/ConfigData.hpp"
#include <iostream>
namespace sf {
void CircleButton::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(shape_, states);
} 

CircleButton::CircleButton(const float& radius)
    : on_pressed_call_back_(), on_released_call_back_(), shape_(radius)
{
}

CircleButton::~CircleButton()
{
}

/* call back evocation */
void CircleButton::on_pressed() const
{
    if(on_pressed_call_back_)
    on_pressed_call_back_();
}

void CircleButton::on_released() const
{
    if(on_released_call_back_)
    on_released_call_back_();
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

    return shape_.getLocalBounds().contains(local_mouse_position);
}
};