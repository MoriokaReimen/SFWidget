#pragma once
#include <memory>

#include "SFButton/IButton.hpp"
#include "SFButton/ConfigData.hpp"

namespace sf
{
struct ConfigData;

class RectangleButton : public IWidget
{
    virtual void draw (RenderTarget &target, RenderStates states) const override; 
    std::function<void()> on_pressed_call_back_;
    std::function<void()> on_released_call_back_;
    std::shared_ptr<ConfigData> config_;

public:
    RectangleButton(std::shared_ptr<ConfigData>& config);
    virtual ~RectangleButton();

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