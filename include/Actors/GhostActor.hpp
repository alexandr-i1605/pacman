#pragma once
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "Actors/Pacman.hpp"
#include "BaseActor.hpp"

class Ghost :public BaseActor {
private:
	bool _door = 0; //1 вышел, 0 внутри
	short _Ghost_id;
	short _kof_of_speed=1; //задает коэффициент скорости
	Position _door_cord{ 320,256 };
	Position _Banned1 = { 14 * TILE_SIZE,9 * TILE_SIZE };
	Position _Banned2 = { 4 * TILE_SIZE,9 * TILE_SIZE };
	Position _scatter;
	short Ghost_mode = 1; //2 на БАЗУ,1 за пакменом, 0 в угол
public:
	Ghost(short id, short start_position_x = 0, short start_position_y = 0, short direction = -1, short speed = 1, unsigned short ScatterX = 0,  unsigned short ScaterY = 0);
	short get_ghost_mode();
	short get_ghost_id();
	float get_dist_targ(short tragetx, short targety);//âîçâðàùàåò ðàññòîÿíèå äî öåëè 
	short get_speed(); //по-хорошему сделать не типа инт, а другого
	Position get_scater();
	Position get_door_cord();
	std::vector<bool> get_collision(Map map);
	bool CheckBaned1();
	bool CheckBaned2();
	bool finish_g(Position Target);
	void movement(Map& map, const Position Target, Position pacman);
	void GhostGetTarget(Position pacman, std::vector<bool> collisions);
	void set_scarry_mode(bool Ghost_Mode);
	void set_speed(float kof);
	void set_door(bool n);
	virtual void draw(sf::RenderWindow& window) override;
	bool check_door();
};
