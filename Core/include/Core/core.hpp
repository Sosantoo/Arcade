/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#ifndef CORE_H_
    #define CORE_H_
    #include "../various.hpp"
    #include "../interface.hpp"
    #include "../Wrapper/Wrapper.hpp"

namespace Core
{

    class Core {
    private:
        InterfaceWrapper<IGraphical> _graphical;
        InterfaceWrapper<IGame> _game;
        IEvent::EventHandler event;
        Lib::lib_t _graphical_details;
        Lib::lib_t _game_details;
        libWrapper &_libs;

        //actions
        void nextGraphicsLibrary();
        void nextGameLibrary();
        void restartGame();
        void goToMenu();
        void closeGraphical();

        //loadings
        void loadStack();
        void loadGraphical();
        void loadGame();

    public:
        Core(libWrapper &);
        ~Core();

        void init(const std::string, const std::string);

        void launchGame();

    protected:
        IEvent::EventHandler &getCoreEventBind();
    };
};

// entrypoint core
int coreEntryPoint(const std::string &baseGraphicalsLibsName);

#endif /* !CORE_H_ */
