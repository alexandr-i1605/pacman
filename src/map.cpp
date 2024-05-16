﻿#include <vector>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "map.hpp"

void Map::draw_map(sf::RenderWindow& window) {
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

bool Map::check_collision(short next_X, short next_Y) { //true - если есть препятствие
	float current_x = next_X / float(TILE_SIZE);
	float current_y = next_Y / float(TILE_SIZE);

	for (short i = 0; i < 4; i++) {
		short x = 0;
		short y = 0;

		switch (i) {
		case 0:
		{
			x = floor(current_x);
			y = floor(current_y);
			break;
		}
		case 1:
		{
			x = ceil(current_x);
			y = floor(current_y);
			break;
		}
		case 2:
		{
			x = floor(current_x);
			y = ceil(current_y);
			break;
		}
		case 3:
		{
			x = ceil(current_x);
			y = ceil(current_y);
			break;
		}
		}

		if (x >= 0 && 0 <= y && y < MAP_HEIGHT && MAP_WIDTH > x) {
		if (map_scheme[y][x] == '#')
		{
			return true;
		}
		}
	}
	return false;
}