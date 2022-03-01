/**
 *  @file   App_Client.hpp
 *  @brief  App_Client class interface
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/
#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <limits>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Network.hpp>
#include <queue>
#include <stack>
#include "Draw.hpp"

// the amount of milliseconds that it takes for a client to realize that it's no
// longer connected to a server.
#define CONNECT_TIMEOUT 1

class App_Client {
private:
    sf::Image *m_image;
    sf::Sprite *m_sprite;
    sf::Texture *m_texture;
    sf::RenderWindow *m_window;

    sf::Clock sys_clock;
    float time_elapsed;
    float total_time_elapsed;

    sf::IpAddress client_ip;
    int client_port_number;
    sf::TcpSocket client_socket;
    sf::SocketSelector client_selector;

public:
    App_Client();
    unsigned int pmouseX, pmouseY;
    sf::Image &GetImage();
    sf::Texture &GetTexture();
    sf::RenderWindow &GetWindow();
    sf::Sprite &GetSprite();
    void setTimeElapsed();

    void destroy();
    void init(void);
    void update(sf::Event event);
    void draw(void);
    void loop();

    void connect();
    void listen();
    void request_undo();
    void request_redo();
    void request_draw(sf::Vector2i mouse_pos, sf::Color color);
    ~App_Client();

    void request_black_color();
    void request_white_color();
    void request_red_color();
    void request_green_color();
    void request_blue_color();
    void request_yellow_color();
    void request_magenta_color();
    void request_cyan_color();
    void request_canvas_color();
    void request_chat();
};

#endif
