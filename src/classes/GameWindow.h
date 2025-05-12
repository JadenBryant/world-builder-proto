//
// Created by jaden on 5/11/2025.
//

#pragma once
#include <iostream>
#include "../constants.h"
#include "SFML/Graphics/RenderWindow.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Singleton class
class GameWindow {
public:
    static void init() {
        if (window.isOpen()) {
            std::cout << "Window has already been initialized." << std::endl;
            return;
        }
        window.create(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), GAME_TITLE);
    }

    static void init(const sf::Vector2u& size, const std::string& title) {
        if (window.isOpen()) {
            std::cout << "Window has already been initialized." << std::endl;
            return;
        }
        window.create(sf::VideoMode(size), title);
    }

    static void init(const unsigned int& width, const unsigned int& height, const std::string& title) {
        if (window.isOpen()) {
            std::cout << "Window has already been initialized." << std::endl;
        }
        window.create(sf::VideoMode({width, height}), title);
    }

    static sf::RenderWindow& getWindow() {
        if (!window.isOpen()) {
            std::cout << "Window has not been initialized - call GameWindow::init()." << std::endl;
        }
        return window;
    }
private:
    static sf::RenderWindow window;

    GameWindow() = default;
    GameWindow(const GameWindow&) = delete;
    GameWindow& operator=(const GameWindow&) = delete;
};

sf::RenderWindow GameWindow::window;