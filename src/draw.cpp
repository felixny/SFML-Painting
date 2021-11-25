#include "draw.hpp"

#include <iostream>

Draws::Draws() : m_window("Chapter 2", sf::Vector2u(800, 600)) {
  m_image.create(800, 600, sf::Color::White);

  // Create the texture that will be displayed

  m_texture.loadFromImage(m_image);

  // Create a sprite that we overaly
  // on top of the texture.

  m_sprite.setTexture(m_texture);
}

Draws::~Draws() {}

void Draws::Update() {
  m_window.Update();
  // DrawExecute();
}

void Draws::DrawExecute() {
  sf::Vector2i m_coords = sf::Mouse::getPosition(m_window.getWindows());
  if (m_coords.x > m_window.getWindows().getSize().x || m_coords.x < 0 ||
      m_coords.y > m_window.getWindows().getSize().y || m_coords.y < 0) {
    std::cout << "Out of boundary at: " << m_coords.x << ", " << m_coords.y
              << std::endl;
    return;
  }

  m_image.setPixel(m_coords.x, m_coords.y, sf::Color::Red);
  std::cout << "Modify Pixel at: " << m_coords.x << ", " << m_coords.y
            << std::endl;

  m_texture.loadFromImage(m_image);
}

void Draws::Render() {
  m_window.BeginDraw();
  m_window.Draw(m_sprite);
  m_window.EndDraw();
}

Window* Draws::getWindow() { return &m_window; }

void Draws::HandleInput() {
  DrawExecute();
}
