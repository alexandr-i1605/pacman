#pragma once

#include "Actors/Pacman.hpp"
#include "BaseActor.hpp"

class Ghost :public BaseActor {
private:
	bool _door = 1;
	Position _door_cord{ 320,224 };
	Position _target{ 320,224 }; // íî ýòî íå òî÷íî
public:
	Ghost(short start_position_x = 0, short start_position_y = 0, short direction = -1, short speed = 1);
	float get_dist_targ(short tragetx, short targety);//âîçâðàùàåò ðàññòîÿíèå äî öåëè 
	//float get_dist_targ(short direction);
	void movement(Map& map, const Position pacman);
	void GhostGetTarget(Position pacman, std::vector<bool> collisions);
	virtual void draw(sf::RenderWindow& window) override;

};
