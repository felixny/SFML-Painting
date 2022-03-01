#define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"

// Include our Third-Party SFML header
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
// Include standard library C++ libraries.
#include <iostream>
#include <string>
// Project header files
#include "App_Server.hpp"
#include "Command.hpp"
#include "Draw.hpp"

TEST_CASE("Commands Added to Queue") {
    App_Server app_server;

    app_server.addCommand(
            new Draw({1, 4}, &app_server.GetImage(), sf::Color::Black));
    app_server.addCommand(
            new Draw({2, 5}, &app_server.GetImage(), sf::Color::Black));
    app_server.addCommand(
            new Draw({135, 36}, &app_server.GetImage(), sf::Color::Black));
    SECTION("Adding commands to the command que") {
        REQUIRE(app_server.GetCommands().size() == 3);
    }

    SECTION("Adding same command to command queue to make sure it's ignored") {
        app_server.addCommand(
                new Draw({123, 343}, &app_server.GetImage(), sf::Color::Black));
        app_server.addCommand(
                new Draw({123, 343}, &app_server.GetImage(), sf::Color::Black));

        REQUIRE(app_server.GetCommands().size() == 4);
    }

    SECTION("Execute commands and remove them from command queue") {
        app_server.executeCommandsInQueue();

        REQUIRE(app_server.GetCommands().size() == 0);
    }

}  // PASSED

TEST_CASE("Check for commands that are out of bounds of the window") {
    App_Server app_server;

    app_server.addCommand(
            new Draw({900, 900}, &app_server.GetImage(), sf::Color::Black));
    app_server.addCommand(
            new Draw({-500, -500}, &app_server.GetImage(), sf::Color::Black));
    app_server.addCommand(
            new Draw({-600, 500}, &app_server.GetImage(), sf::Color::Black));
    app_server.addCommand(
            new Draw({600, -500}, &app_server.GetImage(), sf::Color::Black));

    REQUIRE(app_server.GetUndoCommands().size() == 0);
}  // PASSED

TEST_CASE("Check command is added to undo stack") {
    App_Server app_server;

    app_server.addCommand(
            new Draw({1, 4}, &app_server.GetImage(), sf::Color::Black));
    app_server.addCommand(
            new Draw({2, 5}, &app_server.GetImage(), sf::Color::Black));
    app_server.addCommand(
            new Draw({135, 36}, &app_server.GetImage(), sf::Color::Black));
    app_server.executeCommandsInQueue();

    REQUIRE(app_server.GetUndoCommands().size() == 3);

}  // PASSED

TEST_CASE("Command is moved from undo stack to redo stack") {
    App_Server app_server;

    app_server.addCommand(
            new Draw({1, 4}, &app_server.GetImage(), sf::Color::Black));
    app_server.addCommand(
            new Draw({2, 5}, &app_server.GetImage(), sf::Color::Black));
    app_server.addCommand(
            new Draw({135, 36}, &app_server.GetImage(), sf::Color::Black));
    app_server.executeCommandsInQueue();
    app_server.undoLastCommand();
    app_server.undoLastCommand();

    SECTION("Redo stack is added to") {
        REQUIRE(app_server.GetRedoCommands().size() == 2);
    }

    SECTION("Redo command moves command back to undo stack") {
        REQUIRE(app_server.GetUndoCommands().size() == 1);

        app_server.redoLastCommand();

        REQUIRE(app_server.GetUndoCommands().size() == 2);
    }

}  // PASSED

TEST_CASE("Check color return type") {
    App_Server app_server;

    app_server.colorBlack();

    REQUIRE(app_server.colorBlack() == sf::Color::Black);

    app_server.colorWhite();

    REQUIRE(app_server.colorWhite() == sf::Color::White);

}  // PASSED

TEST_CASE("Check canvas color return type") {
    App_Server app_server;

    app_server.colorWhite();
    app_server.getCanvasColor();

    SECTION("change canvas color to white color") {
        REQUIRE(app_server.getCanvasColor() == sf::Color::White);
    }

    app_server.colorBlack();
    app_server.getCanvasColor();

    SECTION("change canvas color to black color") {
        REQUIRE(app_server.getCanvasColor() == sf::Color::Black);
    }

    SECTION("Undo stack should be clear") {
        REQUIRE(app_server.GetUndoCommands().size() == 0);
    }

    SECTION("Redo stack should be clear") {
        REQUIRE(app_server.GetRedoCommands().size() == 0);
    }
}  // PASSED

TEST_CASE("Check IP Address and server port number Returned") {
    App_Server app_server;

    SECTION("Server IP Address should be local") {
        REQUIRE(app_server.getIpAddress() ==
                sf::IpAddress::getLocalAddress().toString());
    }

    SECTION("server port number should be from user input") {
        REQUIRE(app_server.getServerPortNumber() == -1);
        // -1 indicates only accepts user input
    }

}  // PASSED

TEST_CASE("Check Chat functionality") {
    App_Server app_server;

    sf::Packet packet_received;
    std::string type;
    std::string name_to_recv;
    std::string message_to_recv;
    packet_received >> type;

    if (type == "chat") {
        packet_received >> name_to_recv >> message_to_recv;
    }

        // empty string because client hasn't sent the message.
    SECTION("Name and Message received") {
        REQUIRE(app_server.getNameToRecv() == "");
        REQUIRE(app_server.getMessageToRecv() == "");
    }

    sf::Packet packet_sent;
    std::string name_to_send;
    std::string message_to_send;

    if (type == "chat") {
        name_to_send = name_to_recv;
        message_to_send = message_to_recv;
        packet_sent << std::string("chat") << name_to_send << message_to_send;
    }

    SECTION("Name and Message sent") {
        REQUIRE(app_server.getNameToSend() == "");
        REQUIRE(app_server.getMessageToRecv() == "");
    }

}  // PASSED
