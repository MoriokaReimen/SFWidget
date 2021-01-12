#pragma once
#include <memory>

#include "SFWidget/IWidget.hpp"
#include "SFWidget/ConfigData.hpp"

namespace sf
{
struct ConfigData;

class Label : public IWidget
{
    virtual void draw (RenderTarget &target, RenderStates states) const override; 
    std::function<void()> on_pressed_call_back_;
    std::function<void()> on_released_call_back_;
    sf::RectangleShape shape_;
    sf::Text text_;

public:
    explicit Label(const sf::Vector2f& size = sf::Vector2f(0, 0));
    virtual ~Label();

    /* text function */
    void set_text(const std::string& text, const bool& adjust_shape = false);
    std::string get_text() const;

    /* call back evocation */
    virtual void on_pressed() override;
    virtual void on_released() override;

    /* call back setter */
    virtual void set_on_pressed_call_back(const std::function<void()>& func) override;
    virtual void set_on_released_call_back(const std::function<void()>& func) override;

    /* is functions */
    virtual bool is_hovering(const sf::Vector2f& mouse_position) const override;
};

};