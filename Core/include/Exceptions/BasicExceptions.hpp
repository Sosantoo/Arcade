/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** BasicExceptions
*/

#ifndef BASICEXCEPTIONS_HPP_
    #define BASICEXCEPTIONS_HPP_
    #include "../various.hpp"

 class BasicExceptionWithMessage: public std::exception {
    public:
        BasicExceptionWithMessage(const std::string& errorAuthor, const std::string& errorMsg)
            : _errorMsg("\033[0;31m" + errorAuthor + " " + errorMsg + "\033[0m") {}

        virtual const char *what() const noexcept override {
            return _errorMsg.c_str();
        }

    private:
        std::string _errorMsg;
};


#endif /* !BASICEXCEPTIONS_HPP_ */
