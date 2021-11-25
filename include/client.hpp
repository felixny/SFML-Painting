#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

class Client {
    public:
    Client(sf::TcpSocket& server, int players, sf::String names[]);
    void start();

    private:
    sf::TcpSocket m_server;
    int players;
    sf::String names;
    
};
