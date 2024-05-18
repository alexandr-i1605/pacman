#pragma once 

class Map {
private:
	std::vector<std::string> map_scheme{ //Схема карты
		" ################### ",
		" #********#********# ",
		" #*##*###*#*###*##*# ",
		" #*****************# ",
		" #*##*#*#####*#*##*# ",
		" #****#***#***#****# ",
		" ####*###*#*###*#### ",
		"    #*#*******#*#    ",
		"#####*#*## ##*#*#####",
		"********#   #********",
		"#####*#*#####*#*#####",
		"    #*#*******#*#    ",
		" ####*#*#####*#*#### ",
		" #********#********# ",
		" #*##*###*#*###*##*# ",
		" #**#***********#**# ",
		" ##*#*#*#####*#*#*## ",
		" #****#***#***#****# ",
		" #*######*#*######*# ",
		" #*****************# ",
		" ################### "
	};

	short _pills_counter{ 187 };
	short _boost_pills_counter{ 4 };
public:
	Map() = default;
	~Map() = default;
	void draw_map(sf::RenderWindow& window); //Отрисовывает карту, window - на какой экран выводить
	bool check_collision(short next_X, short next_Y); // Отвечает за коллизию карты
	void collect_manager(short next_X, short next_Y, short direction); // Отвечает за подбор предметов
	short get_pills();
	short get_boost_pills();
};
