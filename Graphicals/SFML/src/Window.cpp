/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Window
*/

#include "GraphicalFactorySFML.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

std::unordered_map<int, bool> keyState;

void WindowSFML::initWindow(std::string name, size_t width, size_t height)
{
    _window = new sf::RenderWindow(sf::VideoMode(width, height), name);
    _window->setFramerateLimit(60);
    _window->setKeyRepeatEnabled(false);
};

void WindowSFML::closeWindow()
{
    _window->close();
};

bool WindowSFML::windowIsOpen()
{
    return _window->isOpen();;
};

void WindowSFML::clear()
{
    _window->clear();
};

void WindowSFML::display()
{
   _window->display();
};

void WindowSFML::eventPollEvent()
{

    while (_window->pollEvent(event)) {
        switch (event.type) {
            case (sf::Event::Closed):
                return callEvent(EventType::QUIT);
            case (sf::Event::KeyPressed):
                if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q)
                    return callEvent(EventType::LEFT_pressed);

                else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
                    return callEvent(EventType::RIGHT_pressed);

                else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z)
                    return callEvent(EventType::UP_pressed);

                else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                    return callEvent(EventType::DOWN_pressed);

                else if (event.key.code == sf::Keyboard::Y)
                    return callEvent(EventType::NEXT_LIB);

                else if (event.key.code == sf::Keyboard::U) {
                    std::cout << "Enter pressed" << std::endl;
                    return callEvent(EventType::NEXT_GAME);
                }

                else if (event.key.code == sf::Keyboard::I)
                    return callEvent(EventType::RESTART);

                else if (event.key.code == sf::Keyboard::O)
                    return callEvent(EventType::GO_TO_MENU);

                else if (event.key.code == sf::Keyboard::P)
                    return callEvent(EventType::QUIT);

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    return callEvent(EventType::ENTER_pressed);
                break;
            default:
                break;
        }
    }
};

void WindowSFML::callEvent(const IWindow::EventType eventType) {
    if (_eventBinding.count(eventType) <= 0)
        throw std::runtime_error("--! [GAME Logic] no event binded");
    _eventBinding[eventType]();
}

void WindowSFML::loadEventBindings(EventHandler &eventBinding) {
    for (auto const& binding : eventBinding) {
        auto it = _eventBinding.find(binding.first);
        if (it != _eventBinding.end())
            it->second = binding.second;
        else
            _eventBinding.insert(binding);
    }
};

//Entity
std::unique_ptr<IText> WindowSFML::createIText() {
    return std::make_unique<TextSFML>(_window);
}

std::unique_ptr<IGrid> WindowSFML::createIGrid() {
    return std::make_unique<GridSFML>(_window);
}
