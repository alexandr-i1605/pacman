#pragma once

class BaseActor {
protected:
	short _position_x{ 0 };
	short _position_y{ 0 };
	short _direction{ 0 };
	short _speed{ 0 };
public:
	BaseActor() = default;
	void set_position(short x, short y);
	virtual void movement() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};