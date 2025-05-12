//
// Created by jaden on 5/11/2025.
//

#pragma once
#include "UIBase.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

class TextLabel : public UIBase {
public:
    TextLabel();
    ~TextLabel() override = default;

    std::string getText() const;
    unsigned int getTextSize() const;
    sf::Color getTextColor() const;

    void setPosition(const sf::Vector2f &position) override;
    void setPosition(const float &x, const float &y) override;
    void setText(const std::string& text);
    void setTextSize(const unsigned int& size);
    void setTextColor(const sf::Color& color);
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Font font;
    sf::Text textObject;
private:
    std::string name = "TextLabel";
    const std::string className = "TextLabel";
    void updateTextPosition();
};
