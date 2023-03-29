/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalSDL2
*/

#pragma once
#include "../../Interface/AGraphical.hpp"
#include <SDL2/SDL.h>

struct GraphicalInfo {
        SDL_Window *window{nullptr};
        SDL_Event event{};
        bool isOpen{false};
        AClock clock;
};

class AGraphicalSDL2 : public AGraphical<GraphicalInfo>
{
    public:
        AGraphicalSDL2() = default;
        ~AGraphicalSDL2() = default;

        // base
        void loadResource() final;
        void destroyRessource() final;

        // Iwindow
        void initWindow(std::string name, std::pair<size_t, size_t> size) final;
        void closeWindow() final;
        bool windowIsOpen() final;
        void clear() final;
        void display() final;

        // event
        void eventPollEvent() final;

        // Clock
        IClock &getClock() final;
};
