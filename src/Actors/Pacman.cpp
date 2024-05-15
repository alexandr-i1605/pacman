
#include <SFML/Graphics.hpp>

#include "Actors/Pacman.hpp"


Pacman::Pacman(short x, short y, short direction, short speed) {
	_position_x = x;
	_position_y = y;
	_direction = direction;
	_speed = speed;
}

void Pacman::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		_direction = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_direction = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		_direction = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		_direction = 3;
	}

	switch (_direction) {
	case 0:
	{
		_position_y -= _speed;
		break;
	}
	case 1:
	{
		_position_x += _speed;
		break;
	}
	case 2:
	{
		_position_y += _speed;
		break;
	}
	case 3:
	{
		_position_x -= _speed;

		break;
	}
	}
}

void Pacman::draw(sf::RenderWindow& window) {
	sf::CircleShape circle(16);
	circle.setFillColor(sf::Color::Yellow);
	circle.setPosition(_position_x, _position_y);
	window.draw(circle);
}