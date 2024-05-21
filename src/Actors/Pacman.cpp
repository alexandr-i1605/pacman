#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "Actors/Pacman.hpp"
#include "map.hpp"

Pacman::Pacman(short start_position_x, short start_position_y, short direction, short speed) {
	_position.x = start_position_x;
	_position.y = start_position_y;
	_direction = direction;
	_speed = speed;
}

void Pacman::movement(Map& map) {

	std::vector<bool> collisions(4);
	collisions[0] = map.check_collision(_position.x, _position.y - _speed);
	collisions[1] = map.check_collision(_position.x + _speed, _position.y);
	collisions[2] = map.check_collision(_position.x, _position.y + _speed);
	collisions[3] = map.check_collision(_position.x - _speed,  _position.y);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (!collisions[0]) {
			_direction = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (!collisions[1]) {
			_direction = 1;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (!collisions[2]) {
			_direction = 2;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (!collisions[3]) {
			_direction = 3;
		}
	}
	if (_direction!=-1 && !collisions[_direction]  ) {
		switch (_direction) {
		case 0:
		{
			_position.y -= _speed;
			break;
		}
		case 1:
		{
			_position.x += _speed;
			break;
		}
		case 2:
		{
			_position.y += _speed;
			break;
		}
		case 3:
		{
			_position.x -= _speed;
			break;
		}
		}
	}
	map.collect_manager(_position.x, _position.y, _direction);

	if (_position.x <= -TILE_SIZE) {
		_position.x = TILE_SIZE * MAP_WIDTH - 2;
	}
	else if (_position.x >= TILE_SIZE * MAP_WIDTH) {
		_position.x =-TILE_SIZE + 2;
	}
}

void Pacman::draw(sf::RenderWindow& window) {
	sf::Sprite PacSprite;
	sf::Texture PacTexture;
	short frame = (short)(floor(_animation_time / 6));
	PacSprite.setPosition(_position.x, _position.y);
	_animation_time = (_animation_time + 1) % 31;
	PacTexture.loadFromFile("res/PacMovement.png");
	PacSprite.setTexture(PacTexture);
	if (_direction == -1) {
		PacSprite.setTextureRect(sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
	}
	else {
		PacSprite.setTextureRect(sf::IntRect(TILE_SIZE * frame, TILE_SIZE * _direction, TILE_SIZE, TILE_SIZE));
	}
	window.draw(PacSprite);
}