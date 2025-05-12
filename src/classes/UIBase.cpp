//
// Created by jaden on 5/11/2025.
//

#include "UIBase.h"

UIBase::~UIBase() = default;

sf::Vector2f UIBase::getPosition() const {
    return rect.getPosition();
}

sf::Vector2f UIBase::getSize() const {
    return rect.getSize();
}

float UIBase::getRotation() const {
    return rect.getRotation().asDegrees();
}

sf::Color UIBase::getColor() const {
    return rect.getFillColor();
}

sf::Color UIBase::getBorderColor() const {
    return rect.getOutlineColor();
}

float UIBase::getBorderThickness() const {
    return rect.getOutlineThickness();
}

bool UIBase::getVisibility() const {
    return visible;
}

float UIBase::getTransparency() const {
    return transparency;
}

void UIBase::setPosition(const sf::Vector2f& position) {
    this->rect.setPosition(position);
}

void UIBase::setPosition(const float& x, const float& y) {
    this->rect.setPosition(sf::Vector2f{x, y});
}

void UIBase::setSize(const sf::Vector2f& size) {
    this->rect.setSize(size);
}

void UIBase::setSize(const float& width, const float& height) {
    this->rect.setSize(sf::Vector2f{width, height});
}

void UIBase::setRotation(const float& rotation) {
    this->rect.setRotation(sf::degrees(rotation));
}

void UIBase::setColor(const sf::Color& color) {
    // Transparency of rect::Shape objects are controlled by their color value and must be maintained.
    const std::uint8_t alpha = this->transparency * 255;
    const auto fullColor = sf::Color(color.r, color.g, color.b, alpha);
    this->rect.setFillColor(fullColor);
}

void UIBase::setBorderColor(const sf::Color& color) {
    this->rect.setOutlineColor(color);
}

void UIBase::setBorderThickness(const float& thickness) {
    this->rect.setOutlineThickness(thickness);
}

void UIBase::setVisibility(const bool& visible) {
    this->visible = visible;
}

void UIBase::setTransparency(const float& transparency) {
    // Ensure that the transparency value stays within an appropriate range.
    if (transparency < 0.0f) {
        this->transparency = 0.0f;
    } else if (transparency > 1.0f) {
        this->transparency = 1.0f;
    } else {
        this->transparency = transparency;
    }

    // Transparency of rect::Shape objects are controlled by their color value.
    const std::uint8_t alpha = this->transparency * 255;
    const auto color = this->rect.getFillColor();
    const auto fullColor = sf::Color(color.r, color.g, color.b, alpha);
    this->rect.setFillColor(fullColor);
}
