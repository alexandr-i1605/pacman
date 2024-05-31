#include <array>
#include <iostream>

#include "Constants.hpp"
#include "Actors/Pacman.hpp"
#include "Actors/GhostControl.hpp"
#include "Actors/GhostActor.hpp"
#include "map.hpp"

GhostController::GhostController(Map map, Position position) : _ghosts({ Ghost(0, 10 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE),Ghost(1, 9 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 18 * TILE_SIZE,1 * TILE_SIZE) ,Ghost(2, 11 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)/*, Ghost(10 * TILE_SIZE, 8 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)*/ })
//_ghosts({Ghost( 10* TILE_SIZE, 9* TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE ),Ghost(8 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE),Ghost(11 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)});
{
	_Scarrry_timer = 0;
	_map = map;
	_NewTarget = position;
	_Boost_pills_counter = map.get_boost_pills();
}

void GhostController::update(Map map, Position newTarget) {
	_NewTarget = newTarget;
	_map = map;
	short New_Boost_pills = _map.get_boost_pills();
	if (New_Boost_pills < _Boost_pills_counter) {
		for (short i = 0; i < _ghosts.size(); i++) {
			_ghosts[i].set_scarry_mode(0);
			_Scarrry_timer = 0;
		}
		_Boost_pills_counter = New_Boost_pills;
	}
	if (_Scarrry_timer > GLOBAL_SCARRY_TIMER) {
		for (short i = 0; i < _ghosts.size(); i++) {
			_ghosts[i].set_scarry_mode(1);
			_ghosts[i].set_speed(1);
			_ghosts[i].set_door(1);
		}
	}
}


void GhostController::GhostTargets(Map map, Pacman New_pac) {
	_map = map;
	for (short i = 0; i < _ghosts.size(); i++) {
		if (i == 0) {
			if (_ghosts[0].get_ghost_mode() == 0 && _Scarrry_timer < GLOBAL_SCARRY_TIMER) {
				_ghosts[0].movement(_map, _ghosts[0].get_scater(), New_pac.get_position());
			}
			else if (_ghosts[0].get_ghost_mode() == 2) {
				_ghosts[0].movement(_map, _ghosts[0].get_door_cord(), New_pac.get_position());
			}
			else {
				_ghosts[0].movement(_map, New_pac.get_position(), New_pac.get_position());
				
			}
		}


		// розовый призрак

		if (i == 1) {
			if (_ghosts[1].get_ghost_mode() == 0 && _Scarrry_timer < GLOBAL_SCARRY_TIMER) {
				_ghosts[1].movement(_map,_ghosts[1].get_scater(),New_pac.get_position());
			}
			else if (_ghosts[1].get_ghost_mode() == 2 ) {
				_ghosts[1].movement(_map, _ghosts[1].get_door_cord(), New_pac.get_position());
			}
			else {
				switch (New_pac.get_direction())
				{
				case 0:
					
					_NewTarget.x = New_pac.get_position().x;
					_NewTarget.y = New_pac.get_position().y - _ghosts[1].get_speed() * 2 * TILE_SIZE; //на 4, а не на 2
					break;
				case 1:
					
					_NewTarget.x = New_pac.get_position().x + _ghosts[1].get_speed() * 2 * TILE_SIZE;
					break;
					_NewTarget.y = New_pac.get_position().y;
				case 2:
					
					_NewTarget.x = New_pac.get_position().x;
					_NewTarget.y = New_pac.get_position().y + _ghosts[1].get_speed() * 2 * TILE_SIZE;
					break;
				case 3:
					
					_NewTarget.x = New_pac.get_position().x - _ghosts[1].get_speed() * 2 * TILE_SIZE;
					_NewTarget.y = New_pac.get_position().y;
					break;

				default:
					break;
				}
				_ghosts[1].movement(_map, _NewTarget,New_pac.get_position());
			}
			
		}

		//голубой(ты) призрак

		if (i == 2) {
			if (_ghosts[2].get_ghost_mode() == 0 && _map.get_pills() < 2 * PILSS_AT_START / 3 && _Scarrry_timer < GLOBAL_SCARRY_TIMER) {
				_ghosts[2].movement(_map, _ghosts[2].get_scater(), New_pac.get_position());
				
			}
			else if (_ghosts[2].get_ghost_mode() == 2) {
				_ghosts[2].movement(_map, _ghosts[2].get_door_cord(), New_pac.get_position());
			}
			else if (_map.get_pills() < 2 * PILSS_AT_START / 3) {
				_NewTarget.x = 2 * (_NewTarget.x - _ghosts[0].get_position().x) + _ghosts[0].get_position().x;
				_NewTarget.y =2 * (_NewTarget.y - _ghosts[0].get_position().y) + _ghosts[0].get_position().y;
				//std::cout << floor(_NewTarget.x / TILE_SIZE) << "   " << floor(_NewTarget.y / TILE_SIZE) << std::endl;
				_ghosts[2].movement(_map, _NewTarget, New_pac.get_position());
			}
		}
	}
	_Scarrry_timer++;
}

void GhostController::GhostDraw(sf::RenderWindow& window) {
	
	_ghosts[0].draw(window);
		
	_ghosts[1].draw(window); //есть id можно делать по нему
		
	_ghosts[2].draw(window);
}
