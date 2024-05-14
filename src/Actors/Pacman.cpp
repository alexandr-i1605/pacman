
#include <SFML/Graphics.hpp>

#include "Actors/Pacman.hpp"


Pacman::Pacman(short x, short y, short direction, short speed) {
	_position_x = x;
	_position_y = y;
	_direction = direction;
	_speed = speed;
}

void Pacman::movement() {
	
}

void Pacman::draw(sf::RenderWindow& window) {
	sf::CircleShape circle(16);
	circle.setFillColor(sf::Color::Yellow);
	circle.setPosition(_position_x, _position_y);
	window.draw(circle);
}