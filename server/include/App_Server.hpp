/**
 *  @file   App_Server.hpp
 *  @brief  App_server class interface
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/
#ifndef APP_HPP
#define APP_HPP

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Network.hpp>
#include <list>
#include <queue>
#include <stack>
#include "Draw.hpp"

// the amount of milliseconds that it takes for a server to go into a while loop.
#define CONNECT_ATTEMPT 100

class App_Server {
private:
    // Queue that stores the next commands.
    std::queue<Command *> m_commands;
    // Stack that stores the last action to occur.
    std::stack<Command *> m_undo;
    // Stack that stores the last undo operation.
    std::stack<Command *> m_redo;

    sf::Image *m_image;

    sf::Color m_color;

    sf::Clock sys_clock;
    float time_elapsed;
    float total_time_elapsed;

    sf::TcpListener server_listener;
    std::list<sf::TcpSocket *> client_sockets;
    sf::SocketSelector socket_selector;
    sf::IpAddress m_IpAddress;
    int server_port_number;

    sf::Color color_to_send;
    sf::Vector2i coords_to_send;
    sf::Color color_change_to_send;
    sf::Vector2i coords_change_to_send;

    std::string message_to_send;
    std::string name_to_send;
    std::string message_to_recv;
    std::string name_to_recv;

    sf::Color default_pixel_color;
    sf::Color default_canvas_color;

    bool action_taken;

    sf::TcpSocket *client_to_service;
    sf::TcpSocket *cascading_clients;
    std::list<sf::TcpSocket *>::iterator it1;
    std::list<sf::TcpSocket *>::iterator it2;
    sf::Vector2i coords;
    std::string type;

    void clearRedoStack();
    void clearUndoStack();
    bool duplicateBackOfQueue(Command *c);
    bool duplicateTopOfStack(Command *c);

public:
    App_Server();
    App_Server(sf::Color default_color, sf::Color default_background);
    unsigned int pmouseX, pmouseY, mouseX, mouseY;
    void addCommand(Command *c);
    void undoLastCommand();
    void redoLastCommand();
    void executeCommandsInQueue();
    sf::Image &GetImage();
    sf::RenderWindow &GetWindow();
    std::queue<Command *> GetCommands() { return m_commands; }
    std::stack<Command *> GetUndoCommands() { return m_undo; }
    std::stack<Command *> GetRedoCommands() { return m_redo; }

    // Getter functions to be used for testing.
    sf::Color getCanvasColor() { return color_change_to_send; }
    sf::IpAddress getIpAddress() { return m_IpAddress; }
    int getServerPortNumber() { return server_port_number; }
    std::string getNameToRecv() { return name_to_recv; }
    std::string getMessageToRecv() { return message_to_recv; }
    std::string getNameToSend() { return name_to_send; }
    std::string getMessageToSend() { return message_to_recv; }

    void destroy();
    void init(void);
    void loop();

    void connect();
    void canvasState(sf::TcpSocket *client_socket, sf::TcpSocket *delete_socket);
    void updateClient(sf::TcpSocket *socket_to_delete);
    void updatePacket(bool action, sf::TcpSocket *socket_to_delete);
    void receivedPacket();
    void listen();
    void disconnect(sf::TcpSocket *ptr);
    ~App_Server();

    sf::Color colorBlack();
    sf::Color colorWhite();
    void colorRed();
    void colorGreen();
    void colorCyan();
    void colorBlue();
    void colorMagenta();
    void colorYellow();
    void canvasColor();
};

#endif
