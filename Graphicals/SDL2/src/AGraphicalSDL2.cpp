/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalSDL2Window
*/

#include "sdl2.hpp"

void AGraphicalSDL2::loadResource()
{

}

void AGraphicalSDL2::destroyRessource()
{
    std::cout << "[SDL2] destroyRessource" << std::endl;
    SDL_Quit();
}

void AGraphicalSDL2::initWindow(std::string name, std::pair<size_t, size_t> size)
{
    std::cout << "[SDL2] initWindow" << std::endl;
    SDL_Init(SDL_INIT_VIDEO);

    graphicalInfo.window = SDL_CreateWindow(name.c_str(),
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          size.first, size.second,
                                          SDL_WINDOW_SHOWN);
    if (graphicalInfo.window == NULL) {
        SDL_GetError();
        throw std::runtime_error("c'est null");
    }
    graphicalInfo.isOpen = true;
};

void AGraphicalSDL2::closeWindow()
{
    graphicalInfo.isOpen = false;
    SDL_DestroyWindow(graphicalInfo.window);
};

bool AGraphicalSDL2::windowIsOpen()
{
    return graphicalInfo.isOpen;
};

void AGraphicalSDL2::clear()
{
};

void AGraphicalSDL2::display()
{
};

void AGraphicalSDL2::eventPollEvent()
{
    while (SDL_PollEvent(&graphicalInfo.event)) {
        switch (graphicalInfo.event.type )
        {
        case SDL_QUIT:
            callEvent(IWindow::EventType::QUIT);
            break;
        case SDL_KEYDOWN:
            switch (graphicalInfo.event.key.keysym.sym) {
                case SDLK_DOWN:
                case SDLK_s:
                    return callEvent(IWindow::EventType::DOWN_pressed);
                case SDLK_UP:
                case SDLK_z:
                    return callEvent(IWindow::EventType::UP_pressed);
                    break;
                case SDLK_LEFT:
                case SDLK_q:
                    return callEvent(IWindow::EventType::LEFT_pressed);
                case SDLK_RIGHT:
                case SDLK_d:
                    return callEvent(IWindow::EventType::RIGHT_pressed);
                    break;
                case SDLK_n:
                    return callEvent(IWindow::EventType::NEXT_LIB);
            }
            break;
        default:
            break;
        }
    }
    std::cout << "event sdl2" << std::endl;
};

//clock
IClock &AGraphicalSDL2::getClock() {
    return graphicalInfo.clock;
};