#pragma once

#include "SFWidget/IWidget.hpp"
#include <memory>

namespace sf
{
struct ConfigData;

class CircleButton : public IWidget
{
    virtual void draw (RenderTarget &target, RenderStates states) const override; 
    std::function<void()> on_pressed_call_back_;
    std::function<void()> on_released_call_back_;

    sf::CircleShape shape_;
    sf::Text text_;
public:
    explicit CircleButton(const float& radius = 0.f);
    virtual ~CircleButton();

    /* text handling */
    void set_text(const std::string& text);
    std::string get_text() const;

    /* call back evocation */
    virtual void on_pressed() override;
    virtual void on_released() override;
    virtual void on_text_entered(const sf::Uint32& ch) override;

    /* call back setter */
    virtual void set_on_pressed_call_back(const std::function<void()>& func) override;
    virtual void set_on_released_call_back(const std::function<void()>& func) override;

    /* is functions */
    virtual bool is_hovering(const sf::Vector2f& mouse_position) const override;
};

};