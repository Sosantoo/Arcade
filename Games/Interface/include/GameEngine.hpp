/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
    #define GAMEENGINE_HPP_
    #include "EventHandler.hpp"
    #include "AGame.hpp"

class GameEngine: public EventHandler {
    public:
        GameEngine(IGraphical &graphical);
        ~GameEngine();

        void GameEngineLoop();

    private:
        IGraphical &_graphical;
};

#endif /* !GAMEENGINE_HPP_ */
