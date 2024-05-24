#pragma once

#include "Actors/Pacman.hpp"
#include "BaseActor.hpp"

class Ghost :public BaseActor {
private:
	bool _door = 0;
	Position _door_cord{ 320,256 };
	Position _Banned1 = { 14 * TILE_SIZE,9 * TILE_SIZE };
	Position _Banned2 = { 4 * TILE_SIZE,9 * TILE_SIZE };
	Position _scatter;
	short Ghost_mode = 1; //1 за пакменом, 0 в угол
public:
	Ghost(short start_position_x = 0, short start_position_y = 0, short direction = -1, short speed = 1, unsigned short ScatterX = 0,  unsigned short ScaterY = 0);
	float get_dist_targ(short tragetx, short targety);//âîçâðàùàåò ðàññòîÿíèå äî öåëè 
	bool CheckBaned1();
	bool CheckBaned2();
	//short choose_dir(Position target, std::vector<bool> collisions);
	//float get_dist_targ(short direction);
	bool finish_g(Position pacman);
	void movement(Map& map, const Position pacman);
	void GhostGetTarget(Position pacman, std::vector<bool> collisions);
	virtual void draw(sf::RenderWindow& window) override;

};
