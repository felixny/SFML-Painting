/**
 *  @file   App_Server.cpp
 *  @brief  Main server class for program
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cassert>
#include <iostream>
#include "App_Server.hpp"
#include "Command.hpp"
#include "Draw.hpp"

/*! \brief 	Before a command is added to the queue it is checked to confirm if
 *          it is already present in the undo stack or as the last element in the
 *          queue. If it is a duplicate then the command is deleted.
 *
 */
void App_Server::addCommand(Command *c) {
    if (duplicateBackOfQueue(c) || duplicateTopOfStack(c)) {
        delete c;
        return;
    }

    m_commands.push(c);

    clearRedoStack();
}

/*! \brief  Checks if the given command is the most recent element in the queue.
 *          If the command is a duplicate returns true otherwise false.
 *
 */
bool App_Server::duplicateBackOfQueue(Command *c) {
    if (!m_commands.empty() && *c == m_commands.back()) return true;

    return false;
}

/*! \brief 	Checks if the given command is the first element of the undo stack.
 *          If the command is a duplicate returns true otherwise false.
 *
 */
bool App_Server::duplicateTopOfStack(Command *c) {
    if (m_commands.empty() && !m_undo.empty() && *c == m_undo.top()) return true;
    return false;
}

/*! \brief 	Clears the redoStack, which occurs when a new command is added
 *          to the queue.
 *
 */
void App_Server::clearRedoStack() {
    while (!m_redo.empty()) {
        delete m_redo.top();
        m_redo.pop();
    }
}

/*! \brief 	Clears the undoStack, returns the memory to the system when the
 *          application is closed.
 *
 */
void App_Server::clearUndoStack() {
    while (!m_undo.empty()) {
        delete m_undo.top();
        m_undo.pop();
    }
}

/*! \brief 	When the undo command is given, the command is taken from the
 *          undo stack. The state is reverted through the undo function
 *          and then the command is placed in the redo stack.
 *
 */
void App_Server::undoLastCommand() {
    if (m_undo.empty()) return;
    color_to_send = static_cast<Draw *>(m_undo.top())->getPreviousColor();
    coords_to_send = static_cast<Draw *>(m_undo.top())->getCoords();
    if (m_undo.top()->undo()) {
        m_redo.push(m_undo.top());
        m_undo.pop();
    }
}

/*! \brief 	When a command is removed from the undo stack it is placed on
 *          the redo stack. If the redo command is given the command is removed
 *          from the redo stack, executed, and then placed back on the undo
 *          stack.
 *
 */
void App_Server::redoLastCommand() {
    if (m_redo.empty()) return;
    color_to_send =
            static_cast<Draw *>(m_redo.top())->getCurrentColor(color_change_to_send);
    coords_to_send = static_cast<Draw *>(m_redo.top())->getCoords();
    m_redo.top()->redo();
    m_undo.push(m_redo.top());
    m_redo.pop();
}

/*! \brief 	Changes the color of the pixel to black and gets its 
 *          coordinates, stores them to send packet. Returns sf::Color
 *          for testing.
 *
 */
sf::Color App_Server::colorBlack() {
    Draw pixel_to_change(coords, m_image, m_color);
    color_change_to_send = pixel_to_change.getBlack();
    coords_change_to_send = pixel_to_change.getCoords();
    return sf::Color::Black;
}

/*! \brief 	Changes the color of the pixel to white and gets its 
 *          coordinates, stores them to send packet. Returns sf::Color
 *          for testing.
 *
 */
sf::Color App_Server::colorWhite() {
    Draw pixel_to_change(coords, m_image, m_color);
    color_change_to_send = pixel_to_change.getWhite();
    coords_change_to_send = pixel_to_change.getCoords();
    return sf::Color::White;
}

/*! \brief 	Changes the color of the pixel to red and gets its 
 *          coordinates, stores them to send packet. Returns sf::Color
 *          for testing.
 *
 */
void App_Server::colorRed() {
    Draw pixel_to_change(coords, m_image, m_color);
    color_change_to_send = pixel_to_change.getRed();
    coords_change_to_send = pixel_to_change.getCoords();
}

/*! \brief 	Changes the color of the pixel to green and gets its 
 *          coordinates, stores them to send packet. Returns sf::Color
 *          for testing.
 *
 */
void App_Server::colorGreen() {
    Draw pixel_to_change(coords, m_image, m_color);
    color_change_to_send = pixel_to_change.getGreen();
    coords_change_to_send = pixel_to_change.getCoords();
}

/*! \brief 	Changes the color of the pixel to blue and gets its 
 *          coordinates, stores them to send packet. Returns sf::Color
 *          for testing.
 *
 */
void App_Server::colorBlue() {
    Draw pixel_to_change(coords, m_image, m_color);
    color_change_to_send = pixel_to_change.getBlue();
    coords_change_to_send = pixel_to_change.getCoords();
}

/*! \brief 	Changes the color of the pixel to cyan and gets its 
 *          coordinates, stores them to send packet. Returns sf::Color
 *          for testing.
 *
 */
void App_Server::colorCyan() {
    Draw pixel_to_change(coords, m_image, m_color);
    color_change_to_send = pixel_to_change.getCyan();
    coords_change_to_send = pixel_to_change.getCoords();
}

/*! \brief 	Changes the color of the pixel to yellow and gets its 
 *          coordinates, stores them to send packet. Returns sf::Color
 *          for testing.
 *
 */
void App_Server::colorYellow() {
    Draw pixel_to_change(coords, m_image, m_color);
    color_change_to_send = pixel_to_change.getYellow();
    coords_change_to_send = pixel_to_change.getCoords();
}

/*! \brief 	Changes the color of the pixel to magenta and gets its 
 *          coordinates, stores them to send packet. Returns sf::Color
 *          for testing.
 *
 */
void App_Server::colorMagenta() {
    Draw pixel_to_change(coords, m_image, m_color);
    color_change_to_send = pixel_to_change.getMagenta();
    coords_change_to_send = pixel_to_change.getCoords();
}

/*! \brief 	Canvas color is changed to color_change_to_send. Redo
 *          and Undo stacks are reset every time canvas color is
 *          changed.
 *
 */
void App_Server::canvasColor() {
    default_canvas_color = color_change_to_send;
    m_image->create(600, 400, default_canvas_color);
    clearRedoStack();
    clearUndoStack();
}

/*! \brief 	Executes commands in the command queue, if successful, the
 *          command is added to the undo stack. If the command is
 *          unsuccessful in execution, it is deleted and removed from queue.
 *
 */
void App_Server::executeCommandsInQueue() {
    while (!m_commands.empty()) {
        if (m_commands.front()->execute()) {
            m_undo.push(m_commands.front());
            m_commands.pop();
            continue;
        }

        delete m_commands.front();
        m_commands.pop();
    }
}

/*! \brief 	Returns a reference to our m_image, so that
 *		    we do not have to publicly expose it.
 *
 */
sf::Image &App_Server::GetImage() { return *m_image; }

/*! \brief 	Manually called to deallocate memory at the end 
 *          of our program.
 *
 */
void App_Server::destroy() {
    clearUndoStack();
    clearRedoStack();

    delete m_image;
}

/*! \brief 	Initializes the App and sets up the drawing canvas.
 *
 */
void App_Server::init(void) {
    connect();
    // Instantiate image pointer
    m_image = new sf::Image;
    // Create an image which stores the pixels we will update
    m_image->create(600, 400, default_canvas_color);
    assert(m_image != nullptr && "m_image != nullptr");

    server_port_number = -1;
    sys_clock.restart();
    time_elapsed = 0;
    total_time_elapsed = 0;
}

/*! \brief 	Loop which handles the main server functions.
 *
 */
void App_Server::loop() {
    while (true) {
        listen();
        executeCommandsInQueue();
    }
}

/*! \brief 	The default constructor that initializes the connection.
 *
 */
App_Server::App_Server() {
    default_pixel_color = sf::Color::Black;
    default_canvas_color = sf::Color::White;

    this->init();
}

/*! \brief 	Initializes connection that gets the local IP address of the
 *          host and sets the port number.
 *
 */
void App_Server::connect() {
    std::cout << "Enter port number to start listening to: ";
    std::cin >> server_port_number;

    while (server_listener.listen(server_port_number) != sf::Socket::Done) {
        std::cout << "Enter valid port number to start listening to: ";
        std::cin >> server_port_number;
    }
    std::cout << "Server listening at said port, server IP: "
              << sf::IpAddress::getLocalAddress().toString() << std::endl;

    m_IpAddress = sf::IpAddress::getLocalAddress().toString();

    // Adding created socket/listener to a selector.
    socket_selector.add(server_listener);
    // Listener determines if a socket has sent data.
}

/*! \brief 	Get the latest version of canvas kept by server.
 *
 */
void App_Server::canvasState(sf::TcpSocket *client_socket,
                             sf::TcpSocket *delete_socket) {
    int width = m_image->getSize().x;
    int height = m_image->getSize().y;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Packet used to encapsulate data to send.
            sf::Packet packet_to_send;
            if (m_image->getPixel(j, i) == sf::Color::Black) {
                packet_to_send << std::string("init") << j << i;
                if (client_socket->send(packet_to_send) == sf::Socket::Done) {
                } else {
                    std::cout << "Client has disconnected, deleting said client.\n";
                    delete_socket = client_socket;
                }
            }
        }
    }
}

/*! \brief 	Sockets check for any data that is received.
 *
 */
void App_Server::listen() {
    // Contains potential socket to delete
    sf::TcpSocket *socket_to_delete = nullptr;

    // Will go inside loop, if within 0.1 seconds data is received
    while (socket_selector.wait(sf::seconds(CONNECT_ATTEMPT))) {
        // Checking if socket to read from is server
        if (socket_selector.isReady(server_listener)) {
            std::cout << "Server detected client attempting connection\n";

            sf::TcpSocket *arriving_client_socket = new sf::TcpSocket;
            // Accepting client's socket details
            if (server_listener.accept(*arriving_client_socket) == sf::Socket::Done) {
                // Storing client's socket in list of references
                client_sockets.push_back(arriving_client_socket);
                // Adding client's socket to list of possible sockets to get data from

                socket_selector.add(*arriving_client_socket);
                std::cout << "Client successfully accepted for service\n";

                canvasState(arriving_client_socket, socket_to_delete);

            } else {
                std::cout << "Could not accept client attempting connection\n";
                delete arriving_client_socket;
            }
        } else {
            updateClient(socket_to_delete);
        }
        break;
    }
    // delete disconnected data
    if (socket_to_delete != nullptr) {
        disconnect(socket_to_delete);
    }
}

/*! \brief 	If server sockets are ready, packet is received
 *          and updated. Otherwise one of the clients is
 *          ready to send data.
 *
 */
void App_Server::updateClient(sf::TcpSocket *socket_to_delete) {
    for (it1 = client_sockets.begin(); it1 != client_sockets.end(); it1++) {
        client_to_service = *it1;
        // Checking if X client has sent data
        if (socket_selector.isReady(*client_to_service)) {
            receivedPacket();
            updatePacket(action_taken, socket_to_delete);
        } else {
            socket_to_delete = *it1;
        }
    }
}

/*! \brief 	Receiving packet and extracting first component.
 *
 */
void App_Server::receivedPacket() {
    sf::Packet packet_received;
    if (client_to_service->receive(packet_received) == sf::Socket::Done) {
        packet_received >> type;
        action_taken = false;
        if (type == "z") {
            App_Server::undoLastCommand();
            action_taken = true;
        }
        if (type == "y") {
            App_Server::redoLastCommand();
            action_taken = true;
        }
        if (type == "draw") {
            packet_received >> coords.x >> coords.y >> m_color.r >> m_color.g >>
                            m_color.b;
            App_Server::addCommand(new Draw(coords, m_image, m_color));
            action_taken = true;
        }
        if (type == "black color") {
            App_Server::colorBlack();
            action_taken = true;
        }
        if (type == "white color") {
            App_Server::colorWhite();
            action_taken = true;
        }
        if (type == "red color") {
            App_Server::colorRed();
            action_taken = true;
        }
        if (type == "green color") {
            App_Server::colorGreen();
            action_taken = true;
        }
        if (type == "blue color") {
            App_Server::colorBlue();
            action_taken = true;
        }
        if (type == "cyan color") {
            App_Server::colorCyan();
            action_taken = true;
        }
        if (type == "yellow color") {
            App_Server::colorYellow();
            action_taken = true;
        }
        if (type == "magenta color") {
            App_Server::colorMagenta();
            action_taken = true;
        }
        if (type == "canvas color") {
            App_Server::canvasColor();
            action_taken = true;
        }
        if (type == "chat") {
            packet_received >> name_to_recv >> message_to_recv;
            action_taken = true;
        }
    }
}

/*! \brief 	If an action has been taken by one client, then 
 *          it needs to be forwarded to the other clients.
 *          The type determines what goes in the packet to 
 *          send.
 *
 */
void App_Server::updatePacket(bool action, sf::TcpSocket *socket_to_delete) {
    sf::Packet packet_sent;
    if (action) {
        if (type == "draw") {
            packet_sent << std::string("draw") << coords.x << coords.y
                        << color_change_to_send.r << color_change_to_send.g
                        << color_change_to_send.b;
        }
        if (type == "y" || type == "z") {
            packet_sent << std::string("change") << coords_to_send.x
                        << coords_to_send.y << color_to_send.r << color_to_send.g
                        << color_to_send.b;
        }

        if (type == "black color" || type == "white color" ||
            type == "green color" || type == "red color" || type == "blue color" ||
            type == "cyan color" || type == "magenta color" ||
            type == "yellow color") {
            packet_sent << std::string("color") << coords_change_to_send.x
                        << coords_change_to_send.y << color_change_to_send.r
                        << color_change_to_send.g << color_change_to_send.b;
        }

        if (type == "canvas color") {
            packet_sent << std::string("canvas") << color_change_to_send.r
                        << color_change_to_send.g << color_change_to_send.b;
        }

        if (type == "chat") {
            name_to_send = name_to_recv;
            message_to_send = message_to_recv;
            std::cout << name_to_send << " said: " << message_to_send << "\n";
            packet_sent << std::string("chat") << name_to_send << message_to_send;
        }

        // Traversing through all clients and sending them packet
        for (it2 = client_sockets.begin(); it2 != client_sockets.end(); it2++) {
            // If request type was draw, then user that sent request is skipped
            if (it1 != it2 && type == "draw") {
                cascading_clients = *it2;
                if (cascading_clients->send(packet_sent) == sf::Socket::Done) {
                } else {
                    socket_to_delete = *it2;
                }
            } else {  // Else no user is skipped
                cascading_clients = *it2;
                if (cascading_clients->send(packet_sent) == sf::Socket::Done) {
                } else {
                    socket_to_delete = *it2;
                }
            }
        }
    }
}

/*! \brief 	Takes a TCP socket and removes its reference from the
 *          list of sockets to retrieve data from. Removes the socket
 *          itself from the list of existing clients.
 *
 */
void App_Server::disconnect(sf::TcpSocket *ptr) {
    socket_selector.remove(*ptr);
    ptr->disconnect();
    client_sockets.remove(ptr);
}

/*! \brief 	Destructor to destroy all the objects created.
 *
 */
App_Server::~App_Server() { destroy(); }
