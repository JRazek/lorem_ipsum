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
	std::string map_id;
	int size_x;//size in x
	int size_y;//size in y
	char** mapa;//contains all the map chars
public:
	Map(std::string, std::string);//directory where the maps are stored (./gamefiles/maps), name/id of the map (map1)
	~Map();//destructor
	int sizex();//returns x size
	int sizey();//returns y size
	void show_map_debugging();
	char **display();//returns a pointer to an array that cointains all the map chars.
	void foreach_settings();//foreaching all settings
};