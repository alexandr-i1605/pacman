#include <vector>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "map.hpp"

void Map::draw_map(sf::RenderWindow& window) {
	sf::RectangleShape wall(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	wall.setFillColor(sf::Color::Blue);
	sf::CircleShape pill(4);
	sf::RectangleShape door(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	door.setFillColor(sf::Color::White);
	sf::CircleShape boost_pill(8);


	for (int i = 0; i < map_scheme.size(); i++) {
		for (int j = 0; j < map_scheme[i].size(); j++) {
			wall.setPosition(j * TILE_SIZE, i * TILE_SIZE);
			pill.setPosition(j * TILE_SIZE + TILE_SIZE / 2 - 4, i * TILE_SIZE + TILE_SIZE / 2 - 4);
			door.setPosition(j * TILE_SIZE, i * TILE_SIZE);
			boost_pill.setPosition(j * TILE_SIZE + TILE_SIZE / 2 - 8, i * TILE_SIZE + TILE_SIZE / 2 - 8);
			if (map_scheme[i][j] == '#') {
				window.draw(wall);
			}
			else if (map_scheme[i][j] == '*') {
				window.draw(pill);
			}
			if (map_scheme[i][j] == '!') {
				window.draw(door);
			}
			else if (map_scheme[i][j] == '@') {
				window.draw(boost_pill);
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
			if (map_scheme[y][x] == '#') {
				return true;
			}
		}
	}
	return false;
}

void Map::collect_manager(short next_X, short next_Y, short direction) {
	float current_x = next_X / float(TILE_SIZE);
	float current_y = next_Y / float(TILE_SIZE);
	short x = 0;
	short y = 0;
	if (direction == 0 || direction == 3) {
		x = ceil(current_x);
		y = ceil(current_y);
	}
	else {
		x = floor(current_x);
		y = floor(current_y);
	}
	if (x >= 0 && 0 <= y && y < MAP_HEIGHT && MAP_WIDTH > x) {
		if (map_scheme[y][x] == '*') {
			map_scheme[y][x] = ' ';
			_pills_counter -= 1;
		}
		else if (map_scheme[y][x] == '@') {
			map_scheme[y][x] = ' ';
			_boost_pills_counter -= 1;
		}
	}
}

short Map::get_pills() {
	return _pills_counter;
}

short Map::get_boost_pills() {
	return _boost_pills_counter;
}
