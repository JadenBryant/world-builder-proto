//
// Created by jaden on 5/11/2025.
//

#include "TextLabel.h"

#include <iostream>

#include "SFML/Graphics.hpp"

TextLabel::TextLabel(): textObject(font) {
    if (!font.openFromFile("../../src/resources/fonts/Arial.ttf")) { // TODO: Fix this.
        std::cerr << "Failed to load font" << std::endl;
    }

    UIBase::setSize(sf::Vector2f(250, 50));
    UIBase::setColor(sf::Color::White);
    UIBase::setBorderColor(sf::Color::Black);
    UIBase::setBorderThickness(1);
    textObject.setFont(font);
    textObject.setCharacterSize(15);
    textObject.setFillColor(sf::Color::Black);
    textObject.setString("TextLabel");
    updateTextPosition();
}

void TextLabel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect, states);
    target.draw(textObject, states);
}

std::string TextLabel::getText() const {
    return textObject.getString();
}

unsigned int TextLabel::getTextSize() const {
    return textObject.getCharacterSize();
}

sf::Color TextLabel::getTextColor() const {
    return textObject.getFillColor();
}

void TextLabel::setPosition(const sf::Vector2f &position) {
    UIBase::setPosition(position);
    updateTextPosition();
}

void TextLabel::setPosition(const float &x, const float &y) {
    UIBase::setPosition(x, y);
    updateTextPosition();
}

void TextLabel::setText(const std::string& text) {
    textObject.setString(text);
}

void TextLabel::setTextSize(const unsigned int& size) {
    textObject.setCharacterSize(size);
}

void TextLabel::setTextColor(const sf::Color& color) {
    textObject.setFillColor(color);
}

void TextLabel::updateTextPosition() {
    // TODO: Add an alignment property and modify this function accordingly.
    sf::FloatRect textBounds = textObject.getLocalBounds();
    sf::FloatRect rectBounds = rect.getGlobalBounds();

    textObject.setOrigin({
        textBounds.position.x + textBounds.size.x / 2,
        textBounds.position.y + textBounds.size.y / 2
    }); // may need to use getSize().
    textObject.setPosition({
        rectBounds.position.x + rectBounds.size.x / 2,
        rectBounds.position.y + rectBounds.size.y / 2
    });
}
