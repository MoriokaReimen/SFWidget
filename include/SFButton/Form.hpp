#pragma once
#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace sf
{
class IWidget;
class Label;
class RectangleButton;
class CircleButton;
struct ConfigData;

class Form : public sf::Drawable
{
    virtual void draw(RenderTarget &target, RenderStates states) const override; 
    std::vector<std::shared_ptr<IWidget>> widgets_;
    std::shared_ptr<ConfigData> config_;
    sf::RenderWindow& window_;

public:
    Form(sf::RenderWindow& window);
    void process_events(const sf::Event&);
    void add_widget(std::shared_ptr<IWidget> widget);
    std::shared_ptr<Label> add_label(const sf::Vector2f& size = sf::Vector2f(0, 0));
    std::shared_ptr<CircleButton> add_circle_button(const float& radius = 0.f);
    std::shared_ptr<RectangleButton> add_rectangle_button(const sf::Vector2f& size = sf::Vector2f(0, 0));
    ConfigData& config();
};

};