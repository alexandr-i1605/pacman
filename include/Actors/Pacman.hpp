#pragma once

#include "BaseActor.hpp"

class Pacman :public BaseActor {
public:
	Pacman(short _position_x = 0, short _position_y = 0, short _direction = -1, short _speed = 3);
	virtual void movement() override;
	virtual void draw(sf::RenderWindow& window) override;
};