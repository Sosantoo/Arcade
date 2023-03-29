/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** sfml
*/

#pragma once
#include "../../Interface/AGraphical.hpp"
#include <SFML/Graphics.hpp>

struct GraphicalInfo {
        sf::Sprite sprite;
        sf::Texture texture;
        sf::RenderWindow window;
        sf::Event event;
        void loadFont();
        void loadImage();
        GraphicalInfo() = default;
};

class AGraphicalSFML : public AGraphical<GraphicalInfo>
{
    public:
        AGraphicalSFML() = default;
        ~AGraphicalSFML() = default;

        // base
        void loadResource() override;
        void destroyRessource() override;

        // Iwindow
        void initWindow(std::string name, std::pair<size_t, size_t> size) override;
        void closeWindow() override;
        bool windowIsOpen() override;
        void clear() override;
        void display() override;

        // event
        void eventPollEvent() override;

        // Clock
        //  IClock &getClock(){};

        // IEntity
        void create(){};
        void setSize(){};
        void setPosition(){};
        void destroy(){};
        void displayEntity(std::vector<IEntity>) override{};
};
