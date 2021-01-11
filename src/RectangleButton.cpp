#include "SFButton/RectangleButton.hpp"
#include "SFButton/ConfigData.hpp"

namespace sf {
void RectangleButton::draw(RenderTarget &target, RenderStates states) const
{

} 

RectangleButton::RectangleButton(std::shared_ptr<ConfigData>& config)
    : on_pressed_call_back_(), on_released_call_back_(), config_(config)
{
}

RectangleButton::~RectangleButton()
{
}

/* call back evocation */
void RectangleButton::on_pressed() const
{
    on_pressed_call_back_();
}

void RectangleButton::on_released() const
{
    on_released_call_back_();
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
    return true;
}
};