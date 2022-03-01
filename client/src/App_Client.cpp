/**
 *  @file   App_Client.cpp
 *  @brief  Main client class for program
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cassert>
#include <iostream>
#include "App_Client.hpp"
#include "Draw.hpp"

/*! \brief 	Returns a reference to our m_image, so that
 *		    we do not have to publicly expose it.
 *
 */
sf::Image &App_Client::GetImage() { return *m_image; }

/*! \brief 	Returns a reference to our m_Texture so that
 *		    we do not have to publicly expose it.
 *
 */
sf::Texture &App_Client::GetTexture() { return *m_texture; }

/*! \brief 	Returns a reference to our m_window so that we
 *		    do not have to publicly expose it.
 *
 */
sf::RenderWindow &App_Client::GetWindow() { return *m_window; }

/*! \brief 	Returns a reference to our m_sprite so that we
 *		    do not have to publicly expose it.
 *
 */
sf::Sprite &App_Client::GetSprite() { return *m_sprite; }

/*! \brief 	Manually called to deallocate memory at the end of our program.
 *
 */
void App_Client::destroy() {
    delete m_image;
    delete m_sprite;
    delete m_texture;
}

/*! \brief 	Initializes the App and sets up the drawing canvas.
 *
 */
void App_Client::init(void) {
    connect();
    // Instantiate sprite pointer
    m_sprite = new sf::Sprite;
    // Instantiate image pointer
    m_image = new sf::Image;
    // Instantiate texture pointer
    m_texture = new sf::Texture;

    // Create our window
    m_window = new sf::RenderWindow(
            sf::VideoMode(600, 400), "Collaborative Paint", sf::Style::Titlebar);
    m_window->setVerticalSyncEnabled(true);
    // Create an image which stores the pixels we will update
    m_image->create(600, 400, sf::Color::White);
    assert(m_image != nullptr && "m_image != nullptr");
    // Create a texture which lives in the GPU and will render our image
    m_texture->loadFromImage(*m_image);
    assert(m_texture != nullptr && "m_texture != nullptr");
    // Create a sprite which is the entity that can be textured
    m_sprite->setTexture(*m_texture);
    assert(m_sprite != nullptr && "m_sprite != nullptr");

    sys_clock.restart();
    time_elapsed = 0;
    total_time_elapsed = 0;
    client_port_number = -1;
}

/*! \brief  Send request to server via packet containing 'z'.
 *
 */
void App_Client::request_undo() {
    sf::Packet packet_sent;
    packet_sent << std::string("z");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send undo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'y'.
 *
 */
void App_Client::request_redo() {
    sf::Packet packet_sent;
    packet_sent << std::string("y");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'black color'.
 *
 */
void App_Client::request_black_color() {
    sf::Packet packet_sent;
    packet_sent << std::string("black color");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'white color'.
 *
 */
void App_Client::request_white_color() {
    sf::Packet packet_sent;
    packet_sent << std::string("white color");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'red color'.
 *
 */
void App_Client::request_red_color() {
    sf::Packet packet_sent;
    packet_sent << std::string("red color");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'green color'.
 *
 */
void App_Client::request_green_color() {
    sf::Packet packet_sent;
    packet_sent << std::string("green color");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'blue color'.
 *
 */
void App_Client::request_blue_color() {
    sf::Packet packet_sent;
    packet_sent << std::string("blue color");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'yellow color'.
 *
 */
void App_Client::request_yellow_color() {
    sf::Packet packet_sent;
    packet_sent << std::string("yellow color");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'magenta color'.
 *
 */
void App_Client::request_magenta_color() {
    sf::Packet packet_sent;
    packet_sent << std::string("magenta color");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'cyan color'.
 *
 */
void App_Client::request_cyan_color() {
    sf::Packet packet_sent;
    packet_sent << std::string("cyan color");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'canvas color'.
 *
 */
void App_Client::request_canvas_color() {
    sf::Packet packet_sent;
    packet_sent << std::string("canvas color");
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send redo command by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'draw'.
 *
 */
void App_Client::request_draw(sf::Vector2i mouse_pos, sf::Color color) {
    sf::Packet packet_sent;
    packet_sent << std::string("draw") << mouse_pos.x << mouse_pos.y << color.r
                << color.g << color.b;
    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send draw pixel request by client\n";
    }
}

/*! \brief  Send request to server via packet containing 'chat'.
 *
 */
void App_Client::request_chat() {
    std::string name;
    std::cout << "What's your name: ";
    std::getline(std::cin, name);
    std::cout << "\n";
    std::string message;
    std::cout << "Send message: ";
    std::getline(std::cin, message);
    std::cout << "Press Enter to send message";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    sf::Packet packet_sent;

    packet_sent << std::string("chat") << name << message;

    if (client_socket.send(packet_sent) == sf::Socket::Done) {
    } else {
        std::cout << "Failure to send chat by client\n";
    }
}

/*! \brief  Updates the application and checks for input through SFML.
 *
 */
void App_Client::update(sf::Event event) {
    while (App_Client::GetWindow().pollEvent(event)) {
        if (event.type != sf::Event::KeyPressed) continue;

        if (event.key.code == sf::Keyboard::Z) {
            App_Client::request_undo();
        }
        if (event.key.code == sf::Keyboard::Y) {
            App_Client::request_redo();
        }
        if (event.key.code == sf::Keyboard::Escape) {
            client_socket.disconnect();
            m_window->close();
            exit(EXIT_SUCCESS);
        }

        if (event.key.code == sf::Keyboard::Space) {
            App_Client::request_canvas_color();
        }

        if (event.key.code == sf::Keyboard::Num1) {
            App_Client::request_red_color();
        } else if (event.key.code == sf::Keyboard::Num2) {
            App_Client::request_green_color();
        } else if (event.key.code == sf::Keyboard::Num3) {
            App_Client::request_black_color();
        } else if (event.key.code == sf::Keyboard::Num4) {
            App_Client::request_white_color();
        } else if (event.key.code == sf::Keyboard::Num5) {
            App_Client::request_blue_color();
        } else if (event.key.code == sf::Keyboard::Num6) {
            App_Client::request_yellow_color();
        } else if (event.key.code == sf::Keyboard::Num7) {
            App_Client::request_magenta_color();
        } else if (event.key.code == sf::Keyboard::Num8) {
            App_Client::request_cyan_color();
        }

        if (event.key.code == sf::Keyboard::C) {
            App_Client::request_chat();
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i coords = sf::Mouse::getPosition(App_Client::GetWindow());
        if ((coords.x < 0 || coords.x > App_Client::GetWindow().getSize().x) ||
            (coords.y < 0 || coords.y > App_Client::GetWindow().getSize().y) ||
            (App_Client::pmouseX == coords.x && App_Client::pmouseY == coords.y)) {
            return;
        }
        sf::Color color;
        App_Client::request_draw(coords, color);
        App_Client::pmouseX = coords.x;
        App_Client::pmouseY = coords.y;
    }
}

/*! \brief 	Each iteration of the main loop after update.
 *
 */
void App_Client::draw(void) {
    total_time_elapsed += time_elapsed;
    if (total_time_elapsed > 1 / 60) {
        App_Client::GetTexture().loadFromImage(App_Client::GetImage());
        total_time_elapsed = 0;
    }
}

/*! \brief 	The default constructor that initializes the connection.
 *
 */
App_Client::App_Client() { this->init(); }

/*! \brief 	Attempt to connect to the server with the given IP 
 *          address and port number.
 *
 */
void App_Client::connect() {
    std::string client_ip_str;
    std::cout << "Enter server's port number to which to connect to: ";
    std::cin >> client_port_number;
    // initialize the client ip
    client_ip = sf::IpAddress::getLocalAddress();
    std::cout << "Enter server's IP address: ";
    std::cin >> client_ip_str;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // overwrite client's ip with the server's ip
    client_ip = client_ip_str;
    while (client_socket.connect(client_ip, client_port_number) !=
           sf::Socket::Done) {  // Check to make sure IP & Port correspond to
        // server
        std::cout << "Client can't connect to server with IP: "
                  << client_ip.toString() << " , and port: " << client_port_number
                  << std::endl;
        std::cout << "Enter server's port number: ";
        std::cin >> client_port_number;
        std::cout << "Enter server's IP address: ";
        std::cin >> client_ip_str;
        client_ip = client_ip_str;
    }

    std::cout << "Successfully connected to socket with IP: "
              << client_ip.toString() << " , and port: " << client_port_number
              << std::endl;
    client_selector.add(client_socket);  // Adding client's socket to selector,
    // which helps client listen to requests
}

/*! \brief 	Listens for packet to receive from the server.
 *
 */
void App_Client::listen() {
    while (client_selector.wait(sf::microseconds(CONNECT_TIMEOUT))) {
        if (client_selector.isReady(client_socket)) {
            sf::Packet packet_recv;
            if (client_socket.receive(packet_recv) == sf::Socket::Done) {
                std::string type;
                packet_recv >> type;
                if (type == "draw") {
                    sf::Vector2i coords;
                    sf::Color color;
                    packet_recv >> coords.x >> coords.y >> color.r >> color.g >> color.b;
                    Draw pixel_to_draw(coords, m_image);
                    pixel_to_draw.execute(color);
                }
                if (type == "change") {
                    sf::Vector2i coords;
                    sf::Color color;
                    packet_recv >> coords.x >> coords.y >> color.r >> color.g >> color.b;
                    Draw pixel_to_change(coords, m_image);
                    pixel_to_change.set_color(color);
                }
                if (type == "init") {
                    sf::Vector2i coords;
                    sf::Color color;
                    packet_recv >> coords.x >> coords.y >> color.r >> color.g >> color.b;
                    Draw pixel_to_draw(coords, m_image);
                    pixel_to_draw.execute(color);
                }

                if (type == "color") {
                    sf::Vector2i coords;
                    sf::Color color;
                    packet_recv >> coords.x >> coords.y >> color.r >> color.g >> color.b;
                    Draw pixel_to_change(coords, m_image);
                    pixel_to_change.set_color(color);
                }

                if (type == "canvas") {
                    sf::Color color;
                    packet_recv >> color.r >> color.g >> color.b;
                    m_image->create(600, 400, color);
                }

                if (type == "chat") {
                    std::string name;
                    std::string message;
                    packet_recv >> name >> message;
                    std::cout << name << " said: " << message << "\n";
                }

            } else {
                std::cout << "Client couldn't receive packet\n";
            }
        }
    }
}

/*! \brief 	Restarts a counter for time elapsed.
 *
 */
void App_Client::setTimeElapsed() {
    time_elapsed = sys_clock.restart().asSeconds();
}

/*! \brief 	Destructor to destroy all the objects created.
 *
 */
App_Client::~App_Client() { destroy(); }
