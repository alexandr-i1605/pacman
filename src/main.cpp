#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "Actors/Pacman.hpp"
#include "Actors/GhostActor.hpp"
#include "map.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pacman");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(120);
    window.setView(sf::View(sf::FloatRect(0, 0, TILE_SIZE * MAP_WIDTH, TILE_SIZE * MAP_HEIGHT)));

    Map map;
    Pacman pacman(320, 352);
    

    Ghost ghost(320, 288, -1 , 1, 3* TILE_SIZE,2* TILE_SIZE); //320 288

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        map.draw_map(window);
        pacman.movement(map);
        pacman.draw(window);
        
        ghost.movement(map, pacman.get_position());
        ghost.draw(window);
        ghost.finish_g(pacman.get_position()); // потом замени void на bool в GhostActor 
        window.display();
    }

    return 0;
}
