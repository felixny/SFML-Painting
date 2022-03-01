/**
 *  @file   Command.cpp
 *  @brief  Implementation of Command.hpp
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/

#include <string>
#include "Command.hpp"

/*! \brief 	Initialize string m_commandDescription object
 *
 */
Command::Command(std::string commandDescription)
        : m_commandDescription(commandDescription) {}

/*! \brief 	Destructor
 *
 */
Command::~Command() {}

/*! \brief  Compares the equality of commandDescription strings within the
 *          compared command objects.
 *
 */
bool Command::operator==(const Command *rhs) {
    return this->m_commandDescription == rhs->m_commandDescription;
}
