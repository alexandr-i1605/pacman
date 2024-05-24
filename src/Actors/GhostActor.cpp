

#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "Constants.hpp"
#include "Actors/Pacman.hpp"
#include "Actors/GhostActor.hpp"
#include "map.hpp"


Ghost::Ghost(short start_position_x, short start_position_y, short direction, short speed, unsigned short scatterX, unsigned short scatterY) {
	_position.x = start_position_x;
	_position.y = start_position_y;
	_direction = direction;
	_speed = speed;
	_scatter.x = scatterX;
	_scatter.y = scatterY;
}

float Ghost::get_dist_targ(short targetx, short targety) {
	Position TempRes;
	TempRes.x = targetx - this->get_position().x;
	TempRes.y = targety - this->get_position().y;
	return std::sqrt(powf(TempRes.x, 2) + powf(TempRes.y, 2)); //ìá òóò íàäî ÷åò ñäåëòü ñ x y è ïðåäóñìîòðåòü îòðèö çíà÷
}

//void Ghost::GhostGetTarget(Position target, std::vector<bool> collisions) {
//	short avalibale_ways = 0;
//	short tempDir = _direction;
//	for (short i =0 ; i < 4; i++) {
//		if (!collisions[i] && (2+i)%4) {
//			avalibale_ways++;
//		}
//	}
//	if (avalibale_ways > 1) {
//		Position TempRes;
//		TempRes.x = target.x - this->get_position().x; //получился вектор
//		TempRes.y = target.y - this->get_position().y;
//		
//		
//		
//		if (((abs(TempRes.x) > abs(TempRes.y)) && TempRes.x>0) && !collisions[1] /*&& get_dist_targ(target.x, target.y) > get_dist_targ(target.x - _speed, target.y)*/ && _door_cord.x != this->get_position().x - _speed && (tempDir != (2 + 1) % 4)) {
//			_direction = 1;
//			std::cout << "1!\n";
//		}
//		else if (((abs(TempRes.y) > abs(TempRes.x)) && TempRes.y < 0) && !collisions[0] /*&& get_dist_targ(target.x, target.y) > get_dist_targ(target.x , target.y + _speed)*/ && _door_cord.y != this->get_position().y + _speed && (tempDir != (2 + 0) % 4)) {
//			_direction = 0;
//			std::cout << "0!\n";
//		}
//		else if (((abs(TempRes.y) > abs(TempRes.x)) && TempRes.y > 0) && !collisions[2]/* && get_dist_targ(target.x, target.y) > get_dist_targ(target.x, target.y - _speed)*/ && _door == 1 && _door_cord.y != this->get_position().y - _speed && (tempDir != (2 + 2) % 4)) {
//			_direction = 2;
//			std::cout << "2!\n";
//		}
//		else if (((abs(TempRes.x) > abs(TempRes.y)) && TempRes.x < 0) && !collisions[3]/* && get_dist_targ(target.x, target.y) > get_dist_targ(target.x + _speed, target.y)*/ && _door_cord.x != this->get_position().x + _speed &&  (tempDir != (2 + 3) % 4)) {
//			_direction = 3;
//			std::cout << "3!\n";
//		}
//		
//		if (((abs(TempRes.y) == abs(TempRes.x)) && TempRes.y > 0 && TempRes.x > 0) && !collisions[1] && !collisions[2] && _door_cord.y != this->get_position().y - _speed && _door_cord.y != this->get_position().x - _speed && (tempDir != (2 + 1) % 4) && (tempDir != (2 + 2) % 4)) {
//			_direction = 2;
//			std::cout << "2?\n";
//		}
//		else if (((abs(TempRes.y) == abs(TempRes.x)) && TempRes.y > 0 && TempRes.x < 0) && !collisions[3] && !collisions[2] && _door_cord.y != this->get_position().y - _speed && _door_cord.y != this->get_position().x + _speed && (tempDir != (2 + 3) % 4) && (tempDir != (2 + 2) % 4)) {
//			_direction = 2;
//			std::cout << "2?\n";
//		}
//		else if (((abs(TempRes.y) == abs(TempRes.x)) && TempRes.y < 0 && TempRes.x < 0) && !collisions[3] && !collisions[0] && _door_cord.y != this->get_position().y + _speed && _door_cord.y != this->get_position().x + _speed && (tempDir != (2 + 3) % 4) && (tempDir != (2 + 0) % 4)) {
//			_direction = 0;
//			std::cout << "0?\n";
//		}
//		else if (((abs(TempRes.y) == abs(TempRes.x)) && TempRes.y < 0 && TempRes.x > 0) && !collisions[0] && !collisions[1] && _door_cord.y != this->get_position().y + _speed && _door_cord.y != this->get_position().x - _speed && (tempDir != (2 + 1) % 4) && (tempDir != (2 + 0) % 4)) {
//			_direction = 0;
//			std::cout << "0?\n";
//		}
//
//		else if (tempDir == _direction && collisions[_direction]) {
//			for (int i = 0; i < 4; i++) {
//				if (!collisions[i] && (tempDir != (2 + i) % 4)) {
//					_direction = i;
//				}
//			}
//		}
//		
//
//	}
//	
//
//	else if (tempDir == _direction && collisions[_direction]) {
//		for (int i = 0; i < 4; i++) {
//			if (!collisions[i] && (tempDir != (2 + i) % 4)) {
//				_direction = i;
//			}
//		}
//	}
//	/*else if (tempDir == _direction && collisions[_direction]) {
//		for (int i = 0; i < 4; i++) {
//			if (!collisions[i] && (tempDir != (2 + i) % 4)) {
//				_direction = i;
//			}
//		}
//	}*/
//
//	if (_direction != -1 && !collisions[_direction]) {
//		switch (_direction) {
//		case 0:
//		{
//			_position.y -= _speed;
//			break;
//		}
//		case 1:
//		{
//			_position.x += _speed;
//			break;
//		}
//		case 2:
//		{
//			_position.y += _speed;
//			break;
//		}
//		case 3:
//		{
//			_position.x -= _speed;
//			break;
//		}
//		}
//	}
//}

bool Ghost::CheckBaned1() {
	if (this->get_position().x - _speed * TILE_SIZE == _Banned1.x && this->get_position().y == _Banned1.y) {
		return 0;
	}
	if (this->get_position().x - _speed * TILE_SIZE == _Banned2.x && this->get_position().y == _Banned2.y) { //razban
		return 0;
	}
	else {
		return 1;
	}
}

bool Ghost::CheckBaned2() {
	if (this->get_position().x + _speed * TILE_SIZE == _Banned1.x && this->get_position().y == _Banned1.y) {
		return 0;
	}
	if (this->get_position().x + _speed * TILE_SIZE == _Banned2.x && this->get_position().y == _Banned2.y) { //razban
		return 0;
	}
	else {
		return 1;
	}
}

void Ghost::GhostGetTarget(Position pacman, std::vector<bool> collisions) {

	short tempDir = _direction;
	
	if (!collisions[0] && _door_cord.y != this->get_position().y + _speed && get_dist_targ(pacman.x, pacman.y) > get_dist_targ(pacman.x, pacman.y + _speed) && (tempDir != (2 + 0) % 4) && (pacman.y + _speed != _door_cord.y)) {
		_direction = 0;

	}
	else if (!collisions[2] && _door == 1 && (_door_cord.y != this->get_position().y + _speed * TILE_SIZE) && get_dist_targ(pacman.x, pacman.y) > get_dist_targ(pacman.x, pacman.y - _speed) && (tempDir != (2 + 2) % 4) && pacman.y - _speed != _door_cord.y) {
		_direction = 2;

	}
	else if (!collisions[3] && _door_cord.x != this->get_position().x + _speed && CheckBaned2() && get_dist_targ(pacman.x, pacman.y) > get_dist_targ(pacman.x + _speed, pacman.y) && (tempDir != (2 + 3) % 4) && pacman.x + _speed != _door_cord.x) {
		_direction = 3;

	}
	else if (!collisions[1] && (_door_cord.x != this->get_position().x - _speed) && /*CheckBaned1()*//*this->get_position().x - _speed * TILE_SIZE != _Banned1.x && this->get_position().x - _speed * TILE_SIZE != _Banned2.x*/ CheckBaned1() && get_dist_targ(pacman.x, pacman.y) > get_dist_targ(pacman.x - _speed, pacman.y) && (tempDir != (2 + 1) % 4)&& pacman.x - _speed != _door_cord.x) {

		_direction = 1;
	}
	
	
	
	else if(tempDir == _direction && collisions[_direction]) {
		for (int i = 0; i < 4; i++) {
			if (!collisions[i] && (tempDir != (2 + i) % 4)) {
				_direction = i;
			}
		}
	}

	if (_direction != -1 && !collisions[_direction]) {
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
}

void Ghost::movement(Map& map, Position pacman) {


	std::vector<bool> collisions(4);
	collisions[0] = map.check_collision(_position.x, _position.y - _speed);
	collisions[1] = map.check_collision(_position.x + _speed, _position.y);
	collisions[2] = map.check_collision(_position.x, _position.y + _speed);
	collisions[3] = map.check_collision(_position.x - _speed, _position.y);

	//_target = pacman;

	if (_door == 0) {
		GhostGetTarget(_door_cord, collisions);
		if (get_dist_targ(_door_cord.x, _door_cord.y) == 0) {
			_door = 1;
			
		}
	}
	else {
		if (Ghost_mode == 1) {
			Ghost::GhostGetTarget(pacman, collisions);
		}
		else {
			Ghost::GhostGetTarget(_scatter, collisions);
		}
		if (_position.x <= -TILE_SIZE) {
			_position.x = TILE_SIZE * MAP_WIDTH - 2;
		}
		else if (_position.x >= TILE_SIZE * MAP_WIDTH) {
			_position.x = -TILE_SIZE + 2;
		}
	}
	std::cout << floor(_position.x / TILE_SIZE) << " " << floor(_position.y/ TILE_SIZE) << "      ";
	std::cout << floor(pacman.x/ TILE_SIZE) << " " << floor(pacman.y/ TILE_SIZE) << "\n";
}

bool Ghost::finish_g(Position pacman) {
	if (get_dist_targ(pacman.x, pacman.y) <= TILE_SIZE) {
		std::cout << "nigger\n";
		if (0) {
			return 1;
		}
	}
}

void Ghost::draw(sf::RenderWindow& window) {
	sf::CircleShape circle(TILE_SIZE / 2);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(_position.x, _position.y);
	window.draw(circle);
}

