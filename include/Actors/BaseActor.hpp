#pragma once
#include "map.hpp"
struct Position {
	short x;
	short y;
};

class BaseActor {
protected:
	Position _position{ 0, 0 };
	short _direction{ 0 };
	short _speed{ 0 };
public:
	BaseActor() = default;
	void set_position(short x, short y);
	Position get_position();
	virtual void movement(Map& map) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};