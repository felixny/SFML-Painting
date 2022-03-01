/**
 *  @file   Draw.cpp
 *  @brief  Draw implementation, all drawing actions are commands.
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/

#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include "Draw.hpp"

/*! \brief 	Constructor of the Draw class which extends the command class.
 *          It sends the coordinates stored within this object's instance in the form of
 *          an std::string to the base class when it calls the base class constructor.
 *          By default, the canvas background is set to white and the brush color 
 *          is set to black.
 *
 */
Draw::Draw(sf::Vector2i coords, sf::Image *image, sf::Color color)
        : m_image(image),
          m_color(color),
          Command("Modify Pixel at: " + std::to_string(coords.x) + ", " +
                  std::to_string(coords.y)),
          m_coords(coords) {}

/*! \brief 	Applies the current drawing color to the canvas at the pixel coordinates
 *          given in the constructor if the coordinates are within the bounds of
 *          the drawing window.
 *
 */
bool Draw::execute() {
    m_previousColor = m_image->getPixel(m_coords.x, m_coords.y);
    m_image->setPixel(m_coords.x, m_coords.y, m_changedColor);
    return true;
}

/*! \brief 	Undoes the last drawing by applying the color stored in the 
 *          object during the execution call back to the pixel, restoring
 *          the original state.
 *
 */
bool Draw::undo() {
    m_image->setPixel(m_coords.x, m_coords.y, m_changedColor);
    return true;
}

/*! \brief  Redoes the last undo by applying the brush color stored in the
 *          object during the redo call to the pixel, restoring user's
 *          previous drawing.
 *
 */
bool Draw::redo() {
    m_image->setPixel(m_coords.x, m_coords.y, m_changedColor);
    return true;
}

/*! \brief 	Returns the current coordinates.
 *
 */
sf::Vector2i Draw::getCoords() { return this->m_coords; }

/*! \brief 	Returns the current color.
 *
 */
sf::Color Draw::getCurrentColor(sf::Color current_color) {
    m_changedColor = current_color;

    return m_changedColor;
}

/*! \brief 	Returns the previous color.
 *
 */
sf::Color Draw::getPreviousColor() { return m_previousColor; }

/*! \brief 	Changes the color to black and returns it.
 *
 */
sf::Color &Draw::getBlack() {
    m_changedColor = sf::Color::Black;

    return m_changedColor;
}

/*! \brief 	Changes the color to white and returns it.
 *
 */
sf::Color &Draw::getWhite() {
    m_changedColor = sf::Color::White;

    return m_changedColor;
}

/*! \brief 	Changes the color to green and returns it.
 *
 */
sf::Color &Draw::getGreen() {
    m_changedColor = sf::Color::Green;

    return m_changedColor;
}

/*! \brief 	Changes the color to red and returns it.
 *
 */
sf::Color &Draw::getRed() {
    m_changedColor = sf::Color::Red;

    return m_changedColor;
}

/*! \brief 	Changes the color to blue and returns it.
 *
 */
sf::Color &Draw::getBlue() {
    m_changedColor = sf::Color::Blue;

    return m_changedColor;
}

/*! \brief 	Changes the color to magenta and returns it.
 *
 */
sf::Color &Draw::getMagenta() {
    m_changedColor = sf::Color::Magenta;

    return m_changedColor;
}

/*! \brief 	Changes the color to yellow and returns it.
 *
 */
sf::Color &Draw::getYellow() {
    m_changedColor = sf::Color::Yellow;

    return m_changedColor;
}

/*! \brief 	Changes the color to cyan and returns it.
 *
 */
sf::Color &Draw::getCyan() {
    m_changedColor = sf::Color::Cyan;

    return m_changedColor;
}
