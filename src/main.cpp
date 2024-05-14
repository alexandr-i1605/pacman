#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "Actors/Pacman.hpp"
#include "map.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pacman");
    window.setVerticalSyncEnabled(true);
    window.setView(sf::View(sf::FloatRect(0, 0, TILE_SIZE * MAP_WIDTH, TILE_SIZE * MAP_HEIGHT)));

	Map Map;
    Pacman pacman(320, 352);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

		Map.draw_map(window);
        pacman.draw(window);
        window.display();
    }

    return 0;
}