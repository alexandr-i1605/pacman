#include <array>


#include "Constants.hpp"
#include "Actors/Pacman.hpp"
#include "Actors/GhostControl.hpp"
#include "Actors/GhostActor.hpp"
#include "map.hpp"

GhostController::GhostController(Map map,Position pacman) : _ghosts({ Ghost(10 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)/*,Ghost(8 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE),Ghost(11 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE), Ghost(10 * TILE_SIZE, 8 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)*/ })
//_ghosts({Ghost( 10* TILE_SIZE, 9* TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE ),Ghost(8 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE),Ghost(11 * TILE_SIZE, 9 * TILE_SIZE, -1 , 1, 2 * TILE_SIZE,19 * TILE_SIZE)});
{
	_pacman = pacman;
	_map = map;
}

void GhostController::GhostTargets(Map map, Position New_pac_pos) {
	_map = map;
	_pacman = New_pac_pos;
	for (short i = 0; i < _ghosts.size(); i++) {
		if (i == 0) {
			_ghosts[i].movement(_map, _pacman);
		}
	}
}

void GhostController::GhostDraw(sf::RenderWindow& window) {
	for (short i = 0; i < _ghosts.size(); i++) {
		if (i == 0) {
			_ghosts[i].draw(window);
		}
	}
}
