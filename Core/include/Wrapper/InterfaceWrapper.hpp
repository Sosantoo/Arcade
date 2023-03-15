/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** InterfaceWrapper
*/

#ifndef INTERFACEWRAPPER_HPP_
    #define INTERFACEWRAPPER_HPP_
    #include "dlfcnWrapper.hpp"
    #include "../various.hpp"

template <typename Interface_t>
class InterfaceWrapper: public DlfcnWrapper {
    public:
        InterfaceWrapper();
        InterfaceWrapper(const std::string& libPath, int flags);
        ~InterfaceWrapper();

        typedef Interface_t* create_interface_t();
        typedef void destroy_interface_t(Interface_t*);

        void load(const std::string& libPath);
        Interface_t *getInterface();

    private:
        std::unique_ptr<Interface_t> _interface;
        create_interface_t* _constructorGraphical;
        destroy_interface_t* _destructorGraphical;
};

#endif /* !INTERFACEWRAPPER_HPP_ */
