#include "SFButton/Form.hpp"
#include "SFButton/ConfigData.hpp"
#include "SFButton/IButton.hpp"

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

Form::Form()
    : widgets_(), config_(std::make_shared<ConfigData>())
{
}

void Form::process_events(const sf::Event& event)
{
    for(const auto& button : widgets_)
    {
        const auto& pos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
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

void Form::add_button(std::shared_ptr<IWidget> button)
{
    widgets_.push_back(button);
}

ConfigData& Form::get_config()
{
    return config;
}
};