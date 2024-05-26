#pragma once
#include "map.hpp"
#include <array>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "Constants.hpp"
#include "Actors/Pacman.hpp"
#include "Actors/GhostActor.hpp"

class GhostController {
private:
	short _Boost_pills_counter;
	Position _NewTarget;
	Map _map;
	std::array<Ghost, 3> _ghosts;
public:
	GhostController(Map map, Position posit_pac);
	void update(Map map, Position pacman);
	void GhostTargets(Map map, Pacman pacman);
	void GhostDraw(sf::RenderWindow& window);
};