#include <iostream>
#include <fstream>
#include <string> 
#include "Configurable.h"
class Map: public Configurable{
	std::map <std::string, std::string> settings;
	const std::string map_directory_pattern = "map";//+id this is how the catalogs are called like. for example gamefiles/maps/map1
	const std::string map_name_pattern = "map";//name of the file's pattern that maps are written in
	const std::string map_config_pattern = "map_config";//name of the file's pattern that contains config of the map
	std::string files_directory;//directory where the map files are in
	std::string map_directory;
	std::string config_directory;
	int map_id;
	int size_x;//size in x
	int size_y;//size in y
	int** map;//contains all the map chars
public:
	Map(std::string, int);
	~Map();
	int sizex();//returns x size
	int sizey();//returns y size
	void foreach_settings();//foreaching all settings
};