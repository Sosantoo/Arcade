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
        AGameWrapper(const AGameWrapper&) = delete;
        AGameWrapper& operator=(const AGameWrapper&) = delete;
        AGameWrapper(AGameWrapper&&) = delete;
        AGameWrapper& operator=(AGameWrapper&&) = delete;
        ~AGameWrapper();

        virtual void start() final;

        virtual void stop() final ;

        virtual void restart() final;

    private:
        std::shared_ptr<GameEngine> gameEngine;
        IGraphical &_graphical;
        IEvent::EventHandler &_coreEvent;
};

class AGame: public IGame {
    public:
        AGame(): _gameWrapper{nullptr} {};
        ~AGame() {};
        AGame(const IGraphical &&) = delete;

        virtual void start(IGraphical &graphical, IEvent::EventHandler &eventHandler) {
            _gameWrapper = std::make_unique<AGameWrapper>(graphical, eventHandler);
            _gameWrapper->start();
        };

        virtual void stop() override {
            _gameWrapper->stop();
        };

        virtual void restart() override {
            _gameWrapper->restart();
        };

    private:
        std::unique_ptr<AGameWrapper> _gameWrapper;
};

#endif /* !AGAME_HPP_ */
