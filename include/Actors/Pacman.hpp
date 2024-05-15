#pragma once

#include "BaseActor.hpp"

class Pacman :public BaseActor {
public:
	Pacman(short start_position_x = 0, short start_position_y = 0, short direction = -1, short speed = 2);
	virtual void movement(Map& map) override;
	virtual void draw(sf::RenderWindow& window) override;
};