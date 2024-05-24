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
	Position _pacman;
	Map _map;
	std::array<Ghost, 1> _ghosts;
public:
	GhostController(Map map, Position pacman);
	void GhostTargets(Map map, Position pacman);
	void GhostDraw(sf::RenderWindow& window);
};