#include <vector>
#include <string>

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "map.hpp"

void draw_map(std::vector<std::string>& map_scheme, sf::RenderWindow& window) {
    sf::RectangleShape wall(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    wall.setFillColor(sf::Color::Blue);

    for (int i = 0; i < map_scheme.size(); i++) {
        for (int j = 0; j < map_scheme[i].size(); j++) {
            wall.setPosition(j * TILE_SIZE, i * TILE_SIZE);
            if (map_scheme[i][j] == '#') {
                window.draw(wall);
            }
        }
    }
}
