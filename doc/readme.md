# Arcade - Games & Graphicals
Implementation of the Games in shared libraries

## Description
Here is the source code for the games, loaded in shared libraries. We made two games, `Snake` and `Nibbler`, but you are welcome to do more if you'd like. The lines below describe how to make one, which methods to implement, ...

## Implementation of a new Game
You have to create a class inheriting from the [`IGame`], and implement the following methods:
* getEventBinding
* processGameTick
* restart

You also have to make an `entryPoint` method, which will allow the `Core` to load the class, and look like this:
```
extern "C" {
    std::unique_ptr<IGame> create() {
        return std::make_unique<AGameNibbler>();
    }
}
```
The `extern "C"` line desactivate C++ polymorphysm, and blocks the compiler to change the function name ([mangling](https://www.ibm.com/docs/en/i/7.3?topic=linkage-name-mangling-c-only)). The function name is recognizable and loadable with dlsym.

## Implementation of a new display method
You have to create a class inheriting from the [`IGraphicalFactory`] interface, which implements the following methods:
* loadResource
* destroyRessource
* createIClock

You also have to implement the [`IWindow`], [`IGraphicalFactory`], [`IWindow`], [`IEntity`] , interfaces whith the chosen library.


To load the IDisplay classe, an `entryPoint` function need to be done and to be able to be loaded using `dlsym` (after `dlopen`); it looks like this:
```
extern "C" {
    std::unique_ptr<IGraphicalFactory> create() {
        return std::make_unique<GraphicalFactorySFML>();
    }
}
```
The `extern "C"` line desactivate C++ polymorphysm, and blocks the compiler to change the function name ([mangling](https://www.ibm.com/docs/en/i/7.3?topic=linkage-name-mangling-c-only)). The function name is recognizable and loadable with dlsym.
