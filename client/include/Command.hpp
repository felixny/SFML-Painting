/**
 *  @file   Command.hpp
 *  @brief  Represents an actionable command by the user.
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Command {
private:
    std::string m_commandDescription;

public:
    Command(std::string commandDescription);
    virtual ~Command();
    virtual bool execute(sf::Color color) = 0;
    virtual bool undo() = 0;
    virtual bool operator==(const Command *rhs);

    virtual std::string getDescription() const { return m_commandDescription; }
};

#endif
