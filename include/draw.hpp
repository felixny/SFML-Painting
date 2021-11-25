#pragma once
#include <SFML/Graphics.hpp>

#include "window.hpp"

class Draws {
 private:
  
  Window m_window;
  sf::Sprite m_sprite;
  sf::Texture m_texture;
  sf::Image m_image;
  
 public:
  Draws();
  ~Draws();

  void DrawExecute();
  void HandleInput();
  void Update();
  void Render();
  Window* getWindow();



};