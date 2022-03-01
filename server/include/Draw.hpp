/**
 *  @file   Draw.hpp
 *  @brief  Drawing actions interface.
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/
#ifndef DRAW_H
#define DRAW_H

#include <string>
#include "Command.hpp"

class Draw : public Command {
private:
    sf::Color m_previousColor;
    sf::Vector2i m_coords;
    sf::Image *m_image;
    sf::Color m_color;
    sf::Color m_changedColor;

public:
    Draw(sf::Vector2i coords, sf::Image *image, sf::Color color);
    bool execute() override;
    bool undo() override;
    bool redo() override;
    sf::Vector2i getCoords();
    sf::Color getPreviousColor();
    sf::Color getCurrentColor(sf::Color current_color);
    sf::Color &getBlack();
    sf::Color &getWhite();
    sf::Color &getGreen();
    sf::Color &getRed();
    sf::Color &getCyan();
    sf::Color &getMagenta();
    sf::Color &getBlue();
    sf::Color &getYellow();
};

#endif
