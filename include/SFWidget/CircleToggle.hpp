#pragma once

#include "SFWidget/IWidget.hpp"
#include <memory>

namespace sf
{
struct ConfigData;

class CircleToggle : public IWidget
{
    virtual void draw (RenderTarget &target, RenderStates states) const override; 
    std::function<void()> on_pressed_call_back_;
    std::function<void()> on_released_call_back_;

    sf::CircleShape shape_;
    bool is_toggled_;
public:
    explicit CircleToggle(const float& radius = 0.f);
    virtual ~CircleToggle();

    /* call back evocation */
    virtual void on_pressed() override;
    virtual void on_released() override;

    /* call back setter */
    virtual void set_on_pressed_call_back(const std::function<void()>& func) override;
    virtual void set_on_released_call_back(const std::function<void()>& func) override;

    /* is functions */
    virtual bool is_hovering(const sf::Vector2f& mouse_position) const override;
    explicit operator bool() const;
};

};