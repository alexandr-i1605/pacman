#include <array>
#include <iostream>

#include "Constants.hpp"
#include "Actors/Pacman.hpp"
#include "Actors/GhostControl.hpp"
#include "Actors/GhostActor.hpp"
#include "map.hpp"

GhostController::GhostController(Map map, Position position) : _ghosts({ Ghost(10 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE),Ghost(9 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)/*,Ghost(11 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE), Ghost(10 * TILE_SIZE, 8 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)*/ })
//_ghosts({Ghost( 10* TILE_SIZE, 9* TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE ),Ghost(8 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE),Ghost(11 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)});
{
	_map = map;
	_NewTarget = position;
}

void GhostController::update(Map map, Position newTarget) {
	_NewTarget = newTarget;
	_map = map;
}


void GhostController::GhostTargets(Map map, Pacman New_pac) {
	_map = map;
	for (short i = 0; i < _ghosts.size(); i++) {
		if (i == 0) {
			_ghosts[0].movement(_map, New_pac.get_position(),New_pac.get_position());
			//std::cout << _ghosts[0].check_door() <<"    ";
		}

		if (i == 1) {
			//std::cout << _ghosts[1].check_door() << std::endl;
			if (_ghosts[1].get_ghost_mode() == 0) {
				_ghosts[1].movement(_map,_ghosts[1].get_scater(),New_pac.get_position());
			}
			else {
				switch (New_pac.get_direction())
				{
				case 0:
					
					_NewTarget.x = New_pac.get_position().x;
					_NewTarget.y = New_pac.get_position().y - _ghosts[1].get_speed() * 2 * TILE_SIZE;
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
	}
}

void GhostController::GhostDraw(sf::RenderWindow& window) {
	
	_ghosts[0].draw(window, 0);
		
	_ghosts[1].draw(window, 1);
		
}
