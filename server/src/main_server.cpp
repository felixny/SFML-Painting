/**
 *  @file   main.cpp
 *  @brief  Entry point into the program.
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <string>
#include "App_Server.hpp"

/*! \brief 	The entry point into our program.
*		
*/
int main() {
    App_Server App_Server;
    // Initialize our application
    App_Server.loop();
    return 0;
}
