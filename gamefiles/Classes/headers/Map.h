#pragma once
#include <iostream>
#include <fstream>
#include "Configurable.h"
class Map: public Configurable{
private:
	const std::string map_name_pattern = "map";//name of the files that maps are written in
	const std::string map_config_pattern = "map_config";//name of the files that contains config of the map
	std::string directory;//directory where the map files are in
	int size_x;//size in x
	int size_y;//size in y
	int** map;//contains all the map chars
public:
	Map(std::string);
	int sizex();//returns x size
	int sizey();//returns y size
};