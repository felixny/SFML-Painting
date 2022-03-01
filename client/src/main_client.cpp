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
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_SFML_GL2_IMPLEMENTATION

#include "nuklear.h"
#include "nuklear_sfml_gl2.h"
#include "NGUI.hpp"
#include "App_Client.hpp"


/*! \brief 	The entry point into our program.
*		
*/
int main() {
    App_Client App_Client;

    NGUI gui(App_Client.GetWindow());

    gui.Init();
    // Print instructions
    std::cout << "Welcome to online paint program!\n";
    std::cout << "Functionalities list\n";
    std::cout << "Press 1 to change color to Red\n";
    std::cout << "Press 2 to change color to Green\n";
    std::cout << "Press 3 to change color to Black\n";
    std::cout << "Press 4 to change color to White\n";
    std::cout << "Press 5 to change color to Blue\n";
    std::cout << "Press 6 to change color to Yellow\n";
    std::cout << "Press 7 to change color to Magenta\n";
    std::cout << "Press 8 to change color to Cyan\n";
    std::cout << "Press Z to undo the last pixel\n";
    std::cout << "Press Y to redo the last pixel\n";
    std::cout << "Press C to start the chat\n";
    std::cout << "Press space to change the canvas color\n";
    std::cout << "Press escape to exit the program\n";
    std::cout << "================================\n";

    // Start the main rendering loop
    while (App_Client.GetWindow().isOpen()) {
        App_Client.setTimeElapsed();
        // Clear the window
        App_Client.GetWindow().clear();
        // Updates specified by the user
        sf::Event event;
        App_Client.update(event);
        gui.Update(event);

        App_Client.draw();
        // Draw to the canvas
        App_Client.GetWindow().draw(App_Client.GetSprite());
        // Display the canvas
        App_Client.GetWindow().display();

        // Complete input from nuklear GUI
        nk_input_end(gui.GetContext());

        // Draw our GUI
        gui.DrawGUI(App_Client);
        gui.getWindow().setActive(true);
        gui.getWindow().clear();
        gui.ClearAndDraw();
        gui.getWindow().display();

        // Listen to server requests
        App_Client.listen();
    }


    return 0;
}
