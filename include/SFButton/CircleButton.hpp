#pragma once

#include "IButton.hpp"
#include <memory>

namespace sf
{
struct ConfigData;

class CircleButton : public IButton
{
    virtual void draw (RenderTarget &target, RenderStates states) const override; 
    std::function<void()> on_pressed_call_back_;
    std::function<void()> on_released_call_back_;
    std::shared_ptr<ConfigData> config_;
    sf::CircleShape circle_;

public:
    CircleButton(std::shared_ptr<ConfigData> config);
    virtual ~CircleButton();

    /* call back evocation */
    virtual void on_pressed() const override;
    virtual void on_released() const override;

    /* call back setter */
    virtual void set_on_pressed_call_back(const std::function<void()>& func) override;
    virtual void set_on_released_call_back(const std::function<void()>& func) override;

    /* is functions */
    virtual bool is_hovering(const sf::Vector2f& mouse_position) const override;
};

};