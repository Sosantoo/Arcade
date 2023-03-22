/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGame
*/

#ifndef AGAME_HPP_
    #define AGAME_HPP_
    #include "various.hpp"
    #include "GameEngine.hpp"

class AGameWrapper {
    public:
        AGameWrapper(IGraphical &, IEvent::EventHandler &);
        ~AGameWrapper();
        AGameWrapper(const IGraphical &&) = delete;

        virtual void start();

        virtual void stop();

        virtual void reset();

    private:
        std::shared_ptr<GameEngine> gameEngine;
        IGraphical &_graphical;
        IEvent::EventHandler &_coreEvent;
};

class AGame: public IGame {
    public:
        AGame(): _gameWrapper{nullptr} {};
        ~AGame();
        AGame(const IGraphical &&) = delete;

        virtual void start(IGraphical &graphical, IEvent::EventHandler &eventHandler) {
            _gameWrapper = new AGameWrapper(graphical, eventHandler);
            _gameWrapper->start();
        };

        virtual void stop() {
            _gameWrapper->stop();
        };

        virtual void reset() {
            _gameWrapper->reset();
        };

    private:
        AGameWrapper *_gameWrapper;
};

#endif /* !AGAME_HPP_ */
