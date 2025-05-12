//
// Created by jaden on 5/11/2025.
//

#pragma once
#include "Object.h"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class UIBase : public Object, public sf::Drawable {
public:
    ~UIBase() override = 0;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;

    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    float getRotation() const;
    sf::Color getColor() const;
    sf::Color getBorderColor() const;
    float getBorderThickness() const;
    bool getVisibility() const;
    float getTransparency() const;

    virtual void setPosition(const sf::Vector2f& position);
    virtual void setPosition(const float& x, const float& y);
    void setSize(const sf::Vector2f& size);
    void setSize(const float& width, const float& height);
    void setRotation(const float& rotation);
    void setColor(const sf::Color& color);
    void setBorderColor(const sf::Color& color);
    void setBorderThickness(const float& thickness);
    void setVisibility(const bool& visible);
    void setTransparency(const float& transparency);
protected:
    sf::RectangleShape rect;
private:
    std::string name = "UIBase";
    const std::string className = "UIBase";
    bool visible = true;
    float transparency = 0;
};
