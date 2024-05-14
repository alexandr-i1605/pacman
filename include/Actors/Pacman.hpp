#pragma once

#include "BaseActor.hpp"

class Pacman :public BaseActor {
public:
	Pacman(short _position_x = 0, short _position_y = 0, short _direction = 0, short _speed = 10);
	virtual void movement() override;
	virtual void draw(sf::RenderWindow& window) override;
};