

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
	short avalibale_ways=0;
	float Min_dist = sqrt(pow((MAP_HEIGHT * TILE_SIZE), 2) + pow((MAP_WIDTH * TILE_SIZE), 2));
	float Dist[4] = { get_dist_targ(pacman.x, pacman.y + _speed), get_dist_targ(pacman.x - _speed, pacman.y), get_dist_targ(pacman.x, pacman.y - _speed), get_dist_targ(pacman.x + _speed, pacman.y) };
	for (short i = 0; i < 4; i++) {
		if (!collisions[i]) {
			avalibale_ways++;
			if (!collisions[i] && (tempDir != (2 + i) % 4)) {
				if (Dist[i] < Min_dist) {
					Min_dist = Dist[i];
				}
			}
			else {
				Dist[i]= sqrt(pow((MAP_HEIGHT * TILE_SIZE), 2) + pow((MAP_WIDTH * TILE_SIZE), 2));
			}
		}
	}
	if (avalibale_ways == 1) {
		for (short i = 0; i < 4; i++) {
			if(!collisions[i]) {
				_direction = i;
			}
		}
		/*_direction = ((2 + tempDir) % 4);*/
	}
	if (avalibale_ways > 1) {
		//float Min_dist = sqrt(pow((MAP_HEIGHT * TILE_SIZE), 2) + pow((MAP_WIDTH * TILE_SIZE), 2));
		if (!collisions[0] && _door_cord.y != this->get_position().y + _speed && Dist[0] == Min_dist /*get_dist_targ(pacman.x, pacman.y) > get_dist_targ(pacman.x, pacman.y + _speed)*/ && (tempDir != (2 + 0) % 4) && (pacman.y + _speed != _door_cord.y)) {
			_direction = 0;

		}
		else if (!collisions[2] && _door == 1 && (_door_cord.y != this->get_position().y + _speed * TILE_SIZE) && Dist[2] == Min_dist/*get_dist_targ(pacman.x, pacman.y) > get_dist_targ(pacman.x, pacman.y - _speed)*/ && (tempDir != (2 + 2) % 4) && pacman.y - _speed != _door_cord.y) {
			_direction = 2;

		}
		else if (!collisions[3] && _door_cord.x != this->get_position().x + _speed && CheckBaned2() && Dist[3] == Min_dist /*get_dist_targ(pacman.x, pacman.y) > get_dist_targ(pacman.x + _speed, pacman.y)*/ && (tempDir != (2 + 3) % 4) && pacman.x + _speed != _door_cord.x) {
			_direction = 3;

		}
		else if (!collisions[1] && (_door_cord.x != this->get_position().x - _speed) &&  CheckBaned1() && Dist[1] == Min_dist && (tempDir != (2 + 1) % 4) && pacman.x - _speed != _door_cord.x) {

			_direction = 1;
		}


		else if (tempDir == _direction && collisions[_direction]) {
			for (int i = 0; i < 4; i++) {
				if (!collisions[i] && (tempDir != (2 + i) % 4)) {
					_direction = i;
				}
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

void Ghost::movement(Map& map, Position Target, Position pacman) {


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
			Ghost::GhostGetTarget(Target, collisions);
			this->finish_g(pacman);
			
		}
		else {
			Ghost::GhostGetTarget(_scatter, collisions);
			if (get_dist_targ(_scatter.x,_scatter.y) == 0) {
				Ghost_mode = 1;
			}
		}
		if (_position.x <= -TILE_SIZE) {
			_position.x = TILE_SIZE * MAP_WIDTH - 2;
		}
		else if (_position.x >= TILE_SIZE * MAP_WIDTH) {
			_position.x = -TILE_SIZE + 2;
		}
	}
	/*std::cout << floor(_position.x / TILE_SIZE) << " " << floor(_position.y/ TILE_SIZE) << "      ";
	std::cout << floor(pacman.x/ TILE_SIZE) << " " << floor(pacman.y/ TILE_SIZE) << "\n";*/
}

bool Ghost::finish_g(Position Target) {
	if (get_dist_targ(Target.x, Target.y) <= TILE_SIZE) {
		std::cout << "nigger"<<rand()%10<<"\n";
		if (0) {
			return 1;
		}
	}
}

void Ghost::draw(sf::RenderWindow& window, short n ) {
	sf::CircleShape circle(TILE_SIZE / 2);
	switch (n)
	{
	case 0:
		circle.setFillColor(sf::Color::Red);
		break;
	case 1:
		circle.setFillColor(sf::Color(255, 182, 255));
		break;
	default:
		break;
	}
	//circle.setFillColor(sf::Color::White);
	circle.setPosition(_position.x, _position.y);
	window.draw(circle);
}

short Ghost::get_speed() {
	return _speed;
}

bool Ghost::check_door() {
	return _door;
}

Position Ghost::get_scater() {
	return _scatter;
}

std::vector<bool> Ghost::get_collision(Map map) {
	std::vector<bool> collisions(4);
	collisions[0] = map.check_collision(_position.x, _position.y - _speed);
	collisions[1] = map.check_collision(_position.x + _speed, _position.y);
	collisions[2] = map.check_collision(_position.x, _position.y + _speed);
	collisions[3] = map.check_collision(_position.x - _speed, _position.y);
	return collisions;
}

short Ghost::get_ghost_mode() {
	return Ghost_mode;
}