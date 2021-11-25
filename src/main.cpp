#include <SFML/Graphics.hpp>

#include "draw.hpp"

int main(int argc, char* argv[]){
	// Program entry point.
	Draws draw; // Creating our game object.
	while(!draw.getWindow()->isDone()){
		// Game loop.
        draw.Update();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		draw.HandleInput();
        }
		
		draw.Render();
		//sf::sleep(sf::seconds(0.2));
	
	}
}