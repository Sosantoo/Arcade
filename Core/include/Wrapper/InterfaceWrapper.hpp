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
        using create_interface_t = Interface_t* (*)();

        InterfaceWrapper();
        InterfaceWrapper(const Lib::lib_t &, const Lib::lib_type);
        ~InterfaceWrapper();

        void load(const Lib::lib_t &, const Lib::lib_type);

        Interface_t& getInterface() const;

    private:
        std::unique_ptr<Interface_t> _interface;
        create_interface_t _constructor;
};

#endif /* !INTERFACEWRAPPER_HPP_ */
