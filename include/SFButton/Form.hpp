#pragma once
#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace sf
{
class IWidget;
struct ConfigData;

class Form : public sf::Drawable
{
    virtual void draw(RenderTarget &target, RenderStates states) const override; 
    std::vector<std::shared_ptr<IWidget>> widgets_;
    std::shared_ptr<ConfigData> config_;

public:
    Form();
    void process_events(const sf::Event&);
    void add_button(std::shared_ptr<IWidget> button);
    ConfigData& get_config();
};

};