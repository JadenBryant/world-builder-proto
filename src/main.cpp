#include <windows.h>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "classes/GameWindow.h"

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
    auto &window = initGameWindow();

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.display();
    }
}
