#include <windows.h>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "classes/GameWindow.h"
#include "classes/TextLabel.h"

sf::RenderWindow& initGameWindow() {
    GameWindow::init();

    auto& window = GameWindow::getWindow();
    window.setTitle(GAME_TITLE);
    window.setFramerateLimit(144);
    ::ShowWindow(window.getNativeHandle(), SW_MAXIMIZE);
    // TODO: window.setIcon();

    return window;
}

int main() {
    auto& window = initGameWindow();
    auto myTextLabel = TextLabel();
    myTextLabel.setText("Hello, World!");
    myTextLabel.setPosition(sf::Vector2f(window.getSize().x / 2 - myTextLabel.getSize().x / 2, window.getSize().y / 2 - myTextLabel.getSize().y / 2));

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(myTextLabel);
        window.display();
    }
}
