/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Entity
*/

#include "GraphicalFactorySDL2.hpp"
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <map>

void GridSDL2::resetColor() {
    SDL_SetRenderDrawColor(_renderer, 255, 255, 204, 255);
}

void GridSDL2::setColor(int x, int y, SDL_Color color) {
    int WINDOW_WIDTH, WINDOW_HEIGHT;
    SDL_GetWindowSize(_window, &WINDOW_WIDTH, &WINDOW_HEIGHT);

    int cellWidth = WINDOW_WIDTH / _gridColumn;
    int cellHeight = WINDOW_HEIGHT / _gridRow;

    SDL_Rect rect = {x * cellWidth, y * cellHeight, cellWidth, cellHeight};
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(_renderer, &rect);
    resetColor();
}

void GridSDL2::create(int gridRow, int gridColumn) {
    // Initialize variables
    _gridRow = gridRow;
    _gridColumn = gridColumn;

    // Create a renderer
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if (_renderer == NULL)
        throw std::runtime_error(SDL_GetError());

   resetColor();

    // Draw the grid
    for (int row = 0; row < gridRow; row++) {
        for (int col = 0; col < gridColumn; col++) {
                if (row == 0 || col == 0 || _gridRow - 1 == row || _gridColumn - 1 == col)
                    updateCell(col, row, IEntity::Color::Orange);
                else
                    updateCell(col, row, colorBackGround);
        }
    }

    // Render the screen
    SDL_RenderPresent(_renderer);
}

void GridSDL2::displayEntity() {
    SDL_RenderPresent(_renderer);
    SDL_Delay(50);
};

void GridSDL2::updateCell(int x, int y, Color color) {
    std::map<IEntity::Color, SDL_Color> colorMap = {
        {IEntity::Color::Blue, {173, 216, 230, 255}},
        {IEntity::Color::Green, {152, 251, 152, 255}},
        {IEntity::Color::Orange, {255, 218, 185, 255}},
        {IEntity::Color::Red, {255, 192, 203, 255}},
        {IEntity::Color::Brown, {222, 184, 135, 255}},
        {IEntity::Color::Yellow, {255, 255, 204, 255}}
    };
    setColor(x, y, colorMap[color]);
};

void GridSDL2::destroy() {
    SDL_DestroyRenderer(_renderer);
}


//Clock
void ClockSDL2::startClock() {
    startTime = SDL_GetTicks();
};

double ClockSDL2::getTimeElapsed() {
    // return (SDL_GetTicks() - startTime) / 1000.0; milliseconds
    return SDL_GetTicks() - startTime;
}

void ClockSDL2::resetClock() {
    startTime = SDL_GetTicks();
};

void ClockSDL2::initClock() {
    startTime = SDL_GetTicks();
};


//text
void TextSDL2::create(std::string str) {
    // TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
    // SDL_Color White = {255, 255, 255, 0};

    // _surfaceMessage = TTF_RenderText_Solid(Sans, str.c_str(), White);
    // _message = SDL_CreateTextureFromSurface(renderer, _surfaceMessage);

    // SDL_Rect Message_rect = {10, 10, 100, 100};

    // SDL_RenderCopy(renderer, _message, NULL, &Message_rect);

    // // Create a new SDL_Surface from the text string
    // _textSurface = TTF_RenderText_Solid(font, str.c_str(), color);

    // // Create an SDL_Texture from the SDL_Surface
    // _texture = SDL_CreateTextureFromSurface(renderer, _textSurface);

    // // Get the dimensions of the SDL_Texture
    // int width, height;
    // SDL_QueryTexture(_texture, NULL, NULL, &width, &height);

    // // Create an SDL_Rect to position the texture
    // SDL_Rect rect = { 15, 15, width, height };

    // // Render the SDL_Texture to the screen
    // SDL_RenderCopy(renderer, _texture, NULL, &rect);
}

void TextSDL2::setPosition(int x, int y) {

}

void TextSDL2::destroy() {
}

void TextSDL2::displayEntity() {
    // SDL_RenderCopy(renderer, _message, NULL, &Message_rect);
}

void TextSDL2::changeString(std::string str) {
    // _textSurface = TTF_RenderText_Solid(font, str.c_str(), color);
}