#include "SFML/Network.hpp"

class Server {

    private:
    sf::TcpSocket m_socket;
    sf::TcpListener m_listener;
    sf::IpAddress m_ipAddress;
    int m_port;

    public:
    void handleinputs();
    void start();
    void receivePacket();
    void sendPacket();

};