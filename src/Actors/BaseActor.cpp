#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "Actors/BaseActor.hpp"


void BaseActor::set_position(short x, short y) {
	_position_x = x;
	_position_y = y;
}

