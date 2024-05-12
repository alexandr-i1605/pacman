#pragma once

class BaseActor {
protected:
	short _position_x;
	short _position_y;
	short _direction;
	const short _speed;
public:
	void set_position(short x, short y);
	virtual void movement() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};