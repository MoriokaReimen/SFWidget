#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

namespace sf {

class IButton : public Drawable, public Transformable
{
public:
    virtual ~IButton() {};
    /* call back evocation */
    virtual void on_pressed() const = 0;
    virtual void on_released() const = 0;

    /* call back setter */
    virtual void set_on_pressed_call_back(const std::function<void()>& func) = 0;
    virtual void set_on_released_call_back(const std::function<void()>& func) = 0;

    /* is functions */
    virtual bool is_hovering(const sf::Vector2f& mouse_position) const = 0;
};

};