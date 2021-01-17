#include "SFWidget/Form.hpp"
#include "SFWidget/ConfigData.hpp"
#include "SFWidget/IWidget.hpp"
#include "SFWidget/Label.hpp"
#include "SFWidget/CircleButton.hpp"
#include "SFWidget/CircleToggle.hpp"
#include "SFWidget/RectangleButton.hpp"
#include "SFWidget/RectangleToggle.hpp"

namespace sf
{
extern ConfigData config;

void Form::draw(RenderTarget &target, RenderStates states) const
{
    for(const auto& button : widgets_)
    {
        target.draw(*button.get(), states);
    }

}

Form::Form(sf::RenderWindow& window)
    : widgets_(), window_(window)
{
}

void Form::process_events(const sf::Event& event)
{
    for(const auto& button : widgets_)
    {
        const auto pos = sf::Vector2f(window_.mapPixelToCoords(sf::Mouse::getPosition(window_)));
        if(button->is_hovering(pos) and (event.type== event.MouseButtonPressed))
        {
            button->on_pressed();
        }

        if(button->is_hovering(pos) and (event.type == event.MouseButtonReleased))
        {
            button->on_released();
        }      
    }
}

void Form::add_widget(std::shared_ptr<IWidget> widget)
{
    widgets_.push_back(widget);
}
std::shared_ptr<Label> Form::add_label(const sf::Vector2f& size)
{
    auto label = std::make_shared<Label>(size);
    add_widget(label);
    return label;
}

std::shared_ptr<CircleButton> Form::add_circle_button(const float& radius)
{
    auto circle_button = std::make_shared<CircleButton>(radius);
    add_widget(circle_button);

    return circle_button;
}

std::shared_ptr<CircleToggle> Form::add_circle_toggle(const float& radius)
{
    auto circle_toggle = std::make_shared<CircleToggle>(radius);
    add_widget(circle_toggle);
    return circle_toggle;
}

std::shared_ptr<RectangleButton> Form::add_rectangle_button(const sf::Vector2f& size)
{
    auto rectangle_button = std::make_shared<RectangleButton>(size);
    add_widget(rectangle_button);
    return rectangle_button;
}

std::shared_ptr<RectangleToggle> Form::add_rectangle_toggle(const sf::Vector2f& size)
{
    auto rectangle_toggle = std::make_shared<RectangleToggle>(size);
    add_widget(rectangle_toggle);
    return rectangle_toggle;
}

ConfigData& Form::config()
{
    return sf::config;
}
};