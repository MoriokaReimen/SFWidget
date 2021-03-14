#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

namespace sf {

class IWidget : virtual public Drawable, virtual public Transformable
{
public:
    virtual ~IWidget() {};
    /* call back evocation */
    virtual void on_pressed() = 0;
    virtual void on_released() = 0;
    virtual void on_text_entered(const sf::Uint32& ch) = 0;

    /* call back setter */
    virtual void set_on_pressed_call_back(const std::function<void()>& func) = 0;
    virtual void set_on_released_call_back(const std::function<void()>& func) = 0;

    /* is functions */
    virtual bool is_hovering(const sf::Vector2f& mouse_position) const = 0;
};

};