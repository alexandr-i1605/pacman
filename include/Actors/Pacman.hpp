#pragma once

#include "BaseActor.hpp"

class Pacman :public BaseActor {
	short _animation_time{ 0 };
public:
	Pacman(short start_position_x = 0, short start_position_y = 0, short direction = -1, short speed = 2);
	short get_direction();
	void movement(Map& map);
	void draw(sf::RenderWindow& window);
};