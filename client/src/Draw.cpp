/**
 *  @file   Draw.cpp
 *  @brief  Draw implementation, all drawing actions are commands.
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/

#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include "Draw.hpp"

/*! \brief  Constructor of the Draw class which extends the command class.
 *          It sends the coordinates stored within this object's instance in the form of
 *          an std::string to the base class when it calls the base class constructor.
 *          By default, the canvas background is set to white and the brush color 
 *          is set to black.
 *
 */
Draw::Draw(sf::Vector2i coords, sf::Image *image)
        : m_image(image),
          Command("Modify Pixel at: " + std::to_string(coords.x) + ", " +
                  std::to_string(coords.y)),
          m_coords(coords) {}

/*! \brief 	Applies the current drawing color to the canvas at the pixel coordinates
 *          given in the constructor if the coordinates are within the bounds of
 *          the drawing window.
 *
 */
bool Draw::execute(sf::Color color) {
    m_previousColor = m_image->getPixel(m_coords.x, m_coords.y);
    m_image->setPixel(m_coords.x, m_coords.y, color);

    return true;
}

/*! \brief 	Undoes the last drawing by applying the color stored in the 
 *          object during the execution call back to the pixel, restoring
 *          the original state.
 *
 */
bool Draw::undo() {
    m_image->setPixel(m_coords.x, m_coords.y, m_previousColor);
    return true;
}

/*! \brief 	Applies the color to the current object.
 *
 */
void Draw::set_color(sf::Color color) {
    m_image->setPixel(m_coords.x, m_coords.y, color);
}
