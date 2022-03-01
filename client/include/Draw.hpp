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
    sf::Color m_setcolor;

public:
    Draw(sf::Vector2i coords, sf::Image *image);
    bool execute(sf::Color color) override;
    bool undo() override;
    void set_color(sf::Color color);
};

#endif
