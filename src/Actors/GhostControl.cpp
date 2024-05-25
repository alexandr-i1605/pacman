#include <array>
#include <iostream>

#include "Constants.hpp"
#include "Actors/Pacman.hpp"
#include "Actors/GhostControl.hpp"
#include "Actors/GhostActor.hpp"
#include "map.hpp"

GhostController::GhostController(Map map, Position position) : _ghosts({ Ghost(10 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE),Ghost(10 * TILE_SIZE, 8 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)/*,Ghost(11 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE), Ghost(10 * TILE_SIZE, 8 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)*/ })
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
			_ghosts[0].movement(_map, New_pac.get_position());
		}

		if (i == 1) {
			if (_ghosts[1].get_ghost_mode() == 0) {
				_ghosts[1].GhostGetTarget(_ghosts[1].get_scater(), _ghosts[1].get_collision(_map));
			}
			else {
				
				switch (New_pac.get_direction())
				{
				case 0:
					std::cout << "0\n";
					_NewTarget.x = New_pac.get_position().x;
					_NewTarget.y = New_pac.get_position().y - _ghosts[i].get_speed() * 2 * TILE_SIZE;
				case 1:
					std::cout << "1\n";
					_NewTarget.x = New_pac.get_position().x + _ghosts[i].get_speed() * 2 * TILE_SIZE;
					_NewTarget.y = New_pac.get_position().y;
				case 2:
					std::cout << "2\n";
					_NewTarget.x = New_pac.get_position().x;
					_NewTarget.y = New_pac.get_position().y + _ghosts[i].get_speed() * 2 * TILE_SIZE;
				case 3:
					std::cout << "3\n";
					_NewTarget.x = New_pac.get_position().x - _ghosts[i].get_speed() * 2 * TILE_SIZE;
					_NewTarget.y = New_pac.get_position().y;

				default:
					//std::cout << New_pac.get_direction();
					break;
				}
				_ghosts[1].movement(_map, _NewTarget);
			}
			//std::cout << _NewTarget .x<< "     "<< _NewTarget.y << "\n";
			/*std::cout << _ghosts[i].get_ghost_mode() << std::endl;*/
			//_ghosts[1].movement(_map, _NewTarget);
		}
	}
}

void GhostController::GhostDraw(sf::RenderWindow& window) {
	
	_ghosts[0].draw(window, 0);
		
	_ghosts[1].draw(window, 1);
		
}
