#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "Actors/BaseActor.hpp"
#include "map.hpp"


void BaseActor::set_position(short x, short y) {
	_position.x = x;
	_position.y = y;
}

Position BaseActor::get_position() {
	return _position;
}
